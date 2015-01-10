
#ifndef __Level__
#define __Level__

#include <iostream>
#include <vector>
#include "Layer.h"

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;

	std::string name;
};

class Level
{
public:

	void update();
	void render();

	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}

	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}

private:	

	friend class LevelParser;
	

	std::vector<Tileset> m_tilesets;

	std::vector<Layer*> m_layers;

};

#endif /*defined (__Level___)*/