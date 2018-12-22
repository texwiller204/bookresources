//===============================================================================
// @ DistanceTime.cpp
// 
// Class to compute Hermite spline for distance-time functions.  Builds the spline
// based on a set of keys and speeds -- slow, fast, linear, step and smooth --
// set at each key.
// ------------------------------------------------------------------------------
// Copyright (C) 2004 by James M. Van Verth. All rights reserved.
//
// The smooth sections of curve are generated by building and solving a linear 
// system.  The particular systems can be found in _Mathematical Elements for
// Computer Graphics_, by Rogers and Adams.  The method for solving those systems
// is a variant of LU-decomposition, optimized for tridiagonal matrices.  One
// place it can be found is in _Numerical Analysis_, by Burden and Faires.  
// Essentially you decompose the linear system into Upper and Lower diagonal 
// systems, and then solve those one at a time.  The array 'z' is the result
// of solving the lower diagonal system.
//
// A few oddities: you can set a step-in at the end of a subcurve, and a non-step
// speed out at the beginning of the subcurve.  The curve will interpolate to a 
// speed of zero and then jump up to the final point (it's easier to see if you try 
// it.  Similarly, you can set non-matching speeds to linear-in and -out speeds.
// Not normally done, but it's there.
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include "DistanceTime.h"
#include <assert.h>
#include <gl/glut.h>

//-------------------------------------------------------------------------------
//-- Static Members -------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Methods --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ DistanceTime::DistanceTime()
//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------
DistanceTime::DistanceTime() :
    mPositions( 0 ),
    mInTangents( 0 ),
    mOutTangents( 0 ),
    mTimes( 0 ),
    mCount( 0 )
{
}   // End of DistanceTime::DistanceTime()


//-------------------------------------------------------------------------------
// @ DistanceTime::DistanceTime()
//-------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------
DistanceTime::~DistanceTime()
{
    Clean();

}   // End of DistanceTime::~DistanceTime()


//-------------------------------------------------------------------------------
// @ DistanceTime::Initialize()
//-------------------------------------------------------------------------------
// Set up Hermite curve using constraints in KeyInfo array
//-------------------------------------------------------------------------------
bool 
DistanceTime::Initialize( const KeyInfo* keys,
					      unsigned int count )
{
    // make sure not already initialized
    if (mCount != 0)
        return false;

    // make sure data is valid
    if ( count < 2 || !keys )
        return false;

    // count the number of steps
    unsigned int numSteps = 0;
    for ( unsigned int j = 0; j < count; ++j )
    {
        if ( keys[j].mInSpeed == kStep )
            ++numSteps;
    }

    // each step "tangent" adds an additional point
    mCount = count+numSteps;

    // allocate the arrays
    mPositions = new float[mCount];
    mTimes = new float[mCount];
    mInTangents = new float[mCount-1]; 
    mOutTangents = new float[mCount-1];

    // for computing smooth sections of curve
    bool inSmooth = false;        // are we following a smooth section of curve?
    float L;                      // current lower diagonal matrix entry
    float* U = new float[count];  // upper diagonal matrix entries
    float* z = new float[count];  // solution of lower diagonal system Lz = b
    unsigned int matrixSize;      // number of entries in linear system

    unsigned int i = 0;           // current key
    unsigned int current = 0;     // current point in Hermite curve (not necessarily the same)
    for ( ; i < count; ++i, ++current )
    {
        // handle incoming speeds
        if ( i > 0 )
        {
            switch (keys[i].mInSpeed)
            {
            case kSlow:
                mInTangents[current-1] = 0.0f;
                // end of clamped spline
                if ( inSmooth )
                {
                    // add final entry to linear system for clamped spline
                    z[matrixSize++] = mInTangents[current-1];
                    FinishSmoothSubcurve( current, U, z, matrixSize );
                    inSmooth = false;
                }
                break;
            case kFast:
                mInTangents[current-1] = 3.0f*(keys[i].mDistance - keys[i-1].mDistance)/(keys[i].mTime - keys[i-1].mTime);
                // end of clamped spline
                if ( inSmooth )
                {
                    // add final entry to linear system for clamped spline
                    z[matrixSize++] = mInTangents[current-1];
                    FinishSmoothSubcurve( current, U, z, matrixSize );
                    inSmooth = false;
                }
                break;
            case kLinear:
                mInTangents[current-1] = (keys[i].mDistance - keys[i-1].mDistance)/(keys[i].mTime - keys[i-1].mTime);
                // end of clamped spline
                if ( inSmooth )
                {
                    // add final entry to linear system for clamped spline
                    z[matrixSize++] = mInTangents[current-1];
                    FinishSmoothSubcurve( current, U, z, matrixSize );
                    inSmooth = false;
                }
                break;
            case kStep:
                mPositions[current] = mPositions[current-1];
                mTimes[current] = keys[i].mTime - 1.0e-6f;
                mInTangents[current-1] = 0.0f;
                // end of clamped spline
                if ( inSmooth )
                {
                    // add final entry to linear system for clamped spline
                    z[matrixSize++] = mInTangents[current-1];
                    FinishSmoothSubcurve( current, U, z, matrixSize );
                    inSmooth = false;
                }
                mOutTangents[current] = (keys[i].mDistance - keys[i-1].mDistance)*1.0e+6f;
                mInTangents[current] = mOutTangents[current];
                ++current;
                break;
            case kSmooth:
                if ( !inSmooth )
                {
                    // start clamped spline
                    inSmooth = true;
                    // add start entry to linear system for clamped spline
                    L = 1.0f;
                    U[0] = 0.0f;
                    z[0] = mOutTangents[current-1];
                    matrixSize = 1;
                }

                // middle of smooth spline
                if ( i < count-1 && keys[i].mOutSpeed == kSmooth )
                {
                    // add internal entry to linear system for smooth spline
 	                float t_k0 = keys[i].mTime - keys[i-1].mTime;
	                float t_k1 = keys[i+1].mTime - keys[i].mTime;
                    L = 2.0f*(keys[i+1].mTime - keys[i-1].mTime) - t_k1*U[matrixSize-1];
                    U[matrixSize] = t_k0/L;
                    z[matrixSize] = 3.0f*(t_k0*t_k0*(keys[i+1].mDistance - keys[i].mDistance) + t_k1*t_k1*(keys[i].mDistance - keys[i-1].mDistance))/(t_k0*t_k1);
                    z[matrixSize] -= t_k1*z[matrixSize-1];
                    z[matrixSize] /= L;
                    ++matrixSize;
                }
                // end of natural spline
                else
                {
                    // add final entry to linear system for natural spline
                    float h = keys[i].mTime - keys[i-1].mTime;
                    L = h*(2.0f - U[matrixSize-1]);
                    z[matrixSize] = 3.0f*(keys[i].mDistance - keys[i-1].mDistance);
                    z[matrixSize] -= h*z[matrixSize-1];
                    z[matrixSize] /= L;
                    ++matrixSize;
                    FinishSmoothSubcurve( current, U, z, matrixSize );
                    inSmooth = false;
                }
            default:
                break;
            }
        }
        // handle outgoing speeds
        if ( i < count-1 )
        {
            switch (keys[i].mOutSpeed)
            {
            case kSlow:
            case kStep:
                mOutTangents[current] = 0.0f;
                break;
            case kFast:
                mOutTangents[current] = 3.0f*(keys[i+1].mDistance - keys[i].mDistance)/(keys[i+1].mTime - keys[i].mTime);
                break;
            case kLinear:
                mOutTangents[current] = (keys[i+1].mDistance - keys[i].mDistance)/(keys[i+1].mTime - keys[i].mTime);
                break;
            case kSmooth:
                if ( !inSmooth )
                {
                    // start of natural spline
                    inSmooth = true;
                    // add start entry to linear system for natural spline
                    L = 2.0f*(keys[i+1].mTime - keys[i].mTime);
                    U[0] = 0.5f;
                    z[0] = 3.0f*(keys[i+1].mDistance - keys[i].mDistance)/L;
                    matrixSize = 1;
                }
            default:
                break;
            }
        }
        mPositions[current] = keys[i].mDistance;
        mTimes[current] = keys[i].mTime;

    }

    // correct tangents for non-normalized spline
    // this could be done more efficiently by handling it as we calculate 
    // the speeds, but it would be significantly less clear 
    for ( i = 0; i < mCount-1; ++i )
    {
        float h = mTimes[i+1]-mTimes[i];
        mInTangents[i] *= h;
        mOutTangents[i] *= h;
    }

    // clean up temp arrays
    delete [] U;
    delete [] z;

    return true;

}   // End of DistanceTime::Initialize()


//-------------------------------------------------------------------------------
// @ DistanceTime::FinishSmoothSubcurve()
//-------------------------------------------------------------------------------
// Finish computing smooth subcurve, using LU decomposition
//-------------------------------------------------------------------------------
void DistanceTime::FinishSmoothSubcurve( unsigned int current, float* U, float* z, 
                                         unsigned int matrixSize )
{
    // solve Ux = z (see Burden and Faires for details)
    mInTangents[current-1] = z[matrixSize-1];
    for ( unsigned int i = matrixSize-2; i > 0; --i )
    {
        mInTangents[current-(matrixSize-i)] = z[i] - U[i]*mInTangents[current-(matrixSize-i)+1];
        mOutTangents[current-(matrixSize-i)+1] = mInTangents[current-(matrixSize-i)];
    }
    mOutTangents[current-(matrixSize-1)] = z[0] - U[0]*mInTangents[current-(matrixSize-1)];
}


//-------------------------------------------------------------------------------
// @ DistanceTime::Clean()
//-------------------------------------------------------------------------------
// Clean out data
//-------------------------------------------------------------------------------
void DistanceTime::Clean()
{
    delete [] mPositions;
    delete [] mInTangents;
    delete [] mOutTangents;
    delete [] mTimes;
    mCount = 0;

}   // End of DistanceTime::Clean()


//-------------------------------------------------------------------------------
// @ DistanceTime::Evaluate()
//-------------------------------------------------------------------------------
// Evaluate spline
//-------------------------------------------------------------------------------
float
DistanceTime::Evaluate( float t )
{
    // make sure data is valid
    assert( mCount >= 2 );
    // just in case
    if ( mCount == 1 )
        return mPositions[0];
    if ( mCount == 0 )
        return 0.0f;

    // handle boundary conditions
    if ( t <= mTimes[0] )
        return mPositions[0];
    else if ( t >= mTimes[mCount-1] )
        return mPositions[mCount-1];

    // find segment and parameter
    unsigned int i;
    for ( i = 0; i < mCount-1; ++i )
    {
        if ( t < mTimes[i+1] )
        {
            break;
        }
    }
    float t0 = mTimes[i];
    float t1 = mTimes[i+1]-t0;
    float u = (t - t0)/t1;

    // evaluate
    float A = 2.0f*mPositions[i]
                - 2.0f*mPositions[i+1]
                + mOutTangents[i]
                + mInTangents[i];
    float B = -3.0f*mPositions[i]
                + 3.0f*mPositions[i+1]
                - 2.0f*mOutTangents[i]
                - mInTangents[i];
    
    return mPositions[i] + u*(mOutTangents[i] + u*(B + u*A));

}   // End of DistanceTime::Evaluate()


//-------------------------------------------------------------------------------
// @ DistanceTime::Render()
//-------------------------------------------------------------------------------
// Render spline 
// Uses forward differencing
//-------------------------------------------------------------------------------
void 
DistanceTime::Render()
{
    // turn off the lighting, if any
    GLboolean lighting = false;
    glGetBooleanv(GL_LIGHTING, &lighting);
    if ( lighting )
        glDisable(GL_LIGHTING);

    // draw hermite spline
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.5f, 0.25f);

    // for each subcurve, do forward differencing
    for ( unsigned int i = 0; i < mCount-1; ++i )
    {
        // set up step variables
        const float h = 0.1f;
        const float h2 = 0.01f;
        const float h3 = 0.001f;
        float A = 2.0f*mPositions[i]
                    - 2.0f*mPositions[i+1]
                    + mOutTangents[i]
                    + mInTangents[i];
        float B = -3.0f*mPositions[i]
                    + 3.0f*mPositions[i+1]
                    - 2.0f*mOutTangents[i]
                    - mInTangents[i];
        float dP1 = h3*A + h2*B + h*mOutTangents[i];
        float dP3 = 6.0f*h3*A;
        float dP2 = dP3 + 2.0f*h2*B;

        // output first point
        float P = mPositions[i];
        glVertex2f( mTimes[i], P );

        // do forward differencing to next points
        for ( unsigned int j = 1; j <= 9; ++j )
        {
            P += dP1;
            glVertex2f( mTimes[i]*(1.0f - float(j)*0.1f) + mTimes[i+1]*(float(j)*0.1f), P );
            dP1 += dP2;
            dP2 += dP3;
        }
    }
    // output last point
    glVertex2f( mTimes[mCount-1], mPositions[mCount-1] );

    glEnd();

    // draw sample points
    glPointSize( 5.0f );
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f);
    for ( i = 0; i < mCount; ++i )
    {
        glVertex2f(mTimes[i], mPositions[i]);        
    }
    glEnd();

    // turn the lights back on, if necessary
    if ( lighting )
        glEnable(GL_LIGHTING);

}   // End of DistanceTime::Render()