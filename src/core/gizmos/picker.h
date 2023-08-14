#ifndef PICKER_H
#define PICKER_H

#include <memory>

#include "core/gizmo.h"
#include "core/mesh.h"
#include "core/camera.h"

#include "core/gizmos/cube.h"


namespace core::gizmos {

	class Picker : public Gizmo {

	public:
		Picker(float size = 0.01,std::shared_ptr<core::Mesh> mesh = std::make_shared<Cube>());

		void setScale(const glm::vec3& scale);
		void setPosition(const glm::vec3& position);

		//Returns ray going through pixel (mouseX,mouseY)
		glm::vec3 generateRay(const glm::mat4& projectionMatrix, const Camera& camera, const Transform& modelTransform, float mouseX, float mouseY,int width,int height);

	private:
	};

}


#endif