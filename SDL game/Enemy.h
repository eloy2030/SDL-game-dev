#ifndef __Enemy__
#define __Enemy__

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "SDLGameObject.h"
#include "GameObjectFactory.h"


class Enemy : public SDLGameObject
{
public:
	Enemy();

	virtual void draw();
	virtual void update();
	virtual void clean();

	// new load function
	virtual void load(const LoaderParams* pParams);
};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};

#endif /* defined(__Enemy__) */