#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include "SDLGameObject.h"
#include "Level.h"
#include <vector>

class GameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;

	Level* pLevel;
	
};
#endif /* defined(__PlayState__) */