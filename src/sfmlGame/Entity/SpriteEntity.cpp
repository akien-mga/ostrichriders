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

#include "SpriteEntity.h"

SpriteEntity::SpriteEntity(sf::Texture* image, float x, float y, int width, int height, int imagesProLine) : GameEntity(x, y)
{
    frame = 0;
    isFading = false;
    this->image = image;
    sprite.setTexture(*image);
    this->width  = width  <= 0 ? image->getSize().x  : width;
    this->height = height <= 0 ? image->getSize().y : height;
    //sprite.SetSubRect(sf::IntRect(0, 0, this->width, this->height));
    sprite.setOrigin((float)(this->width / 2), (float)(this->height / 2));
    this->imagesProLine = imagesProLine;
}

void SpriteEntity::setFading(bool isFading)
{
    this->isFading = isFading;
}

void SpriteEntity::setFrame(int frame) { this->frame = frame; }

void SpriteEntity::render(sf::RenderWindow* app)
{
    int nx = frame;
    int ny = 0;

    if (imagesProLine > 0)
    {
        nx = frame % imagesProLine;
        ny = frame / imagesProLine;
    }

    sprite.setTextureRect(sf::IntRect(nx * width, ny * height, width, height));

    sprite.setPosition(x, y);
    sprite.setRotation(angle);

    if (isFading)
    {
        sprite.setColor(sf::Color(255, 255, 255, (sf::Uint8)(getFade() * 255)));
    }

    app->draw(sprite);
}

void SpriteEntity::animate(float delay)
{
    GameEntity::animate(delay);
}
