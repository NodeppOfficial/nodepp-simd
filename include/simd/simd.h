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

#if SIMD_ENGINE == SIMD_WASM
    #include <emscripten.h>
    #include <wasm_simd128.h>
    #include "macro.h"
    #include "wasm.h"
#elif SIMD_ENGINE == SIMD_ARM
    #include <arm_neon.h>
    #include "macro.h"
    #include "arm.h"
#elif SIMD_ENGINE == SIMD_X86
    #include <immintrin.h>
    #include "macro.h"
    #include "x86.h"
#else
    #include "macro.h"
    #include "none.h"
#endif

/*────────────────────────────────────────────────────────────────────────────*/

#endif

/*────────────────────────────────────────────────────────────────────────────*/