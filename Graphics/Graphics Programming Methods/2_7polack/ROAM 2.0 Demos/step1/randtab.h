//==============================================================
//= randtab.h ==================================================
//= Original coders: Mark Duchaineau
//==============================================================
//= A hash table of random values
//==============================================================
#ifndef __RANDTAB_H__
#define __RANDTAB_H__

int randtab[2048] = {
    0xb6cefe9c,0x4ebb177b,0x60b81955,0xcda3b481,0x05d9444e,0x043f4287,
    0xca41309e,0x0b6a5fd9,0x001af513,0xa10f3a7d,0x86dd17d6,0x089c25f2,
    0x086009cf,0x114e7b11,0x1a3b0974,0x099219b6,0xfbb01555,0x4ed38a79,
    0x622d4e5b,0xbecba0d3,0x97af14d7,0x045f47e9,0x992b862c,0x9e946935,
    0xb372d132,0xfc6f7ac0,0xe98f314a,0x483556f8,0x8afa4bc6,0xd3ddf176,
    0x46348652,0xae9e34f6,0xac5bdf48,0xa44e2e13,0x07d5edf2,0xe77f3d0b,
    0xd7437dee,0xd4ea3b96,0x6e9f6a2a,0x23e3e697,0x08ed74cc,0xd44b4e32,
    0x553386df,0x60e68b0f,0x2b9696e4,0xd9f44357,0x18b7d744,0x47961e2f,
    0xe238720a,0x81445feb,0x33ff7e0a,0x866bd816,0xf58f724d,0x01fb7030,
    0x4e570833,0x1f6cbdf2,0x32a43d83,0xf578cd38,0xdfaef638,0xc536af4b,
    0x3e96ee66,0xe6249839,0x5180ec9a,0x97fa6010,0x4d3b7d23,0xf2496d9c,
    0x1f7156d1,0xc4782963,0x9cb2b879,0x077dd871,0x3d94a03c,0x267729d9,
    0xb382e2ec,0xa14e6e5c,0xc9758307,0x6e4bed87,0xec0ca057,0x275ca888,
    0x58385175,0xeaed8a44,0xe937944b,0xfd906dce,0x0b38402f,0x6ab57fbb,
    0xb6985618,0x58b3589e,0x1f762861,0x99a69b74,0xee07d4aa,0x6759c3fd,
    0xbc451380,0xaf4de704,0x633f9b49,0x9a160954,0x956af9f3,0x1ff74def,
    0xf3963de8,0x817c3f90,0x319d14a5,0x08281ad6,0x04b9af63,0x1f667303,
    0x8d32e3be,0x5fa4719d,0xb230f955,0x378625de,0xc492df35,0x2499122d,
    0x6f8be443,0x959ccae8,0x75aacfc6,0x6da9fd0a,0x181249d3,0x4846b5c8,
    0x4690bfcf,0xb0c09758,0x0af34b3e,0x96cc12aa,0x12960dd0,0x9cb5bd31,
    0x99bc701e,0xe3a7d6ec,0x407b545f,0x6249060f,0x0202d51e,0x12b06daa,
    0x10228712,0x84c6af86,0xc2242abe,0x820b330f,0x9bf1b9a5,0xe9a7b127,
    0xe54ad4ac,0x8d02d91b,0x88132248,0xbd313c00,0x2718dde4,0xdb642071,
    0x086dd367,0xb8487862,0x8fb88d33,0xd747a8a1,0x11dd45d8,0x79e8c53c,
    0xce91b435,0xa23475b9,0x052d423b,0x252021d5,0x107a1bd9,0x314f4b34,
    0x6ebdb62d,0xddf9874e,0xffdf26c2,0xcb26bf4e,0xbdb59751,0x0ed3f179,
    0xf6d5bb35,0x371fa1f6,0x3b0c61a1,0x0389b5f1,0x8ebfdbac,0x4da79ddf,
    0xd95d2dba,0x829b6d6a,0x60aa0a4c,0x5dd2c59d,0x4ccd574d,0x2e177b8d,
    0xb00c5c9f,0xa60e2691,0x36d98b0c,0xf3fd900a,0xa771a0ee,0xa10848bf,
    0x179e6ab5,0x84550457,0x2a6bd349,0xb6806301,0xbdefea4d,0xeec832e6,
    0x2e4a9f30,0x2197dfd1,0x92c50630,0xf05042e3,0x6944fb9d,0xa9b5276a,
    0x35bd4e12,0x43424ad8,0xd3cff641,0xde959d94,0xe2367984,0x2d8fcd45,
    0xb8d0da46,0xc1e99a07,0xa6604de4,0xc866dcbe,0xb8a51224,0x04477365,
    0xefacacdb,0x718b2971,0x6f47d37f,0xcbc0d0ea,0xf21d3b11,0xdc155d21,
    0xb67fc680,0xfa484192,0xc455ec6b,0x76916651,0x92e1dba8,0x977f4f3f,
    0x92d43fde,0x20325414,0x921c6790,0xa12eacc0,0xe1445ad1,0x94fc7f08,
    0xb67f8922,0xe83b2764,0x08f0bb00,0x1aab1371,0x00dcb101,0x9f0ba707,
    0x59a446e7,0xaaa41011,0x9071ed6a,0x9f180c83,0xbe48e876,0x02da0642,
    0xd30c9d33,0x11b41f12,0xfc8f7b1e,0xaa7345a9,0xa9a44f2e,0xee507901,
    0xe728f96f,0x37ee5870,0x4c70e265,0x2d9e518d,0xa52fec92,0x9ac90e04,
    0x5e7d7588,0xb3840f1f,0xe1f39c4b,0x680b8043,0x1d21b821,0x250c5dff,
    0xee637b27,0x2b07977a,0x725a3e06,0x04d52661,0xb851b6aa,0xf08bba51,
    0x87711cbf,0xabd2cf66,0x43b5fac5,0xa623be24,0xffd882b5,0xb0fcbe4b,
    0x2192b771,0xc4bedacf,0xda7bed4b,0xa57f183e,0x8cab3485,0xbc234dfb,
    0x78237bd5,0xe46efe78,0x7815e00b,0xb4005c36,0x409e7666,0xf7d25f6e,
    0x773a046c,0x76fd3531,0xa8dddcb9,0xf0b73fb3,0xae1237cd,0xdc574d0c,
    0x73c90f2f,0xb5295ca2,0x4772efe9,0x53adbdec,0xada6b7c5,0xc4d571ae,
    0xfe7ddde3,0xaaea6166,0x97c8fd27,0xdd768793,0xdc067b05,0xd6c14d14,
    0x6a876e71,0x886ec8db,0x70a659f4,0xb5545572,0xc59131a4,0x32fbe007,
    0x40409262,0x2d1a0cae,0xdf1b2429,0x0d062af6,0x2358a207,0x878f1d62,
    0x979b26c0,0x9164c111,0x35c8a9e9,0x4fb8543e,0x00f359d6,0x00e30ab9,
    0x3f8d0aeb,0x4d9b918b,0x46a5a7be,0x6e897a79,0x055cece2,0x471d2c27,
    0xd966bf6e,0x89327fe0,0x1c3f6207,0x4577609b,0xce68d53a,0x0f18daa3,
    0x156c6f90,0xbcec1902,0xb437a241,0x0efdf56a,0x4c81a93a,0xafdbd4f2,
    0x8e62f048,0xff5fb0ce,0xfe8fba0f,0xcaee3484,0x704d4778,0xa200beee,
    0xd40f7c01,0x2ec51029,0x021564e6,0x42b58981,0x00d6d1be,0x4ac8cf16,
    0xde8ef073,0x6964eed2,0x5c04ee66,0x9b9db9e0,0x1e3c5ef1,0x2cc2fefb,
    0xf809edd8,0x2ec25ed2,0x53a11738,0x6cc9358f,0xc729cddb,0x2bac6e0f,
    0x1d396593,0x8493c69e,0xa1877c4a,0xb6e43ca6,0x4b411ae6,0xb5e4fa50,
    0xd32b2011,0x7c685f7d,0xc8e86701,0x5bf768b6,0xf432f45c,0x938b4122,
    0x9c151003,0x50287f6f,0x77acb2bc,0x244310d6,0x4c6ecf92,0xf0f7efa2,
    0x26cf38d1,0x27a75878,0x455db032,0x0d2f216e,0x9fb4dfd9,0xe053ebbe,
    0xe5ac4949,0x097407e8,0x5b1ea51c,0xd8768f4b,0x17bb6419,0xd868f381,
    0x7ce50384,0x967d826e,0x82b007f6,0x7b3586b8,0x26163eea,0x9bc91d55,
    0xa1bebad8,0xb9fc01c6,0x1cefe709,0xd64b7337,0x3fdaef33,0x0a2bfcc0,
    0x34d20a96,0xdaf97972,0x1fa9bbf4,0x203aea35,0xfc455192,0xa2c78c81,
    0x0c189be3,0xeb82386f,0xc40f26da,0xb6521c7a,0x6fa4efde,0x40fc587b,
    0xa23ea059,0x2d8ade7b,0x0437a46c,0xad52bfc6,0x30fcd40a,0xc67d8861,
    0x43b20c93,0xb2a0d562,0xc6877425,0xb31facba,0x8c81ac20,0x159a4ec5,
    0x5e8ca2bd,0x2c56857b,0x7d4fd426,0x7524ecf6,0xd57c03fb,0xff2248ec,
    0xa83772cc,0x4a527552,0xb3e2f192,0x1c9dcc94,0x77daa10e,0x5d9961c6,
    0x41c490e8,0x48b74cc4,0x54deb7fd,0xed0dc355,0x3fb16b6a,0x31f30013,
    0x736bfd06,0xef2318b8,0xdb3c4376,0x8c05cf8e,0xcfb3403c,0x8b302ecd,
    0x164b7811,0xf64dfb0a,0xb64ad686,0xc99f05d3,0xe312d8c4,0x33329e13,
    0xaa3068b0,0x51658284,0x0c9f039e,0x882fb564,0x0a528510,0xc2aa8822,
    0xf1e96381,0xb0db44d2,0x1ffedf09,0x225b58db,0x4ceadc4e,0xdb222fa4,
    0xc5f31692,0x1e5ea3cb,0xd92ab230,0x784049a9,0x6a147d9b,0x805e4553,
    0xc6f33caa,0xe9ba9569,0x938f0796,0x4b0a29a4,0x0b692655,0xae8a101a,
    0x10a86658,0xa2377b44,0x1fa1c3f3,0x7bdae9f5,0xdbc11951,0x5f2494af,
    0x2a410248,0xb39072af,0x10106bc0,0x609b2b64,0x22fa69f4,0x56a8e2e9,
    0xb2e80330,0x982b5c4a,0x415243ce,0x62715ceb,0x8ecc9fd8,0xdd2c5661,
    0xe78baa05,0x2f1c997d,0xae2e3137,0x420697b1,0x207d6f17,0xc406c973,
    0x95f4ea7e,0xec5279f0,0x9eceda7e,0xdbd3da6c,0x217d5769,0xd7a56c4e,
    0x1b5b709d,0x1e9f5025,0x9cf7efaf,0x04aacb77,0xe2581bdc,0x2e687cb8,
    0x3753708f,0x1f812398,0xd769eaf2,0xd1e642a4,0x4108dc97,0x21cd77e7,
    0x7ce7892f,0x56c5008a,0x1fa684e0,0x74f7e4fb,0x28178279,0x5dea6cb1,
    0x1246d89d,0x6dbab940,0xf5be4239,0x2b26c121,0x2a7b1219,0x735fb80d,
    0x8a14d5a5,0x640ebaea,0x7a7ca5e7,0xa5dcf3a6,0x3de3b1fc,0x085d6ce7,
    0x5399b9b3,0x9c13ad72,0x42eb099e,0xa0639bc3,0x110abc00,0xa8065e55,
    0x76e4f16e,0xaee9a9af,0x4ed94652,0xaa5e635a,0xc55c51fc,0x6ae56a6d,
    0x7ae762b0,0xd1f45223,0x1af4abcf,0xc91f9f8e,0x7c3e3cc8,0x6685adb2,
    0x9d2c25b6,0x79a814a2,0x29a870f0,0x26b2cd57,0x90093dc9,0x29c0eccd,
    0xdffe1a92,0x7bf6ce0f,0xd7a35760,0x2c22fe92,0x98d17598,0x23a5973a,
    0x213945b6,0x5ac62d13,0x147b965b,0xe2b0323e,0xae323c8e,0xa44e6f3b,
    0xe1317da8,0xec835399,0xae8668a0,0x35932086,0xd65f2801,0x766f243c,
    0x8633b544,0x5d5c8bbd,0x0fabbaff,0xcf6f7a1e,0x6a92ef51,0x9bef0f0a,
    0x9988bffd,0x89ece7ed,0xd78f96ba,0x0d94a29b,0xbac07f93,0xeb1dc400,
    0xdc5672cb,0xadf579cc,0xc4187dce,0xbd887056,0x9db297c7,0x34ded7ef,
    0x25da8753,0x327bbbbf,0xafea88eb,0x3003a2c5,0x345f25b4,0x38ae0b8d,
    0x3f89974c,0xed357cb1,0x4ee29524,0xe1e4811a,0xed38e2e5,0x85de0246,
    0x99fd5d9b,0x665dfc2a,0xc2490e18,0x89df0363,0x44493fda,0xd47c5571,
    0x19aa3b72,0xe341cbf1,0xcff5cbb5,0x9da1518f,0x580eb58a,0xb598a534,
    0x9565a5d2,0xa3967e17,0xbca9d0a3,0xd8d8db2b,0xd85e14e2,0x7a5cc8db,
    0x955ef29e,0x8f885b98,0x2b9e0ea6,0x522d061d,0x585ef2e1,0xee2f0eee,
    0xdb2eda69,0x9d1fec3d,0x8d5e21a3,0x315f5b1d,0x8fee60fd,0x606dcc7b,
    0xb4d91a28,0xe2a35bf9,0x9fd5a055,0x31f9960a,0xa999fab1,0xc803aa94,
    0x32bd46e1,0x88afb22c,0xa02f0c2b,0x0acc907b,0x920cf8be,0x1440b55d,
    0x0e3e7c80,0x29225721,0xc9e2b6d7,0xec36cc69,0x7956f994,0x1f58c11f,
    0xd9c6251a,0xbbc9332a,0x0dbb8621,0x18a92e8d,0x4814f53a,0xcae92540,
    0x7f84eeed,0x3313508a,0x2d1a3a67,0xd66e787e,0xe336397c,0xbf674c0a,
    0xf9096b34,0x10229e38,0xa32f805f,0x0a1584a9,0x9bcb3d54,0x8231c4af,
    0x46b55e14,0xa73df046,0xf08e1698,0x02c6861d,0xfccc6fb6,0xd1b99d0f,
    0xcdcb6583,0x7c728c92,0x79d75664,0xaeab57a0,0x56697bc2,0x26b47f29,
    0x9aa6f9a0,0xa9482768,0xdb8c34a4,0x14e0fe2e,0x7808af5a,0xadc45192,
    0x8c623957,0xff1ed9c8,0x2b2296d8,0x58e950ae,0xb604f75b,0x592147d2,
    0xf150c99b,0x3d025b17,0xa02b8a21,0x5185aec7,0xabd708e7,0x9dba1b73,
    0x30c6fd9a,0x1b2480ae,0x7f46e691,0x9f0bc6ec,0x9d87d081,0x7517d632,
    0x44146e73,0x2194eb59,0xc354f69b,0x43084069,0xe8246b30,0x15dad081,
    0x8c1644c0,0x58613cc7,0xefd87949,0xccf9563f,0xf5d4b308,0x0394e445,
    0xd9e4ad08,0x84fd13b7,0xb7358659,0xa5eafca5,0xc261886f,0x3d2b4500,
    0x9f74b33a,0x84b855f3,0x3ec9c8cf,0x8fa17d97,0x247099c8,0x4c0f80fb,
    0xb3af790a,0xad6a2764,0x7095cc26,0xcb9d0bd5,0xc4dd2253,0x31c8bd7f,
    0x8e030824,0xe36ce778,0x9c34a7b0,0x99e070f4,0x14787c9d,0x9b0958c3,
    0xf538ba0c,0x5f6493cb,0xd2196371,0x915ddfa0,0x4f2c35f2,0x4ad38cba,
    0xdd5803f0,0x8ec4398f,0xe336c118,0x2c1de40e,0xd352670d,0x74e2226f,
    0xc1e65d7b,0xa03b6223,0x25b80c00,0xcd63aee7,0x8d608a63,0xb9b459fb,
    0x794bb5d4,0x6e1cda3f,0xbe08f3ab,0x3cd43d0d,0x7c643670,0x9f4edf18,
    0xd523409d,0xbfd75f5c,0x093c3867,0x6f1cbd6f,0xa037da1d,0x6cb6a88c,
    0x1349d582,0xbd71faba,0x9cc6fcc2,0xdb9612c9,0x241a3ae1,0x97700236,
    0x97423503,0xe51b1ff8,0x9f7ec0e7,0x853c815b,0x0d400a54,0x490013b5,
    0xa1fb449d,0xd63504e8,0xc4db67d8,0xd315fad3,0x73b3c3b3,0x1f9c5071,
    0xf5f650ed,0xb3a8ef23,0xc9ab1173,0xcb8f519a,0x747c911e,0x84799fc1,
    0xb7dae4ba,0x0b46ce2e,0xc70733dd,0x12f995c0,0xea8f8b7d,0x83265f87,
    0x7e4f1dd6,0xf295b1e7,0xbd367d1e,0x20d06ff8,0xa736808b,0x731b325d,
    0x8d6f8204,0x648fee7c,0x32920b80,0x1eb839bf,0x2d925c9f,0xd41b5b1a,
    0xd41efa91,0x3de3d8f5,0x2a165e7d,0xff89f4ad,0x04b3173b,0x87524602,
    0x7a4f00ff,0x93715a55,0xe7c0c649,0x33380475,0x13050513,0x621291ec,
    0x34c9dcf5,0xbb54f926,0x63979cdf,0x7921e9cd,0x4734700e,0x427e2661,
    0xebf69137,0xc3d84ea9,0x7826f1ab,0xb477866f,0x63ab2ae6,0xb2e569c1,
    0x978bb46f,0xf6ab458d,0x0b932264,0x10609297,0x99ecc0cf,0xdf623e52,
    0xf67b3efb,0xf2d5d4bc,0x410942e1,0xa99a13e4,0x5e733e26,0x293e86c2,
    0xc44d7394,0xc59b2bd5,0xb26ed217,0x225ca325,0x00eebb0e,0x2374fb50,
    0xa1cc9a96,0x4cf7d93b,0x526946bc,0x54983d1a,0xa2b39551,0x7bdc67eb,
    0x0e3fab17,0x122d3c4d,0xc633d949,0x2d7b7d34,0x9dd93e0b,0xb994c4e2,
    0x7aeba4c7,0xaadb3414,0xbfa8e29e,0x831a881f,0x15a0468a,0xcd09c79e,
    0x45234d45,0xa875b147,0xe7394534,0xb181e796,0x9b3e8691,0x1602ae47,
    0x2e5919ac,0x6248c05a,0xfaab7736,0xbc015c08,0x7da6365c,0x9deb1f38,
    0x0c42a684,0xbbc3ed70,0x0440eb0d,0xc802468e,0xd9e96644,0x15d9014b,
    0x004fddf8,0x5a167f29,0x178e3625,0x11679e5b,0xb879ad6a,0xb42febf7,
    0x4612ee86,0xc35c140d,0x8a5494d3,0xe449fcfb,0x42f502e3,0x88ee0413,
    0x182a070a,0x77fb3a3b,0xe07978c9,0x1fede48a,0xf10be9a2,0xb7d61995,
    0x417e0ce6,0x97b41354,0xe87894af,0xada6b36f,0xcb21013a,0x62a7af40,
    0xb7175d87,0x15a20271,0x834910cf,0xafb9d7d5,0xadb277d8,0x40be65b1,
    0x8f076d5b,0x7ec3e7dd,0x315725a6,0x7c60cbad,0x97d45eac,0x60e44bed,
    0x64f5408c,0x778fc9c2,0xcebf2cbf,0xc6368e20,0x0f9b672b,0x6e2098b2,
    0xd242fe95,0xa4224892,0xf0e77791,0x706e61bd,0xb40be20f,0xd2b464aa,
    0xc9fec183,0xe95fe27f,0xe89ae13f,0x7b7e2017,0x35cb2693,0x68e91ea2,
    0xf0b9db61,0xd943bddd,0x8171845f,0xb3a4271c,0xc54eb7b7,0x1f68f13e,
    0xedfda124,0xbecd71af,0x17f20547,0x10b8fa5e,0x95b0ed49,0xb2b4b6f8,
    0x76691e7c,0xb9192d05,0x6dcdf938,0x629fdc96,0x0ad1459b,0x63935765,
    0xf654d4fe,0xb2bb4aa6,0x02932e1c,0xe50d5b7c,0x2a129793,0x05fb446a,
    0x4ba88acb,0x33d0d8d0,0xf3023b19,0xf66d613a,0x551766de,0x0964cbd2,
    0x9577c3e8,0x4c6a7ae0,0xea30ddc2,0x3eaa2fc0,0xcbb6e917,0x189caa00,
    0x5bfa4e08,0x960bbe93,0x0b6c1f04,0x4f305f8f,0x5cd61f7a,0xa25cd07d,
    0xa95399ad,0xd3403442,0xebfd337c,0x897d0f31,0x445df049,0x777ae814,
    0xf177790f,0x4fd8df74,0x5f3f6ba9,0x383c27d8,0x3d31c859,0x252be2df,
    0x0f69ef75,0x3f338b37,0x26a847a2,0x149909d8,0xc7b8a756,0xe9fa0570,
    0x05bf7e13,0x980278b4,0xc133eccb,0xaf40d0e1,0x05716aa9,0x5dcc4b83,
    0x812ceaf9,0x096f49fd,0x9d0e0638,0x8d1bfc65,0xc915f976,0x953b772c,
    0x5db6e135,0xdf6a2d93,0xf8d73d20,0xfe429cce,0x06acc531,0xe054151b,
    0xce89fb3d,0x63115e24,0xb299f53d,0x3b75339d,0x9db5c05a,0x8af90f79,
    0xb3a86075,0xa5bc9071,0xc21cbef3,0xe6388eae,0x35c2260b,0x37ed41fc,
    0x4223ea38,0xa0b832a7,0x883cf41f,0x71441939,0x25a84d81,0x100476ba,
    0xb83105ed,0x0143275c,0x2c59efc0,0x81fe49a2,0x439847ed,0xe5eaf6d0,
    0x0f7fd8d6,0x6372a3ca,0x1a064230,0x0bff1d86,0xdcee38da,0xe881fade,
    0x9c5b1b88,0xe186894d,0xc1b1b102,0x857c1dc9,0x7ad651fe,0x0c1f3214,
    0x629d0024,0xfbf28cc9,0xbf0acba1,0x855d8f23,0x9ed995d5,0x83bc244d,
    0xde52c197,0x10575108,0xcd533f82,0xeab7ba47,0x13eb7757,0xc4262d5f,
    0x9c600268,0xe8f5129a,0x83640681,0xcc4ff44c,0x965ce4e7,0x7e097730,
    0x9cdc4ddd,0x80288b33,0x4b9e7edb,0x22f0d8cf,0xec3ea252,0x40f950be,
    0xd52c9206,0x32d9fa59,0xd87dec7c,0x75add344,0x81c52261,0x011ae4d8,
    0x32259add,0x0f75c436,0xc8299ba7,0xc8daa8bd,0xc2ceeea3,0xb93867fe,
    0xa27bc2a1,0x0563357b,0x1af1ea55,0x55300c7c,0xaae76eea,0xb1e1ca4d,
    0x54d089a3,0x40a0c9e4,0x5588a6bb,0x98d58572,0xd04415db,0xad2aa53a,
    0x14f98c27,0x4a59e8be,0x6c8abb7e,0x186c04ee,0xcf638e27,0xbbc72ce2,
    0x52d9b4ea,0x5bdd8e74,0x3a71f960,0x062d42ac,0x13a9d6d9,0x54f2c99d,
    0xf8253e02,0x88d35326,0x4f98901d,0x508ec6fa,0x5d255bed,0x839fd868,
    0xb4b68b44,0xd2a9cda6,0x182e53fa,0x3a27e6e7,0x0e762428,0x939bc2ce,
    0x4ac79636,0x9b3e8560,0x6e554eb7,0xd4937694,0x36dde512,0x2735b054,
    0xd7e9620f,0xfd401068,0x417c58bb,0xbdec1800,0x88b093bd,0x6184fc05,
    0xcf899c43,0xb689eb06,0x4f112500,0x47ca6604,0x9302c657,0xff7f9975,
    0x68bc2236,0x8d9cd346,0x8a5775dd,0x205872ba,0xda2d880c,0x79315b92,
    0x2e5850f7,0xf64ef93e,0x010d5893,0x7f2560c8,0xa9d1f45c,0xc3f5b8fe,
    0xe2105f00,0x58d9354a,0x58b3b7fe,0xa51f475d,0xa5375b6c,0xa2f10895,
    0xae6c69a9,0xa051600e,0x62da6c42,0x22d210b3,0xdb99d0eb,0x0e677be6,
    0xb1424c22,0x49186ff2,0x3c72dbf4,0x734968ba,0x57c11cdb,0xb094de89,
    0xd58e3970,0x734d3c56,0x6cd70b4d,0x2b9c9b7c,0x2fe9eda5,0x1ce30aae,
    0x37c93c8e,0x325a0a28,0x94245896,0xad157948,0x2db43122,0xdfc43e50,
    0x80f88bd7,0x984ddd6e,0x95bda3d3,0x2b295ecb,0xb8361822,0xcce637e0,
    0x7aee75ef,0xf9cbc477,0xfab29c2e,0x263de43e,0x2889973a,0x1686540c,
    0x7a069904,0x915d988f,0x1c722061,0x1424405d,0x3f5d288b,0x46b0668a,
    0xe068a588,0xdf2e348b,0xd6f53f2a,0x1e03f3e0,0xc24b6bcf,0x08cb0df8,
    0x6945f398,0x67766081,0x62cb5120,0x33710091,0x4e6b4cb0,0x84cb88c7,
    0x2b5fb601,0x808eba42,0x3c0e9562,0xdb75ee94,0x4b07f2fd,0x90dc9560,
    0x9f11b4f3,0x76ec406a,0x288926ff,0x1ef9da4c,0x16c58c3f,0x39b9a8c2,
    0x373c28c8,0xad7ab420,0x81006853,0xcda94c93,0xd2a6b848,0xeef80735,
    0x2c705619,0x49265dcd,0xef28b3e6,0xa1ebe54a,0x2ef89ea1,0x5abdef79,
    0x59299769,0xe01528e5,0x4fff616b,0x8ae6a890,0x8bde0e03,0x163c3fe3,
    0x058f604a,0x3543c2f8,0x75bc2a11,0xdbac1a00,0x12c7cfb4,0xcd8cc39b,
    0x87422ce3,0x6027286b,0xae7fc306,0x9e2dff28,0x4702cfb0,0xb514ce36,
    0x4d4f5998,0xc7f87f89,0xdd0dd348,0x4ac86711,0xb0dcadd7,0x9c54b8c1,
    0xaf4a9129,0x6d42a2a0,0xd66b806d,0x99b4c267,0x9939fc1e,0xf90816c0,
    0x7e617eee,0x78d251b1,0x365809e5,0x9bb17b54,0x8e4f78c9,0xce8d2f5c,
    0x5aabf74e,0x47a3b1e5,0x3df494a8,0x413f00f7,0x1742f5a1,0x5fb368c2,
    0xe2ccaec1,0x8d0b72b8,0x2017549b,0xab1af325,0xa253cac0,0x5f837369,
    0xaa3319a9,0x22fa847e,0xf2b92ce6,0xb6b0c509,0x0ed0e12a,0x405acf8c,
    0x0c8b0b10,0x21afc50f,0xf01b2cf2,0xeeec2426,0xcf38d500,0xbb1dd76e,
    0x608f992f,0xde204a4b,0xb68a0442,0x6e757888,0x51618270,0x7adba448,
    0x5ba6f53b,0xdd52caef,0x416ffdfb,0xc2c613a3,0x64f23fb3,0x5581b317,
    0x0753e5e8,0xf6e5b513,0x3087d43d,0xf4d5a31c,0x81e25c73,0xa72620b3,
    0x9f44fc47,0x84af4218,0x6eed4eae,0x4ff2dcf0,0xbbfd60ea,0x758388f0,
    0x3504db8f,0x25231bf7,0x2c482751,0xdad873a5,0x7ac81048,0xd245b23a,
    0xa2a9c6e7,0x42727c01,0xcbf0187b,0x92e3de19,0x1773f1db,0xd8b82934,
    0x8bf40a06,0xc4793242,0x93e83657,0xa166fe33,0xf4dcbd0f,0x4e544711,
    0x49a937b0,0x55485b5b,0x0c61957d,0x7dd195a8,0x13428a2e,0x9ebf7e96,
    0x3430731c,0x07006945,0x975e001a,0xb1d1e8f0,0x90ffc9cf,0x90b28bf6,
    0x8f36e572,0x0f9f1435,0x1c35a928,0x674d2acd,0xab7d8577,0xaa899ef4,
    0xa9eb68c9,0x7d17ce82,0xf63f78c4,0x8832eff0,0xf495bb18,0x4ccb4a51,
    0xb515e19f,0x0c14ff76,0x9293600e,0x836b670f,0xa246c558,0x2d917c3a,
    0xa0768380,0xbf064400,0xb75a2fcd,0x0c1e9f82,0xdbda64d9,0x61afa894,
    0x7618e02f,0xc7b8c2ac,0x4e767768,0x1e566570,0x5c4410c2,0xd00fe854,
    0x657e7e35,0x6d7ec562,0x2396eb7d,0x816f3eba,0x8a142483,0xe8dbe7b2,
    0xd88126ba,0x65f9855e,0xc718988c,0xc4b42ff2,0x086342d1,0xe3504fae,
    0x904d47fc,0xa5625856,0xa0b648b1,0x79354e5c,0x00304994,0xa9d7dc4d,
    0x4269f7c0,0x15fc9e4c,0x20629d5a,0x0c69287b,0xb3e56d08,0xda5430fe,
    0xd0189ab1,0x76b0854f,0x3fd50f78,0x94f1b91e,0xefe1b6f3,0x52dfff74,
    0xdd09e516,0x4539f396,0xf7da30b4,0xd625de5d,0x5c1976ec,0xf3313062,
    0x9ab32801,0xbc613e60,0x9bf72c55,0xba512c69,0x60bf206e,0x3ae77e91,
    0x2bfb44c7,0xbdbce623,0xe4b968fb,0x7beadcbf,0x7fd79c6a,0xd798359e,
    0x28250b93,0x8cfbf480,0xdcbd2006,0x89314adb,0x67675c07,0xa546a92a,
    0x37f410a7,0x687b1c5e,0x978dd433,0x2cdda7cd,0xb7edf47e,0xf044b3e2,
    0x9bfdee7e,0xf04a57a5,0x54931ad6,0x32d0c3eb,0x2c387f98,0x3378455f,
    0xb76b716c,0x01178e87,0xeed2df66,0x4f7b0408,0x36b8f44e,0xb6f91d49,
    0xaff70475,0xc9f087e1,0x433eae28,0xb221a0bb,0xe606fbc4,0x91f5c010,
    0x7399a234,0x056f3d04,0xaa35303a,0x0a576d76,0x17cf5ae9,0xde10ed92,
    0xa78dd499,0x1f2af35f,0xd8a219b0,0xc5e9d7a0,0xd6954b81,0x123a04c9,
    0x6d77d987,0x2e98f213,0x7850d9ae,0x8423d17c,0x850b3cd9,0xa84b3bc7,
    0x003c690a,0x2f8b7439,0xa0b79a54,0x5c77717e,0xfb9ecea6,0x1caaabd4,
    0x2fd70c91,0x62aa5345,0xd921cf01,0x63113669,0x2a8199e8,0x031e7f88,
    0xcb21bd5f,0x05e28cbb,0x088db3c6,0x795c09af,0xe32a6c84,0x4d5647ca,
    0x61f2c91a,0x316641ca,0xbc211fb2,0x7cda03a6,0xf222d3d9,0x0ad426d7,
    0xeafe4e48,0x3f325d3b,0x3f34fc6e,0xa61d9c24,0x47ac2aad,0x8dec0e56,
    0x98af5888,0xe55f6071,0x3b1adfe5,0x49638b64,0x07ffc88a,0xf70fee82,
    0x13ab4750,0x2ae22869,0x7744ebe1,0x0b62224d,0x9f909c5e,0xcfbd5d55,
    0x8257e81e,0xd308b93d,0x57b8e3b6,0xb3c01b41,0x6e59bb65,0x9750e753,
    0xb47d4690,0x0b0ff7d8,0xe76a405d,0xe935e8a6,0xb45155fb,0x8db1f0dc,
    0x860fadf2,0x3f6f81af,0x3ecb1ff6,0xce3c95d7,0x257b6538,0x1ebb5bae,
    0x05fb5f1c,0xa4d60e79,0x29e6325a,0x4fc02f39,0x5dc6bbe3,0x95531489,
    0x81201a6e,0x6e8af202,0x2b6fcea6,0xb20ca3da,0xfdba130b,0xb900b824,
    0x059961f4,0x5084c3fa,0xfb8d6688,0x41cb332c,0xfb23b343,0x6ec995f2,
    0x5c1f3b98,0xe62e9a8b,0x0128bd19,0x159cce79,0xb77f2e98,0x411ebc8b,
    0xd47b6b58,0x0906faba,0x1e4da35b,0x05e242f8,0x8e7a6d22,0x251851fd,
    0x13a771e7,0x72335faf,0x730e7c41,0xa6e6624f,0x64b68c8a,0xf2692582,
    0x96afd85f,0x14f33a31,0x0cd89c09,0x6db7be6e,0x21553551,0x9821e852,
    0x092eb312,0xafc122fa,0x47a34e15,0x8f38dd9d,0x8f97701f,0x578f49c3,
    0x67793ea5,0x3e42654e,0x05954570,0xe245978c,0xcd4722b0,0xb0de77dd,
    0x8c37a3f7,0x333e1b19,0x0575b41e,0x8efcda4e,0x68e30931,0xba6ebfaa,
    0x841243f5,0xd4ba46eb,0xf548cb9a,0xd26a2dcd,0xad71ed45,0x10e94fdd,
    0xf6ccd0ca,0xca0df0d9,0x474b96a1,0x6775e500,0x3183d5df,0xc1ab8c79,
    0xba8fe492,0xd8f40bc8,0x951029da,0xe5371b22,0x6c22b444,0x0b61b66b,
    0xe0f5b233,0x78e390c1,0xfe010438,0xa49ce6e8,0xe7eccf3a,0xa07a1182,
    0x8a039742,0xc71605dc,0x3e951d9e,0x01801237,0x69021132,0x602b8e89,
    0x99cdadb3,0x890358c6,0x1c103aed,0x3b819d97,0x3a8fae01,0xe22d8054,
    0xa62884c7,0xc1916712,0x8bb90cde,0x166791ec,0xae7b9be4,0xc6f22864,
    0x8f8cba10,0x76433d98,0x3885462d,0x8d8edcb6,0x3d555b85,0x3ed3f703,
    0xd4101e39,0xe7a6f6c5,0x58e00b25,0xaf457d4e,0x2b9512c1,0x3e12af14,
    0x2f4b5ddf,0x8801ee93,0xd2b194d3,0x4e3dd6d2,0xce45b731,0x8c44ad8f,
    0x336f569c,0x09acf0a1,0xc29546ba,0x40487ea7,0x7a4a7a2b,0xdbe1837c,
    0x5c747675,0x209ec153,0x84c026f2,0x69dc216b,0xfce90392,0x7e11db07,
    0xf85dbd3d,0x862ff7a2,0x84ab2db4,0xbbb35dc9,0x656dd076,0x88924fbd,
    0xf8ef1050,0x62f2b8fc,0xf64f67c9,0xdb97e935,0x30db7e45,0xa5f59eb3,
    0x886cad9c,0x580fc7c2,0x4922ceaf,0x74aefdf3,0x386ee473,0x9d2cd89d,
    0xf1f7c06d,0x76fa6784,0x0936189a,0x276ee5fa,0x25099731,0x77e8f595,
    0x668c1092,0xf5ef32c3,0x93bd4761,0xf1241c4f,0xe25ccb1a,0x0772a0c0,
    0xa2c37d35,0x8ae8c783,0x6b12eef4,0xb1e0aaca,0x4f658b89,0xcfe9f02e,
    0xa0cf8bff,0x8980c9b9,0x8ddc4ca8,0xb2979415,0x0ce9ee79,0x36ee8491,
    0xec116b65,0xd86346ac,0xc30dba48,0xf936a2f1,0xbf5980bc,0xb9e2aa89,
    0xede1d7e0,0xb831d164,0xd51944d7,0x9abe0061,0x567f6654,0x6b043f14,
    0xacb0bc3a,0xa84ee4ee,0xe420b5ed,0x6e8e886c,0xd37717a7,0x706bdbd6,
    0x25acf8e9,0x68f3986c,0x3f2445d8,0x642881f8,0xee69a3eb,0xb71c4130,
    0xf30a264f,0x079650cb,0xaa72214b,0xb421a529,0x030bb23d,0xc89e3e71,
    0x04c77464,0x766ed0b0,0xc2739fe4,0x28cd20b4,0x4c7a4fae,0xb6ca06fa,
    0xa919a556,0xabb55ae2,0x3d985d71,0xad299861,0x97a0b247,0x3284d952,
    0xbec161a6,0x9e7c31ef,0xb4692506,0xd6ba9c93,0x90ec025e,0xe78d540f,
    0x12a48e9b,0xfe7e1228,0xa65b0bfe,0xe3e627cf,0xb8937b90,0x33176cde,
    0xc8c27547,0xb1dfc974,0xecbbdeae,0x25594668,0xce10d431,0x4233db7b,
    0x0c8b71b9,0x4768368f,0xedd077d6,0x6311f665,0x55a0ce68,0xaa9f0758,
    0xb817f50f,0xd116d42f,0x83c647af,0x69f24120,0x64d91beb,0xd5eb1eff,
    0xc6542a8d,0x03c21a0b,0x27d91c2e,0x6dc3fc8e,0x5f983080,0x50ef0d00,
    0xb87f890f,0x80e1f9de,0x5daa12cc,0xbcc0a676,0x087b9277,0x5dcc0e2d,
    0x5db0f9a7,0x74778c02,0x9c4aaabc,0x9f5b0c8f,0x83e86444,0x79289b76,
    0xf5101806,0x1bb9c25f,0x9b7ffc68,0x4911cc55,0x12528c35,0x5c0936ed,
    0xcf0601a7,0x3453646f,0x0691cf4a,0xd7d7b2aa,0xc8d46252,0x79e7228c,
    0x6ae3d234,0x30872dd8,0x795830b2,0x805d4007,0x0c13d026,0x74817d0a,
    0x3450c7b1,0xb79ac3a8,0xfe0e15a9,0x337cab7d,0xdf974b07,0x35f9e2c8,
    0xf2c873e4,0x1f53df03,0xd69afd8b,0x40e8c4ca,0xaa3b26eb,0xe6c62407,
    0x6e159ced,0xb687d8e4,0xdbd6e65a,0x9fe37615,0x0f9d3d41,0x135cf309,
    0x74c6dcac,0x9ede336c,0xb61a4995,0xa41292e4,0x65eed6d8,0xe3a50b31,
    0x36855a6f,0x73a5a628,0xb93a706c,0x19bc8de9,0x861f5911,0x4047db00,
    0x26ca8b88,0x475adfae,0x7c62e3ce,0xd7ba188f,0xd09298fd,0xd023d7e9,
    0xd0277760,0x41a3ebf2,0xeec3971c,0x27ffff35,0x65954a40,0x2c390f02,
    0xa797839a,0x4ccd9663,0x010cf531,0xaf3c3151,0xc10a4e81,0x99d39ba1,
    0x337529de,0xbac1848f,0x24bb9910,0xdfa550f8,0xa85d189f,0x32f7e7d8,
    0x23345d22,0x8520853d,0x1d26434f,0xca852389,0xb0eb57fd,0xcdb7ec46,
    0x21ce00e7,0xcec93317,0x6d50c41a,0xeef932fd,0x91e8bc5e,0x1489defd,
    0x5294c3f6,0x547dfeb7,0x376ea552,0x9cb2e315,0x96389276,0x87d580e6,
    0x73a3870f,0x963c0429,0x325acc33,0xf9acb156,0xf287058b,0x8079dfc3,
    0xab27739b,0xf699f598,0x01ed571f,0x5b9e7ef1,0x421625e0,0x34264b89,
    0x59f330b8,0x1c288d53,0xf948464d,0xd1347eaa,0x1faebe01,0xde0c70b7,
    0xf1f20f36,0xa11eea16,0x7a69fc8d,0x8b8525f9,0xd27c301d,0xe9515c29,
    0x2e054933,0x966ae4ef,0x7a8b9ed1,0x3ac5256c,0x0a81eb07,0x356a7868,
    0x1409f5e4,0xb3f318b6,0x95550b3f,0x9b2979b4,0xcbf09945,0xaace41e5,
    0xf259f07a,0x44c13797,0x9f64a92f,0x8484b08a,0x163b6979,0x582816a1,
    0xef0d790f,0x4eefd5e9,0x096d480d,0x3280a1fb,0xd5b96138,0xffa0f63f,
    0x961a6bda,0xc468ea58,0x707ad519,0x72fabd8e,0xe1812984,0x49f961fd,
    0x4e54e4ec,0xa3326149,0xc58a68c7,0x16abde3d,0x8587c217,0xf4a76b96,
    0x6ec683a2,0x4327548d,0x7cf8232e,0x1adb3cd8,0x7c59986b,0x4c52fbb0,
    0x470f9b30,0xafa06c33,0x29576a40,0xf69eddef,0x0f599e8d,0x016c8aa2,
    0x9b5c3c97,0xefbcfa52,0x06f5135d,0x7cf22244,0xcb579ecc,0xc6e161c3,
    0x434e49d0,0x9a2df574,0x3bbf1c0c,0xae34ca66,0xdff132f4,0xda028295,
    0xcae60e3b,0x5bcf4b79,0x2ea842c4,0x04eaca12,0x1ab56dcd,0x048116cd,
    0x981fd308,0xde9f8b53,0x479b6424,0x4ecc551a,0x815d5928,0x8149db52,
    0x6355605f,0x38465229,0x5dfab35b,0xd7fff774,0x30415cd2,0xc1dd72e3,
    0x4f408d11,0xeb5ef4da,0x37f09cfc,0xeb204f34,0x64dc9a41,0x0ce8c5c9,
    0x6897b0fd,0x0a3c7aaf,0xf2d0942d,0x2ba346bd,0x2d13d65d,0x2b1fdc4f,
    0xf4c5b39d,0x64fa1dfa,0x2c4e6245,0xa007cb10,0x83df919c,0xd11ef456,
    0xb64c7bea,0xa41d4bb8,0x88f27305,0x16d892a5,0xe5778970,0x1bf38b43,
    0xf1b5e28e,0x6a757b2a,0xe611d325,0x440f9523,0x9719f9f1,0x9feef917,
    0xfc6ef228,0xe5c34432,0x55041464,0x26cb4541,0x3b4ccef2,0x66474547,
    0xae33ec28,0x1f3931bf,0x755ed95c,0x079c7a23,0xd629d86b,0xbd5c15ca,
    0x37a7f800,0x9eb10b4d,0xd8532a77,0x873b7942,0xdb11daad,0x15a5b9e0,
    0x5a99636a,0x197b3453
};

#endif	//__RANDTAB_H__