//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// equal_to

#include <functional>
#include <type_traits>
#include <cassert>

int main()
{
    typedef std::equal_to<int> F;
    const F f = F();
    static_assert((std::is_base_of<std::binary_function<int, int, bool>, F>::value), "");
    assert(f(36, 36));
    assert(!f(36, 6));
#if _LIBCPP_STD_VER > 11
    typedef std::equal_to<> F2;
    const F2 f2 = F2();
    assert(f2(36, 36));
    assert(!f2(36, 6));
    assert(f2(36, 36.0));
    assert(f2(36.0, 36L));
#endif
}
