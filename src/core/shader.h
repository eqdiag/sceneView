#ifndef SHADER_H
#define SHADER_H

#include <unordered_map>
#include <string>

#include <glad/glad.h>


namespace core {

	class Shader {
	public:
		Shader();
		~Shader();

		//Returns true on success, false otherwise
		bool init(const char* shaderDirectory, const char* vertexShaderFile, const char* fragmentShaderFile);
		void use();

		GLuint getId() const;
		GLint getAttributeLocation(const char* str);
		GLint getUniformLocation(const char* str);

		void enableVertexAttributeArray(const char* str);

		void setUniformFloat(const char* str, float value);
		void setUniformFloat2(const char* str, float valueX, float valueY);
		void setUniformFloat3(const char* str, float valueX, float valueY, float valueZ);
		void setUniformFloat4(const char* str, float valueX, float valueY, float valueZ,float valueW);

		void setUniformMat4(const char* str, float* value);


	private:
		GLuint id;
		std::unordered_map<std::string, GLint> mAttributeCache;
		std::unordered_map<std::string, GLint> mUniformCache;

		std::pair<bool, GLuint> compileShader(const char* shaderDirectory, const char* shaderFile, GLuint shaderType);
	};

}

#endif