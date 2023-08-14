#ifndef MESH_H
#define MESH_H

#include <vector>
#include <optional>

#include <glad/glad.h>
#include "glm/glm.hpp"

#include "core/shader.h"

namespace core {

    struct VertexData {
        float x, y, z, nx, ny, nz;
    };

    class Mesh {
    public:

        Mesh(
            const std::vector<VertexData>& vertexData,
            const std::vector<GLuint>& indices,
            bool buildFaceNormals = false);
 
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;
        Mesh(Mesh&&) = delete;
        Mesh& operator=(Mesh&&) = delete;
        virtual ~Mesh();

        virtual void Render();

        glm::vec3 getCentroid() const;
        float getBoundingRadius() const;
        const int getNumVertices() const;
        const int getNumIndices() const;
        const std::vector<VertexData>& getVertexData() const;
        const std::vector<GLuint>& getIndices() const;
        glm::vec3 getVertexPoint(int index) const;
        glm::vec3 getFaceCentroid(int faceIndex) const;
        glm::vec3 getNormalVector(int index) const;
        void computeOpposites();

        void computeFaceCentroids();
        std::pair<int,glm::vec3> getIntersection(const glm::vec3& p, const glm::vec3& v) const;

        //Uses corners representation of opposites table
        int face(int c) const;
        int next(int c) const;
        int prev(int c) const;
        int vertex(int c) const;
        int corner(int v) const;
        int opp(int c) const;
        int swing(int c) const;

    protected:

        GLuint mVAO, mVBO, mEBO;

        float mRadius;
        glm::vec3 mCentroid;

        std::vector<VertexData> mVertexData;
        std::vector<GLuint> mIndices;
        std::vector<int> mOpposites;

        std::vector<glm::vec3> mFaceCentroids;

        //Variables keeping track of cached computations
        bool mOppositesComputed;

        //For printing info about mesh processing
        int mPrintFrequency;


        void computeBoundingSphere();


        

        glm::vec3 getVertexData(int c) const;

        bool checkOpposites(int c0, int c1) const;
        void computeFaceNormals(const std::vector<VertexData>& vertexData, const std::vector<GLuint>& indices);

    private:
        std::optional<glm::vec3> computeTriangleInteresection(const glm::vec3& p,const glm::vec3& v,int faceId) const;
        

    };

}

#endif