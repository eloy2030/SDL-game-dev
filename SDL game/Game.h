#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <SDL_image.h>
#include "GameStateMachine.h"

class Game
{
public:
	
	// create the public instance function
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();	
	void update();
	void handleEvents();
	void clean();
	void quit();

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }

	bool running() { return m_bRunning; }

	int getGameWidth() const
	{
		return m_gameWidth;
	}

	int getGameHeight() const
	{
		return m_gameHeight;
	}

private:

	Game(){}
	// create the s_pInstance member variable
	static Game* s_pInstance;
	
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameStateMachine* m_pGameStateMachine;

	bool m_bRunning;

	int m_gameWidth;
	int m_gameHeight;
	
};

// create the typedef
typedef Game TheGame;

#endif /* defined(__Game__) */