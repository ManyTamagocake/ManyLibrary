#include <cstdint>

uint64_t mod_prod(uint64_t a, uint64_t b, uint64_t mod) {
    return static_cast<uint64_t>((static_cast<__uint128_t>(a) * b) % mod);
}

uint64_t mod_pow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            res = mod_prod(res, base, mod);
        }
        base = mod_prod(base, base, mod);
        exp >>= 1;
    }
    return res;
}

bool is_prime(uint64_t n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || (n & 1) == 0) {
        return false;
    }
    const uint64_t n_minus_1 = n - 1;
    uint64_t d = n_minus_1;
    uint32_t s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    const uint64_t bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (uint64_t a : bases) {
        a %= n;
        if (a == 0) {
            continue;
        }
        uint64_t t = mod_pow(a, d, n);
        if (t == 1 || t == n_minus_1) {
            continue;
        }
        bool is_composite = true;
        for (uint32_t r = 1; r < s; ++r) {
            t = mod_prod(t, t, n);
            if (t == n_minus_1) {
                is_composite = false;
                break;
            }
        }
        if (is_composite) {
            return false;
        }
    }
    return true;
}