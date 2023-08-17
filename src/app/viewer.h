#ifndef VIEWER_H
#define VIEWER_H

#include <memory>

#include "core/app.h"
#include "core/shader.h"
#include "core/mesh.h"
#include "core/asset_loader.h"
#include "core/camera.h"

#include "math/matrix.h"

#include "material.h"
#include "light.h"

class Viewer : public core::App {
public:
	Viewer();
	void init() override;
	void update();
	void render();

	void loadNewMesh(const char* modelFilename);
	void toggleShader();


	//Static app state
	static Light mLight;
	static Material mMaterial;

	//Input state variables
	bool mViewerOpen;
	bool mMousePressed;
	bool mMouseInit;
	float mMouseX;
	float mMouseY;
	bool mNormalShadingMode;
	float lightAngle;

	//Shader uniforms
	math::Mat4 mModelMatrix{};
	math::Mat4 mViewMatrix{};
	math::Mat4 mProjMatrix{};

	//Model and camera
	std::unique_ptr<core::Mesh> mMesh;
	std::unique_ptr<core::ArcCamera> mCamera;

private:

	void replaceMesh(std::unique_ptr<core::Mesh> newMesh);

	core::Shader* mCurrentShader;

	core::Shader mNormalShader{};
	core::Shader mPhongShader{};

	core::AssetLoader mLoader{};


};


#endif