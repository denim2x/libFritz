#pragma once
#include <numeric>
#include <valarray>
#include "core.hpp"

typedef Vector<float> VectorF;

/**
 * Mutable Vector class of 4 elements (x, y, z, w)
 */
class Vector4 : public VectorF {

public:
  Vector4(float x, float y, float z, float w) : VectorF { x, y, z, w } { }
  Vector4(float value) : VectorF(value, 4) { }
  Vector4(fixed<Vector4> other) : VectorF(other) { }
  Vector4(Vector_fixed<float> other, float w) : 
    VectorF(other[0], other[1], other[2], w) { }

  inline Vector4 transform(fixed<Matrix4> matrix) const {
    let self = *this;
    Vector4 res(0);
    for (auto i = 0; i < 4; ++i) {
      for (auto j = 0; j < 4; ++j) {
        res[i] += self[j] * matrix[j][i];
      }
    }
    return res;
  }

  inline Vector4 lerp(fixed<Vector4> other, float blend) const {
    let self = *this;
    return (blend * (other - self)) + self;
  }

  inline VectorfF raw() {
    return static_cast<VectorF>(*this);
  }

  inline Vector4 apply(float func(float)) const {
    return Vector4(VectorF::apply(func));
  }

  inline Vector4 apply(float func(fixed<float>)) const {
    return Vector4(VectorF::apply(func));
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
  inline VectorF xyz() const {
    return (*this)[std::slice(0, 3, 1)];
  }

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

#pragma region Operators
#pragma region vector ~ vector
inline Vector4 operator+(fixed<Vector4> a, fixed<Vector4> b) {
  return Vector4(a.raw() + b.raw());
}
inline Vector4 operator-(fixed<Vector4> a, fixed<Vector4> b) {
  return Vector4(a.raw() - b.raw());
}
inline Vector4 operator*(fixed<Vector4> a, fixed<Vector4> b) {
  return Vector4(a.raw() * b.raw());
}
inline Vector4 operator/(fixed<Vector4> a, fixed<Vector4> b) {
  return Vector4(a.raw() / b.raw());
}
#pragma endregion
#pragma region scalar ~ vector
inline Vector4 operator+(float a, fixed<Vector4> b) {
  return Vector4(a + b.raw());
}
inline Vector4 operator-(float a, fixed<Vector4> b) {
  return Vector4(a - b.raw());
}
inline Vector4 operator*(float a, fixed<Vector4> b) {
  return Vector4(a * b.raw());
}
inline Vector4 operator/(float a, fixed<Vector4> b) {
  return Vector4(a / b.raw());
}
#pragma endregion
#pragma region vector ~ scalar
inline Vector4 operator+(fixed<Vector4> a, float b) {
  return Vector4(a.raw() + b);
}
inline Vector4 operator-(fixed<Vector4> a, float b) {
  return Vector4(a.raw() - b);
}
inline Vector4 operator*(fixed<Vector4> a, float b) {
  return Vector4(a.raw() * b);
}
inline Vector4 operator/(fixed<Vector4> a, float b) {
  return Vector4(a.raw() / b);
}
#pragma endregion
#pragma endregion
  
inline float dot(fixed<Vector4> a, fixed<Vector4> b) {
  return std::inner_product(std::begin(a), std::end(a), std::begin(b), 0);
}

inline Vector4 saturate(fixed<Vector4> vector) {
  return vector.apply(saturate);
}
