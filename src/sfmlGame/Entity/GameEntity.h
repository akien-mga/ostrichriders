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

#ifndef __GAMEENTITY
#define __GAMEENTITY

#include <SFML/Graphics.hpp>

#include "../MyTools.h"
#include "EntityManager.h"
#include "../Game.h"

class EntityManager;

/** Objects to be displayed during the game.
  * A basic physics has been implemented.
  * The EntityManager will destroy the GameEntity when dying. */
class GameEntity
{
public:
	struct bboxStruct
	{
		float x, y, width, height;
	} bbox;

	GameEntity();
	GameEntity(float m_x, float m_y);
	//GameEntity(float m_x = 0.0f, float m_y = 0.0f, m_type = TypePart02 );

	virtual ~GameEntity();

    // accesors
	bool getDying();
	float getX();
	float getY();
	Vector2D getVelocity();
	float getAge();

	// mutators
	void setX(float x);
	void setY(float y);
	void setAngle(float angle);
	void setWeight(float weight);
	void setVelocity(Vector2D velocity);
	void setSpin(float spin);
	void setAge(float age);
	void setLifetime(float lifetime);
	void setDying(bool dying);


	virtual void render(sf::RenderWindow* app);
	virtual void animate(float delay);

	virtual void onDying();

	float getFade();



protected:
	// position and physics (geometry)
	float x, y;
	float angle;
	float spin;

	Vector2D velocity;
	Vector2D acceleration;
	float weight;
	float viscosity;

	// visibility
	bool visible;

	// life_time
	float age, lifetime;
	bool isDying;
};

#endif
