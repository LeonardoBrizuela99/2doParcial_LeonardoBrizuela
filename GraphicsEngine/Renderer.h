#ifndef RENDERER_H
#define RENDERER_H

#include "glm.hpp"
#include "Export.h"
#include <gtc\type_ptr.hpp>

class ENGINE_API Renderer
{
private:
	unsigned int modelLoc;
	unsigned int projectLoc;
	unsigned int viewLoc; 
public:
	Renderer();
	void Draw(float* vertex, int vertexLength, unsigned int* index, int indexLength, glm::mat4 modelMatrix);
	void SpriteDraw(float* vertex, int vertexLength, unsigned int* index, int indexLength, glm::mat4 modelMatrix, bool alpha);
	unsigned int VBO = 0; // VertexBufferObject
	unsigned int VAO = 0; // VertexArrayObject
	unsigned int EBO = 0; // ElementsBufferObject
	unsigned int program = 0; // ProgramShader
	void CreateBuffers();
	void BindBuffers();
	unsigned int CompileShader(unsigned int type, const char* shaderPath);
	void CreateProgram(const char* vertexShaderPath, const char* pixelShaderPath);
	void DefVertexAttribute();
	void DefVertexSpriteAttribute();
	void CallUniformShaders();
	static Renderer* myRef;
	void SetStaticRenderer(Renderer* newRef);
	Renderer* GetStaticRenderer();

	void UpdateModelUniformShaders(glm::mat4 modelMatrix);
	void UpdateProjectUniformShaders(glm::mat4 projectMatrix);
	void UpdateProjection();
	void UpdateViewUniformShaders(glm::mat4 viewMatrix);
	void UpdateView();

	void CameraMove(float x, float y, float z);
	float cameraSpeed = 0.01f; // adjust accordingly

	glm::mat4 projection; //size/count of pixel inside the viewport
	glm::mat4 view; //move the "camera" but really move all object in the inverse
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};

#endif