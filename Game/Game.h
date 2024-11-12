#ifndef GAME_H
#define GAME_H

#include "GraphicsEngine/BaseGame.h"
#include "GraphicsEngine/Animation.h"
#include "GraphicsEngine/Sprite.h"

class Game : public BaseGame
{
private:
    Sprite knuckles;
    Sprite rock;

    void Update();
    bool Input(int keycode, float& variable, float modif);
    void Start();
    void Delete();

    Animation* leftAnim;
    Animation* rightAnim;
    Animation* spinAnim;
    Animation* collisionAnim;
    Animation* idleKnuckles;

public:
    Game();
    void Play();
};

#endif 