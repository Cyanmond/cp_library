#pragma once

namespace cpl {
template <typename T> constexpr T rem_euclid(T value, const T mod) {
    assert(mod > 0);
    value %= mod;
    return value >= 0 ? value : value + mod;
}
} // namespace cpl