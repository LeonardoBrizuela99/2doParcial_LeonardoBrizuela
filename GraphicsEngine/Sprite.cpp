#include "Sprite.h"
#include <iostream>

Sprite::Sprite() : Entity2D()
{
	actualAnim = nullptr;
	data.height = 0;
	data.width = 0;
	data.nrChannels = 0;
	data.texture = 0;
}

Sprite::Sprite(const char* filePath) : Entity2D()
{
	actualAnim = nullptr;
	data = TextureImporter::ImportTexture(filePath);
	if (data.nrChannels == 4)
		alpha = true;
	currentFrameIndex = 1;
	previousFrameIndex = 99;
}

void Sprite::SetAnimation(Animation* anim)
{
	actualAnim = anim;
	currentFrameIndex = 0;
	SetTextureCoordinate(actualAnim->myFrames[currentFrameIndex].coords[0].U,
		actualAnim->myFrames[currentFrameIndex].coords[0].V,
		actualAnim->myFrames[currentFrameIndex].coords[1].U,
		actualAnim->myFrames[currentFrameIndex].coords[1].V,
		actualAnim->myFrames[currentFrameIndex].coords[2].U,
		actualAnim->myFrames[currentFrameIndex].coords[2].V,
		actualAnim->myFrames[currentFrameIndex].coords[3].U,
		actualAnim->myFrames[currentFrameIndex].coords[3].V);
	previousFrameIndex = std::numeric_limits<unsigned int>::max_digits10;
}

Animation* Sprite::GetAnimation()
{
	return actualAnim;
}

void Sprite::Update()
{
	lastPosition = position;

	if (!actualAnim)
		return;

	actualAnim->Update();
	currentFrameIndex = actualAnim->currentFrame;

	if (currentFrameIndex != previousFrameIndex)
	{
		SetTextureCoordinate(actualAnim->myFrames[currentFrameIndex].coords[0].U,
			actualAnim->myFrames[currentFrameIndex].coords[0].V,
			actualAnim->myFrames[currentFrameIndex].coords[1].U,
			actualAnim->myFrames[currentFrameIndex].coords[1].V,
			actualAnim->myFrames[currentFrameIndex].coords[2].U,
			actualAnim->myFrames[currentFrameIndex].coords[2].V,
			actualAnim->myFrames[currentFrameIndex].coords[3].U,
			actualAnim->myFrames[currentFrameIndex].coords[3].V);

		previousFrameIndex = currentFrameIndex;
	}


}

void Sprite::Draw()
{
	TextureImporter::BindTexture(data.texture);
	renderer->SpriteDraw(vertexSprite, vertexLength, index, indexLength, model, alpha);
}

void Sprite::SetTextureCoordinate(float u0, float v0, float u1, float v1, float u2, float v2, float u3, float v3)
{
	vertexSprite[7] = u3; //right
	vertexSprite[8] = v3; //up

	vertexSprite[16] = u1; //right 
	vertexSprite[17] = v1; //down

	vertexSprite[25] = u0; //let   
	vertexSprite[26] = v0; //down      

	vertexSprite[34] = u2; //left
	vertexSprite[35] = v2; //up
}