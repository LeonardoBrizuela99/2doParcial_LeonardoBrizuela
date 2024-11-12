#ifndef FRAME_H
#define FRAME_H
#include "export.h"

struct UVcoords
{
	float U;
	float V;
};

class ENGINE_API Frame
{
public:
	UVcoords coords[4];
	Frame();
	~Frame();

private:

};
#endif