---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
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
    }\n\n} // namespace cpl\n"
  code: "#pragma once\n\n#include <algorithm>\n\nnamespace cpl { \n\nnamespace detail\
    \ {\nclass range {\n    struct iterator {\n        int itr;\n        constexpr\
    \ iterator(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { ++itr; }\n        constexpr bool operator!=(const iterator &other)\
    \ const noexcept { return itr != other.itr; }\n        constexpr int operator*()\
    \ const noexcept { return itr; }\n    };\n    const iterator first, last;\n\n\
    \  public:\n    explicit constexpr range(const int f, const int l) noexcept :\
    \ first(f), last(std::max(f, l)) {}\n    constexpr iterator begin() const noexcept\
    \ { return first; }\n    constexpr iterator end() const noexcept { return last;\
    \ }\n};\n} // namespace detail\n\nconstexpr detail::range rep(const int l, const\
    \ int r) noexcept { return detail::range(l, r); }\nconstexpr detail::range rep(const\
    \ int n) noexcept { return detail::range(0, n); }\n\nnamespace detail {\nclass\
    \ reversed_range {\n    struct iterator {\n        int itr;\n        constexpr\
    \ iterator(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { --itr; }\n        constexpr bool operator!=(const iterator &other)\
    \ const noexcept { return itr != other.itr; }\n        constexpr int operator*()\
    \ const noexcept { return itr; }\n    };\n    const iterator first, last;\n\n\
    \  public:\n    explicit constexpr reversed_range(const int f, const int l) noexcept\n\
    \        : first(l - 1), last(std::min(f, l) - 1) {}\n    constexpr iterator begin()\
    \ const noexcept { return first; }\n    constexpr iterator end() const noexcept\
    \ { return last; }\n};\n} // namespace detail\n\nconstexpr detail::reversed_range\
    \ rev_rep(const int l, const int r) noexcept {\n    return detail::reversed_range(l,\
    \ r);\n}\nconstexpr detail::reversed_range rev_rep(const int n) noexcept {\n \
    \   return detail::reversed_range(0, n);\n}\n\n} // namespace cpl"
  dependsOn: []
  isVerificationFile: false
  path: utility/repeat.hpp
  requiredBy:
  - modulo/binomial.hpp
  timestamp: '2022-08-25 22:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/repeat.hpp
layout: document
redirect_from:
- /library/utility/repeat.hpp
- /library/utility/repeat.hpp.html
title: utility/repeat.hpp
---
