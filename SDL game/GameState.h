#ifndef __GameState__
#define __GameState__

#include <string>
#include <vector>

class GameState
{
public:
	GameState();


	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateID() const = 0;

	bool getIsValid() const { return m_isValid; }
	void setIsValid(bool isValid) { m_isValid = isValid; }

protected:
	std::vector<std::string> m_textureIDList;

private:

	bool m_isValid;
};

#endif /* defined(__GameState__) */