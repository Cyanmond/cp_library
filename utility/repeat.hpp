#pragma once

#include <algorithm>

namespace cpl { 

namespace detail {
class range {
    struct iterator {
        int itr;
        constexpr iterator(const int pos) noexcept : itr(pos) {}
        constexpr void operator++() noexcept { ++itr; }
        constexpr bool operator!=(const iterator &other) const noexcept { return itr != other.itr; }
        constexpr int operator*() const noexcept { return itr; }
    };
    const iterator first, last;

  public:
    explicit constexpr range(const int f, const int l) noexcept : first(f), last(std::max(f, l)) {}
    constexpr iterator begin() const noexcept { return first; }
    constexpr iterator end() const noexcept { return last; }
};
} // namespace detail

constexpr detail::range rep(const int l, const int r) noexcept { return detail::range(l, r); }
constexpr detail::range rep(const int n) noexcept { return detail::range(0, n); }

namespace detail {
class reversed_range {
    struct iterator {
        int itr;
        constexpr iterator(const int pos) noexcept : itr(pos) {}
        constexpr void operator++() noexcept { --itr; }
        constexpr bool operator!=(const iterator &other) const noexcept { return itr != other.itr; }
        constexpr int operator*() const noexcept { return itr; }
    };
    const iterator first, last;

  public:
    explicit constexpr reversed_range(const int f, const int l) noexcept
        : first(l - 1), last(std::min(f, l) - 1) {}
    constexpr iterator begin() const noexcept { return first; }
    constexpr iterator end() const noexcept { return last; }
};
} // namespace detail

constexpr detail::reversed_range rev_rep(const int l, const int r) noexcept {
    return detail::reversed_range(l, r);
}
constexpr detail::reversed_range rev_rep(const int n) noexcept {
    return detail::reversed_range(0, n);
}

} // namespace cpl