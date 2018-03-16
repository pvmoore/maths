#pragma once
///
///	Currently supports float, double, int and unsigned int.
/// Add more types as needed.
///

#include <algorithm>

namespace maths {

template<typename T> struct matrix4;

template<typename T>
struct vector4 final {
	static_assert(std::is_arithmetic<T>::value);

	T x = 0, y = 0, z = 0, w = 0;
	vector4() = default;
	constexpr vector4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
	/// Copy constructors
	constexpr vector4(const vector4<int>& i) : x(T(i.x)), y(T(i.y)), z(T(i.z)), w(T(i.w)) {}
	constexpr vector4(const vector4<unsigned int>& i) : x(T(i.x)), y(T(i.y)), z(T(i.z)), w(T(i.w)) {}
	constexpr vector4(const vector4<float>& i) : x(T(i.x)), y(T(i.y)), z(T(i.z)), w(T(i.w)) {}
	constexpr vector4(const vector4<double>& i) : x(T(i.x)), y(T(i.y)), z(T(i.z)), w(T(i.w)) {}

	constexpr T& operator[](unsigned int index) { 
		assert(index<4);
		T* p = (&x)+index;
		return *p; 
	}
	constexpr T operator[](unsigned int index) const {
		assert(index<4);
		const T* p = (&x) + index;
		return *p;
	}

	constexpr vector4 operator-() const {
		return {-x, -y, -z, -w};
	}
	constexpr vector4 operator+(T o) const {
		return {x + o, y + o, z + o, w + o};
	}
	constexpr vector4 operator+(const vector4& o) const {
		return {x + o.x, y + o.y, z + o.z, w + o.w};
	}
	constexpr vector4 operator-(T o) const {
		return {x - o, y - o, z - o, w - o};
	}
	constexpr vector4 operator-(const vector4& o) const {
		return {x - o.x, y - o.y, z - o.z, w - o.w};
	}
	constexpr vector4 operator*(T o) const {
		return {x*o, y*o, z*o, w*o};
	}
	constexpr vector4 operator*(const vector4& o) const {
		return {x*o.x, y*o.y, z*o.z, w*o.w};
	}
	constexpr vector4 operator/(T o) const {
		return {x / o, y / o, z / o, w / o};
	}
	constexpr vector4 operator/(const vector4& o) const {
		return {x / o.x, y / o.y, z / o.z, w / o.w};
	}

	constexpr vector4 operator*(const matrix4<T>& o) const {
		return {o[0].x * x + o[0].y * y + o[0].z * z + o[0].w * w,
			o[1].x * x + o[1].y * y + o[1].z * z + o[1].w * w,
			o[2].x * x + o[2].y * y + o[2].z * z + o[2].w * w,
			o[3].x * x + o[3].y * y + o[3].z * z + o[3].w * w};
	}

	constexpr vector4& operator+=(T o) {
		x += o; y += o; z += o; w += o;
		return *this;
	}
	constexpr vector4& operator+=(const vector4& o) {
		x += o.x; y += o.y; z += o.z; w += o.w;
		return *this;
	}
	constexpr vector4& operator-=(T o) {
		x -= o; y -= o; z -= o; w -= o;
		return *this;
	}
	constexpr vector4& operator-=(const vector4& o) {
		x -= o.x; y -= o.y; z -= o.z; w -= o.w;
		return *this;
	}
	constexpr vector4& operator*=(T o) {
		x *= o; y *= o; z *= o; w *= o;
		return *this;
	}
	constexpr vector4& operator*=(const vector4& o) {
		x *= o.x; y *= o.y; z *= o.z; w *= o.w;
		return *this;
	}
	constexpr vector4& operator/=(T o) {
		x /= o; y /= o; z /= o; w /= o;
		return *this;
	}
	constexpr vector4& operator/=(const vector4& o) {
		x /= o.x; y /= o.y; z /= o.z; w /= o.w;
		return *this;
	}

	constexpr bool operator==(const T o) const {
		return x == o && y == o && z == o && w==o;
	}
	constexpr bool operator==(const vector4& o) const {
		return x == o.x && y == o.y && z == o.z && w==o.w;
	}
	constexpr bool operator!=(const T o) const {
		return !operator==(o);
	}
	constexpr bool operator!=(const vector4& o) const {
		return !operator==(o);
	}
	constexpr bool approx(const vector4& o) const {
		return approxEqual(x, o.x) && approxEqual(y, o.y) &&
			   approxEqual(z, o.z) && approxEqual(w, o.w);
	}

	constexpr bool anyLT(T v) const { return x<v || y<v || z<v || w<v; }
	constexpr bool anyLTE(T v) const { return x <= v || y <= v || z <= v || w <= v; }
	constexpr bool anyGT(T v) const { return x>v || y>v || z>v || w>v; }
	constexpr bool anyGTE(T v) const { return x >= v || y >= v || z >= v || w >= v; }
	constexpr bool anyLT(const vector4& v) const { return x<v.x || y<v.y || z<v.z || w<v.w; }
	constexpr bool anyLTE(const vector4& v) const { return x <= v.x || y <= v.y || z <= v.z || w <= v.w; }
	constexpr bool anyGT(const vector4& v) const { return x>v.x || y>v.y || z>v.z || w>v.w; }
	constexpr bool anyGTE(const vector4& v) const { return x >= v.x || y >= v.y || z >= v.z || w >= v.w; }

	constexpr bool allLT(T v) const { return x<v && y<v && z<v && w<v; }
	constexpr bool allLTE(T v) const { return x <= v && y <= v && z <= v && w <= v; }
	constexpr bool allGT(T v) const { return x>v && y>v && z>v && w>v; }
	constexpr bool allGTE(T v) const { return x >= v && y >= v && z >= v && w >= v; }
	constexpr bool allLT(const vector4& v) const { return x<v.x && y<v.y && z<v.z && w<v.w; }
	constexpr bool allLTE(const vector4& v) const { return x <= v.x && y <= v.y && z <= v.z && w <= v.w; }
	constexpr bool allGT(const vector4& v) const { return x>v.x && y>v.y && z>v.z && w>v.w; }
	constexpr bool allGTE(const vector4& v) const { return x >= v.x && y >= v.y && z >= v.z && w >= v.w; }

	constexpr T hadd() const { return x + y + z + w; }
	constexpr T hmul() const { return x * y * z * w; }

	vector4 floor() const {
		return {(T)::floor(x), (T)::floor(y), (T)::floor(z), (T)::floor(w)};
	}
	vector4 ceil() const {
		return {(T)::ceil(x), (T)::ceil(y), (T)::ceil(z), (T)::ceil(w)};
	}

	T min() const { return std::min({x, y, z, w}); }
	T max() const { return std::max({x, y, z, w}); }

	vector4 min(const vector4& o) const {
		return {std::min(x, o.x), std::min(y, o.y), std::min(z, o.z), std::min(w, o.w)};
	}
	vector4 max(const vector4& o) const {
		return {std::max(x, o.x), std::max(y, o.y), std::max(z, o.z), std::max(w, o.w)};
	}

	T dot(const vector4& o) const {
		return {x*o.x + y*o.y + z*o.z + w*o.w};
	}
	T length() const {
		return sqrt(lengthSquared());
	}
	T lengthSquared() const {
		return x*x + y*y + z*z + w*w;
	}
	T invLength() const {
		return 1 / length();
	}

	auto& normalise() {
		operator*=(invLength());
		return *this;
	}
	vector4 normalised() const {
		return operator*(invLength());
	}

	/// Returns 1/this
	vector4 reciprocal() const {
		return {1 / x, 1 / y, 1 / z, 1 / w};
	}

	vector4 abs() const {
		return {std::abs(x), std::abs(y), std::abs(z), std::abs(w)};
	}

	std::string toString() const {
		char buf[64];
		const char* fmt = nullptr;
		if constexpr(std::is_floating_point<T>::value) {
			fmt = "[%.3f, %.3f, %.3f, %.3f]";
		} else if constexpr(std::is_signed<T>::value) {
			if constexpr(sizeof(T) == 8) {
				fmt = "[%lld, %lld, %lld, %lld]";
			} else {
				fmt = "[%d, %d, %d, %d]";
			}
		} else if constexpr(sizeof(T) == 8) {
			fmt = "[%llu, %llu, %llu, %llu]";
		} else {
			fmt = "[%u, %u, %u, %u]";
		}
		sprintf_s(buf, fmt, x, y, z, w);
		return std::string(buf);
	}
};

typedef vector4<int> int4;
typedef vector4<unsigned int> uint4;
typedef vector4<float> float4;
typedef vector4<double> double4;

}