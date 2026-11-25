/*
 * Copyright 2023 The Nodepp Project Authors. All Rights Reserved.
 *
 * Licensed under the MIT (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://github.com/NodeppOfficial/nodepp/blob/main/LICENSE
 */

/*────────────────────────────────────────────────────────────────────────────*/

#ifndef SIND_MACRO
#define SIMD_MACRO

/*────────────────────────────────────────────────────────────────────────────*/

#define SIMD_FORMAT_CONVERTER( A, B, size ) ([&]()->A { \
    A out; memmove( out.value, B.value, size );         \
    return out;                                         \
})()

/*────────────────────────────────────────────────────────────────────────────*/

#define F64_CONVERTER( B ) SIMD_FORMAT_CONVERTER( f64_t, B, sizeof(uchar_64)*2 )

#define F64_CREATOR( A ) f64_t ({ A, A })

#define F64_GENERATOR_V_( A, OPERATOR ) f64_t ({ \
    double( OPERATOR double( A.value[0] ) ), \
    double( OPERATOR double( A.value[1] ) )  \
})

#define F64_GENERATOR_VS( A, B, OPERATOR ) f64_t ({ \
    double( double( A.value[0] ) OPERATOR B ), \
    double( double( A.value[1] ) OPERATOR B )  \
})

#define F64_GENERATOR_VV( A, B, OPERATOR ) f64_t ({ \
    double( double( A.value[0] ) OPERATOR B.value[0]  ), \
    double( double( A.value[1] ) OPERATOR B.value[1]  )  \
})

/*────────────────────────────────────────────────────────────────────────────*/

#define F32_CONVERTER( B ) SIMD_FORMAT_CONVERTER( f32_t, B, sizeof(uchar_32)*4 )

#define F32_CREATOR( A ) f32_t ({ A, A, A, A })

#define F32_GENERATOR_V_( A, OPERATOR ) f32_t ({ \
    float( OPERATOR float( A.value[0] ) ), \
    float( OPERATOR float( A.value[1] ) ), \
    float( OPERATOR float( A.value[2] ) ), \
    float( OPERATOR float( A.value[3] ) )  \
})

#define F32_GENERATOR_VS( A, B, OPERATOR ) f32_t ({ \
    float( float( A.value[0] ) OPERATOR B ), \
    float( float( A.value[1] ) OPERATOR B ), \
    float( float( A.value[2] ) OPERATOR B ), \
    float( float( A.value[3] ) OPERATOR B )  \
})

#define F32_GENERATOR_VV( A, B, OPERATOR ) f32_t ({ \
    float( float( A.value[0] ) OPERATOR float( B.value[0] ) ), \
    float( float( A.value[1] ) OPERATOR float( B.value[1] ) ), \
    float( float( A.value[2] ) OPERATOR float( B.value[2] ) ), \
    float( float( A.value[3] ) OPERATOR float( B.value[3] ) )  \
})

/*────────────────────────────────────────────────────────────────────────────*/

#define U64_CONVERTER( B ) SIMD_FORMAT_CONVERTER( u64_t, B, sizeof(uchar_64)*2 )

#define U64_CREATOR( A ) u64_t ({ A, A })

#define U64_GENERATOR_V_( A, OPERATOR ) u64_t ({ \
    uchar_64( OPERATOR uchar_64( A.value[0] ) ), \
    uchar_64( OPERATOR uchar_64( A.value[1] ) )  \
})

#define U64_GENERATOR_VS( A, B, OPERATOR ) u64_t ({ \
    uchar_64( uchar_64( A.value[0] ) OPERATOR B ), \
    uchar_64( uchar_64( A.value[1] ) OPERATOR B )  \
})

#define U64_GENERATOR_VV( A, B, OPERATOR ) u64_t ({ \
    uchar_64( uchar_64( A.value[0] ) OPERATOR uchar_64( B.value[0] ) ), \
    uchar_64( uchar_64( A.value[1] ) OPERATOR uchar_64( B.value[1] ) )  \
})

/*────────────────────────────────────────────────────────────────────────────*/

#define U32_CONVERTER( A ) SIMD_FORMAT_CONVERTER( u32_t, A, sizeof(uchar_32)*4 )

#define U32_CREATOR( A ) u32_t ({ A, A, A, A })

#define U32_GENERATOR_V_( A, OPERATOR ) u32_t ({ \
    uchar_32( OPERATOR uchar_32( A.value[0] ) ), \
    uchar_32( OPERATOR uchar_32( A.value[1] ) ), \
    uchar_32( OPERATOR uchar_32( A.value[2] ) ), \
    uchar_32( OPERATOR uchar_32( A.value[3] ) )  \
})

#define U32_GENERATOR_VS( A, B, OPERATOR ) u32_t ({ \
    uchar_32( uchar_32( A.value[0] ) OPERATOR B ), \
    uchar_32( uchar_32( A.value[1] ) OPERATOR B ), \
    uchar_32( uchar_32( A.value[2] ) OPERATOR B ), \
    uchar_32( uchar_32( A.value[3] ) OPERATOR B )  \
})

#define U32_GENERATOR_VV( A, B, OPERATOR ) u32_t ({ \
    uchar_32( uchar_32( A.value[0] ) OPERATOR uchar_32( B.value[0] ) ), \
    uchar_32( uchar_32( A.value[1] ) OPERATOR uchar_32( B.value[1] ) ), \
    uchar_32( uchar_32( A.value[2] ) OPERATOR uchar_32( B.value[2] ) ), \
    uchar_32( uchar_32( A.value[3] ) OPERATOR uchar_32( B.value[3] ) )  \
})

/*────────────────────────────────────────────────────────────────────────────*/

#define U16_CONVERTER( A ) SIMD_FORMAT_CONVERTER( u16_t, A, sizeof(uchar_16)*8 )

#define U16_CREATOR( A ) u16_t ({ A, A, A, A, A, A, A, A })

#define U16_GENERATOR_V_( A, OPERATOR ) u16_t ({ \
    uchar_16( OPERATOR uchar_16( A.value[0] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[1] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[2] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[3] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[4] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[5] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[6] ) ), \
    uchar_16( OPERATOR uchar_16( A.value[7] ) )  \
})

#define U16_GENERATOR_VS( A, B, OPERATOR ) u16_t({ \
    uchar_16( uchar_16( A.value[0] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[1] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[2] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[3] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[4] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[5] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[6] ) OPERATOR B ), \
    uchar_16( uchar_16( A.value[7] ) OPERATOR B )  \
})

#define U16_GENERATOR_VV( A, B, OPERATOR ) u16_t ({ \
    uchar_16( uchar_16( A.value[0] ) OPERATOR uchar_16( B.value[0] ) ), \
    uchar_16( uchar_16( A.value[1] ) OPERATOR uchar_16( B.value[1] ) ), \
    uchar_16( uchar_16( A.value[2] ) OPERATOR uchar_16( B.value[2] ) ), \
    uchar_16( uchar_16( A.value[3] ) OPERATOR uchar_16( B.value[3] ) ), \
    uchar_16( uchar_16( A.value[4] ) OPERATOR uchar_16( B.value[4] ) ), \
    uchar_16( uchar_16( A.value[5] ) OPERATOR uchar_16( B.value[5] ) ), \
    uchar_16( uchar_16( A.value[6] ) OPERATOR uchar_16( B.value[6] ) ), \
    uchar_16( uchar_16( A.value[7] ) OPERATOR uchar_16( B.value[7] ) )  \
})

/*────────────────────────────────────────────────────────────────────────────*/

#define U8_CREATOR( A ) u8_t ({ A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A })

#define U8_CONVERTER( A ) SIMD_FORMAT_CONVERTER( u8_t, A, sizeof(uchar_8)*16 )

#define U8_GENERATOR_V_( A, OPERATOR ) u8_t ({ \
    uchar_8( OPERATOR uchar_8( A.value[0]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[1]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[2]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[3]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[4]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[5]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[6]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[7]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[8]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[9]  ) ), \
    uchar_8( OPERATOR uchar_8( A.value[10] ) ), \
    uchar_8( OPERATOR uchar_8( A.value[11] ) ), \
    uchar_8( OPERATOR uchar_8( A.value[12] ) ), \
    uchar_8( OPERATOR uchar_8( A.value[13] ) ), \
    uchar_8( OPERATOR uchar_8( A.value[14] ) ), \
    uchar_8( OPERATOR uchar_8( A.value[15] ) )  \
})

#define U8_GENERATOR_VS( A, B, OPERATOR ) u8_t ({ \
    uchar_8( uchar_8( A.value[0]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[1]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[2]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[3]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[4]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[5]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[6]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[7]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[8]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[9]  ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[10] ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[11] ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[12] ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[13] ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[14] ) OPERATOR B ), \
    uchar_8( uchar_8( A.value[15] ) OPERATOR B )  \
})

#define U8_GENERATOR_VV( A, B, OPERATOR ) u8_t ({ \
    uchar_8( uchar_8( A.value[0]  ) OPERATOR B.value[0]  ), \
    uchar_8( uchar_8( A.value[1]  ) OPERATOR B.value[1]  ), \
    uchar_8( uchar_8( A.value[2]  ) OPERATOR B.value[2]  ), \
    uchar_8( uchar_8( A.value[3]  ) OPERATOR B.value[3]  ), \
    uchar_8( uchar_8( A.value[4]  ) OPERATOR B.value[4]  ), \
    uchar_8( uchar_8( A.value[5]  ) OPERATOR B.value[5]  ), \
    uchar_8( uchar_8( A.value[6]  ) OPERATOR B.value[6]  ), \
    uchar_8( uchar_8( A.value[7]  ) OPERATOR B.value[7]  ), \
    uchar_8( uchar_8( A.value[8]  ) OPERATOR B.value[8]  ), \
    uchar_8( uchar_8( A.value[9]  ) OPERATOR B.value[9]  ), \
    uchar_8( uchar_8( A.value[10] ) OPERATOR B.value[10] ), \
    uchar_8( uchar_8( A.value[11] ) OPERATOR B.value[11] ), \
    uchar_8( uchar_8( A.value[12] ) OPERATOR B.value[12] ), \
    uchar_8( uchar_8( A.value[13] ) OPERATOR B.value[13] ), \
    uchar_8( uchar_8( A.value[14] ) OPERATOR B.value[14] ), \
    uchar_8( uchar_8( A.value[15] ) OPERATOR B.value[15] )  \
})

/*────────────────────────────────────────────────────────────────────────────*/

#endif

/*────────────────────────────────────────────────────────────────────────────*/