#ifndef  NODEPP_NO_SIMD
#define  NODEPP_NO_SIMD

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace f64 {

    inline f64_t set( const double& value ) { return F64_CREATOR( value ); }

    inline f64_t get( const f64_t&  value ) { return value; }

    /*─······································································─*/

    inline f64_t shuffle( const f64_t& A, const f64_t& B, const u64_t& index ) {
        double value[4]; memcpy( value+0, A.value, sizeof(double)*2 );
                         memcpy( value+2, B.value, sizeof(double)*2 );
        auto &idx = index.value; return f64_t({ 
             value[idx[0]], value[idx[1]]
        }); 
    }
        
    /*─······································································─*/

    inline f64_t cmplt( const f64_t& A, const f64_t& B ) { 
    return F64_CONVERTER( u64_t ({
        uchar_64( A.value[0] < B.value[0] ? -1: 0x00 ),
        uchar_64( A.value[1] < B.value[1] ? -1: 0x00 )
    }) ); }

    inline f64_t cmpgt( const f64_t& A, const f64_t& B ) { 
    return F64_CONVERTER( u64_t ({
        uchar_64( A.value[0] > B.value[0] ? -1: 0x00 ),
        uchar_64( A.value[1] > B.value[1] ? -1: 0x00 )
    }) ); }

    inline f64_t cmpeq( const f64_t& A, const f64_t& B ) { 
    return F64_CONVERTER( u64_t ({
        uchar_64( A.value[0] == B.value[0] ? -1: 0x00 ),
        uchar_64( A.value[1] == B.value[1] ? -1: 0x00 )
    }) ); }

    /*─······································································─*/
    
    inline f64_t min( const f64_t& A, const f64_t& B ) { 
    return f64_t ({
        double( A.value[0] < B.value[0] ? A.value[0] : B.value[0] ),
        double( A.value[1] < B.value[1] ? A.value[1] : B.value[1] )
    }); }

    inline f64_t max( const f64_t& A, const f64_t& B ) { 
    return f64_t ({
        double( A.value[0] > B.value[0] ? A.value[0] : B.value[0] ),
        double( A.value[1] > B.value[1] ? A.value[1] : B.value[1] )
    }); }

    /*─······································································─*/

    inline f64_t add( const f64_t& A, const f64_t& B ) { return F64_GENERATOR_VV( A, B, + ); }
    inline f64_t sub( const f64_t& A, const f64_t& B ) { return F64_GENERATOR_VV( A, B, - ); }
    inline f64_t mul( const f64_t& A, const f64_t& B ) { return F64_GENERATOR_VV( A, B, * ); }
    inline f64_t div( const f64_t& A, const f64_t& B ) { return F64_GENERATOR_VV( A, B, / ); }

    /*─······································································─*/

    inline f64_t bit_and( const f64_t& A, const f64_t& B ) { return F64_CONVERTER( U64_GENERATOR_VV( A, B, & ) ); }
    inline f64_t bit_or ( const f64_t& A, const f64_t& B ) { return F64_CONVERTER( U64_GENERATOR_VV( A, B, | ) ); }
    inline f64_t bit_xor( const f64_t& A, const f64_t& B ) { return F64_CONVERTER( U64_GENERATOR_VV( A, B, ^ ) ); }
    inline f64_t bit_not( const f64_t& A ) /*-----------*/ { return F64_CONVERTER( U64_GENERATOR_V_( A, ~ ) );    }

    /*─······································································─*/

    inline f64_t select ( const f64_t& mask, const f64_t& v_true, const f64_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

    inline f64_t abs( const f64_t& A ) { return bit_and( A, bit_not( set( -0.0 ) ) ); }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace f32 {

    inline f32_t set( const float& value ) { return F32_CREATOR( value ); }

    inline f32_t get( const f32_t& value ) { return value; }

    /*─······································································─*/

    inline f32_t shuffle( const f32_t& A, const f32_t& B, const u32_t& index ) {
        float value[8]; memcpy( value+0, A.value, sizeof(float)*4 );
                        memcpy( value+4, B.value, sizeof(float)*4 );
        auto &idx = index.value; return f32_t({ 
             value[idx[0]], value[idx[1]], 
             value[idx[2]], value[idx[3]]
        }); 
    }
        
    /*─······································································─*/

    inline f32_t cmplt( const f32_t& A, const f32_t& B ) { 
    return F32_CONVERTER( u32_t ({
        uchar_32( A.value[0] < B.value[0] ? -1: 0x00 ),
        uchar_32( A.value[1] < B.value[1] ? -1: 0x00 ),
        uchar_32( A.value[2] < B.value[2] ? -1: 0x00 ),
        uchar_32( A.value[3] < B.value[3] ? -1: 0x00 )
    }) ); }

    inline f32_t cmpgt( const f32_t& A, const f32_t& B ) {
    return F32_CONVERTER( u32_t ({
        uchar_32( A.value[0] > B.value[0] ? -1: 0x00 ),
        uchar_32( A.value[1] > B.value[1] ? -1: 0x00 ),
        uchar_32( A.value[2] > B.value[2] ? -1: 0x00 ),
        uchar_32( A.value[3] > B.value[3] ? -1: 0x00 )
    }) ); }

    inline f32_t cmpeq( const f32_t& A, const f32_t& B ) {
    return F32_CONVERTER( u32_t ({
        uchar_32( A.value[0] == B.value[0] ? -1: 0x00 ),
        uchar_32( A.value[1] == B.value[1] ? -1: 0x00 ),
        uchar_32( A.value[2] == B.value[2] ? -1: 0x00 ),
        uchar_32( A.value[3] == B.value[3] ? -1: 0x00 )
    }) ); }

    /*─······································································─*/
    
    inline f32_t min( const f32_t& A, const f32_t& B ) {
    return f32_t ({
        float( A.value[0] < B.value[0] ? A.value[0] : B.value[0] ),
        float( A.value[1] < B.value[1] ? A.value[1] : B.value[1] ),
        float( A.value[2] < B.value[2] ? A.value[2] : B.value[2] ),
        float( A.value[3] < B.value[3] ? A.value[3] : B.value[3] )
    } ); }

    inline f32_t max( const f32_t& A, const f32_t& B ) {
    return f32_t ({
        float( A.value[0] > B.value[0] ? A.value[0] : B.value[0] ),
        float( A.value[1] > B.value[1] ? A.value[1] : B.value[1] ),
        float( A.value[2] > B.value[2] ? A.value[2] : B.value[2] ),
        float( A.value[3] > B.value[3] ? A.value[3] : B.value[3] )
    }); }

    /*─······································································─*/

    inline f32_t add( const f32_t& A, const f32_t& B ) { return F32_GENERATOR_VV( A, B, + ); }
    inline f32_t sub( const f32_t& A, const f32_t& B ) { return F32_GENERATOR_VV( A, B, - ); }
    inline f32_t mul( const f32_t& A, const f32_t& B ) { return F32_GENERATOR_VV( A, B, * ); }
    inline f32_t div( const f32_t& A, const f32_t& B ) { return F32_GENERATOR_VV( A, B, / ); }

    /*─······································································─*/

    inline f32_t bit_and( const f32_t& A, const f32_t& B ) { return F32_CONVERTER( U32_GENERATOR_VV( A, B, & ) ); }
    inline f32_t bit_or ( const f32_t& A, const f32_t& B ) { return F32_CONVERTER( U32_GENERATOR_VV( A, B, | ) ); }
    inline f32_t bit_xor( const f32_t& A, const f32_t& B ) { return F32_CONVERTER( U32_GENERATOR_VV( A, B, ^ ) ); }
    inline f32_t bit_not( const f32_t& A ) /*-----------*/ { return F32_CONVERTER( U32_GENERATOR_V_( A, ~ ) );    }

    /*─······································································─*/

    inline f32_t select ( const f32_t& mask, const f32_t& v_true, const f32_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

    inline f32_t abs( const f32_t& A ) { return bit_and( A, bit_not( set( -0.0f ) ) ); }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u64 {

    inline u64_t set( const uchar_64& value ) { return U64_CREATOR( value ); }

    inline u64_t get( const u64_t&    value ) { return value; }

    /*─······································································─*/

    inline u64_t shuffle( const u64_t& A, const u64_t& B, const u64_t& index ) {
        uchar_64 value[4]; memcpy( value+0, A.value, sizeof(uchar_64)*2 );
                           memcpy( value+2, B.value, sizeof(uchar_64)*2 );
        auto &idx = index.value; return u64_t({ 
             value[idx[0]], value[idx[1]]
        }); 
    }
    
    /*─······································································─*/

    inline u64_t cmplt( const u64_t& A, const u64_t& B ) { return u64_t ({
        uchar_64( A.value[0] < B.value[0] ? -1: 0x00 ),
        uchar_64( A.value[1] < B.value[1] ? -1: 0x00 )
    }); }

    inline u64_t cmpgt( const u64_t& A, const u64_t& B ) { return u64_t ({
        uchar_64( A.value[0] > B.value[0] ? -1: 0x00 ),
        uchar_64( A.value[1] > B.value[1] ? -1: 0x00 )
    }); }

    inline u64_t cmpeq( const u64_t& A, const u64_t& B ) { return u64_t ({
        uchar_64( A.value[0] == B.value[0] ? -1: 0x00 ),
        uchar_64( A.value[1] == B.value[1] ? -1: 0x00 )
    }); }

    /*─······································································─*/
    
    inline u64_t min( const u64_t& A, const u64_t& B ) { return u64_t ({
        uchar_64( A.value[0] < B.value[0] ? A.value[0] : B.value[0] ),
        uchar_64( A.value[1] < B.value[1] ? A.value[1] : B.value[1] )
    }); }

    inline u64_t max( const u64_t& A, const u64_t& B ) { return u64_t ({
        uchar_64( A.value[0] > B.value[0] ? A.value[0] : B.value[0] ),
        uchar_64( A.value[1] > B.value[1] ? A.value[1] : B.value[1] )
    }); }

    /*─······································································─*/

    inline u64_t add( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, + ); }
    inline u64_t sub( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, - ); }
    inline u64_t mul( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, * ); }
    inline u64_t div( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, / ); }

    /*─······································································─*/

    inline u64_t bit_and( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, & ); }
    inline u64_t bit_or ( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, | ); }
    inline u64_t bit_xor( const u64_t& A, const u64_t& B ) { return U64_GENERATOR_VV( A, B, ^ ); }
    inline u64_t bit_not( const u64_t& A ) /*-----------*/ { return U64_GENERATOR_V_( A, ~ );    }

    /*─······································································─*/

    inline u64_t bit_shl( const u64_t& A, int shift ) { return U64_GENERATOR_VS( A, shift, << ); }
    inline u64_t bit_shr( const u64_t& A, int shift ) { return U64_GENERATOR_VS( A, shift, >> ); }

    /*─······································································─*/

    inline u64_t select( const u64_t& mask, const u64_t& v_true, const u64_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u32 {

    inline u32_t set( const uchar_32& value ) { return U32_CREATOR( value ); }

    inline u32_t get( const u32_t&    value ) { return value; }

    /*─······································································─*/

    inline u32_t shuffle( const u32_t& A, const u32_t& B, const u32_t& index ) {
        uchar_32 value[8]; memcpy( value+0, A.value, sizeof(uchar_32)*4 );
                           memcpy( value+4, B.value, sizeof(uchar_32)*4 );
        auto &idx = index.value; return u32_t({ 
             value[idx[0]], value[idx[1]], 
             value[idx[2]], value[idx[3]]
        }); 
    }
        
    /*─······································································─*/

    inline u32_t cmplt( const u32_t& A, const u32_t& B ) { return u32_t ({
        uchar_32( A.value[0] < B.value[0] ? -1: 0x00 ),
        uchar_32( A.value[1] < B.value[1] ? -1: 0x00 ),
        uchar_32( A.value[2] < B.value[2] ? -1: 0x00 ),
        uchar_32( A.value[3] < B.value[3] ? -1: 0x00 )
    }); }

    inline u32_t cmpgt( const u32_t& A, const u32_t& B ) { return u32_t ({
        uchar_32( A.value[0] > B.value[0] ? -1: 0x00 ),
        uchar_32( A.value[1] > B.value[1] ? -1: 0x00 ),
        uchar_32( A.value[2] > B.value[2] ? -1: 0x00 ),
        uchar_32( A.value[3] > B.value[3] ? -1: 0x00 )
    }); }

    inline u32_t cmpeq( const u32_t& A, const u32_t& B ) { return u32_t ({
        uchar_32( A.value[0] == B.value[0] ? -1: 0x00 ),
        uchar_32( A.value[1] == B.value[1] ? -1: 0x00 ),
        uchar_32( A.value[2] == B.value[2] ? -1: 0x00 ),
        uchar_32( A.value[3] == B.value[3] ? -1: 0x00 )
    }); }

    /*─······································································─*/
    
    inline u32_t min( const u32_t& A, const u32_t& B ) { return u32_t ({
        uchar_32( A.value[0] < B.value[0] ? A.value[0] : B.value[0] ),
        uchar_32( A.value[1] < B.value[1] ? A.value[1] : B.value[1] ),
        uchar_32( A.value[2] < B.value[2] ? A.value[2] : B.value[2] ),
        uchar_32( A.value[3] < B.value[3] ? A.value[3] : B.value[3] )
    }); }

    inline u32_t max( const u32_t& A, const u32_t& B ) { return u32_t ({
        uchar_32( A.value[0] > B.value[0] ? A.value[0] : B.value[0] ),
        uchar_32( A.value[1] > B.value[1] ? A.value[1] : B.value[1] ),
        uchar_32( A.value[2] > B.value[2] ? A.value[2] : B.value[2] ),
        uchar_32( A.value[3] > B.value[3] ? A.value[3] : B.value[3] )
    }); }

    /*─······································································─*/

    inline u32_t add( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, + ); }
    inline u32_t sub( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, - ); }
    inline u32_t mul( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, * ); }
    inline u32_t div( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, / ); }

    /*─······································································─*/

    inline u32_t bit_and( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, & ); }
    inline u32_t bit_or ( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, | ); }
    inline u32_t bit_xor( const u32_t& A, const u32_t& B ) { return U32_GENERATOR_VV( A, B, ^ ); }
    inline u32_t bit_not( const u32_t& A ) /*-----------*/ { return U32_GENERATOR_V_( A, ~ );    }

    /*─······································································─*/

    inline u32_t bit_shl( const u32_t& A, int shift ) { return U32_GENERATOR_VS( A, shift, << ); }
    inline u32_t bit_shr( const u32_t& A, int shift ) { 
        
        return U32_GENERATOR_VS( A, shift, >> ); }

    /*─······································································─*/

    inline u32_t select( const u32_t& mask, const u32_t& v_true, const u32_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u16 {

    inline u16_t set( const uchar_16& value ) { return U16_CREATOR( value ); }

    inline u16_t get( const u16_t&    value ) { return value; }

    /*─······································································─*/

    inline u16_t shuffle( const u16_t& A, const u16_t& B, const u16_t& index ) {
        uchar_16 value[16]; memcpy( value+0, A.value, sizeof(uchar_16)*8 );
                            memcpy( value+8, B.value, sizeof(uchar_16)*8 );
        auto &idx = index.value; return u16_t({ 
            value[idx[0]], value[idx[1]], 
            value[idx[2]], value[idx[3]], 
            value[idx[4]], value[idx[5]], 
            value[idx[6]], value[idx[7]] 
        }); 
    }
        
    /*─······································································─*/

    inline u16_t cmplt( const u16_t& A, const u16_t& B ) { return u16_t ({
        uchar_16( A.value[0] < B.value[0] ? -1: 0x00 ),
        uchar_16( A.value[1] < B.value[1] ? -1: 0x00 ),
        uchar_16( A.value[2] < B.value[2] ? -1: 0x00 ),
        uchar_16( A.value[3] < B.value[3] ? -1: 0x00 ),
        uchar_16( A.value[4] < B.value[4] ? -1: 0x00 ),
        uchar_16( A.value[5] < B.value[5] ? -1: 0x00 ),
        uchar_16( A.value[6] < B.value[6] ? -1: 0x00 ),
        uchar_16( A.value[7] < B.value[7] ? -1: 0x00 )
    }); }

    inline u16_t cmpgt( const u16_t& A, const u16_t& B ) { return u16_t ({
        uchar_16( A.value[0] > B.value[0] ? -1: 0x00 ),
        uchar_16( A.value[1] > B.value[1] ? -1: 0x00 ),
        uchar_16( A.value[2] > B.value[2] ? -1: 0x00 ),
        uchar_16( A.value[3] > B.value[3] ? -1: 0x00 ),
        uchar_16( A.value[4] > B.value[4] ? -1: 0x00 ),
        uchar_16( A.value[5] > B.value[5] ? -1: 0x00 ),
        uchar_16( A.value[6] > B.value[6] ? -1: 0x00 ),
        uchar_16( A.value[7] > B.value[7] ? -1: 0x00 )
    }); }

    inline u16_t cmpeq( const u16_t& A, const u16_t& B ) { return u16_t ({
        uchar_16( A.value[0] == B.value[0] ? -1: 0x00 ),
        uchar_16( A.value[1] == B.value[1] ? -1: 0x00 ),
        uchar_16( A.value[2] == B.value[2] ? -1: 0x00 ),
        uchar_16( A.value[3] == B.value[3] ? -1: 0x00 ),
        uchar_16( A.value[4] == B.value[4] ? -1: 0x00 ),
        uchar_16( A.value[5] == B.value[5] ? -1: 0x00 ),
        uchar_16( A.value[6] == B.value[6] ? -1: 0x00 ),
        uchar_16( A.value[7] == B.value[7] ? -1: 0x00 )
    }); }

    /*─······································································─*/
    
    inline u16_t min( const u16_t& A, const u16_t& B ) { return u16_t ({
        uchar_16( A.value[0] < B.value[0] ? A.value[0] : B.value[0] ),
        uchar_16( A.value[1] < B.value[1] ? A.value[1] : B.value[1] ),
        uchar_16( A.value[2] < B.value[2] ? A.value[2] : B.value[2] ),
        uchar_16( A.value[3] < B.value[3] ? A.value[3] : B.value[3] ),
        uchar_16( A.value[4] < B.value[4] ? A.value[4] : B.value[4] ),
        uchar_16( A.value[5] < B.value[5] ? A.value[5] : B.value[5] ),
        uchar_16( A.value[6] < B.value[6] ? A.value[6] : B.value[6] ),
        uchar_16( A.value[7] < B.value[7] ? A.value[7] : B.value[7] )
    }); }

    inline u16_t max( const u16_t& A, const u16_t& B ) { return u16_t ({
        uchar_16( A.value[0] > B.value[0] ? A.value[0] : B.value[0] ),
        uchar_16( A.value[1] > B.value[1] ? A.value[1] : B.value[1] ),
        uchar_16( A.value[2] > B.value[2] ? A.value[2] : B.value[2] ),
        uchar_16( A.value[3] > B.value[3] ? A.value[3] : B.value[3] ),
        uchar_16( A.value[4] > B.value[4] ? A.value[4] : B.value[4] ),
        uchar_16( A.value[5] > B.value[5] ? A.value[5] : B.value[5] ),
        uchar_16( A.value[6] > B.value[6] ? A.value[6] : B.value[6] ),
        uchar_16( A.value[7] > B.value[7] ? A.value[7] : B.value[7] )
    }); }

    /*─······································································─*/

    inline u16_t add( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, + ); }
    inline u16_t sub( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, - ); }
    inline u16_t mul( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, * ); }
    inline u16_t div( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, / ); }

    /*─······································································─*/

    inline u16_t bit_and( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, & ); }
    inline u16_t bit_or ( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, | ); }
    inline u16_t bit_xor( const u16_t& A, const u16_t& B ) { return U16_GENERATOR_VV( A, B, ^ ); }
    inline u16_t bit_not( const u16_t& A ) /*-----------*/ { return U16_GENERATOR_V_( A, ~ );    }

    /*─······································································─*/

    inline u16_t bit_shl( const u16_t& A, int shift ) { return U16_GENERATOR_VS( A, shift, << ); }
    inline u16_t bit_shr( const u16_t& A, int shift ) { return U16_GENERATOR_VS( A, shift, >> ); }

    /*─······································································─*/

    inline u16_t select( const u16_t& mask, const u16_t& v_true, const u16_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u8 {

    inline u8_t set( const uchar_8& value ) { return U8_CREATOR( value ); }

    inline u8_t get( const u8_t&    value ) { return value; }

    /*─······································································─*/

    inline u8_t shuffle( const u8_t& A, const u8_t& B, const u8_t& index ) {
        uchar_8 value[32]; memcpy( value+0 , A.value, sizeof(uchar_8)*16 );
                           memcpy( value+16, B.value, sizeof(uchar_8)*16 );
        auto &idx = index.value; return u8_t({ 
            value[idx[0] ], value[idx[1] ], 
            value[idx[2] ], value[idx[3] ], 
            value[idx[4] ], value[idx[5] ], 
            value[idx[6] ], value[idx[7] ],
            value[idx[8] ], value[idx[9] ], 
            value[idx[10]], value[idx[11]], 
            value[idx[12]], value[idx[13]], 
            value[idx[14]], value[idx[15]] 
        }); 
    }
        
    /*─······································································─*/

    inline u8_t cmplt( const u8_t& A, const u8_t& B ) { return u8_t ({
        uchar_8( A.value[0]  < B.value[0] ? -1: 0x00 ),
        uchar_8( A.value[1]  < B.value[1] ? -1: 0x00 ),
        uchar_8( A.value[2]  < B.value[2] ? -1: 0x00 ),
        uchar_8( A.value[3]  < B.value[3] ? -1: 0x00 ),
        uchar_8( A.value[4]  < B.value[4] ? -1: 0x00 ),
        uchar_8( A.value[5]  < B.value[5] ? -1: 0x00 ),
        uchar_8( A.value[6]  < B.value[6] ? -1: 0x00 ),
        uchar_8( A.value[7]  < B.value[7] ? -1: 0x00 ),
        uchar_8( A.value[8]  < B.value[8] ? -1: 0x00 ),
        uchar_8( A.value[9]  < B.value[9] ? -1: 0x00 ),
        uchar_8( A.value[10] < B.value[10]? -1: 0x00 ),
        uchar_8( A.value[11] < B.value[11]? -1: 0x00 ),
        uchar_8( A.value[12] < B.value[12]? -1: 0x00 ),
        uchar_8( A.value[13] < B.value[13]? -1: 0x00 ),
        uchar_8( A.value[14] < B.value[14]? -1: 0x00 ),
        uchar_8( A.value[15] < B.value[15]? -1: 0x00 )
    }); }

    inline u8_t cmpgt( const u8_t& A, const u8_t& B ) { return u8_t ({
        uchar_8( A.value[0]  > B.value[0] ? -1: 0x00 ),
        uchar_8( A.value[1]  > B.value[1] ? -1: 0x00 ),
        uchar_8( A.value[2]  > B.value[2] ? -1: 0x00 ),
        uchar_8( A.value[3]  > B.value[3] ? -1: 0x00 ),
        uchar_8( A.value[4]  > B.value[4] ? -1: 0x00 ),
        uchar_8( A.value[5]  > B.value[5] ? -1: 0x00 ),
        uchar_8( A.value[6]  > B.value[6] ? -1: 0x00 ),
        uchar_8( A.value[7]  > B.value[7] ? -1: 0x00 ),
        uchar_8( A.value[8]  > B.value[8] ? -1: 0x00 ),
        uchar_8( A.value[9]  > B.value[9] ? -1: 0x00 ),
        uchar_8( A.value[10] > B.value[10]? -1: 0x00 ),
        uchar_8( A.value[11] > B.value[11]? -1: 0x00 ),
        uchar_8( A.value[12] > B.value[12]? -1: 0x00 ),
        uchar_8( A.value[13] > B.value[13]? -1: 0x00 ),
        uchar_8( A.value[14] > B.value[14]? -1: 0x00 ),
        uchar_8( A.value[15] > B.value[15]? -1: 0x00 )
    }); }

    inline u8_t cmpeq( const u8_t& A, const u8_t& B ) { return u8_t ({
        uchar_8( A.value[0]  == B.value[0] ? -1: 0x00 ),
        uchar_8( A.value[1]  == B.value[1] ? -1: 0x00 ),
        uchar_8( A.value[2]  == B.value[2] ? -1: 0x00 ),
        uchar_8( A.value[3]  == B.value[3] ? -1: 0x00 ),
        uchar_8( A.value[4]  == B.value[4] ? -1: 0x00 ),
        uchar_8( A.value[5]  == B.value[5] ? -1: 0x00 ),
        uchar_8( A.value[6]  == B.value[6] ? -1: 0x00 ),
        uchar_8( A.value[7]  == B.value[7] ? -1: 0x00 ),
        uchar_8( A.value[8]  == B.value[8] ? -1: 0x00 ),
        uchar_8( A.value[9]  == B.value[9] ? -1: 0x00 ),
        uchar_8( A.value[10] == B.value[10]? -1: 0x00 ),
        uchar_8( A.value[11] == B.value[11]? -1: 0x00 ),
        uchar_8( A.value[12] == B.value[12]? -1: 0x00 ),
        uchar_8( A.value[13] == B.value[13]? -1: 0x00 ),
        uchar_8( A.value[14] == B.value[14]? -1: 0x00 ),
        uchar_8( A.value[15] == B.value[15]? -1: 0x00 )
    }); }

    /*─······································································─*/
    
    inline u8_t min( const u8_t& A, const u8_t& B ) { return u8_t ({
        uchar_8( A.value[0]  < B.value[0] ? A.value[0] : B.value[0]  ),
        uchar_8( A.value[1]  < B.value[1] ? A.value[1] : B.value[1]  ),
        uchar_8( A.value[2]  < B.value[2] ? A.value[2] : B.value[2]  ),
        uchar_8( A.value[3]  < B.value[3] ? A.value[3] : B.value[3]  ),
        uchar_8( A.value[4]  < B.value[4] ? A.value[4] : B.value[4]  ),
        uchar_8( A.value[5]  < B.value[5] ? A.value[5] : B.value[5]  ),
        uchar_8( A.value[6]  < B.value[6] ? A.value[6] : B.value[6]  ),
        uchar_8( A.value[7]  < B.value[7] ? A.value[7] : B.value[7]  ),
        uchar_8( A.value[8]  < B.value[8] ? A.value[8] : B.value[8]  ),
        uchar_8( A.value[9]  < B.value[9] ? A.value[9] : B.value[9]  ),
        uchar_8( A.value[10] < B.value[10]? A.value[10]: B.value[10] ),
        uchar_8( A.value[11] < B.value[11]? A.value[11]: B.value[11] ),
        uchar_8( A.value[12] < B.value[12]? A.value[12]: B.value[12] ),
        uchar_8( A.value[13] < B.value[13]? A.value[13]: B.value[13] ),
        uchar_8( A.value[14] < B.value[14]? A.value[14]: B.value[14] ),
        uchar_8( A.value[15] < B.value[15]? A.value[15]: B.value[15] )
    }); }

    inline u8_t max( const u8_t& A, const u8_t& B ) { return u8_t ({
        uchar_8( A.value[0]  > B.value[0] ? A.value[0] : B.value[0]  ),
        uchar_8( A.value[1]  > B.value[1] ? A.value[1] : B.value[1]  ),
        uchar_8( A.value[2]  > B.value[2] ? A.value[2] : B.value[2]  ),
        uchar_8( A.value[3]  > B.value[3] ? A.value[3] : B.value[3]  ),
        uchar_8( A.value[4]  > B.value[4] ? A.value[4] : B.value[4]  ),
        uchar_8( A.value[5]  > B.value[5] ? A.value[5] : B.value[5]  ),
        uchar_8( A.value[6]  > B.value[6] ? A.value[6] : B.value[6]  ),
        uchar_8( A.value[7]  > B.value[7] ? A.value[7] : B.value[7]  ),
        uchar_8( A.value[8]  > B.value[8] ? A.value[8] : B.value[8]  ),
        uchar_8( A.value[9]  > B.value[9] ? A.value[9] : B.value[9]  ),
        uchar_8( A.value[10] > B.value[10]? A.value[10]: B.value[10] ),
        uchar_8( A.value[11] > B.value[11]? A.value[11]: B.value[11] ),
        uchar_8( A.value[12] > B.value[12]? A.value[12]: B.value[12] ),
        uchar_8( A.value[13] > B.value[13]? A.value[13]: B.value[13] ),
        uchar_8( A.value[14] > B.value[14]? A.value[14]: B.value[14] ),
        uchar_8( A.value[15] > B.value[15]? A.value[15]: B.value[15] )
    }); }

    /*─······································································─*/

    inline u8_t add( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, + ); }
    inline u8_t sub( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, - ); }
    inline u8_t mul( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, * ); }
    inline u8_t div( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, / ); }

    /*─······································································─*/

    inline u8_t bit_and( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, & ); }
    inline u8_t bit_or ( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, | ); }
    inline u8_t bit_xor( const u8_t& A, const u8_t& B ) { return U8_GENERATOR_VV( A, B, ^ ); }
    inline u8_t bit_not( const u8_t& A ) /*----------*/ { return U8_GENERATOR_V_( A, ~ );    }

    /*─······································································─*/

    inline u8_t bit_shl( const u8_t& A, int shift ) { return U8_GENERATOR_VS( A, shift, << ); }
    inline u8_t bit_shr( const u8_t& A, int shift ) { return U8_GENERATOR_VS( A, shift, >> ); }

    /*─······································································─*/

    inline u8_t select( const u8_t& mask, const u8_t& v_true, const u8_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

#endif

/*────────────────────────────────────────────────────────────────────────────*/