/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
/**#include <SDL2/SDL.h>
#include <iostream>


int main(int argc, char **argv)
{
	// Notre fenêtre

	SDL_Window* fenetre(0);
	SDL_GLContext contexteOpenGL(0);

	SDL_Event evenements;
	bool terminer(false);


	// Initialisation de la SDL

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}


	// Version d'OpenGL

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);


	// Double Buffer

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	// Création de la fenêtre

	fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if(fenetre == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}


	// Création du contexte OpenGL

	contexteOpenGL = SDL_GL_CreateContext(fenetre);

	if(contexteOpenGL == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(fenetre);
		SDL_Quit();

		return -1;
	}


	// Boucle principale

	while(!terminer)
	{
		SDL_WaitEvent(&evenements);

		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = true;
	}


	// On quitte la SDL

	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();

	return 0;
}*/
#include "SDL2/SDL.h"

#include "SDL2/SDL_ttf.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

const char* WINDOW_TITLE = "SDL Start";


int main(int argc, char **argv)
{

	SDL_Init( SDL_INIT_VIDEO );

	TTF_Init();


	SDL_Surface* screen = SDL_SetVideoMode( WINDOW_WIDTH, WINDOW_HEIGHT, 0, SDL_HWSURFACE | SDL_DOUBLEBUF );

	SDL_WM_SetCaption( WINDOW_TITLE, 0 );
	TTF_Font* font = TTF_OpenFont("ARIAL.TTF", 12);

	SDL_Color foregroundColor = { 255, 255, 255 };
	SDL_Color backgroundColor = { 0, 0, 255 };

	SDL_Surface* textSurface = TTF_RenderText_Shaded(font, "This is my text.", foregroundColor, backgroundColor);

	// Pass zero for width and height to draw the whole surface
	SDL_Rect textLocation = { 100, 100, 0, 0 };

	SDL_Event event;
	bool gameRunning = true;


	while (gameRunning)
	{

		if (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}

		}

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

		SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

		SDL_Flip(screen);

	}



	SDL_FreeSurface(textSurface);

	TTF_CloseFont(font);
	TTF_Quit();

	SDL_Quit();


	return 0;
}