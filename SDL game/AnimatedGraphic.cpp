
#include "AnimatedGraphic.h"
#include "InputHandler.h"
#include <string>


AnimatedGraphic::AnimatedGraphic() : SDLGameObject()
{
}

void AnimatedGraphic::load(const LoaderParams *pParams)
{
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 6));
}

void AnimatedGraphic::clean()
{
}

void AnimatedGraphic::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}