#ifndef MATERIAL_H
#define MATERIAL_H

#include "math/vec.h"

struct Material {
public:
	Material(
		math::Color3 emissiveColor,
		math::Color3 ambientColor,
		math::Color3 diffuseColor,
		math::Color3 specularColor
	);

	math::Color3 mEmissiveColor;
	math::Color3 mAmbientColor;
	math::Color3 mDiffuseColor;
	math::Color3 mSpecularColor;
};

#endif