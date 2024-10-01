#ifndef RANDOM_LIB_H
#define RANDOM_LIB_H

#include <ctime>
#include <iostream>
#include <type_traits>
#include <cmath> // Для std::round

// Глобальный seed, инициализируемый один раз
unsigned int seed = static_cast<unsigned int>(time(nullptr));

// Функция для округления до двух знаков после запятой
float roundToTwoDecimals(float value) {
    return std::round(value * 100.0f) / 100.0f;
}

// Шаблонная функция для генерации случайного числа
template <typename T>
T Random(const T min, const T max) {
    // Параметры линейного конгруэнтного генератора (LCG)
    int long long a = 1664525;
    int long long c = 1013904223;
    int long long m = 4294967296;

    // Генерация нового случайного числа
    seed = (a * seed + c) % m;

    // Если тип данных целочисленный
    if constexpr (std::is_integral<T>::value) {
        return min + (seed % (max - min + 1));
    }
    // Если тип данных с плавающей точкой
    else if constexpr (std::is_floating_point<T>::value) {
        float result = min + static_cast<float>(seed) / static_cast<float>(m) * (max - min);
        return roundToTwoDecimals(result); // Округляем до двух знаков после запятой
    }
}
#endif // RANDOM_LIB_H