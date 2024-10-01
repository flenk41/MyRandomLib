#ifndef RANDOM_LIB_H
#define RANDOM_LIB_H

#include <ctime>
#include <iostream>
#include <type_traits>
#include <cmath> // ��� std::round

// ���������� seed, ���������������� ���� ���
unsigned int seed = static_cast<unsigned int>(time(nullptr));

// ������� ��� ���������� �� ���� ������ ����� �������
float roundToTwoDecimals(float value) {
    return std::round(value * 100.0f) / 100.0f;
}

// ��������� ������� ��� ��������� ���������� �����
template <typename T>
T Random(const T min, const T max) {
    // ��������� ��������� ������������� ���������� (LCG)
    int long long a = 1664525;
    int long long c = 1013904223;
    int long long m = 4294967296;

    // ��������� ������ ���������� �����
    seed = (a * seed + c) % m;

    // ���� ��� ������ �������������
    if constexpr (std::is_integral<T>::value) {
        return min + (seed % (max - min + 1));
    }
    // ���� ��� ������ � ��������� ������
    else if constexpr (std::is_floating_point<T>::value) {
        float result = min + static_cast<float>(seed) / static_cast<float>(m) * (max - min);
        return roundToTwoDecimals(result); // ��������� �� ���� ������ ����� �������
    }
}
#endif // RANDOM_LIB_H