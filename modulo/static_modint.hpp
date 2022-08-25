#pragma once
#include "../utility/int_alias.hpp"
#include "utility.hpp"
#include <ostream>

namespace cpl {
template <int MOD> class static_modint {
    using self = static_modint;

    int value;

  public:
    static constexpr int mod() { return MOD; }
    template <typename T> static constexpr T normalize(const T x) {
        return rem_euclid<std::common_type_t<T, i64>>(x, MOD);
    }

    constexpr static_modint() noexcept : value(0) {}
    template <typename T> constexpr static_modint(const T v) : value(normalize(v)) {}
    static constexpr self raw(int v) {
        self x;
        x.value = v;
        return x;
    }

    constexpr int val() const noexcept { return value; }

    // pow, inv
    constexpr self pow(i64 exp) const noexcept {
        self ret(1), mul(*this);
        while (exp > 0) {
            if (exp & 1) ret *= mul;
            mul *= mul;
            exp >>= 1;
        }
        return ret;
    }

    constexpr self inv() {
        int a = value, b = MOD, u = 1, v = 0, t = 0;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return self(u);
    }

    constexpr self operator+() const noexcept { return *this; }
    constexpr self operator-() const noexcept { return raw(value == 0 ? 0 : MOD - value); }

    constexpr self &operator+=(const self &rhs) noexcept {
        value += rhs.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    constexpr self &operator-=(const self &rhs) noexcept {
        value -= rhs.value;
        if (value < 0) value += MOD;
        return *this;
    }
    constexpr self &operator*=(const self &rhs) noexcept {
        value = static_cast<int>(static_cast<i64>(value) * rhs.value % MOD);
        return *this;
    }
    constexpr self &operator/=(const self &rhs) noexcept {
        *this *= rhs.inv();
        return *this;
    }

    constexpr self operator+(const self &rhs) const noexcept { return self(*this) += rhs; }
    constexpr self operator-(const self &rhs) const noexcept { return self(*this) -= rhs; }
    constexpr self operator*(const self &rhs) const noexcept { return self(*this) *= rhs; }
    constexpr self operator/(const self &rhs) const noexcept { return self(*this) /= rhs; }

    constexpr bool operator==(const self &rhs) const noexcept { return value == rhs.value; }
    constexpr bool operator!=(const self &rhs) const noexcept { return value != rhs.value; }

    friend std::ostream &operator<<(std::ostream &stream, const self &rhs) {
        return stream << rhs.value;
    }
};

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
} // namespace cpl