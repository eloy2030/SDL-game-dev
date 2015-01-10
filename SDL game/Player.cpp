
#include "Player.h"
#include "InputHandler.h"
#include <string>


Player::Player() : SDLGameObject()
{
}

void Player::load(const LoaderParams *pParams)
{
	SDLGameObject::load(pParams);
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;

	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}