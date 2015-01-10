#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

#include <SDL.h>
#include <SDL_image.h>
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic();

	virtual void handleInput();
	virtual void draw();
	virtual void update();
	virtual void clean();

	// new load function
	virtual void load(const LoaderParams* pParams);

private:
	int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};

#endif /* defined(__AnimatedGraphic__) */