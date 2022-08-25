---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: utility/repeat.hpp
    title: utility/repeat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/repeat.hpp\"\n\n#include <algorithm>\n\nnamespace\
    \ cpl { \n\nnamespace detail {\nclass range {\n    struct iterator {\n       \
    \ int itr;\n        constexpr iterator(const int pos) noexcept : itr(pos) {}\n\
    \        constexpr void operator++() noexcept { ++itr; }\n        constexpr bool\
    \ operator!=(const iterator &other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const iterator first, last;\n\n  public:\n    explicit constexpr range(const\
    \ int f, const int l) noexcept : first(f), last(std::max(f, l)) {}\n    constexpr\
    \ iterator begin() const noexcept { return first; }\n    constexpr iterator end()\
    \ const noexcept { return last; }\n};\n} // namespace detail\n\nconstexpr detail::range\
    \ rep(const int l, const int r) noexcept { return detail::range(l, r); }\nconstexpr\
    \ detail::range rep(const int n) noexcept { return detail::range(0, n); }\n\n\
    namespace detail {\nclass reversed_range {\n    struct iterator {\n        int\
    \ itr;\n        constexpr iterator(const int pos) noexcept : itr(pos) {}\n   \
    \     constexpr void operator++() noexcept { --itr; }\n        constexpr bool\
    \ operator!=(const iterator &other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const iterator first, last;\n\n  public:\n    explicit constexpr reversed_range(const\
    \ int f, const int l) noexcept\n        : first(l - 1), last(std::min(f, l) -\
    \ 1) {}\n    constexpr iterator begin() const noexcept { return first; }\n   \
    \ constexpr iterator end() const noexcept { return last; }\n};\n} // namespace\
    \ detail\n\nconstexpr detail::reversed_range rev_rep(const int l, const int r)\
    \ noexcept {\n    return detail::reversed_range(l, r);\n}\nconstexpr detail::reversed_range\
    \ rev_rep(const int n) noexcept {\n    return detail::reversed_range(0, n);\n\
    }\n\n} // namespace cpl\n#line 3 \"modulo/binomial.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace cpl {\ntemplate <class M> class fp_binomial {\n\
    \    static M fact(const int n) {\n        static std::vector<M> data;\n     \
    \   assert(n >= 0);\n        if (data.empty()) data = {M(1)};\n        for (const\
    \ int i : rep((int)data.size(), n + 1)) {\n            data.push_back(data.back()\
    \ * M(i));\n        }\n        return data[n];\n    }\n\n    static M inv(const\
    \ int n) {\n        static std::vector<M> data;\n        assert(n >= 0);\n   \
    \     if (data.empty()) data = {M(1)};\n        for (const int i : rep((int)data.size(),\
    \ n + 1)) {\n            data.push_back(-M(M::mod() / i) * data[M::mod() % i]);\n\
    \        }\n        return data[n];\n    }\n\n    static M inv_fact(const int\
    \ n) {\n        static std::vector<M> data;\n        assert(n >= 0);\n       \
    \ if (data.empty()) data = {M(1)};\n        for (const int i : rep((int)data.size(),\
    \ n + 1)) {\n            data.push_back(data.back() * inv(i));\n        }\n  \
    \      return data[n];\n    }\n\n    static M comb(const int n, const int r) {\n\
    \        assert(0 <= r and r <= n);\n        return fact(n) * inv_fact(r) * inv_fact(n\
    \ - r);\n    }\n\n    static M perm(const int n, const int r) {\n        assert(0\
    \ <= r and r <= n);\n        return fact(n) * inv_fact(n - r);\n    }\n\n    static\
    \ M homo(const int n, const int r) {\n        assert((n == 0 and r == 0) or (n\
    \ > 0 and k >= 0));\n        return comb(n + r - 1, r - 1);\n    }\n};\n} // namespace\
    \ cpl\n"
  code: "#pragma once\n#include \"../utility/repeat.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace cpl {\ntemplate <class M> class fp_binomial {\n    static\
    \ M fact(const int n) {\n        static std::vector<M> data;\n        assert(n\
    \ >= 0);\n        if (data.empty()) data = {M(1)};\n        for (const int i :\
    \ rep((int)data.size(), n + 1)) {\n            data.push_back(data.back() * M(i));\n\
    \        }\n        return data[n];\n    }\n\n    static M inv(const int n) {\n\
    \        static std::vector<M> data;\n        assert(n >= 0);\n        if (data.empty())\
    \ data = {M(1)};\n        for (const int i : rep((int)data.size(), n + 1)) {\n\
    \            data.push_back(-M(M::mod() / i) * data[M::mod() % i]);\n        }\n\
    \        return data[n];\n    }\n\n    static M inv_fact(const int n) {\n    \
    \    static std::vector<M> data;\n        assert(n >= 0);\n        if (data.empty())\
    \ data = {M(1)};\n        for (const int i : rep((int)data.size(), n + 1)) {\n\
    \            data.push_back(data.back() * inv(i));\n        }\n        return\
    \ data[n];\n    }\n\n    static M comb(const int n, const int r) {\n        assert(0\
    \ <= r and r <= n);\n        return fact(n) * inv_fact(r) * inv_fact(n - r);\n\
    \    }\n\n    static M perm(const int n, const int r) {\n        assert(0 <= r\
    \ and r <= n);\n        return fact(n) * inv_fact(n - r);\n    }\n\n    static\
    \ M homo(const int n, const int r) {\n        assert((n == 0 and r == 0) or (n\
    \ > 0 and k >= 0));\n        return comb(n + r - 1, r - 1);\n    }\n};\n} // namespace\
    \ cpl"
  dependsOn:
  - utility/repeat.hpp
  isVerificationFile: false
  path: modulo/binomial.hpp
  requiredBy: []
  timestamp: '2022-08-25 22:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/binomial.hpp
layout: document
redirect_from:
- /library/modulo/binomial.hpp
- /library/modulo/binomial.hpp.html
title: modulo/binomial.hpp
---
