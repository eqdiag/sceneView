#include <iostream>

#include "core/gizmos/picker.h"

core::gizmos::Picker::Picker(float size,std::shared_ptr<core::Mesh> mesh):
	Gizmo{ mesh ,Transform::buildScale(glm::vec3(size))}
{

}

void core::gizmos::Picker::setScale(const glm::vec3& scale)
{
	mLocalTransform.setScale(scale);
}

void core::gizmos::Picker::setPosition(const glm::vec3& position)
{
	mLocalTransform.setTranslation(position);
}

glm::vec3 core::gizmos::Picker::generateRay(const glm::mat4& projectionMatrix, const Camera& camera, const Transform& modelTransform, float mouseX, float mouseY,int width,int height)
{
	float dx = mouseX / static_cast<float>(width);
	float dy = 1.0 - (mouseY / static_cast<float>(height));

	auto v = glm::inverse(projectionMatrix) * glm::vec4(2.0*dx -1.0,2.0*dy - 1.0,-1.0,1.0);
	v = glm::inverse(camera.getViewMatrix()) * glm::vec4(v.x,v.y,-1.0,0.0);

	return glm::normalize(glm::vec3(v.x, v.y,v.z));
}
