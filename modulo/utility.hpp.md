---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: modulo/static_modint.hpp
    title: modulo/static_modint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/utility.hpp\"\n#include <cassert>\n\nnamespace cpl\
    \ {\ntemplate <typename T> constexpr T rem_euclid(T value, const T mod) {\n  \
    \  assert(mod > 0);\n    value %= mod;\n    return value >= 0 ? value : value\
    \ + mod;\n}\n} // namespace cpl\n"
  code: "#pragma once\n#include <cassert>\n\nnamespace cpl {\ntemplate <typename T>\
    \ constexpr T rem_euclid(T value, const T mod) {\n    assert(mod > 0);\n    value\
    \ %= mod;\n    return value >= 0 ? value : value + mod;\n}\n} // namespace cpl"
  dependsOn: []
  isVerificationFile: false
  path: modulo/utility.hpp
  requiredBy:
  - modulo/static_modint.hpp
  timestamp: '2022-08-25 23:46:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/utility.hpp
layout: document
redirect_from:
- /library/modulo/utility.hpp
- /library/modulo/utility.hpp.html
title: modulo/utility.hpp
---
