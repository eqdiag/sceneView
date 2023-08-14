#ifndef CAMERA_H
#define CAMERA_H

#include "glm/glm.hpp"


namespace core {

    static const double CAMERA_SHIFT = 0.001;


    class Camera {
    public:
        Camera(
            float theta,
            float phi,
            const glm::vec3& eye,
            const glm::vec3& up,
            const glm::vec3& forward,
            const glm::vec3& right
        );

        virtual void translate(float x, float y, float z) = 0;
        virtual void rotateTheta(float dtheta) = 0;
        virtual void rotatePhi(float dphi) = 0;
        virtual void zoom(float amt) = 0;
        virtual void setRadius(double radius) = 0;
        virtual void reset(glm::vec3& center, double radius) = 0;

        virtual glm::mat4 getViewMatrix() const = 0;
        virtual glm::vec3 getEye() const = 0;

        virtual void recomputeFrame() = 0;

    protected:

        //Spherical coordinate representation
        float mTheta;
        float mPhi;

        //Orthonormal basis representation
        glm::vec3 mEye;
        glm::vec3 mUp;
        glm::vec3 mForward;
        glm::vec3 mRight;
    };

    class FlyCamera : public Camera {
    public:
        FlyCamera(const glm::vec3& eye);
        void translate(float x, float y, float z) override;
        void rotateTheta(float dtheta) override;
        void rotatePhi(float dphi) override;
        void zoom(float amt) override;
        void setRadius(double radius) override;
        void reset(glm::vec3& center, double radius) override;

        glm::mat4 getViewMatrix() const override;
        glm::vec3 getEye() const override;

    private:

        static const double MIN_THETA;
        static const double MAX_THETA;
        static const double MIN_PHI;
        static const double MAX_PHI;

        void recomputeFrame() override;

    };

    class ArcCamera : public Camera {

    public:
        ArcCamera(glm::vec3& center, float radius);
        ArcCamera();
        void translate(float x, float y, float z) override;
        void rotateTheta(float dtheta) override;
        void rotatePhi(float dphi) override;
        void zoom(float amt) override;
        void setRadius(double radius) override;
        void reset(glm::vec3& center, double radius) override;

        glm::mat4 getViewMatrix() const override;
        glm::vec3 getEye() const override;

    private:
        void recomputeFrame() override;

        static const double MIN_PHI;
        static const double MAX_PHI;

        glm::vec3 mCenter;
        float mRadius;
    };

}

#endif