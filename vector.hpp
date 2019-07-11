#pragma once
#include <numeric>
#include "core.hpp"

/**
 * Mutable Vector class of 4 elements (x, y, z, w)
 */
class Vector4 : public Vector<float> {
  
public:
  Vector4(float x, float y, float z, float w) : Vector<float> { x, y, z, w } { }
  Vector4(float value) : Vector<float>(value, 4) { }
  Vector4(fixed<Vector4> other) : Vector<float>(other) { }
  
  static inline float dot(fixed<Vector4> a, fixed<Vector4> b) {
    return std::inner_product(std::begin(a), std::end(a), std::begin(b), 0);
  }
  
#pragma region Mutators
  inline float x(float value) {
    return (*this)[0] = value;
  }
  
  inline float y(float value) {
    return (*this)[1] = value;
  }
  
  inline float z(float value) {
    return (*this)[2] = value;
  }
  
  inline float w(float value) {
    return (*this)[3] = value;
  }
#pragma endregion
  
#pragma region Accessors
  inline float x() const {
    return (*this)[0];
  }
  
  inline float y() const {
    return (*this)[1];
  }
  
  inline float z() const {
    return (*this)[2];
  }
  
  inline float w() const {
    return (*this)[3];
  }
#pragma endregion
};

Vector4 saturate(fixed<Vector4> vector) {
  return vector.apply(saturate);
}
