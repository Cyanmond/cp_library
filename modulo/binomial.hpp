#pragma once
#include "../utility/repeat.hpp"
#include <cassert>
#include <vector>

namespace cpl {
template <class M> class fp_binomial {
    static M fact(const int n) {
        static std::vector<M> data;
        assert(n >= 0);
        if (data.empty()) data = {M(1)};
        for (const int i : rep((int)data.size(), n + 1)) {
            data.push_back(data.back() * M(i));
        }
        return data[n];
    }

    static M inv(const int n) {
        static std::vector<M> data;
        assert(n >= 0);
        if (data.empty()) data = {M(1)};
        for (const int i : rep((int)data.size(), n + 1)) {
            data.push_back(-M(M::mod() / i) * data[M::mod() % i]);
        }
        return data[n];
    }

    static M inv_fact(const int n) {
        static std::vector<M> data;
        assert(n >= 0);
        if (data.empty()) data = {M(1)};
        for (const int i : rep((int)data.size(), n + 1)) {
            data.push_back(data.back() * inv(i));
        }
        return data[n];
    }

    static M comb(const int n, const int r) {
        assert(0 <= r and r <= n);
        return fact(n) * inv_fact(r) * inv_fact(n - r);
    }

    static M perm(const int n, const int r) {
        assert(0 <= r and r <= n);
        return fact(n) * inv_fact(n - r);
    }

    static M homo(const int n, const int r) {
        assert((n == 0 and r == 0) or (n > 0 and k >= 0));
        return comb(n + r - 1, r - 1);
    }
};
} // namespace cpl