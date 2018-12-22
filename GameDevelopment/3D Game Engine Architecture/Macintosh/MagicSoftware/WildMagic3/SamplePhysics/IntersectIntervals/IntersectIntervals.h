// Magic Software, Inc.
// http://www.magic-software.com
// http://www.wild-magic.com
// Copyright (c) 2004.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement http://www.wild-magic.com/License/WildMagic3.pdf and
// may not be copied or disclosed except in accordance with the terms of that
// agreement.

#ifndef INTERSECTINTERVALS_H
#define INTERSECTINTERVALS_H

#include "Wm3ConsoleApplication.h"
using namespace Wm3;

class IntersectIntervals : public ConsoleApplication
{
    WM3_DECLARE_INITIALIZE;

public:
    IntersectIntervals ();

    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void BookExample ();
};

WM3_REGISTER_INITIALIZE(IntersectIntervals);

#endif