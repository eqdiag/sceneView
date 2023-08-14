#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace core {

	class Transform {
	public:
		Transform(const glm::vec3& scale = glm::vec3(1.0f), const glm::vec3& rotation = glm::vec3(0.0f), const glm::vec3& translation = glm::vec3(0.0f));
		Transform(const glm::mat4& matrix);
		~Transform();

		glm::mat4 getMatrix() const;

		Transform getScaleComponent() const;
		Transform getRotationComponent() const;
		Transform getTranslationComponent() const;

		void setScale(const glm::vec3& scale);
		void setRotation(const glm::vec3& rotation);
		void setTranslation(const glm::vec3& translation);

		void reset();

		Transform operator*(const Transform& rhs) const;

		static Transform buildTranslation(const glm::vec3& v);
		static Transform buildScale(const glm::vec3& v);

	private:
		glm::vec3 mScale;
		glm::vec3 mRotation;
		glm::vec3 mTranslation;
		glm::mat4 mMatrix;

		void computeMatrix();
	};

}

#endif