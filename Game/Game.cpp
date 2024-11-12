#include "Game.h"

Game::Game()
{
    idleKnuckles = nullptr;
    leftAnim = nullptr;
    rightAnim = nullptr;
    spinAnim = nullptr;
    collisionAnim = nullptr;
}

void Game::Play()
{
    EngineInit(800, 600, "Knuckles Animation");
    UpdateEngine();
}

enum State
{
    Sleft, Sright, Sup, Sdown, Sspin
};

State knucklesState = Sdown;

void Game::Start()
{
    knuckles = Sprite("Res/Sprites/Knuckles_Sprite_Sheet.png");
    rock = Sprite("Res/Sprites/Rock.png");

    rock.SetPosition(-0.5f, 0.0f, -1.0f);
    rock.Scale(1.0f, 1.0f, 1.0f);

    knuckles.SetPosition(0.5f, 0.0f, -1.0f);
    knuckles.Scale(1.0f, 1.0f, 1.0f);

    rock.canCollision = true;
    knuckles.canCollision = true;

    
    idleKnuckles = new Animation();
    idleKnuckles->AddFrame(0, 0, 36, 41, 646, 473, 0.001, 1);

    leftAnim = new Animation();
    leftAnim->AddFrame(0, 118, 161, 118, 646, 473, 0.001, 10);

    rightAnim = new Animation();
    rightAnim->AddFrame(0, 236, 161, 118, 646, 473, 0.001, 10);

    spinAnim = new Animation();
    spinAnim->AddFrame(0, 354, 161, 118, 646, 473, 0.001, 10);

    collisionAnim = new Animation();
    collisionAnim->AddFrame(0, 472, 161, 118, 646, 473, 0.001, 4);

    knuckles.SetAnimation(idleKnuckles);
}

float rotation = 1.0f;
float cameraX = 0.1f;
float cameraY = 0.1f;
float cameraZ = 8.0f;

const float valueModif = 0.01f;

float rockX = -0.5f;

void Game::Update()
{
    rotation += 0.001;

    CameraMove(cameraX, cameraY, cameraZ);

    Input(KEYCODE_Z, cameraX, -valueModif);
    Input(KEYCODE_X, cameraY, -valueModif);
    Input(KEYCODE_C, cameraZ, -valueModif);

    Input(KEYCODE_V, cameraX, valueModif);
    Input(KEYCODE_B, cameraY, valueModif);
    Input(KEYCODE_N, cameraZ, valueModif);

    if (GetKey(KEYCODE_A))
    {
        knucklesState = Sleft;
        knuckles.SetAnimation(leftAnim);
        knuckles.SetPosition(knuckles.GetPositionX() - 0.01f, knuckles.GetPositionY(), knuckles.GetPositionZ());
    }
    else if (knucklesState == Sleft)
    {
        knuckles.SetAnimation(idleKnuckles);
    }

    if (GetKey(KEYCODE_D))
    {
        knucklesState = Sright;
        knuckles.SetAnimation(rightAnim);
        knuckles.SetPosition(knuckles.GetPositionX() + 0.01f, knuckles.GetPositionY(), knuckles.GetPositionZ());
    }
    else if (knucklesState == Sright)
    {
        knuckles.SetAnimation(idleKnuckles);
    }

    if (GetKey(KEYCODE_W))
    {
        knucklesState = Sup;
        knuckles.SetPosition(knuckles.GetPositionX(), knuckles.GetPositionY() + 0.01f, knuckles.GetPositionZ());
    }
    else if (knucklesState == Sup)
    {
        knuckles.SetAnimation(idleKnuckles);
    }

    if (GetKey(KEYCODE_S))
    {
        knucklesState = Sdown;
        knuckles.SetAnimation(spinAnim);
        knuckles.SetPosition(knuckles.GetPositionX(), knuckles.GetPositionY() - 0.01f, knuckles.GetPositionZ());
    }
    else if (knucklesState == Sdown)
    {
        knuckles.SetAnimation(idleKnuckles);
    }

    rock.SetPosition(rockX, 0.0f, -1.0f);

    // Detección de colisiones
    if (knuckles.CheckCollisionAABB(rock))
    {
        rock.SetAnimation(collisionAnim);
    }

    rock.Draw();
    knuckles.Update();
    knuckles.Draw();
}

bool Game::Input(int keycode, float& variable, float modif)
{
    if (GetKey(keycode))
    {
        variable += modif;
        return true;
    }
    return false;
}

void Game::Delete()
{
    if (rightAnim) delete rightAnim;
    if (leftAnim) delete leftAnim;
    if (spinAnim) delete spinAnim;
    if (collisionAnim) delete collisionAnim;
    if (idleKnuckles) delete idleKnuckles;
}
