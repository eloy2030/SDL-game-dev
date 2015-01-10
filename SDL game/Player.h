#ifndef __Player__
#define __Player__

#include <SDL.h>
#include <SDL_image.h>
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject
{
public:
	Player();

	virtual void handleInput();
	virtual void draw();
	virtual void update();
	virtual void clean();

	// new load function
	virtual void load(const LoaderParams* pParams);
};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif /* defined(__Player__) */