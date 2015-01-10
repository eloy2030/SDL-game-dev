
#include "GameStateMachine.h"
#include "InputHandler.h"

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}	

void GameStateMachine::changeState(GameState* pState)
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getStateID() == pState->getStateID()){
			return; // do nothing if they are the same
		}

		if (m_gameStates.back()->getIsValid())
		{
			m_gameStates.back()->setIsValid(false); // Mark the state as invalid
		}
	}

	// push back our new state
	m_gameStates.push_back(pState);

	m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::dequeState(){
	if (!m_gameStates.empty()){
		// If the state is invalid we proceed to dequeue the state
		if (!m_gameStates[0]->getIsValid() && m_gameStates[0]->onExit())
		{
			delete m_gameStates[0];
			m_gameStates.erase(m_gameStates.begin());

			// Reset the Input handler buttons state
			// This line is extremely important, fixes an issue with the "State traveling"
			// when a button is in the position of another button in another state
			// this will prevent the accident of traveling 2 states with 1 click.
			TheInputHandler::Instance()->reset();
			
		}
	}
}