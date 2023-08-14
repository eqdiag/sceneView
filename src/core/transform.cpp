#include <glm/gtx/euler_angles.hpp>

#include "core/transform.h"




core::Transform::Transform(const glm::vec3& scale, const glm::vec3& rotation, const glm::vec3& translation):
	mScale{scale},mRotation{rotation},mTranslation{translation}
{
	computeMatrix();
}

core::Transform::Transform(const glm::mat4& matrix):
	mScale{glm::vec3(1.0f)},mRotation{glm::vec3(0.0f)},mTranslation{glm::vec3(0.0f)},mMatrix{matrix}
{
	
}


core::Transform::~Transform()
{
}

glm::mat4 core::Transform::getMatrix() const
{
	return mMatrix;
}

core::Transform core::Transform::getScaleComponent() const
{
	return Transform{ mScale };
}

core::Transform core::Transform::getRotationComponent() const
{
	return Transform{ glm::vec3(1.0),mRotation};
}

core::Transform core::Transform::getTranslationComponent() const
{
	return Transform{ glm::vec3(1.0),glm::vec3(0.0),mTranslation};
}

void core::Transform::setScale(const glm::vec3& scale)
{
	this->mScale = scale;
	computeMatrix();
}

void core::Transform::setRotation(const glm::vec3& rotation)
{
	this->mRotation = rotation;
	computeMatrix();
}

void core::Transform::setTranslation(const glm::vec3& translation)
{
	this->mTranslation = translation;
	computeMatrix();
}

void core::Transform::reset()
{
	mScale = glm::vec3(1.0f);
	mRotation = glm::vec3(0.0f);
	mTranslation = glm::vec3(0.0f);
	mMatrix = glm::mat4(1.0f);
}

core::Transform core::Transform::operator*(const Transform& rhs) const
{
	return Transform{mMatrix * rhs.getMatrix()};
}

core::Transform core::Transform::buildTranslation(const glm::vec3& v)
{
	return Transform{ glm::vec3{1.0f},glm::vec3(0.0f),v };
}

core::Transform core::Transform::buildScale(const glm::vec3& v)
{
	return Transform{ v,glm::vec3(0.0f),glm::vec3(0.0f)};
}

void core::Transform::computeMatrix()
{
	mMatrix =
		glm::translate(glm::mat4(1.0f), mTranslation) *
		glm::eulerAngleX(mRotation.x) *
		glm::eulerAngleY(mRotation.y) *
		glm::eulerAngleZ(mRotation.z) *
		glm::scale(glm::mat4(1.0f),mScale );
}
