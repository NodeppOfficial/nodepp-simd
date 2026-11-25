#include <nodepp/nodepp.h>
#include <simd/simd.h>

using namespace nodepp;

void onMain(){

    auto a = SIMD::f64::get   ({-20, 20 });
    auto b = SIMD::f64::get   ({ 10, 10 });
    auto c = SIMD::f64::cmpgt ( a, b );
    auto d = SIMD::f64::select( c, a, b );

    console::log( ">>", d.value[0], d.value[1] );

}