#include "core/settings.h"

#include "app/viewer.h"


Light Viewer::mLight{
	math::Vec4{1.0,1.0,0.0,0.0},
	math::Color3{1.0,1.0,1.0}, //white light
	2.0
};

Material Viewer::mMaterial{
	math::Color3{0.0}, //Default: no emissive
	math::Color3{0.0,0.0,0.2}, //Default: a little ambient
	math::Color3{0.0, 0.0, 0.7}, //Default: blue diffuse color
	math::Color3{1.0, 1.0, 1.0} //Default: White highlights
};

Viewer::Viewer():
	App{},
	mViewerOpen{true},
	mMousePressed{false},
	mMouseInit{false},
	mMouseX{},
	mMouseY{},
	mNormalShadingMode{true},
	lightAngle{0.0},
	mCurrentShader{nullptr}
{

}

void Viewer::init()
{

	//Create graphics assets
	mNormalShader.init(SHADER_DIR, "basic.vs", "basic.fs");
	mPhongShader.init(SHADER_DIR, "phong.vs", "phong.fs");
	
	mMesh = mLoader.loadMesh(MODEL_DIR, "cube.obj");
	mCamera = std::make_unique<core::ArcCamera>(mMesh->getCentroid(), 2.0 * mMesh->getBoundingRadius());

	auto eye = mCamera->getEye();

	mModelMatrix = math::Mat4::identity();
	mViewMatrix = mCamera->getViewMatrix();
	mProjMatrix = math::Mat4::perspectiveProjection(3.14*45.0/180.0, 800.0 / 600.0, 0.1, 1000.);


	mNormalShader.use();
	mNormalShader.setUniformMat4("model", mModelMatrix.getRawData());
	mNormalShader.setUniformMat4("view",mViewMatrix.getRawData());
	mNormalShader.setUniformMat4("proj",mProjMatrix.getRawData());

	mPhongShader.use();
	mPhongShader.setUniformMat4("model", mModelMatrix.getRawData());
	mPhongShader.setUniformMat4("view", mViewMatrix.getRawData());
	mPhongShader.setUniformMat4("proj", mProjMatrix.getRawData());

	mCurrentShader = &mNormalShader;

	glClearColor(0.22f, 0.22f, 0.22f, 1.0f);
	glEnable(GL_DEPTH_TEST);

}

void Viewer::update()
{
	lightAngle += 0.001;
	mLight.mPosition[0] = cos(lightAngle);
	mLight.mPosition[2] = -sin(lightAngle);
}

void Viewer::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	//Set uniforms
	mCurrentShader->use();
	mViewMatrix = mCamera->getViewMatrix();
	mCurrentShader->setUniformMat4("view", mViewMatrix.getRawData());

	auto eye = mCamera->getEye();
	mCurrentShader->setUniformFloat3("eye", eye[0], eye[1], eye[2]);

	//Material properties
	mCurrentShader->setUniformFloat3("emissive", mMaterial.mEmissiveColor.x(), mMaterial.mEmissiveColor.y(), mMaterial.mEmissiveColor.z());
	mCurrentShader->setUniformFloat3("ambient", mMaterial.mAmbientColor.x(), mMaterial.mAmbientColor.y(), mMaterial.mAmbientColor.z());
	mCurrentShader->setUniformFloat3("diffuse", mMaterial.mDiffuseColor.x(), mMaterial.mDiffuseColor.y(), mMaterial.mDiffuseColor.z());
	mCurrentShader->setUniformFloat3("specular", mMaterial.mSpecularColor.x(), mMaterial.mSpecularColor.y(), mMaterial.mSpecularColor.z());

	mCurrentShader->setUniformFloat4("lightPosition", mLight.mPosition.x(), mLight.mPosition.y(), mLight.mPosition.z(), mLight.mPosition.w());
	mCurrentShader->setUniformFloat3("lightColor", mLight.mColor.x(), mLight.mColor.y(), mLight.mColor.z());
	mCurrentShader->setUniformFloat("shininess", mLight.mShininess);


	mMesh->Render();

}

void Viewer::loadNewMesh(const char* modelFilename)
{
	replaceMesh(mLoader.loadMesh(MODEL_DIR, modelFilename));
}

void Viewer::toggleShader()
{
	mNormalShadingMode = !mNormalShadingMode;
	if (mNormalShadingMode) {
		mCurrentShader = &mNormalShader;
	}
	else {
		mCurrentShader = &mPhongShader;
	}
}

void Viewer::replaceMesh(std::unique_ptr<core::Mesh> newMesh)
{
	mMesh.swap(newMesh);

	mCamera->reset(mMesh->getCentroid(), 2.0 * mMesh->getBoundingRadius());
}
