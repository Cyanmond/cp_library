#pragma once
#include <limits>

namespace cpl {
template <typename T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max() / Div;
};