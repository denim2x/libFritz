#pragma once
#include <cmath>
#include <cstdint>
#include <array>
#include <valarray>
#include <vector>
#include <algorithm>

#define var auto&
#define let auto&&

#define accessor(T, N)                \
  inline T N() const {                \
    return _##N;                      \
  }

#define _accessor_(T, N)              \
  inline fixed<T> N() const {         \
    return _##N;                      \
  }
  
inline float saturate(float value) {
  return std::clamp(value, 0, 1);
}

typedef uint8_t byte;

inline int ceil(float value) {
  return (int)std::ceil(value);
}

template<typename T>
using ref = T&&;

template<typename T>
using fixed = const T&;

#pragma region Array
template<typename T, size_t N>
using Array = std::array<T, N>;

template<typename T, size_t N>
using Array_ref = ref<Array<T, N>>;

template<typename T, size_t N>
using Array_fixed = fixed<Array<T, N>>;
#pragma endregion

#pragma region Vector
template<typename T>
using Vector = std::valarray<T>;

template<typename T>
using Vector_ref = ref<Vector<T>>;

template<typename T>
using Vector_fixed = fixed<Vector<T>>;
#pragma endregion

#pragma region List
template<typename T>
using List = std::vector<T>;

template<typename T>
using List_ref = ref<List<T>>;

template<typename T>
using List_fixed = fixed<List<T>>;
#pragma endregion
