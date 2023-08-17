#ifndef LIGHT_H
#define LIGHT_H

#include "math/vec.h"

struct Light {
public:
	Light(
		math::Vec4 position,
		math::Color3 color,
		float shininess
	);

	math::Vec4 mPosition;
	math::Color3 mColor;
	float mShininess;
};

#endif