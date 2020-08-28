#pragma once

//Straight from the source XD

#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

class IntVector3
{
public:
	int x, y, z;

	IntVector3() : x(0), y(0), z(0) {}
	IntVector3(const IntVector3&) = default;
	IntVector3(int x, int y, int z) : x(x), y(y), z(z) {}

	static IntVector3 Make(int x, int y, int z)
	{
		IntVector3 v = { x, y, z };
		return v;
	}

	static int Dot(const IntVector3& a, const IntVector3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	IntVector3 operator+(const IntVector3& v) const { return Make(x + v.x, y + v.y, z + v.z); }
	IntVector3 operator-(const IntVector3& v) const { return Make(x - v.x, y - v.y, z - v.z); }
	IntVector3 operator*(const IntVector3& v) const { return Make(x * v.x, y * v.y, z * v.z); }
	IntVector3 operator/(const IntVector3& v) const { return Make(x / v.x, y / v.y, z / v.z); }

	IntVector3 operator+(int v) const { return Make(x + v, y + v, z + v); }
	IntVector3 operator-(int v) const { return Make(x - v, y - v, z - v); }
	IntVector3 operator*(int v) const { return Make(x * v, y * v, z * v); }
	IntVector3 operator/(int v) const { return Make(x / v, y / v, z / v); }

	IntVector3 operator-() const { return Make(-x, -y, -z); }

	bool operator==(const IntVector3& v) const { return x == v.x && y == v.y && z == v.z; }

	int GetManhattanLength() const
	{
		return std::max<int>(x, -x) + std::max<int>(y, -y) + std::max<int>(z, -z);
	}

	int GetChebyshevLength() const
	{
		return std::max<int>(std::max<int>(x, -x), std::max<int>(std::max<int>(y, -y), std::max<int>(z, -z)));
	}

	IntVector3& operator+=(const IntVector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	IntVector3& operator-=(const IntVector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	IntVector3& operator*=(const IntVector3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	IntVector3& operator/=(const IntVector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}

	IntVector3& operator+=(int v)
	{
		x += v;
		y += v;
		z += v;
		return *this;
	}

	IntVector3& operator-=(int v)
	{
		x -= v;
		y -= v;
		z -= v;
		return *this;
	}

	IntVector3& operator*=(int v)
	{
		x *= v;
		y *= v;
		z *= v;
		return *this;
	}

	IntVector3& operator/=(int v)
	{
		x /= v;
		y /= v;
		z /= v;
		return *this;
	}
};

class Vector2
{
public:
	float x, y;

	Vector2() : x(0), y(0) {}
	Vector2(const Vector2&) = default;
	Vector2(float x, float y) : x(x), y(y) {}

	static Vector2 Make(float x, float y)
	{
		Vector2 v = { x, y };
		return v;
	}

	Vector2 operator+(const Vector2& v) const { return Make(x + v.x, y + v.y); }
	Vector2 operator-(const Vector2& v) const { return Make(x - v.x, y - v.y); }
	Vector2 operator*(const Vector2& v) const { return Make(x * v.x, y * v.y); }
	Vector2 operator/(const Vector2& v) const { return Make(x / v.x, y / v.y); }

	Vector2 operator+(float v) const { return Make(x + v, y + v); }
	Vector2 operator-(float v) const { return Make(x - v, y - v); }
	Vector2 operator*(float v) const { return Make(x * v, y * v); }
	Vector2 operator/(float v) const { return Make(x / v, y / v); }

	Vector2 operator-() const { return Make(-x, -y); }
	bool operator==(const Vector2& v) const { return x == v.x && y == v.y; }

	Vector2& operator+=(const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& operator-=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2& operator*=(const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	Vector2& operator/=(const Vector2& v)
	{
		x /= v.x;
		y /= v.y;
		return *this;
	}

	Vector2& operator+=(float v)
	{
		x += v;
		y += v;
		return *this;
	}

	Vector2& operator-=(float v)
	{
		x -= v;
		y -= v;
		return *this;
	}

	Vector2& operator*=(float v)
	{
		x *= v;
		y *= v;
		return *this;
	}

	Vector2& operator/=(float v)
	{
		x /= v;
		y /= v;
		return *this;
	}

	static float Dot(const Vector2& a, const Vector2& b) { return a.x * b.x + a.y * b.y; }

	float GetPoweredLength() const { return x * x + y * y; }

	float GetLength() const { return sqrtf(GetPoweredLength()); }

	float GetManhattanLength() const { return fabsf(x) + fabsf(y); }

	float GetChebyshevLength() const { return std::max<float>(fabsf(x), fabsf(y)); }

	Vector2 Normalize() const
	{
		float scale = 1.f / GetLength();
		return Make(x * scale, y * scale);
	}

	Vector2 Floor() const { return Vector2(floorf(x), floorf(y)); }
};

class Vector3
{
public:
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}
	Vector3(const Vector3&) = default;
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	static Vector3 Make(float x, float y, float z)
	{
		Vector3 v = { x, y, z };
		return v;
	}

	Vector3 operator+(const Vector3& v) const { return Make(x + v.x, y + v.y, z + v.z); }
	Vector3 operator-(const Vector3& v) const { return Make(x - v.x, y - v.y, z - v.z); }
	Vector3 operator*(const Vector3& v) const { return Make(x * v.x, y * v.y, z * v.z); }
	Vector3 operator/(const Vector3& v) const { return Make(x / v.x, y / v.y, z / v.z); }

	Vector3 operator+(float v) const { return Make(x + v, y + v, z + v); }
	Vector3 operator-(float v) const { return Make(x - v, y - v, z - v); }
	Vector3 operator*(float v) const { return Make(x * v, y * v, z * v); }
	Vector3 operator/(float v) const { return Make(x / v, y / v, z / v); }

	Vector3 operator-() const { return Make(-x, -y, -z); }
	bool operator==(const Vector3& v) const { return x == v.x && y == v.y && z == v.z; }

	Vector3& operator+=(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3& operator-=(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3& operator*=(const Vector3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}

	Vector3& operator/=(const Vector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}

	Vector3& operator+=(float v)
	{
		x += v;
		y += v;
		z += v;
		return *this;
	}

	Vector3& operator-=(float v)
	{
		x -= v;
		y -= v;
		z -= v;
		return *this;
	}

	Vector3& operator*=(float v)
	{
		x *= v;
		y *= v;
		z *= v;
		return *this;
	}

	Vector3& operator/=(float v)
	{
		x /= v;
		y /= v;
		z /= v;
		return *this;
	}

	static float Dot(const Vector3& a, const Vector3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	static Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Make(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

	static Vector3 Normal(const Vector3& a, const Vector3& b, const Vector3& c)
	{
		return Cross(c - a, c - b).Normalize();
	}

	float GetPoweredLength() const { return x * x + y * y + z * z; }

	float GetLength() const { return sqrtf(GetPoweredLength()); }

	float GetManhattanLength() const { return fabsf(x) + fabsf(y) + fabsf(z); }

	float GetChebyshevLength() const
	{
		return std::max<float>(fabsf(x), std::max<float>(fabsf(y), fabsf(z)));
	}

	Vector3 Normalize() const
	{
		float scale = GetLength();
		if (scale != 0.f)
			scale = 1.f / scale;
		return Make(x * scale, y * scale, z * scale);
	}

	IntVector3 Floor() const
	{
		return IntVector3::Make((int)floorf(x), (int)floorf(y), (int)floorf(z));
	}

	Vector3 CrossProduct(const Vector3& arg)
	{
		return Vector3(y * arg.z - z * arg.y,
			z * arg.x - x * arg.z,
			x * arg.y - y * arg.x);
	}
};

class Vector4
{
public:
	float x, y, z, w;

	Vector4() : x(0), y(0), z(0), w(0) {}
	Vector4(const Vector4&) = default;
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	static Vector4 Make(float x, float y, float z, float w)
	{
		Vector4 v = { x, y, z, w };
		return v;
	}

	Vector4 operator+(const Vector4& v) const
	{
		return Make(x + v.x, y + v.y, z + v.z, w + v.w);
	}
	Vector4 operator-(const Vector4& v) const
	{
		return Make(x - v.x, y - v.y, z - v.z, w - v.w);
	}
	Vector4 operator*(const Vector4& v) const
	{
		return Make(x * v.x, y * v.y, z * v.z, w * v.w);
	}
	Vector4 operator/(const Vector4& v) const
	{
		return Make(x / v.x, y / v.y, z / v.z, w / v.w);
	}

	Vector4 operator+(float v) const { return Make(x + v, y + v, z + v, w + v); }
	Vector4 operator-(float v) const { return Make(x - v, y - v, z - v, w - v); }
	Vector4 operator*(float v) const { return Make(x * v, y * v, z * v, w * v); }
	Vector4 operator/(float v) const { return Make(x / v, y / v, z / v, w / v); }

	Vector4 operator-() const { return Make(-x, -y, -z, -w); }

	bool operator==(const Vector4& v) const
	{
		return x == v.x && y == v.y && z == v.z && w == v.w;
	}
	bool operator!=(const Vector4& v) const
	{
		return x != v.x || y != v.y || z != v.z || z != v.w;
	}

	Vector4& operator+=(const Vector4& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	Vector4& operator-=(const Vector4& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	Vector4& operator*=(const Vector4& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	Vector4& operator/=(const Vector4& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		w /= v.w;
		return *this;
	}

	Vector4& operator+=(float v)
	{
		x += v;
		y += v;
		z += v;
		w += v;
		return *this;
	}

	Vector4& operator-=(float v)
	{
		x -= v;
		y -= v;
		z -= v;
		w -= v;
		return *this;
	}

	Vector4& operator*=(float v)
	{
		x *= v;
		y *= v;
		z *= v;
		w *= v;
		return *this;
	}

	Vector4& operator/=(float v)
	{
		x /= v;
		y /= v;
		z /= v;
		w /= v;
		return *this;
	}

	static float Dot(const Vector4& a, const Vector4& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	float GetPoweredLength() const { return x * x + y * y + z * z + w * w; }

	float GetLength() const { return sqrtf(GetPoweredLength()); }

	float GetManhattanLength() const { return fabsf(x) + fabsf(y) + fabsf(z) + fabsf(w); }

	float GetChebyshevLength() const
	{
		return std::max<float>(std::max<float>(fabsf(x), std::max<float>(fabsf(y), fabsf(z))), fabsf(w));
	}

	Vector4 Normalize() const
	{
		float scale = 1.f / GetLength();
		return Make(x * scale, y * scale, z * scale, w * scale);
	}

	Vector3 GetXYZ() const { return Vector3::Make(x, y, z); }
};

inline Vector2 MakeVector2(float x, float y) { return Vector2::Make(x, y); }
inline Vector3 MakeVector3(float x, float y, float z) { return Vector3::Make(x, y, z); }
inline float DistanceVector2(Vector2 src, Vector2 dst)
{
	float distance;
	distance = sqrtf(powf(src.x - dst.x, 2) + powf(src.y - dst.y, 2));
	return distance;
}