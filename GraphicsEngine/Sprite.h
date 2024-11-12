#ifndef SPRITE_H
#define SPRITE_H
#include "Entity2D.h"
#include "TextureImporter.h"
#include "Animation.h"

class ENGINE_API Sprite : public Entity2D
{
private:
    static const int vertexLength = 36;
    float vertexSprite[vertexLength] = {
        // positions          // colors                // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,  1.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,  1.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,  1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,  1.0f,   0.0f, 1.0f  // top left 
    };
    static const int indexLength = 6;
    unsigned int index[indexLength] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    TextureData data;
    bool alpha = false;
    Animation* actualAnim;
    unsigned int previousFrameIndex = 99;
    unsigned int currentFrameIndex = 0;

public:

    Sprite();
    Sprite(const char* filePath);
    void SetAnimation(Animation* anim);
    Animation* GetAnimation();
    void Update();
    void Draw();
    void SetTextureCoordinate(float u0, float v0, float u1, float v1,
        float u2, float v2, float u3, float v3);
};
#endif