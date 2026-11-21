#include <nodepp/nodepp.h>
#include <simd/simd.h>

using namespace nodepp;

void onMain(){

    auto a = SIMD::u64::get   ({-10ULL,-10ULL});
    auto b = SIMD::u64::get   ({-20ULL,-10ULL});
    auto c = SIMD::u64::cmplt ( a, b );
    auto d = SIMD::u64::select( c, a, b );

    console::log( (char_64) d.value[0], (char_64) d.value[1] );

}