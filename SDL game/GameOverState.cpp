

#include <iostream>
#include "MainMenuState.h"
#include "AnimatedGraphic.h"
#include "GameOverState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "StateParser.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

bool GameOverState::onEnter()
{
	// parse the state
	StateParser stateParser;

	stateParser.parseState("test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);

	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	std::cout << "entering PauseState\n";
	return true;
}

bool GameOverState::onExit()
{
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	// clear the texture manager
	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exiting MenuState\n";

	return true;
}

void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->update();
	}

	//Check and deque the state if its invalid
	TheGame::Instance()->getStateMachine()->dequeState();
}

void GameOverState::render()
{
	for (unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}


void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}