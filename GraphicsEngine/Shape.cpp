#include "Shape.h"

Shape::Shape() : Entity2D()
{
	myType = ShapeType::Triangle;
}

Shape::Shape(ShapeType type) : Entity2D()
{
	myType = type;
}

void Shape::Draw()
{
	switch (myType)
	{
	case ShapeType::Triangle:
		renderer->Draw(VertexTriangle, vertexTriangleLength, IndexTriangle, indexTriangleLength, model);
		break;
	case ShapeType::Square:
		renderer->Draw(VertexSquare, vertexSquareLength, IndexSquare, indexSquareLength, model);
		break;
	}
}