
#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"
#include "Vector2D.h"
#include <vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	// joystick
	void initialiseJoysticks();
	bool joysticksInitialised() { return m_bJoysticksInitialised; }

	// mouse	
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	void update();
	void clean();

	void reset()
	{
		for (int i = 0; i < 3; i++)
		{
			m_mouseButtonStates[i] = false;
		}
	}

	// keyboard
	bool InputHandler::isKeyDown(SDL_Scancode key);

private:

	InputHandler()
	{
		for (int i = 0; i < 3; i++)
		{
			m_mouseButtonStates.push_back(false);
		}
		m_mousePosition = new Vector2D(0.0, 0.0);
	}
	
	static InputHandler* s_pInstance;

	// joystick
	std::vector<SDL_Joystick*> m_joysticks;

	// mouose
	std::vector<bool> m_mouseButtonStates;	
	Vector2D* m_mousePosition;

	// keyboard
	const Uint8* m_keystates;

	bool m_bJoysticksInitialised;

	// private functions to handle different event types

	/*// handle keyboard events
	void onKeyDown();
	void onKeyUp();

	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	// handle joysticks events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);*/
};
typedef InputHandler TheInputHandler;

#endif /* defined(__InputHandler__) */