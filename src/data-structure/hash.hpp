#include <cstdint>
#include <vector>
#include <string>
#include <random>
using namespace std;

class ModInt61 {
private:
    static constexpr uint64_t MOD = (1ULL << 61) - 1;
    uint64_t _value;

public:
    ModInt61() : _value() {};
    ModInt61(long long value) {
        _value = ((value % (long long)MOD) + MOD) % MOD;
    }

    uint64_t val() const {
        return _value;
    }

    ModInt61& operator++() {
        _value++;
        if (_value == MOD) {
            _value = 0;
        }
        return *this;
    }
    ModInt61 operator++(int) {
        ModInt61 result = *this;
        ++(*this);
        return result;
    }
    ModInt61& operator--() {
        if (_value == 0) {
            _value = MOD;
        }
        _value--;
        return *this;
    }
    ModInt61 operator--(int) {
        ModInt61 result = *this;
        --(*this);
        return result;
    }

    ModInt61& operator+=(const ModInt61& other) {
        _value += other._value;
        if (_value >= MOD) {
            _value -= MOD;
        }
        return *this;
    }
    ModInt61& operator-=(const ModInt61& other) {
        if (_value < other._value) {
            _value += MOD;
        }
        _value -= other._value;
        return *this;
    }
    ModInt61& operator*=(const ModInt61& other) {
        __uint128_t product = (__uint128_t)_value * other._value;
        uint64_t upper = (uint64_t)(product >> 61);
        uint64_t lower = (uint64_t)(product & MOD);
        _value = upper + lower;
        if (_value >= MOD) {
            _value -= MOD;
        }
        return *this;
    }

    ModInt61 operator+() const {
        return *this;
    }
    ModInt61 operator-() const {
        return ModInt61() -= *this;
    }

    bool operator==(const ModInt61& other) const {
        return _value == other._value;
    }
    bool operator!=(const ModInt61& other) const {
        return _value != other._value;
    }

    ModInt61 pow(long long n) const {
        ModInt61 result = 1;
        ModInt61 current_base = _value;
        while (n > 0) {
            if (n % 2 == 1) {
                result *= current_base;
            }
            current_base *= current_base;
            n /= 2;
        }
        return result;
    }

    ModInt61 inv() const {
        return pow(MOD - 2);
    }
};

ModInt61 operator+(const ModInt61& left_hand_side, const ModInt61& right_hand_side) {
    return ModInt61(left_hand_side) += right_hand_side;
}
ModInt61 operator-(const ModInt61& left_hand_side, const ModInt61& right_hand_side) {
    return ModInt61(left_hand_side) -= right_hand_side;
}
ModInt61 operator*(const ModInt61& left_hand_side, const ModInt61& right_hand_side) {
    return ModInt61(left_hand_side) *= right_hand_side;
}

template <class T, ModInt61 (*h)(T)>
class RollingHash {
private:
    inline static ModInt61 _base;
    inline static vector<ModInt61> _base_pow;
    vector<ModInt61> _prefix_hash;

public:
    static void Init(const int max_size, const int base = 27) {
        _base = base;
        _base_pow.resize(max_size + 1);
        _base_pow[0] = 1;
        for (int i = 1; i <= max_size; i++) {
            _base_pow[i] = _base_pow[i - 1] * _base;
        }
        return;
    }
    static void RandomBasehInit(const int max_size, const int base_lower, const int base_upper) {
        random_device rd;
        mt19937_64 rng(rd());
        Init(max_size, (int)rng() % (base_upper - base_lower) + base_lower);
    }

    RollingHash() {}
    RollingHash(const vector<T>& s) {
        _prefix_hash.resize(s.size() + 1);
        _prefix_hash[0] = 0;
        for (size_t i = 1; i <= s.size(); i++) {
            _prefix_hash[i] = _prefix_hash[i - 1] * _base + h(s[i - 1]);
        }
        return;
    }
    RollingHash(const string& s) {
        _prefix_hash.resize(s.size() + 1);
        _prefix_hash[0] = 0;
        for (size_t i = 1; i <= s.size(); i++) {
            _prefix_hash[i] = _prefix_hash[i - 1] * _base + h(s[i - 1]);
        }
        return;
    }

    ModInt61 get(const int left, const int right) const {
        return _prefix_hash[right] - _prefix_hash[left] * _base_pow[right - left];
    }
};

ModInt61 h(char c) {
    return c - 'a' + 1;
}
