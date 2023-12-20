#include "MgMath.h"

using namespace MgMath;

MgVec2::MgVec2()
{
	m_vec = glm::vec2(0.0f, 0.0f);
}

MgVec2::MgVec2(float x, float y)
{
	m_vec = glm::vec2(x, y);
}

MgVec2::MgVec2(glm::vec2 vec)
{
	m_vec = vec;
}

float MgVec2::magnitude()
{
	return glm::length(m_vec);
}

void MgVec2::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* MgVec2::data()
{
	return glm::value_ptr(m_vec);
}

float MgVec2::getX()
{
	return m_vec.x;
}

float MgVec2::getY()
{
	return m_vec.y;
}

glm::vec2 MgVec2::getMVec()
{
	return m_vec;
}

MgVec2 MgVec2::getNormalized()
{
	return MgVec2(glm::normalize(m_vec));
}

void MgVec2::setX(float x)
{
	m_vec.x = x;
}

void MgVec2::setY(float y)
{
	m_vec.y = y;
}

MgVec2 MgVec2::operator+(const MgVec2& vec)
{
	return MgVec2(m_vec + vec.m_vec);
}

MgVec2 MgVec2::operator-(const MgVec2& vec)
{
	return MgVec2(m_vec - vec.m_vec);
}

MgVec2 MgVec2::operator*(const float& scalar)
{
	return MgVec2(m_vec * scalar);
}

MgVec3::MgVec3()
{
	m_vec = glm::vec3(0.0f, 0.0f, 0.0f);
}

MgVec3::MgVec3(float x, float y, float z)
{
	m_vec = glm::vec3(x, y, z);
}

MgVec3::MgVec3(glm::vec3 vec)
{
	m_vec = vec;
}

float MgVec3::magnitude()
{
	return glm::length(m_vec);
}

void MgVec3::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* MgVec3::data()
{
	return glm::value_ptr(m_vec);
}

float MgVec3::getX()
{
	return m_vec.x;
}

float MgVec3::getY()
{
	return m_vec.y;
}

float MgVec3::getZ()
{
	return m_vec.z;
}

glm::vec3 MgVec3::getMVec()
{
	return m_vec;
}

MgVec3 MgVec3::getNormalized()
{
	return MgVec3(glm::normalize(m_vec));
}

void MgVec3::setX(float x)
{
	m_vec.x = x;
}

void MgVec3::setY(float y)
{
	m_vec.y = y;
}

void MgVec3::setZ(float z)
{
	m_vec.z = z;
}

MgVec3 MgVec3::operator+(const MgVec3& vec)
{
	return MgVec3(m_vec + vec.m_vec);
}

MgVec3 MgVec3::operator-(const MgVec3& vec)
{
	return MgVec3(m_vec - vec.m_vec);
}

MgVec3 MgVec3::operator*(const float& scalar)
{
	return MgVec3(m_vec * scalar);
}

MgVec4::MgVec4()
{
	m_vec = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

MgVec4::MgVec4(float x, float y, float z, float w)
{
	m_vec = glm::vec4(x, y, z, w);
}

MgVec4::MgVec4(glm::vec4 vec)
{
	m_vec = vec;
}

float MgVec4::magnitude()
{
	return glm::length(m_vec);
}

void MgVec4::normalize()
{
	m_vec = glm::normalize(m_vec);
}

float* MgVec4::data()
{
	return glm::value_ptr(m_vec);
}

float MgVec4::getX()
{
	return m_vec.x;
}

float MgVec4::getY()
{
	return m_vec.y;
}

float MgVec4::getZ()
{
	return m_vec.z;
}

float MgVec4::getW()
{
	return m_vec.w;
}

glm::vec4 MgVec4::getMVec()
{
	return m_vec;
}

MgVec4 MgVec4::getNormalized()
{
	return MgVec4(glm::normalize(m_vec));
}

void MgVec4::setX(float x)
{
	m_vec.x = x;
}

void MgVec4::setY(float y)
{
	m_vec.y = y;
}

void MgVec4::setZ(float z)
{
	m_vec.z = z;
}

void MgVec4::setW(float w)
{
	m_vec.w = w;
}

MgVec4 MgVec4::operator+(const MgVec4& vec)
{
	return MgVec4(m_vec + vec.m_vec);
}

MgVec4 MgVec4::operator-(const MgVec4& vec)
{
	return MgVec4(m_vec - vec.m_vec);
}

MgVec4 MgVec4::operator*(const float& scalar)
{
	return MgVec4(m_vec * scalar);
}

MgVec3 MgMath::Cross(const MgVec3& vec1, const MgVec3& vec2)
{
	return MgVec3(glm::cross(vec1.m_vec, vec2.m_vec));
}

float MgMath::Dot(const MgVec2& vec1, const MgVec2& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

float MgMath::Dot(const MgVec3& vec1, const MgVec3& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

float MgMath::Dot(const MgVec4& vec1, const MgVec4& vec2)
{
	return glm::dot(vec1.m_vec, vec2.m_vec);
}

MgMat2x2::MgMat2x2()
{
	m_mat = glm::mat2x2(0.0f);
}

MgMat2x2::MgMat2x2(float scalar)
{
	m_mat = glm::mat2x2(scalar);
}

MgMat2x2::MgMat2x2(glm::mat2x2 mat)
{
	m_mat = mat;
}

glm::mat2x2 MgMat2x2::getMMat()
{
	return m_mat;
}

float* MgMat2x2::data()
{
	return glm::value_ptr(m_mat);
}

MgMat2x2 MgMat2x2::operator+(const MgMat2x2& mat)
{
	return MgMat2x2(m_mat + mat.m_mat);
}

MgMat2x2 MgMat2x2::operator-(const MgMat2x2& mat)
{
	return MgMat2x2(m_mat - mat.m_mat);
}

MgMat2x2 MgMat2x2::Identity()
{
	return MgMat2x2(1.0f);
}

MgMat2x3::MgMat2x3()
{
	m_mat = glm::mat2x3(0.0f);
}

MgMat2x3::MgMat2x3(float scalar)
{
	m_mat = glm::mat2x3(scalar);
}

MgMat2x3::MgMat2x3(glm::mat2x3 mat)
{
	m_mat = mat;
}

glm::mat2x3 MgMat2x3::getMMat()
{
	return m_mat;
}

float* MgMat2x3::data()
{
	return glm::value_ptr(m_mat);
}

MgMat2x3 MgMat2x3::operator+(const MgMat2x3& mat)
{
	return MgMat2x3(m_mat + mat.m_mat);
}

MgMat2x3 MgMat2x3::operator-(const MgMat2x3& mat)
{
	return MgMat2x3(m_mat - mat.m_mat);
}

MgMat2x3 MgMat2x3::Identity()
{
	return MgMat2x3(1.0f);
}

MgMat2x4::MgMat2x4()
{
	m_mat = glm::mat2x4(0.0f);
}

MgMat2x4::MgMat2x4(float scalar)
{
	m_mat = glm::mat2x4(scalar);
}

MgMat2x4::MgMat2x4(glm::mat2x4 mat)
{
	m_mat = mat;
}

glm::mat2x4 MgMat2x4::getMMat()
{
	return m_mat;
}

float* MgMat2x4::data()
{
	return glm::value_ptr(m_mat);
}

MgMat2x4 MgMat2x4::operator+(const MgMat2x4& mat)
{
	return MgMat2x4(m_mat + mat.m_mat);
}

MgMat2x4 MgMat2x4::operator-(const MgMat2x4& mat)
{
	return MgMat2x4(m_mat - mat.m_mat);
}

MgMat2x4 MgMat2x4::Identity()
{
	return MgMat2x4(1.0f);
}

MgMat3x2::MgMat3x2()
{
	m_mat = glm::mat3x2(0.0f);
}

MgMat3x2::MgMat3x2(float scalar)
{
	m_mat = glm::mat3x2(scalar);
}

MgMat3x2::MgMat3x2(glm::mat3x2 mat)
{
	m_mat = mat;
}

glm::mat3x2 MgMat3x2::getMMat()
{
	return m_mat;
}

float* MgMat3x2::data()
{
	return glm::value_ptr(m_mat);
}

MgMat3x2 MgMat3x2::operator+(const MgMat3x2& mat)
{
	return MgMat3x2(m_mat + mat.m_mat);
}

MgMat3x2 MgMat3x2::operator-(const MgMat3x2& mat)
{
	return MgMat3x2(m_mat - mat.m_mat);
}

MgMat3x2 MgMat3x2::Identity()
{
	return MgMat3x2(1.0f);
}

MgMat3x3::MgMat3x3()
{
	m_mat = glm::mat3x3(0.0f);
}

MgMat3x3::MgMat3x3(float scalar)
{
	m_mat = glm::mat3x3(scalar);
}

MgMat3x3::MgMat3x3(glm::mat3x3 mat)
{
	m_mat = mat;
}

glm::mat3x3 MgMat3x3::getMMat()
{
	return m_mat;
}

float* MgMat3x3::data()
{
	return glm::value_ptr(m_mat);
}

MgMat3x3 MgMat3x3::operator+(const MgMat3x3& mat)
{
	return MgMat3x3(m_mat + mat.m_mat);
}

MgMat3x3 MgMat3x3::operator-(const MgMat3x3& mat)
{
	return MgMat3x3(m_mat - mat.m_mat);
}

MgMat3x3 MgMat3x3::Identity()
{
	return MgMat3x3(1.0f);
}

MgMat3x4::MgMat3x4()
{
	m_mat = glm::mat3x4(0.0f);
}

MgMat3x4::MgMat3x4(float scalar)
{
	m_mat = glm::mat3x4(scalar);
}

MgMat3x4::MgMat3x4(glm::mat3x4 mat)
{
	m_mat = mat;
}

glm::mat3x4 MgMat3x4::getMMat()
{
	return m_mat;
}

float* MgMat3x4::data()
{
	return glm::value_ptr(m_mat);
}

MgMat3x4 MgMat3x4::operator+(const MgMat3x4& mat)
{
	return MgMat3x4(m_mat + mat.m_mat);
}

MgMat3x4 MgMat3x4::operator-(const MgMat3x4& mat)
{
	return MgMat3x4(m_mat - mat.m_mat);
}

MgMat3x4 MgMat3x4::Identity()
{
	return MgMat3x4(1.0f);
}

MgMat4x2::MgMat4x2()
{
	m_mat = glm::mat4x2(0.0f);
}

MgMat4x2::MgMat4x2(float scalar)
{
	m_mat = glm::mat4x2(scalar);
}

MgMat4x2::MgMat4x2(glm::mat4x2 mat)
{
	m_mat = mat;
}

glm::mat4x2 MgMat4x2::getMMat()
{
	return m_mat;
}

float* MgMat4x2::data()
{
	return glm::value_ptr(m_mat);
}

MgMat4x2 MgMat4x2::operator+(const MgMat4x2& mat)
{
	return MgMat4x2(m_mat + mat.m_mat);
}

MgMat4x2 MgMat4x2::operator-(const MgMat4x2& mat)
{
	return MgMat4x2(m_mat - mat.m_mat);
}

MgMat4x2 MgMat4x2::Identity()
{
	return MgMat4x2(1.0f);
}

MgMat4x3::MgMat4x3()
{
	m_mat = glm::mat4x3(0.0f);
}

MgMat4x3::MgMat4x3(float scalar)
{
	m_mat = glm::mat4x3(scalar);
}

MgMat4x3::MgMat4x3(glm::mat4x3 mat)
{
	m_mat = mat;
}

glm::mat4x3 MgMat4x3::getMMat()
{
	return m_mat;
}

float* MgMat4x3::data()
{
	return glm::value_ptr(m_mat);
}

MgMat4x3 MgMat4x3::operator+(const MgMat4x3& mat)
{
	return MgMat4x3(m_mat + mat.m_mat);
}

MgMat4x3 MgMat4x3::operator-(const MgMat4x3& mat)
{
	return MgMat4x3(m_mat - mat.m_mat);
}

MgMat4x3 MgMat4x3::Identity()
{
	return MgMat4x3(1.0f);
}

MgMat4x4::MgMat4x4()
{
	m_mat = glm::mat4x4(0.0f);
}

MgMat4x4::MgMat4x4(float scalar)
{
	m_mat = glm::mat4x4(scalar);
}

MgMat4x4::MgMat4x4(glm::mat4x4 mat)
{
	m_mat = mat;
}

glm::mat4x4 MgMat4x4::getMMat()
{
	return m_mat;
}

float* MgMat4x4::data()
{
	return glm::value_ptr(m_mat);
}

MgMat4x4 MgMat4x4::operator+(const MgMat4x4& mat)
{
	return MgMat4x4(m_mat + mat.m_mat);
}

MgMat4x4 MgMat4x4::operator-(const MgMat4x4& mat)
{
	return MgMat4x4(m_mat - mat.m_mat);
}

MgMat4x4 MgMat4x4::Identity()
{
	return MgMat4x4(1.0f);
}

MgMat2x2 MgMath::operator*(MgMat2x2& mat1, MgMat2x2& mat2)
{
	return MgMat2x2(mat1.getMMat() * mat2.getMMat());
}

MgMat2x2 MgMath::operator*(MgMat2x3& mat1, MgMat3x2& mat2)
{
	return MgMat2x2(mat1.getMMat() * mat2.getMMat());
}

MgMat2x2 MgMath::operator*(MgMat2x4& mat1, MgMat4x2& mat2)
{
	return MgMat2x2(mat1.getMMat() * mat2.getMMat());
}

MgMat3x3 MgMath::operator*(MgMat3x2& mat1, MgMat2x3& mat2)
{
	return MgMat3x3(mat1.getMMat() * mat2.getMMat());
}

MgMat3x3 MgMath::operator*(MgMat3x3& mat1, MgMat3x3& mat2)
{
	return MgMat3x3(mat1.getMMat() * mat2.getMMat());
}

MgMat3x3 MgMath::operator*(MgMat3x4& mat1, MgMat4x3& mat2)
{
	return MgMat3x3(mat1.getMMat() * mat2.getMMat());
}

MgMat4x4 MgMath::operator*(MgMat4x2& mat1, MgMat2x4& mat2)
{
	return MgMat4x4(mat1.getMMat() * mat2.getMMat());
}

MgMat4x4 MgMath::operator*(MgMat4x3& mat1, MgMat3x4& mat2)
{
	return MgMat4x4(mat1.getMMat() * mat2.getMMat());
}

MgMat4x4 MgMath::operator*(MgMat4x4& mat1, MgMat4x4& mat2)
{
	return MgMat4x4(mat1.getMMat() * mat2.getMMat());
}

MgVec2 MgMath::operator*(MgMat2x2& mat, MgVec2& vec)
{
	return MgVec2(mat.getMMat() * vec.getMVec());
}

MgVec2 MgMath::operator*(MgMat2x3& mat, MgVec3& vec)
{
	return MgVec2(mat.getMMat() * vec.getMVec());
}

MgVec2 MgMath::operator*(MgMat2x4& mat, MgVec4& vec)
{
	return MgVec2(mat.getMMat() * vec.getMVec());
}

MgVec3 MgMath::operator*(MgMat3x3& mat, MgVec3& vec)
{
	return MgVec3(mat.getMMat() * vec.getMVec());
}

MgVec3 MgMath::operator*(MgMat3x4& mat, MgVec4& vec)
{
	return MgVec3(mat.getMMat() * vec.getMVec());
}

MgVec4 MgMath::operator*(MgMat4x4& mat, MgVec4& vec)
{
	return MgVec4(mat.getMMat() * vec.getMVec());
}
