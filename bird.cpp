/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * bird.cpp
 *
 */

#include "bird.h"

Bird::Bird()
{
	birdPos.x = 285;
	birdPos.y = 285;
	birdPos.w = 30;
	birdPos.h = 30;
}

Bird::~Bird()
{
}

void
Bird::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x33, 0x33, 0xFF);
	SDL_RenderFillRect(renderer, &birdPos);
}
