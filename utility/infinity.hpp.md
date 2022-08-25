---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/infinity.hpp"

    #include <limits>


    namespace cpl {

    template <typename T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max()
    / Div;

    };

    '
  code: '#pragma once

    #include <limits>


    namespace cpl {

    template <typename T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max()
    / Div;

    };'
  dependsOn: []
  isVerificationFile: false
  path: utility/infinity.hpp
  requiredBy: []
  timestamp: '2022-08-25 22:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/infinity.hpp
layout: document
redirect_from:
- /library/utility/infinity.hpp
- /library/utility/infinity.hpp.html
title: utility/infinity.hpp
---
