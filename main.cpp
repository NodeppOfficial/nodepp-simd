#include <nodepp/nodepp.h>
#include <simd/simd.h>

using namespace nodepp;

void onMain(){

    auto a = SIMD::f32::get({-1 ,-1 ,-1 ,-1  });
    auto b = SIMD::f32::get({ 40, 30, 20, 10 });
    auto c = SIMD::f32::mul( a, b );

    console::log( c.value[0], c.value[1], c.value[2], c.value[3] );

}