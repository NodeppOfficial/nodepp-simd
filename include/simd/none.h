#ifndef  NODEPP_NO_SIMD
#define  NODEPP_NO_SIMD

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace f64 {

    inline f64_t set( const double& value ) { return f64_t({ value, value }); }

    inline f64_t get( const f64_t&  value ) { return value; }

    /*─······································································─*/

    inline f64_t add( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x] + B.value[x]; }); }
    inline f64_t sub( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x] - B.value[x]; }); }
    inline f64_t mul( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x] * B.value[x]; }); }
    inline f64_t div( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/

    inline f64_t abs( const f64_t& A ) /*-----------*/ { return map_f64([&]( int x ){ return ::abs( A.value[x] ); }); }
    inline f64_t min( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return nodepp::min( A.value[x], B.value[x] ); }); }
    inline f64_t max( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return nodepp::max( A.value[x], B.value[x] ); }); }

    /*─······································································─*/

    inline f64_t cmplt( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x] < B.value[x] ? (uchar_64) -1 : 0; }); }
    inline f64_t cmpgt( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x] > B.value[x] ? (uchar_64) -1 : 0; }); }
    inline f64_t cmpeq( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return A.value[x]== B.value[x] ? (uchar_64) -1 : 0; }); }

    /*─······································································─*/

    inline f64_t bit_and( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return (uchar_64) A.value[x] & (uchar_64)B.value[x]; }); }
    inline f64_t bit_or ( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return (uchar_64) A.value[x] | (uchar_64)B.value[x]; }); }
    inline f64_t bit_xor( const f64_t& A, const f64_t& B ) { return map_f64([&]( int x ){ return (uchar_64) A.value[x] ^ (uchar_64)B.value[x]; }); }
    inline f64_t bit_not( const f64_t& A ) /*-----------*/ { return map_f64([&]( int x ){ return (uchar_64) A.value[x] ^ (uchar_64) -1; }); }

    /*─······································································─*/

    inline f64_t select ( const f64_t& mask, const f64_t& v_true, const f64_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace f32 {

    inline f32_t set( const float& value ) { return f32_t({ value, value, value, value }); }

    inline f32_t get( const f32_t& value ) { return value; }

    /*─······································································─*/

    inline f32_t add( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x] + B.value[x]; }); }
    inline f32_t sub( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x] - B.value[x]; }); }
    inline f32_t mul( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x] * B.value[x]; }); }
    inline f32_t div( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/
    
    inline f32_t abs( const f32_t& A ) /*-----------*/ { return map_f32([&]( int x ){ return ::abs( A.value[x] ); }); }
    inline f32_t min( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return nodepp::min( A.value[x], B.value[x] ); }); }
    inline f32_t max( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return nodepp::max( A.value[x], B.value[x] ); }); }

    /*─······································································─*/

    inline f32_t cmplt( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x] < B.value[x] ? (uchar_32) -1 : 0; }); }
    inline f32_t cmpgt( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x] > B.value[x] ? (uchar_32) -1 : 0; }); }
    inline f32_t cmpeq( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return A.value[x]== B.value[x] ? (uchar_32) -1 : 0; }); }

    /*─······································································─*/

    inline f32_t bit_and( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return (uchar_32) A.value[x] & (uchar_32)B.value[x]; }); }
    inline f32_t bit_or ( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return (uchar_32) A.value[x] | (uchar_32)B.value[x]; }); }
    inline f32_t bit_xor( const f32_t& A, const f32_t& B ) { return map_f32([&]( int x ){ return (uchar_32) A.value[x] ^ (uchar_32)B.value[x]; }); }
    inline f32_t bit_not( const f32_t& A ) /*-----------*/ { return map_f32([&]( int x ){ return (uchar_32) A.value[x] ^ (uchar_32) -1; }); }

    /*─······································································─*/

    inline f32_t select ( const f32_t& mask, const f32_t& v_true, const f32_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u64 {

    inline u64_t set( const uchar_64& value ) { return u64_t({ value, value }); }

    inline u64_t get( const u64_t&    value ) { return value; }

    /*─······································································─*/

    inline u64_t bit_shl( const u64_t& A, int shift ) { return map_u64([&]( int x ){ return A.value[x] << shift; }); }
    inline u64_t bit_shr( const u64_t& A, int shift ) { return map_u64([&]( int x ){ return A.value[x] >> shift; }); }

    /*─······································································─*/

    inline u64_t add( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] + B.value[x]; }); }
    inline u64_t sub( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] - B.value[x]; }); }
    inline u64_t mul( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] * B.value[x]; }); }
    inline u64_t div( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/

    inline u64_t bit_and( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] & B.value[x]; }); }
    inline u64_t bit_or ( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] | B.value[x]; }); }
    inline u64_t bit_xor( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] ^ B.value[x]; }); }
    inline u64_t bit_not( const u64_t& A ) /*-----------*/ { return map_u64([&]( int x ){ return A.value[x] ^(uchar_64)-1;}); }

    /*─······································································─*/
    
    inline u64_t min( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return nodepp::min( A.value[x], B.value[x] ); }); }
    inline u64_t max( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return nodepp::max( A.value[x], B.value[x] ); }); }

    /*─······································································─*/

    inline u64_t cmplt( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] < B.value[x] ? (uchar_64) -1 : 0; }); }
    inline u64_t cmpgt( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] > B.value[x] ? (uchar_64) -1 : 0; }); }
    inline u64_t cmpeq( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x]== B.value[x] ? (uchar_64) -1 : 0; }); }

    /*─······································································─*/

    inline u64_t select( const u64_t& mask, const u64_t& v_true, const u64_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u32 {

    inline u32_t set( const uchar_32& value ) { return u32_t({ value, value, value, value }); }

    inline u32_t get( const u32_t&    value ) { return value; }

    /*─······································································─*/

    inline u32_t bit_shl( const u32_t& A, int shift ) { return map_u32([&]( int x ){ return A.value[x] << shift; }); }
    inline u32_t bit_shr( const u32_t& A, int shift ) { return map_u32([&]( int x ){ return A.value[x] >> shift; }); }

    /*─······································································─*/

    inline u32_t add( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] + B.value[x]; }); }
    inline u32_t sub( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] - B.value[x]; }); }
    inline u32_t mul( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] * B.value[x]; }); }
    inline u32_t div( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/

    inline u32_t bit_and( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] & B.value[x]; }); }
    inline u32_t bit_or ( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] | B.value[x]; }); }
    inline u32_t bit_xor( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] ^ B.value[x]; }); }
    inline u32_t bit_not( const u32_t& A ) /*-----------*/ { return map_u32([&]( int x ){ return A.value[x] ^(uchar_32)-1;}); }

    /*─······································································─*/
    
    inline u32_t min( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return nodepp::min( A.value[x], B.value[x] ); }); }
    inline u32_t max( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return nodepp::max( A.value[x], B.value[x] ); }); }

    /*─······································································─*/

    inline u32_t cmplt( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] < B.value[x] ? (uchar_32) -1 : 0; }); }
    inline u32_t cmpgt( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] > B.value[x] ? (uchar_32) -1 : 0; }); }
    inline u32_t cmpeq( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x]== B.value[x] ? (uchar_32) -1 : 0; }); }

    /*─······································································─*/

    inline u32_t select( const u32_t& mask, const u32_t& v_true, const u32_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u16 {

    inline u16_t set( const uchar_16& value ) { return u16_t({ 
        value, value, value, value, 
        value, value, value, value 
    }); }

    inline u16_t get( const u16_t&    value ) { return value; }

    /*─······································································─*/

    inline u16_t bit_shl( const u16_t& A, int shift ) { return map_u16([&]( int x ){ return A.value[x] << shift; }); }
    inline u16_t bit_shr( const u16_t& A, int shift ) { return map_u16([&]( int x ){ return A.value[x] >> shift; }); }

    /*─······································································─*/

    inline u16_t add( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] + B.value[x]; }); }
    inline u16_t sub( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] - B.value[x]; }); }
    inline u16_t mul( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] * B.value[x]; }); }
    inline u16_t div( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/

    inline u16_t bit_and( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] & B.value[x]; }); }
    inline u16_t bit_or ( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] | B.value[x]; }); }
    inline u16_t bit_xor( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] ^ B.value[x]; }); }
    inline u16_t bit_not( const u16_t& A ) /*-----------*/ { return map_u16([&]( int x ){ return A.value[x] ^(uchar_16)-1;}); }

    /*─······································································─*/
    
    inline u16_t min( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return nodepp::min( A.value[x], B.value[x] ); }); }
    inline u16_t max( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return nodepp::max( A.value[x], B.value[x] ); }); }

    /*─······································································─*/

    inline u16_t cmplt( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] < B.value[x] ? (uchar_16) -1 : 0; }); }
    inline u16_t cmpgt( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] > B.value[x] ? (uchar_16) -1 : 0; }); }
    inline u16_t cmpeq( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x]== B.value[x] ? (uchar_16) -1 : 0; }); }

    /*─······································································─*/

    inline u16_t select( const u16_t& mask, const u16_t& v_true, const u16_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u8 {

    inline u8_t set( const uchar_8& value ) { return u8_t({ 
        value, value, value, value, value, value, value, value,
        value, value, value, value, value, value, value, value
    }); }

    inline u8_t get( const u8_t&    value ) { return value; }

    /*─······································································─*/

    inline u8_t bit_shl( const u8_t& A, int shift ) { return map_u8([&]( int x ){ return A.value[x] << shift; }); }
    inline u8_t bit_shr( const u8_t& A, int shift ) { return map_u8([&]( int x ){ return A.value[x] >> shift; }); }

    /*─······································································─*/

    inline u8_t add( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] + B.value[x]; }); }
    inline u8_t sub( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] - B.value[x]; }); }
    inline u8_t mul( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] * B.value[x]; }); }
    inline u8_t div( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/

    inline u8_t bit_and( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] & B.value[x]; }); }
    inline u8_t bit_or ( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] | B.value[x]; }); }
    inline u8_t bit_xor( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] ^ B.value[x]; }); }
    inline u8_t bit_not( const u8_t& A ) /*----------*/ { return map_u8([&]( int x ){ return A.value[x] ^(uchar_8)-1; }); }

    /*─······································································─*/
    
    inline u8_t min( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return nodepp::min( A.value[x], B.value[x] ); }); }
    inline u8_t max( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return nodepp::max( A.value[x], B.value[x] ); }); }

    /*─······································································─*/

    inline u8_t cmplt( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] < B.value[x] ? (uchar_8) -1 : 0; }); }
    inline u8_t cmpgt( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] > B.value[x] ? (uchar_8) -1 : 0; }); }
    inline u8_t cmpeq( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x]== B.value[x] ? (uchar_8) -1 : 0; }); }

    /*─······································································─*/

    inline u8_t select( const u8_t& mask, const u8_t& v_true, const u8_t& v_false ) { 
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) ); 
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

#endif

/*────────────────────────────────────────────────────────────────────────────*/