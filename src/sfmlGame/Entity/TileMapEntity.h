/**  This file is part of sfmlGame.
  *
  *  FreeTumble is free software: you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation, either version 3 of the License, or
  *  (at your option) any later version.
  *
  *  FreeTumble is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with FreeTumble.  If not, see <http://www.gnu.org/licenses/>.
  */

#ifndef TILEMAPENTITY_H_INCLUDED
#define TILEMAPENTITY_H_INCLUDED

#include "GameEntity.h"
#include "../Model/GameMap.h"

// Basis class for TileMap
class TileMapEntity : public GameEntity
{
public:
    // create a sprite with the entire image
    TileMapEntity(sf::Texture* image, GameMap* gameMap, int tileWidth, int tileHeight, int tilesProLine);
    ~TileMapEntity();

    int getTilesProLine();

    virtual void render(sf::RenderWindow* app);
	virtual void animate(float delay);

protected:
    int width;
    int height;
    int tileWidth;
    int tileHeight;
    int tilesProLine;

    sf::Texture* image;
    GameMap* gameMap;
};

#endif // TILEMAPENTITY_H_INCLUDED
