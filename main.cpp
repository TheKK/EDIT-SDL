/*
 * Author: KK <thumbd03803@gmail.com>
 *
 * main.cpp
 *
 */

#include <iostream>
#include "bird.h"
#include "timer.h"

using namespace std;

bool gameIsRunning = true;
SDL_Window* mainWindow = NULL;
SDL_Renderer* mainRenderer = NULL;

Bird bird;

void
SDLInit()
{
	mainWindow = SDL_CreateWindow(
			"Bird",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			600, 600,
			SDL_WINDOW_SHOWN
			);
	if (mainWindow == NULL) {
		cout << "Error: can not create SDL window!" << endl;
		exit(1);
	}

	mainRenderer = SDL_CreateRenderer(
			mainWindow,
			-1,
			SDL_RENDERER_ACCELERATED
			);
	if (mainRenderer == NULL) {
		cout << "Error: can not create SDL renderer!" << endl;
		exit(1);
	}
}

void
EventHandler(SDL_Event* event)
{
		while (SDL_PollEvent(event)) {

			//Global events
			switch (event->type) {
				case SDL_QUIT:
					gameIsRunning = false;
			}

		}
}

void
Update()
{
}

void
Render()
{
	//Clear screen with this kind of color
	SDL_SetRenderDrawColor(mainRenderer, 0x0E, 0xE2, 0x7F, 0xFF);
	SDL_RenderClear(mainRenderer);

	bird.Render(mainRenderer);

	SDL_RenderPresent(mainRenderer);
}

int
main(int argc, char* argv[])
{
	SDLInit();

	SDL_Event event;
	Timer timer;

	//Main game loop
	while (gameIsRunning) {
		timer.Start();

		EventHandler(&event);

		Update();
		Render();

		if (timer.GetTicks() < (1000 / 60))
			SDL_Delay((1000 / 60) - timer.GetTicks());
	}
	return 0;
}
