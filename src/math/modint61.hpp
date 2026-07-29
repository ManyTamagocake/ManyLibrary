#include <cstdint>
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
