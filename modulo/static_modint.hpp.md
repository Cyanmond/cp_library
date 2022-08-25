---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: modulo/utility.hpp
    title: modulo/utility.hpp
  - icon: ':warning:'
    path: utility/int_alias.hpp
    title: utility/int_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.hpp\"\n\nnamespace cpl {\nusing i16 =\
    \ int16_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\n\nusing llint = long long int;\n\
    using uint = unsigned int;\nusing ullint = unsigned long long int;\n} // namespace\
    \ cpl\n#line 2 \"modulo/utility.hpp\"\n#include <cassert>\n\nnamespace cpl {\n\
    template <typename T> constexpr T rem_euclid(T value, const T mod) {\n    assert(mod\
    \ > 0);\n    value %= mod;\n    return value >= 0 ? value : value + mod;\n}\n\
    } // namespace cpl\n#line 4 \"modulo/static_modint.hpp\"\n#include <ostream>\n\
    \nnamespace cpl {\ntemplate <int MOD> class static_modint {\n    using self =\
    \ static_modint;\n\n    int value;\n\n  public:\n    static constexpr int mod()\
    \ { return MOD; }\n    template <typename T> static constexpr T normalize(const\
    \ T x) {\n        return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n   \
    \ }\n\n    constexpr static_modint() noexcept : value(0) {}\n    template <typename\
    \ T> constexpr static_modint(const T v) : value(normalize(v)) {}\n    static constexpr\
    \ self raw(int v) {\n        self x;\n        x.value = v;\n        return x;\n\
    \    }\n\n    constexpr int val() const noexcept { return value; }\n\n    // pow,\
    \ inv\n    constexpr self pow(i64 exp) const noexcept {\n        self ret(1),\
    \ mul(*this);\n        while (exp > 0) {\n            if (exp & 1) ret *= mul;\n\
    \            mul *= mul;\n            exp >>= 1;\n        }\n        return ret;\n\
    \    }\n\n    constexpr self inv() {\n        int a = value, b = MOD, u = 1, v\
    \ = 0, t = 0;\n        while (b > 0) {\n            t = a / b;\n            std::swap(a\
    \ -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ self(u);\n    }\n\n    constexpr self operator+() const noexcept { return *this;\
    \ }\n    constexpr self operator-() const noexcept { return raw(value == 0 ? 0\
    \ : MOD - value); }\n\n    constexpr self &operator+=(const self &rhs) noexcept\
    \ {\n        value += rhs.value;\n        if (value >= MOD) value -= MOD;\n  \
    \      return *this;\n    }\n    constexpr self &operator-=(const self &rhs) noexcept\
    \ {\n        value -= rhs.value;\n        if (value < 0) value += MOD;\n     \
    \   return *this;\n    }\n    constexpr self &operator*=(const self &rhs) noexcept\
    \ {\n        value = static_cast<int>(static_cast<i64>(value) * rhs.value % MOD);\n\
    \        return *this;\n    }\n    constexpr self &operator/=(const self &rhs)\
    \ noexcept {\n        *this *= rhs.inv();\n        return *this;\n    }\n\n  \
    \  constexpr self operator+(const self &rhs) const noexcept { return self(*this)\
    \ += rhs; }\n    constexpr self operator-(const self &rhs) const noexcept { return\
    \ self(*this) -= rhs; }\n    constexpr self operator*(const self &rhs) const noexcept\
    \ { return self(*this) *= rhs; }\n    constexpr self operator/(const self &rhs)\
    \ const noexcept { return self(*this) /= rhs; }\n\n    constexpr bool operator==(const\
    \ self &rhs) const noexcept { return value == rhs.value; }\n    constexpr bool\
    \ operator!=(const self &rhs) const noexcept { return value != rhs.value; }\n\n\
    \    friend std::ostream &operator<<(std::ostream &stream, const self &rhs) {\n\
    \        return stream << rhs.value;\n    }\n};\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\n} // namespace cpl\n"
  code: "#pragma once\n#include \"../utility/int_alias.hpp\"\n#include \"utility.hpp\"\
    \n#include <ostream>\n\nnamespace cpl {\ntemplate <int MOD> class static_modint\
    \ {\n    using self = static_modint;\n\n    int value;\n\n  public:\n    static\
    \ constexpr int mod() { return MOD; }\n    template <typename T> static constexpr\
    \ T normalize(const T x) {\n        return rem_euclid<std::common_type_t<T, i64>>(x,\
    \ MOD);\n    }\n\n    constexpr static_modint() noexcept : value(0) {}\n    template\
    \ <typename T> constexpr static_modint(const T v) : value(normalize(v)) {}\n \
    \   static constexpr self raw(int v) {\n        self x;\n        x.value = v;\n\
    \        return x;\n    }\n\n    constexpr int val() const noexcept { return value;\
    \ }\n\n    // pow, inv\n    constexpr self pow(i64 exp) const noexcept {\n   \
    \     self ret(1), mul(*this);\n        while (exp > 0) {\n            if (exp\
    \ & 1) ret *= mul;\n            mul *= mul;\n            exp >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    constexpr self inv() {\n        int a = value,\
    \ b = MOD, u = 1, v = 0, t = 0;\n        while (b > 0) {\n            t = a /\
    \ b;\n            std::swap(a -= t * b, b);\n            std::swap(u -= t * v,\
    \ v);\n        }\n        return self(u);\n    }\n\n    constexpr self operator+()\
    \ const noexcept { return *this; }\n    constexpr self operator-() const noexcept\
    \ { return raw(value == 0 ? 0 : MOD - value); }\n\n    constexpr self &operator+=(const\
    \ self &rhs) noexcept {\n        value += rhs.value;\n        if (value >= MOD)\
    \ value -= MOD;\n        return *this;\n    }\n    constexpr self &operator-=(const\
    \ self &rhs) noexcept {\n        value -= rhs.value;\n        if (value < 0) value\
    \ += MOD;\n        return *this;\n    }\n    constexpr self &operator*=(const\
    \ self &rhs) noexcept {\n        value = static_cast<int>(static_cast<i64>(value)\
    \ * rhs.value % MOD);\n        return *this;\n    }\n    constexpr self &operator/=(const\
    \ self &rhs) noexcept {\n        *this *= rhs.inv();\n        return *this;\n\
    \    }\n\n    constexpr self operator+(const self &rhs) const noexcept { return\
    \ self(*this) += rhs; }\n    constexpr self operator-(const self &rhs) const noexcept\
    \ { return self(*this) -= rhs; }\n    constexpr self operator*(const self &rhs)\
    \ const noexcept { return self(*this) *= rhs; }\n    constexpr self operator/(const\
    \ self &rhs) const noexcept { return self(*this) /= rhs; }\n\n    constexpr bool\
    \ operator==(const self &rhs) const noexcept { return value == rhs.value; }\n\
    \    constexpr bool operator!=(const self &rhs) const noexcept { return value\
    \ != rhs.value; }\n\n    friend std::ostream &operator<<(std::ostream &stream,\
    \ const self &rhs) {\n        return stream << rhs.value;\n    }\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    } // namespace cpl"
  dependsOn:
  - utility/int_alias.hpp
  - modulo/utility.hpp
  isVerificationFile: false
  path: modulo/static_modint.hpp
  requiredBy: []
  timestamp: '2022-08-25 23:46:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/static_modint.hpp
layout: document
redirect_from:
- /library/modulo/static_modint.hpp
- /library/modulo/static_modint.hpp.html
title: modulo/static_modint.hpp
---
