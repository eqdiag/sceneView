#include "material.h"

Material::Material(math::Color3 emissiveColor, math::Color3 ambientColor, math::Color3 diffuseColor, math::Color3 specularColor):
	mEmissiveColor{emissiveColor},mAmbientColor{ambientColor},mDiffuseColor{diffuseColor},mSpecularColor{specularColor}
{
}
