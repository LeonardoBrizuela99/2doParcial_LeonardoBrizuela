#ifndef SHAPE_H
#define SHAPE_H
#include "export.h"
#include "Entity2D.h"
#include "Export.h"

enum class ENGINE_API ShapeType
{
	Triangle, Square
};

class ENGINE_API Shape : public Entity2D
{
private:
	static const int vertexTriangleLength = 18;
	float VertexTriangle[vertexTriangleLength] = { 
	-0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 1.0f,// X,Y,Z  R,G,B
	 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f
	};

	static const int indexTriangleLength = 3;
	unsigned int IndexTriangle[indexTriangleLength] = {
		0, 1, 2
	};

	static const int vertexSquareLength = 24;
	float VertexSquare[vertexSquareLength] = {
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,// X,Y,Z  R,G,B
	 0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
	 0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 1.0f
	};

	static const int indexSquareLength = 6;
	unsigned int IndexSquare[indexSquareLength] = {
		0, 1, 2,
		1, 3, 2
	};

public:
	
	Shape();
	Shape(ShapeType type);
	void Draw();
	ShapeType myType;

};

#endif 