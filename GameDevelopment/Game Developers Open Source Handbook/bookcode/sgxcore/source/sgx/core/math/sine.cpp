#include "sgx/core/types/types.hpp"

tREAL32 sgxSineTable[] = {
0.000000f, 0.006136f, 0.012272f, 0.018407f, 0.024541f, 0.030675f, 0.036807f, 0.042938f, 0.049068f, 0.055195f, 0.061321f, 0.067444f, 0.073565f, 0.079682f, 0.085797f, 0.091909f, 0.098017f, 0.104122f, 0.110222f, 0.116319f, 0.122411f, 0.128498f, 0.134581f, 0.140658f, 0.146730f, 0.152797f, 0.158858f, 0.164913f, 0.170962f, 0.177004f, 0.183040f, 0.189069f, 
0.195090f, 0.201105f, 0.207111f, 0.213110f, 0.219101f, 0.225084f, 0.231058f, 0.237024f, 0.242980f, 0.248928f, 0.254866f, 0.260794f, 0.266713f, 0.272621f, 0.278520f, 0.284408f, 0.290285f, 0.296151f, 0.302006f, 0.307850f, 0.313682f, 0.319502f, 0.325310f, 0.331106f, 0.336890f, 0.342661f, 0.348419f, 0.354164f, 0.359895f, 0.365613f, 0.371317f, 0.377007f, 
0.382683f, 0.388345f, 0.393992f, 0.399624f, 0.405241f, 0.410843f, 0.416430f, 0.422000f, 0.427555f, 0.433094f, 0.438616f, 0.444122f, 0.449611f, 0.455084f, 0.460539f, 0.465977f, 0.471397f, 0.476799f, 0.482184f, 0.487550f, 0.492898f, 0.498228f, 0.503538f, 0.508830f, 0.514103f, 0.519356f, 0.524590f, 0.529804f, 0.534998f, 0.540172f, 0.545325f, 0.550458f, 
0.555570f, 0.560662f, 0.565732f, 0.570781f, 0.575808f, 0.580814f, 0.585798f, 0.590760f, 0.595699f, 0.600617f, 0.605511f, 0.610383f, 0.615232f, 0.620057f, 0.624860f, 0.629638f, 0.634393f, 0.639124f, 0.643832f, 0.648514f, 0.653173f, 0.657807f, 0.662416f, 0.667000f, 0.671559f, 0.676093f, 0.680601f, 0.685084f, 0.689541f, 0.693971f, 0.698376f, 0.702755f, 
0.707107f, 0.711432f, 0.715731f, 0.720003f, 0.724247f, 0.728464f, 0.732654f, 0.736817f, 0.740951f, 0.745058f, 0.749136f, 0.753187f, 0.757209f, 0.761202f, 0.765167f, 0.769103f, 0.773010f, 0.776888f, 0.780737f, 0.784557f, 0.788346f, 0.792107f, 0.795837f, 0.799537f, 0.803208f, 0.806848f, 0.810457f, 0.814036f, 0.817585f, 0.821103f, 0.824589f, 0.828045f, 
0.831470f, 0.834863f, 0.838225f, 0.841555f, 0.844854f, 0.848120f, 0.851355f, 0.854558f, 0.857729f, 0.860867f, 0.863973f, 0.867046f, 0.870087f, 0.873095f, 0.876070f, 0.879012f, 0.881921f, 0.884797f, 0.887640f, 0.890449f, 0.893224f, 0.895966f, 0.898674f, 0.901349f, 0.903989f, 0.906596f, 0.909168f, 0.911706f, 0.914210f, 0.916679f, 0.919114f, 0.921514f, 
0.923880f, 0.926210f, 0.928506f, 0.930767f, 0.932993f, 0.935184f, 0.937339f, 0.939459f, 0.941544f, 0.943593f, 0.945607f, 0.947586f, 0.949528f, 0.951435f, 0.953306f, 0.955141f, 0.956940f, 0.958704f, 0.960431f, 0.962121f, 0.963776f, 0.965394f, 0.966976f, 0.968522f, 0.970031f, 0.971504f, 0.972940f, 0.974339f, 0.975702f, 0.977028f, 0.978317f, 0.979570f, 
0.980785f, 0.981964f, 0.983105f, 0.984210f, 0.985278f, 0.986308f, 0.987301f, 0.988258f, 0.989177f, 0.990058f, 0.990903f, 0.991710f, 0.992480f, 0.993212f, 0.993907f, 0.994565f, 0.995185f, 0.995767f, 0.996313f, 0.996820f, 0.997290f, 0.997723f, 0.998118f, 0.998476f, 0.998795f, 0.999078f, 0.999322f, 0.999529f, 0.999699f, 0.999831f, 0.999925f, 0.999981f, 
1.000000f, 0.999981f, 0.999925f, 0.999831f, 0.999699f, 0.999529f, 0.999322f, 0.999078f, 0.998795f, 0.998476f, 0.998118f, 0.997723f, 0.997290f, 0.996820f, 0.996313f, 0.995767f, 0.995185f, 0.994565f, 0.993907f, 0.993212f, 0.992480f, 0.991710f, 0.990903f, 0.990058f, 0.989177f, 0.988258f, 0.987301f, 0.986308f, 0.985278f, 0.984210f, 0.983105f, 0.981964f, 
0.980785f, 0.979570f, 0.978317f, 0.977028f, 0.975702f, 0.974339f, 0.972940f, 0.971504f, 0.970031f, 0.968522f, 0.966976f, 0.965394f, 0.963776f, 0.962121f, 0.960431f, 0.958703f, 0.956940f, 0.955141f, 0.953306f, 0.951435f, 0.949528f, 0.947586f, 0.945607f, 0.943593f, 0.941544f, 0.939459f, 0.937339f, 0.935184f, 0.932993f, 0.930767f, 0.928506f, 0.926210f, 
0.923880f, 0.921514f, 0.919114f, 0.916679f, 0.914210f, 0.911706f, 0.909168f, 0.906596f, 0.903989f, 0.901349f, 0.898674f, 0.895966f, 0.893224f, 0.890449f, 0.887640f, 0.884797f, 0.881921f, 0.879012f, 0.876070f, 0.873095f, 0.870087f, 0.867046f, 0.863973f, 0.860867f, 0.857729f, 0.854558f, 0.851355f, 0.848120f, 0.844854f, 0.841555f, 0.838225f, 0.834863f, 
0.831470f, 0.828045f, 0.824589f, 0.821102f, 0.817585f, 0.814036f, 0.810457f, 0.806848f, 0.803208f, 0.799537f, 0.795837f, 0.792107f, 0.788346f, 0.784557f, 0.780737f, 0.776888f, 0.773010f, 0.769103f, 0.765167f, 0.761202f, 0.757209f, 0.753187f, 0.749136f, 0.745058f, 0.740951f, 0.736816f, 0.732654f, 0.728464f, 0.724247f, 0.720003f, 0.715731f, 0.711432f, 
0.707107f, 0.702755f, 0.698376f, 0.693971f, 0.689541f, 0.685084f, 0.680601f, 0.676093f, 0.671559f, 0.667000f, 0.662416f, 0.657807f, 0.653173f, 0.648514f, 0.643832f, 0.639124f, 0.634393f, 0.629638f, 0.624859f, 0.620057f, 0.615232f, 0.610383f, 0.605511f, 0.600616f, 0.595699f, 0.590760f, 0.585798f, 0.580814f, 0.575808f, 0.570781f, 0.565732f, 0.560661f, 
0.555570f, 0.550458f, 0.545325f, 0.540171f, 0.534997f, 0.529803f, 0.524590f, 0.519356f, 0.514103f, 0.508830f, 0.503538f, 0.498228f, 0.492898f, 0.487550f, 0.482184f, 0.476799f, 0.471397f, 0.465976f, 0.460539f, 0.455083f, 0.449611f, 0.444122f, 0.438616f, 0.433094f, 0.427555f, 0.422000f, 0.416429f, 0.410843f, 0.405241f, 0.399624f, 0.393992f, 0.388345f, 
0.382683f, 0.377007f, 0.371317f, 0.365613f, 0.359895f, 0.354163f, 0.348419f, 0.342661f, 0.336890f, 0.331106f, 0.325310f, 0.319502f, 0.313682f, 0.307849f, 0.302006f, 0.296151f, 0.290285f, 0.284408f, 0.278520f, 0.272621f, 0.266713f, 0.260794f, 0.254866f, 0.248928f, 0.242980f, 0.237023f, 0.231058f, 0.225084f, 0.219101f, 0.213110f, 0.207111f, 0.201105f, 
0.195090f, 0.189069f, 0.183040f, 0.177004f, 0.170962f, 0.164913f, 0.158858f, 0.152797f, 0.146730f, 0.140658f, 0.134581f, 0.128498f, 0.122411f, 0.116319f, 0.110222f, 0.104122f, 0.098017f, 0.091909f, 0.085797f, 0.079682f, 0.073564f, 0.067444f, 0.061321f, 0.055195f, 0.049067f, 0.042938f, 0.036807f, 0.030675f, 0.024541f, 0.018407f, 0.012271f, 0.006136f, 
-0.000000f, -0.006136f, -0.012272f, -0.018407f, -0.024541f, -0.030675f, -0.036807f, -0.042938f, -0.049068f, -0.055195f, -0.061321f, -0.067444f, -0.073565f, -0.079683f, -0.085797f, -0.091909f, -0.098017f, -0.104122f, -0.110222f, -0.116319f, -0.122411f, -0.128498f, -0.134581f, -0.140658f, -0.146730f, -0.152797f, -0.158858f, -0.164913f, -0.170962f, -0.177004f, -0.183040f, -0.189069f, 
-0.195090f, -0.201105f, -0.207112f, -0.213110f, -0.219101f, -0.225084f, -0.231058f, -0.237024f, -0.242980f, -0.248928f, -0.254866f, -0.260794f, -0.266713f, -0.272622f, -0.278520f, -0.284408f, -0.290285f, -0.296151f, -0.302006f, -0.307850f, -0.313682f, -0.319502f, -0.325310f, -0.331106f, -0.336890f, -0.342661f, -0.348419f, -0.354164f, -0.359895f, -0.365613f, -0.371317f, -0.377007f, 
-0.382683f, -0.388345f, -0.393992f, -0.399624f, -0.405241f, -0.410843f, -0.416430f, -0.422000f, -0.427555f, -0.433094f, -0.438616f, -0.444122f, -0.449612f, -0.455084f, -0.460539f, -0.465977f, -0.471397f, -0.476799f, -0.482184f, -0.487550f, -0.492898f, -0.498228f, -0.503538f, -0.508830f, -0.514103f, -0.519356f, -0.524590f, -0.529804f, -0.534998f, -0.540172f, -0.545325f, -0.550458f, 
-0.555570f, -0.560662f, -0.565732f, -0.570781f, -0.575808f, -0.580814f, -0.585798f, -0.590760f, -0.595699f, -0.600617f, -0.605511f, -0.610383f, -0.615232f, -0.620057f, -0.624860f, -0.629638f, -0.634393f, -0.639125f, -0.643832f, -0.648515f, -0.653173f, -0.657807f, -0.662416f, -0.667000f, -0.671559f, -0.676093f, -0.680601f, -0.685084f, -0.689541f, -0.693972f, -0.698376f, -0.702755f, 
-0.707107f, -0.711432f, -0.715731f, -0.720003f, -0.724247f, -0.728464f, -0.732654f, -0.736817f, -0.740951f, -0.745058f, -0.749136f, -0.753187f, -0.757209f, -0.761202f, -0.765167f, -0.769103f, -0.773010f, -0.776888f, -0.780737f, -0.784557f, -0.788346f, -0.792107f, -0.795837f, -0.799537f, -0.803208f, -0.806848f, -0.810457f, -0.814036f, -0.817585f, -0.821103f, -0.824589f, -0.828045f, 
-0.831470f, -0.834863f, -0.838225f, -0.841555f, -0.844854f, -0.848121f, -0.851355f, -0.854558f, -0.857729f, -0.860867f, -0.863973f, -0.867046f, -0.870087f, -0.873095f, -0.876070f, -0.879012f, -0.881921f, -0.884797f, -0.887640f, -0.890449f, -0.893224f, -0.895966f, -0.898675f, -0.901349f, -0.903989f, -0.906596f, -0.909168f, -0.911706f, -0.914210f, -0.916679f, -0.919114f, -0.921514f, 
-0.923880f, -0.926210f, -0.928506f, -0.930767f, -0.932993f, -0.935183f, -0.937339f, -0.939459f, -0.941544f, -0.943593f, -0.945607f, -0.947586f, -0.949528f, -0.951435f, -0.953306f, -0.955141f, -0.956940f, -0.958704f, -0.960431f, -0.962121f, -0.963776f, -0.965394f, -0.966977f, -0.968522f, -0.970031f, -0.971504f, -0.972940f, -0.974339f, -0.975702f, -0.977028f, -0.978317f, -0.979570f, 
-0.980785f, -0.981964f, -0.983105f, -0.984210f, -0.985278f, -0.986308f, -0.987301f, -0.988258f, -0.989177f, -0.990058f, -0.990903f, -0.991710f, -0.992480f, -0.993212f, -0.993907f, -0.994565f, -0.995185f, -0.995767f, -0.996313f, -0.996820f, -0.997290f, -0.997723f, -0.998118f, -0.998476f, -0.998795f, -0.999078f, -0.999322f, -0.999529f, -0.999699f, -0.999831f, -0.999925f, -0.999981f, 
-1.000000f, -0.999981f, -0.999925f, -0.999831f, -0.999699f, -0.999529f, -0.999322f, -0.999078f, -0.998795f, -0.998476f, -0.998118f, -0.997723f, -0.997290f, -0.996820f, -0.996313f, -0.995767f, -0.995185f, -0.994565f, -0.993907f, -0.993212f, -0.992480f, -0.991710f, -0.990903f, -0.990058f, -0.989177f, -0.988258f, -0.987301f, -0.986308f, -0.985278f, -0.984210f, -0.983105f, -0.981964f, 
-0.980785f, -0.979570f, -0.978317f, -0.977028f, -0.975702f, -0.974339f, -0.972940f, -0.971504f, -0.970031f, -0.968522f, -0.966976f, -0.965394f, -0.963776f, -0.962121f, -0.960430f, -0.958703f, -0.956940f, -0.955141f, -0.953306f, -0.951435f, -0.949528f, -0.947586f, -0.945607f, -0.943593f, -0.941544f, -0.939459f, -0.937339f, -0.935183f, -0.932993f, -0.930767f, -0.928506f, -0.926210f, 
-0.923879f, -0.921514f, -0.919114f, -0.916679f, -0.914210f, -0.911706f, -0.909168f, -0.906596f, -0.903989f, -0.901349f, -0.898674f, -0.895966f, -0.893224f, -0.890449f, -0.887640f, -0.884797f, -0.881921f, -0.879012f, -0.876070f, -0.873095f, -0.870087f, -0.867046f, -0.863973f, -0.860867f, -0.857729f, -0.854558f, -0.851355f, -0.848120f, -0.844853f, -0.841555f, -0.838225f, -0.834863f, 
-0.831469f, -0.828045f, -0.824589f, -0.821102f, -0.817585f, -0.814036f, -0.810457f, -0.806847f, -0.803208f, -0.799537f, -0.795837f, -0.792107f, -0.788346f, -0.784557f, -0.780737f, -0.776888f, -0.773010f, -0.769103f, -0.765167f, -0.761202f, -0.757209f, -0.753187f, -0.749136f, -0.745058f, -0.740951f, -0.736816f, -0.732654f, -0.728464f, -0.724247f, -0.720002f, -0.715731f, -0.711432f, 
-0.707107f, -0.702754f, -0.698376f, -0.693971f, -0.689541f, -0.685084f, -0.680601f, -0.676093f, -0.671559f, -0.667000f, -0.662416f, -0.657807f, -0.653173f, -0.648514f, -0.643831f, -0.639124f, -0.634393f, -0.629638f, -0.624859f, -0.620057f, -0.615231f, -0.610383f, -0.605511f, -0.600616f, -0.595699f, -0.590759f, -0.585798f, -0.580814f, -0.575808f, -0.570780f, -0.565732f, -0.560661f, 
-0.555570f, -0.550458f, -0.545325f, -0.540172f, -0.534998f, -0.529804f, -0.524590f, -0.519356f, -0.514103f, -0.508830f, -0.503538f, -0.498228f, -0.492898f, -0.487550f, -0.482184f, -0.476799f, -0.471397f, -0.465976f, -0.460538f, -0.455083f, -0.449611f, -0.444122f, -0.438616f, -0.433094f, -0.427555f, -0.422000f, -0.416429f, -0.410843f, -0.405241f, -0.399624f, -0.393992f, -0.388345f, 
-0.382683f, -0.377007f, -0.371317f, -0.365613f, -0.359895f, -0.354163f, -0.348419f, -0.342661f, -0.336890f, -0.331106f, -0.325310f, -0.319502f, -0.313682f, -0.307849f, -0.302006f, -0.296151f, -0.290284f, -0.284407f, -0.278519f, -0.272621f, -0.266712f, -0.260794f, -0.254865f, -0.248928f, -0.242980f, -0.237024f, -0.231058f, -0.225084f, -0.219101f, -0.213110f, -0.207111f, -0.201105f, 
-0.195090f, -0.189069f, -0.183040f, -0.177004f, -0.170962f, -0.164913f, -0.158858f, -0.152797f, -0.146730f, -0.140658f, -0.134580f, -0.128498f, -0.122410f, -0.116318f, -0.110222f, -0.104121f, -0.098017f, -0.091909f, -0.085797f, -0.079682f, -0.073565f, -0.067444f, -0.061321f, -0.055195f, -0.049068f, -0.042938f, -0.036807f, -0.030675f, -0.024541f, -0.018407f, -0.012271f, -0.006136f, 
};
