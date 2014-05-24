/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * bird.h
 *
 */

#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <SDL2/SDL.h>

class Bird
{
	public:
		Bird();
		~Bird();

		void EventHandler(SDL_Event* event);
		void Update();
		void Render(SDL_Renderer* renderer);

	private:
		SDL_Rect birdPos;
};

#endif
