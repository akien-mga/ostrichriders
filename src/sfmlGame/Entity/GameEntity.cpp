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

#include "GameEntity.h"
#include <stdlib.h>

GameEntity::GameEntity()
{
	GameEntity(0.0f, 0.0f);
}

GameEntity::GameEntity(float m_x, float m_y)
{
	x = m_x;
	y = m_y;
	bbox.x = 0.0f; bbox.y = 0.0f;
	bbox.width = 0.0f; bbox.height = 0.0f;
	age = 0;
	lifetime = -1;
	visible = true;
	isDying = false;
	viscosity = 0.99f;

	weight = 0.0f;
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	angle = 0.0f;
	spin = 0.0f;

	EntityManager::getEntityManager()->add(this);
}

GameEntity::~GameEntity()
{
}

bool GameEntity::getDying() { return isDying; }
float GameEntity::getX() { return x; }
float GameEntity::getY() { return y; }
float GameEntity::getAge() { return age; }
Vector2D GameEntity::getVelocity() { return Vector2D(velocity.x, velocity.y); }

void GameEntity::setX(float x) { this->x = x; }
void GameEntity::setY(float y) { this->y = y; }
void GameEntity::setAngle(float angle) { this->angle = angle; }
void GameEntity::setWeight(float weight) { this->weight = weight; }
void GameEntity::setSpin(float spin) { this->spin = spin; }
void GameEntity::setAge(float age) { this->age = age; }
void GameEntity::setLifetime(float lifetime) { this->lifetime = lifetime; }
void GameEntity::setVelocity(Vector2D velocity)
{
    this->velocity.x = velocity.x;
    this->velocity.y = velocity.y;
}
void GameEntity::setDying(bool dying) { isDying = dying; }

void GameEntity::animate(float delay)
{
	//velocity.x *= viscosity;
	//velocity.y *= viscosity;

	velocity.y += weight * delay;

	x += velocity.x * delay;
	y += velocity.y * delay;

	angle += spin * delay;

    age += delay;
	if (lifetime > 0)
	{
		if (age >= lifetime) isDying = true;
	}
}

void GameEntity::render(sf::RenderWindow* app)
{
    if (app == NULL) return;
}

void GameEntity::onDying()
{
}

float GameEntity::getFade()
{
	if (lifetime > 0)
	{
		float f= 1.0f - (float)age/lifetime;
		if (f < 0.0f) f=0.0f;
		if (f > 1.0f) f=1.0f;
		return f;
	}
	else return 1.0f;
}

