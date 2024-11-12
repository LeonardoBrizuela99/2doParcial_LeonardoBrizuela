#ifndef ANIMATION_H
#define ANIMATION_H
#include "export.h"
#include "Utility.h"
#include "Frame.h"
#include <vector>
class ENGINE_API Animation
{
public:
	Animation();
	~Animation();
	void AddFrame(float xFrame, float yFrame, float widthFrame, float heightFrame,
		float textureWidth, float textureHegiht, float durationInSec);
	void AddFrame(float xFrame, float yFrame, float widthFrame, float heightFrame,
		float textureWidth, float textureHegiht, float durationInSec, int frameCount);
	std::vector<Frame> myFrames;
	void Update();
	int currentFrame;
	float currentTime;
private:
	float length = 0;
	const float lengthMultiply = 1000;

};
#endif