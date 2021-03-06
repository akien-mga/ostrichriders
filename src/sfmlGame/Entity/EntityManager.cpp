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

#include "EntityManager.h"
#include <stdlib.h>

#include "GuiEntity.h"

EntityManager::EntityManager()
{
	initIterator();
	mItems = 0;
}

 EntityManager* EntityManager::getEntityManager()
 {
   static EntityManager singleton;
   return &singleton;
 }


void EntityManager::add(GameEntity* g)
{
	entityList.push_back(g);
	mItems++;
}


void EntityManager::initIterator()
{
	mIterator = entityList.begin ();
}

GameEntity* EntityManager::nextItem()
{
	if (mIterator == entityList.end ()) return NULL;

	GameEntity *e = *mIterator;
	mIterator++;
	return e;
}

void EntityManager::animate (float delay)
{
	if (!isEmpty())
	{
		EntityList::iterator it;
		EntityList::iterator oldit = entityList.begin ();
		//bool isBegin = false;
		for (it = entityList.begin (); it != entityList.end () && !isEmpty();)
		{
			GameEntity *e = *it;
			oldit = it;
			it++;

			if (e->getDying())
			{
				entityList.erase(oldit);
				e->onDying();
				delete e;
				//e == NULL;
				mItems--;
			} // endif
			else
				e->animate(delay);
		} // end for
	}
}

void EntityManager::render(sf::RenderWindow* app)
{
	if (!isEmpty())
	{
		EntityList::iterator it;
		EntityList::iterator oldit = entityList.begin ();
		//bool isBegin = false;
		for (it = entityList.begin (); it != entityList.end () && !isEmpty();)
		{
			GameEntity* e = *it;
			oldit = it;
			e->render(app);
			it++;
		} // end for
	}
}

void EntityManager::onEvent(sf::Event event)
{
    if (!isEmpty())
	{
		EntityList::iterator it;
		EntityList::iterator oldit = entityList.begin ();
		for (it = entityList.begin (); it != entityList.end () && !isEmpty();)
		{
			GuiEntity* guiEntity = dynamic_cast<GuiEntity*>(*it);
            if (guiEntity != NULL)
            {
                guiEntity->onEvent(event);
            }
			oldit = it;
			it++;
		} // end for
	}
}

void EntityManager::clean ()
{
	if (!isEmpty())
	{
		EntityList::iterator it;
		EntityList::iterator oldit = entityList.begin ();
		//bool isBegin = false;
		//EL.clear();
		for (it = entityList.begin (); it != entityList.end ();)
		{
			GameEntity *e = *it;
			oldit = it;
			it++;

			entityList.erase(oldit);

            //e->onDying();
			delete e;
			//e == NULL;
		} // end for*/
		mItems = 0;
	}
}

EntityManager::EntityList* EntityManager::getList()
{
    return &entityList;
}
