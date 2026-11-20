#ifndef NODEPP_SIMD
#define NODEPP_SIMD

/*────────────────────────────────────────────────────────────────────────────*/

#include <nodepp/nodepp.h>
#include <cmath>

/*────────────────────────────────────────────────────────────────────────────*/

#define SIMD_ARM  3
#define SIMD_X86  2
#define SIMD_WASM 1
#define SIMD_NONE 0

/*────────────────────────────────────────────────────────────────────────────*/

#ifndef SIMD_ENGINE
#if NODEPP_ARCH == NODEPP_ARCH_CPU_64 || NODEPP_ARCH == NODEPP_ARCH_CPU_32
    #define SIMD_ENGINE SIMD_X86
#elif NODEPP_ARCH == NODEPP_ARCH_ARM_32 || NODEPP_ARCH == NODEPP_ARCH_ARM_64
    #define SIMD_ENGINE SIMD_ARM
#elif NODEPP_KERNEL == NODEPP_KERNEL_WASM
    #define SIMD_ENGINE SIMD_WASM
#else
    #define SIMD_ENGINE SIMD_NONE
#endif
#endif

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD { 
    struct f64_t { double   value[2] ; };
    struct f32_t { float    value[4] ; };
    struct u64_t { uchar_64 value[2] ; };
    struct u32_t { uchar_32 value[4] ; };
    struct u16_t { uchar_16 value[8] ; };
    struct u8_t  { uchar_8  value[16]; };
}}

/*────────────────────────────────────────────────────────────────────────────*/

namespace nodepp { namespace SIMD {
    f64_t map_f64( function_t<double  ,int> cb ){ f64_t out; for( int x=0; x<2 ; x++ ){ out.value[x]=cb(x); } return out; }
    f32_t map_f32( function_t<float   ,int> cb ){ f32_t out; for( int x=0; x<4 ; x++ ){ out.value[x]=cb(x); } return out; }
    u64_t map_u64( function_t<uchar_64,int> cb ){ u64_t out; for( int x=0; x<2 ; x++ ){ out.value[x]=cb(x); } return out; }
    u32_t map_u32( function_t<uchar_32,int> cb ){ u32_t out; for( int x=0; x<4 ; x++ ){ out.value[x]=cb(x); } return out; }
    u16_t map_u16( function_t<uchar_16,int> cb ){ u16_t out; for( int x=0; x<8 ; x++ ){ out.value[x]=cb(x); } return out; }
    u8_t  map_u8 ( function_t<uchar_8 ,int> cb ){ u8_t  out; for( int x=0; x<16; x++ ){ out.value[x]=cb(x); } return out; }
}}

/*────────────────────────────────────────────────────────────────────────────*/

#if SIMD_ENGINE == SIMD_WASM
    #include <emscripten.h>
    #include <wasm_simd128.h>
    #include "wasm.h"
#elif SIMD_ENGINE == SIMD_ARM
    #include <arm_neon.h>
    #include "arm.h"
#elif SIMD_ENGINE == SIMD_X86
    #include <immintrin.h>
    #include "x86.h"
#else
    #include "none.h"
#endif

/*────────────────────────────────────────────────────────────────────────────*/

#endif

/*────────────────────────────────────────────────────────────────────────────*/