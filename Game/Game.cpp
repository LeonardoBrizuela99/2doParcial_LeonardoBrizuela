#include "Game.h"

Game::Game()
{
	idleKnuckles = nullptr;
	leftAnim = nullptr;
	rightAnim = nullptr;
	spinAnim = nullptr;
	moveRockAnim = nullptr;
}

void Game::Play()
{
	EngineInit(800, 600, "Knuckles Animation");
	UpdateEngine();
}

enum State
{
	Sleft, Sright, Sup, Sdown, Sspin, Srock
};

State knucklesState = Sdown;

void Game::Start()
{
	knuckles = Sprite("Res/Sprites/Knuckles_Sprite_Sheet.png");
	rock = Sprite("Res/Sprites/Rock.png");

	rock.SetPosition(0.0f, 0.0f, 1.0f);
	rock.Scale(1.5f, 1.0f, 1.0f);

	knuckles.SetPosition(-2.5f, 0.0f, -1.0f);
	knuckles.Scale(1.0f, 1.0f, 1.0f);

	rock.canCollision = true;
	knuckles.canCollision = true;

	rock.weight = 1;
	knuckles.strength = 2;

	idleKnuckles = new Animation();
	idleKnuckles->AddFrame(0, 430, 36, 43, 646, 473, 0.001, 1);

	rockFrame = new Animation();
	rockFrame->AddFrame(70, 129, 92, 63, 244, 207, 0.001, 1);

	rightAnim = new Animation();
	rightAnim->AddFrame(0, 388, 35, 40, 646, 473, 0.001, 2);

	spinAnim = new Animation();
	spinAnim->AddFrame(229, 302, 32, 40, 646, 473, 0.001, 4);

	moveRockAnim = new Animation();
	moveRockAnim->AddFrame(425, 341, 35, 35, 646, 473, 0.001, 4);

	rock.SetAnimation(rockFrame);
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

	if (GetKey(KEYCODE_D))
	{
		knucklesState = Sright;
		knuckles.SetAnimation(rightAnim);
		knuckles.Scale(1.0f, 1.0f, 1.0f);
		knuckles.SetPosition(knuckles.GetPositionX() + 0.0001f, knuckles.GetPositionY(), knuckles.GetPositionZ());
	}
	else if (knucklesState == Sright)
	{
		knuckles.SetAnimation(idleKnuckles);
		knuckles.Scale(1.0f, 1.0f, 1.0f);
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

	if (GetKey(KEYCODE_A))
	{
		knucklesState = Sleft;
		knuckles.SetAnimation(rightAnim); // Usar la animación de derecha
		knuckles.Scale(-1.0f, 1.0f, 1.0f); // Invertir imagen para izquierda
		knuckles.SetPosition(knuckles.GetPositionX() - 0.0001f, knuckles.GetPositionY(), knuckles.GetPositionZ());
	}
	else if (knucklesState == Sleft)
	{
		knuckles.SetAnimation(idleKnuckles);
		knuckles.Scale(-1.0f, 1.0f, 1.0f); // Invertir imagen para izquierda
	}


	if (GetKey(KEYCODE_Q))
	{
		knucklesState = Sspin;
		knuckles.SetAnimation(spinAnim);
		knuckles.SetPosition(knuckles.GetPositionX(), knuckles.GetPositionY(), knuckles.GetPositionZ());
	}
	else if (knucklesState == Sspin)
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

	//rock.SetPosition(rockX, 0.0f, -1.0f);

	/* Detección de colisiones*/
	if (knuckles.CheckCollisionAABB(rock))
	{
		knuckles.SetAnimation(moveRockAnim);

		rock.SetAnimation(rockFrame);
	}
	else if (knucklesState == Srock)
	{
		knuckles.SetAnimation(idleKnuckles);
	}


	knuckles.CheckCollisionAABB(rock);
	rock.Update();
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
	if (moveRockAnim) delete moveRockAnim;
	if (idleKnuckles) delete idleKnuckles;
}
