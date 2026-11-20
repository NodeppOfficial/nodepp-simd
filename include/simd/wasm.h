#ifndef NODEPP_WASM_SIMD
#define NODEPP_WASM_SIMD

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace f64 {

    inline f64_t set( const double& value ) { return f64_t({ value, value }); }

    inline f64_t get( const f64_t&  value ) { return value; }

    /*─······································································─*/

    inline f64_t div( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_div ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }
    
    inline f64_t add( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_add ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t sub( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_sub ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t mul( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_mul ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline f64_t min( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_min ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t max( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_max ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline f64_t cmplt( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_lt  ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t cmpgt( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_gt  ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t cmpeq( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f64x2_eq  ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline f64_t bit_and( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_and  ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t bit_or( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_or   ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t bit_xor( const f64_t& A, const f64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_xor  ( memA, memB );
        f64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f64_t bit_not( const f64_t& A ) { return bit_xor( A, cmpeq( f64_t(), f64_t() ) ); }

    /*─······································································─*/

    inline f64_t abs( const f64_t& A ) { return bit_and( A, bit_not( set( -0.0 ) ) ); }

    inline f64_t select ( const f64_t& mask, const f64_t& v_true, const f64_t& v_false ) {
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) );
    }

    /*─······································································─*/

    template< ulong N=2 >
    inline f64_t shuffle( const f64_t& A, const f64_t& B, uchar (&index)[N] ) {
        auto memA = wasm_v128_load    ( A.value );
        auto memB = wasm_v128_load    ( B.value );
        auto mem  = wasm_f64x2_shuffle( memA, memB, index[0], index[1] );
        f64_t out ; wasm_v128_store   ( out.value, mem ); return out;
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace f32 {

    inline f32_t set( const float& value ) { return f32_t({ value, value, value, value }); }

    inline f32_t get( const f32_t& value ) { return value; }

    /*─······································································─*/

    inline f32_t div( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_div ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    } 
    
    inline f32_t add( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_add ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t sub( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_sub ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t mul( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_mul ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline f32_t min( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_min ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t max( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_max ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline f32_t cmplt( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_lt  ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t cmpgt( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_gt  ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t cmpeq( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_eq  ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline f32_t bit_and( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_and  ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t bit_or( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_or   ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t bit_xor( const f32_t& A, const f32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_xor  ( memA, memB );
        f32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline f32_t bit_not( const f32_t& A ) { return bit_xor( A, cmpeq( f32_t(), f32_t() ) ); }

    /*─······································································─*/

    inline f32_t abs( const f32_t& A ) { return bit_and( A, bit_not( set( -0.0f ) ) ); }

    inline f32_t select ( const f32_t& mask, const f32_t& v_true, const f32_t& v_false ) {
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) );
    }

    /*─······································································─*/

    template< ulong N=4 >
    inline f32_t shuffle( const f32_t& A, const f32_t& B, uchar (&index)[N] ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_f32x4_shuffle( memA, memB, 
             index[0], index[1] , 
             index[2], index[3] );
        f32_t out; wasm_v128_store( out.value, mem ); return out;
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u64 { 

    inline u64_t div( const u64_t& A, const u64_t& B ) { return map_u64([&]( int x ){ return A.value[x] / B.value[x]; }); }

    inline u64_t set( const uchar_64& value ) { return u64_t({ value, value }); }

    inline u64_t get( const u64_t&    value ) { return value; }

    /*─······································································─*/

    inline u64_t min( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u64x2_min ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t max( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u64x2_max ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }
    
    /*─······································································─*/
    
    inline u64_t add( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u64x2_add ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t sub( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u64x2_sub ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t mul( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u64x2_mul ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u64_t bit_shl( const u64_t& A, int shift ) {
        auto memA = wasm_v128_load ( A.value );
        auto mem  = wasm_u64x2_shl ( memA, shift );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t bit_shr( const u64_t& A, int shift ) {
        auto memA = wasm_v128_load ( A.value );
        auto mem  = wasm_u64x2_shr ( memA, shift );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u64_t bit_and( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_and  ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t bit_or( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_or   ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t bit_xor( const u64_t& A, const u64_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_xor  ( memA, memB );
        u64_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u64_t bit_not( const u64_t& A ) { return bit_xor( A, set( (uchar_64) -1 ) ); }

    /*─······································································─*/

    inline u64_t select ( const u64_t& mask, const u64_t& v_true, const u64_t& v_false ) {
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) );
    }

    /*─······································································─*/

    inline u64_t cmplt( const u64_t& A, const u64_t& B ) { 
        return bit_not( sub( bit_and( bit_shr( sub(A,B), 63 ), set(1) ), set(1) ) );
    }

    inline u64_t cmpgt( const u64_t& A, const u64_t& B ) { 
        return bit_not( sub( bit_and( bit_shr( sub(B,A), 63 ), set(1) ), set(1) ) );
    }
    
    inline u64_t cmpeq( const u64_t& A, const u64_t& B ) { 
        return bit_not( bit_xor( cmplt(A,B), cmpgt(A,B) ) );
    }

    /*─······································································─*/

    template< ulong N=2 >
    inline u64_t shuffle( const u64_t& A, const u64_t& B, uchar (&index)[N] ) {
        auto memA = wasm_v128_load    ( A.value );
        auto memB = wasm_v128_load    ( B.value );
        auto mem  = wasm_u64x2_shuffle( memA, memB, index[0], index[1] );
        u64_t out; wasm_v128_store( out.value, mem ); return out;
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u32 { 

    inline u32_t div( const u32_t& A, const u32_t& B ) { return map_u32([&]( int x ){ return A.value[x] / B.value[x]; }); }

    inline u32_t set( const uchar_32& value ) { return u32_t({ value, value, value, value }); }

    inline u32_t get( const u32_t&    value ) { return value; }

    /*─······································································─*/

    inline u32_t min( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_min ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t max( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_max ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/
    
    inline u32_t add( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_add ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t sub( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_sub ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t mul( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_mul ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u32_t cmplt( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_lt  ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t cmpgt( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_gt  ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t cmpeq( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u32x4_eq  ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u32_t bit_shl( const u32_t& A, int shift ) {
        auto memA = wasm_v128_load ( A.value );
        auto mem  = wasm_u32x2_shl ( memA, shift );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t bit_shr( const u32_t& A, int shift ) {
        auto memA = wasm_v128_load ( A.value );
        auto mem  = wasm_u32x2_shr ( memA, shift );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u32_t bit_and( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_and  ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t bit_or( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_or   ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t bit_xor( const u32_t& A, const u32_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_xor  ( memA, memB );
        u32_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u32_t bit_not( const u32_t& A ) { return bit_xor( A, set( (uchar_32) -1 ) ); }

    /*─······································································─*/

    inline u32_t select ( const u32_t& mask, const u32_t& v_true, const u32_t& v_false ) {
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) );
    }

    /*─······································································─*/

    template< ulong N=4 >
    inline u32_t shuffle( const u32_t& A, const u32_t& B, uchar (&index)[N] ) {
        auto memA = wasm_v128_load    ( A.value );
        auto memB = wasm_v128_load    ( B.value );
        auto mem  = wasm_u32x4_shuffle( memA, memB, 
             index[0], index[1] , 
             index[2], index[3] );
        u32_t out; wasm_v128_store( out.value, mem ); return out;
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { namespace u16 {

    inline u16_t div( const u16_t& A, const u16_t& B ) { return map_u16([&]( int x ){ return A.value[x] / B.value[x]; }); }

    inline u16_t set( const uchar_16& value ) { return u16_t({ 
        value, value, value, value, 
        value, value, value, value 
    }); }

    inline u16_t get( const u16_t&    value ) { return value; }

    /*─······································································─*/

    inline u16_t min( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_min ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t max( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_max ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/
    
    inline u16_t add( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_add ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t sub( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_sub ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t mul( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_mul ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u16_t cmplt( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_lt  ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t cmpgt( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_gt  ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t cmpeq( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u16x8_eq  ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u16_t bit_shl( const u16_t& A, int shift ) {
        auto memA = wasm_v128_load ( A.value );
        auto mem  = wasm_u16x8_shl ( memA, shift );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t bit_shr( const u16_t& A, int shift ) {
        auto memA = wasm_v128_load ( A.value );
        auto mem  = wasm_u16x8_shr ( memA, shift );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u16_t bit_and( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_and  ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t bit_or( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_or   ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t bit_xor( const u16_t& A, const u16_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_xor  ( memA, memB );
        u16_t out ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u16_t bit_not( const u16_t& A ) { return bit_xor( A, set( (uchar_16) -1 ) ); }

    /*─······································································─*/

    inline u16_t select ( const u16_t& mask, const u16_t& v_true, const u16_t& v_false ) {
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) );
    }

    /*─······································································─*/

    template< ulong N=8 >
    inline u16_t shuffle( const u16_t& A, const u16_t& B, uchar (&index)[N] ) {
        auto memA = wasm_v128_load    ( A.value );
        auto memB = wasm_v128_load    ( B.value );
        auto mem  = wasm_u16x8_shuffle( memA, memB, 
             index[0], index[1] , 
             index[2], index[3] , 
             index[4], index[5] , 
             index[6], index[7] );
        u16_t out; wasm_v128_store( out.value, mem ); return out;
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
    
    inline u8_t add( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_add ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t sub( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_sub ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t mul( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] * B.value[x]; }); }

    inline u8_t div( const u8_t& A, const u8_t& B ) { return map_u8([&]( int x ){ return A.value[x] / B.value[x]; }); }

    /*─······································································─*/

    inline u8_t min( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_min ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t max( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_max ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u8_t cmplt( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_lt  ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t cmpeq( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_eq  ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t cmpgt( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_u8x16_gt  ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    /*─······································································─*/

    inline u8_t bit_and( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_and  ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t bit_or( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_or   ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t bit_xor( const u8_t& A, const u8_t& B ) {
        auto memA = wasm_v128_load ( A.value );
        auto memB = wasm_v128_load ( B.value );
        auto mem  = wasm_v128_xor  ( memA, memB );
        u8_t out  ; wasm_v128_store( out.value, mem ); return out;
    }

    inline u8_t bit_not( const u8_t& A ) { return bit_xor( A, set( (uchar_8) -1 ) ); }

    /*─······································································─*/

    inline u8_t select( const u8_t& mask, const u8_t& v_true, const u8_t& v_false ) {
        return bit_or( bit_and( mask, v_true ), bit_and( bit_not( mask ), v_false ) );
    }

    /*─······································································─*/

    inline u8_t bit_shl( const u8_t& A, int shift ) { return map_u8([&]( int x ){ return A.value[x] << shift; }); }
    inline u8_t bit_shr( const u8_t& A, int shift ) { return map_u8([&]( int x ){ return A.value[x] >> shift; }); }

    /*─······································································─*/

    template< ulong N=16 >
    inline u8_t shuffle( const u8_t& A, const u8_t& B, uchar (&index)[N] ) {
        auto memA = wasm_v128_load    ( A.value );
        auto memB = wasm_v128_load    ( B.value );
        auto mem  = wasm_u8x16_shuffle( memA, memB, 
             index[0] , index[1]  , 
             index[2] , index[3]  , 
             index[4] , index[5]  , 
             index[6] , index[7]  , 
             index[8] , index[9]  , 
             index[10], index[11] );
        u8_t out; wasm_v128_store( out.value, mem ); return out;
    }

}}}

/*────────────────────────────────────────────────────────────────────────────*/

#endif

/*────────────────────────────────────────────────────────────────────────────*/