#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace MgMath
{
	const double PI = 3.141592653589793238;

	float Radians(float degrees);
	float Degrees(float radians);

	class MgVec
	{
	public:
		virtual float magnitude() = 0;
		virtual void normalize() = 0;
		virtual float* data() = 0;

		virtual float getX() = 0;
		virtual float getY() = 0;

		virtual void setX(float x) = 0;
		virtual void setY(float y) = 0;
	};

	class MgVec2 : public MgVec
	{
	public:
		MgVec2();
		MgVec2(float x, float y);
		MgVec2(glm::vec2 vec);

		float magnitude();
		void normalize();
		float* data();

		float getX();
		float getY();
		glm::vec2 getMVec();
		MgVec2 getNormalized();

		void setX(float x);
		void setY(float y);
		
		friend float Dot(const MgVec2& vec1, const MgVec2& vec2);

		MgVec2 operator+(const MgVec2& vec);
		MgVec2 operator-(const MgVec2& vec);
		MgVec2 operator*(const float& scalar);

	private:
		glm::vec2 m_vec;
	};

	class MgVec3 : public MgVec
	{
	public:
		MgVec3();
		MgVec3(float x, float y, float z);
		MgVec3(glm::vec3 vec);

		float magnitude();
		void normalize();
		float* data();

		float getX();
		float getY();
		float getZ();
		glm::vec3 getMVec();
		MgVec3 getNormalized();

		void setX(float x);
		void setY(float y);
		void setZ(float z);

		friend MgVec3 Cross(const MgVec3& vec1, const MgVec3& vec2);
		friend float Dot(const MgVec3& vec1, const MgVec3& vec2);

		MgVec3 operator+(const MgVec3& vec);
		MgVec3 operator-(const MgVec3& vec);
		MgVec3 operator*(const float& scalar);

	private:
		glm::vec3 m_vec;
	};

	class MgVec4 : public MgVec
	{
	public:
		MgVec4();
		MgVec4(float x, float y, float z, float w);
		MgVec4(glm::vec4 vec);

		float magnitude();
		void normalize();
		float* data();

		float getX();
		float getY();
		float getZ();
		float getW();
		glm::vec4 getMVec();
		MgVec4 getNormalized();

		void setX(float x);
		void setY(float y);
		void setZ(float z);
		void setW(float w);

		friend float Dot(const MgVec4& vec1, const MgVec4& vec2);

		MgVec4 operator+(const MgVec4& vec);
		MgVec4 operator-(const MgVec4& vec);
		MgVec4 operator*(const float& scalar);

	private:
		glm::vec4 m_vec;
	};

	MgVec3 Cross(const MgVec3& vec1, const MgVec3& vec2);
	float Dot(const MgVec2& vec1, const MgVec2& vec2);
	float Dot(const MgVec3& vec1, const MgVec3& vec2);
	float Dot(const MgVec4& vec1, const MgVec4& vec2);

	class MgMat
	{
		virtual float* data() = 0;
	};

	class MgMat2x2 : public MgMat
	{
	public:
		MgMat2x2();
		MgMat2x2(float scalar);
		MgMat2x2(glm::mat2x2 mat);

		glm::mat2x2 getMMat();

		float* data();

		MgMat2x2 operator+(const MgMat2x2& mat);
		MgMat2x2 operator-(const MgMat2x2& mat);

		static MgMat2x2 Identity();

	private:
		glm::mat2x2 m_mat;
	};

	class MgMat2x3 : public MgMat
	{
	public:
		MgMat2x3();
		MgMat2x3(float scalar);
		MgMat2x3(glm::mat2x3 mat);

		glm::mat2x3 getMMat();

		float* data();

		MgMat2x3 operator+(const MgMat2x3& mat);
		MgMat2x3 operator-(const MgMat2x3& mat);

		static MgMat2x3 Identity();

	private:
		glm::mat2x3 m_mat;
	};

	class MgMat2x4 : public MgMat
	{
	public:
		MgMat2x4();
		MgMat2x4(float scalar);
		MgMat2x4(glm::mat2x4 mat);

		glm::mat2x4 getMMat();

		float* data();

		MgMat2x4 operator+(const MgMat2x4& mat);
		MgMat2x4 operator-(const MgMat2x4& mat);

		static MgMat2x4 Identity();

	private:
		glm::mat2x4 m_mat;
	};

	class MgMat3x2 : public MgMat
	{
	public:
		MgMat3x2();
		MgMat3x2(float scalar);
		MgMat3x2(glm::mat3x2 mat);

		glm::mat3x2 getMMat();

		float* data();

		MgMat3x2 operator+(const MgMat3x2& mat);
		MgMat3x2 operator-(const MgMat3x2& mat);

		static MgMat3x2 Identity();

	private:
		glm::mat3x2 m_mat;
	};

	class MgMat3x3 : public MgMat
	{
	public:
		MgMat3x3();
		MgMat3x3(float scalar);
		MgMat3x3(glm::mat3x3 mat);

		glm::mat3x3 getMMat();

		float* data();

		MgMat3x3 operator+(const MgMat3x3& mat);
		MgMat3x3 operator-(const MgMat3x3& mat);

		static MgMat3x3 Identity();

	private:
		glm::mat3x3 m_mat;
	};

	class MgMat3x4 : public MgMat
	{
	public:
		MgMat3x4();
		MgMat3x4(float scalar);
		MgMat3x4(glm::mat3x4 mat);

		glm::mat3x4 getMMat();

		float* data();

		MgMat3x4 operator+(const MgMat3x4& mat);
		MgMat3x4 operator-(const MgMat3x4& mat);

		static MgMat3x4 Identity();

	private:
		glm::mat3x4 m_mat;
	};

	class MgMat4x2 : public MgMat
	{
	public:
		MgMat4x2();
		MgMat4x2(float scalar);
		MgMat4x2(glm::mat4x2 mat);

		glm::mat4x2 getMMat();

		float* data();

		MgMat4x2 operator+(const MgMat4x2& mat);
		MgMat4x2 operator-(const MgMat4x2& mat);

		static MgMat4x2 Identity();

	private:
		glm::mat4x2 m_mat;
	};

	class MgMat4x3 : public MgMat
	{
	public:
		MgMat4x3();
		MgMat4x3(float scalar);
		MgMat4x3(glm::mat4x3 mat);

		glm::mat4x3 getMMat();

		float* data();

		MgMat4x3 operator+(const MgMat4x3& mat);
		MgMat4x3 operator-(const MgMat4x3& mat);

		static MgMat4x3 Identity();

	private:
		glm::mat4x3 m_mat;
	};

	class MgMat4x4 : public MgMat
	{
	public:
		MgMat4x4();
		MgMat4x4(float scalar);
		MgMat4x4(glm::mat4x4 mat);

		glm::mat4x4 getMMat();

		float* data();

		MgMat4x4 operator+(const MgMat4x4& mat);
		MgMat4x4 operator-(const MgMat4x4& mat);

		static MgMat4x4 Identity();

	private:
		glm::mat4x4 m_mat;
	};

	MgMat2x2 operator*(MgMat2x2& mat1, MgMat2x2& mat2);
	MgMat2x2 operator*(MgMat2x3& mat1, MgMat3x2& mat2);
	MgMat2x2 operator*(MgMat2x4& mat1, MgMat4x2& mat2);

	MgMat3x3 operator*(MgMat3x2& mat1, MgMat2x3& mat2);
	MgMat3x3 operator*(MgMat3x3& mat1, MgMat3x3& mat2);
	MgMat3x3 operator*(MgMat3x4& mat1, MgMat4x3& mat2);

	MgMat4x4 operator*(MgMat4x2& mat1, MgMat2x4& mat2);
	MgMat4x4 operator*(MgMat4x3& mat1, MgMat3x4& mat2);
	MgMat4x4 operator*(MgMat4x4& mat1, MgMat4x4& mat2);


	MgVec2 operator*(MgMat2x2& mat, MgVec2& vec);
	MgVec2 operator*(MgMat2x3& mat, MgVec3& vec);
	MgVec2 operator*(MgMat2x4& mat, MgVec4& vec);

	MgVec3 operator*(MgMat3x3& mat, MgVec3& vec);
	MgVec3 operator*(MgMat3x4& mat, MgVec4& vec);

	MgVec4 operator*(MgMat4x4& mat, MgVec4& vec);


	typedef MgMat2x2 MgMat2;
	typedef MgMat3x3 MgMat3;
	typedef MgMat4x4 MgMat4;
}
