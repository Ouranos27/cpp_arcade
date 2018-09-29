/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include <iostream>
#include "sdl.hpp"

arc::sdl::sdl()
: _width(0), _height(0)
{}

arc::sdl::sdl(const int &width, const int &height)
: _width(width), _height(height)
{}

arc::sdl::sdl(const sdl &sdl)
{
	_width = sdl.getWidth();
	_height = sdl.getHeight();
}

arc::sdl::~sdl()
{}

int arc::sdl::getWidth() const
{
	return _width;
}

int arc::sdl::getHeight() const
{
	return _height;
}

arc::sdl  &arc::sdl::operator=(const sdl &sdl)
{
	_width = sdl.getWidth();
	_height = sdl.getHeight();
	return *this;
}

void arc::sdl::initWindow(const int &width, const int &height)
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	this->window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED
	, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	this->surface = SDL_GetWindowSurface(this->window);
	this->context = SDL_GL_CreateContext(window);
}

void arc::sdl::refreshWindow()
{
	SDL_UpdateWindowSurface(this->window);
}

void arc::sdl::closeWindow()
{
	TTF_Quit();
	SDL_FreeSurface(this->surface);
	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

arc::IGraphicalLibrary::keys	switchKeys(const SDL_Event &event)
{
	switch (event.key.keysym.scancode) {
	case SDL_SCANCODE_ESCAPE :
		return arc::IGraphicalLibrary::ESC;
	case SDL_SCANCODE_Z :
		return arc::IGraphicalLibrary::UP;
	case SDL_SCANCODE_S :
		return arc::IGraphicalLibrary::DOWN;
	case SDL_SCANCODE_Q :
		return arc::IGraphicalLibrary::LEFT;
	case SDL_SCANCODE_D :
		return arc::IGraphicalLibrary::RIGHT;
	case SDL_SCANCODE_RIGHT :
		return arc::IGraphicalLibrary::NEXT_LIB;
	case SDL_SCANCODE_LEFT :
		return arc::IGraphicalLibrary::PREV_LIB;
	case SDL_SCANCODE_RSHIFT :
		return arc::IGraphicalLibrary::NEXT_GAME;
	case SDL_SCANCODE_LSHIFT :
		return arc::IGraphicalLibrary::PREV_GAME;
	case SDL_SCANCODE_UP :
		return arc::IGraphicalLibrary::MENU_UP;
	case SDL_SCANCODE_DOWN :
		return arc::IGraphicalLibrary::MENU_DOWN;
	case SDL_SCANCODE_F5 :
		return arc::IGraphicalLibrary::RESTART_GAME;
	case SDL_SCANCODE_KP_ENTER :
		return arc::IGraphicalLibrary::ENTER;
	case SDL_SCANCODE_BACKSPACE :
		return arc::IGraphicalLibrary::BACKSPACE;
	default:
		return arc::IGraphicalLibrary::NO_KEY_ENTERED;
	}
}

arc::IGraphicalLibrary::keys arc::sdl::getKey()
{
	arc::IGraphicalLibrary::keys key = NO_KEY_ENTERED;
	SDL_Event	event;

	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			isOpen = false;
		key = switchKeys(event);
	}
	return key;
}


void arc::sdl::printText(const std::string &toPrint, const int &x,
const int &y, const int &col)
{
	static_cast<void>(x);
	static_cast<void>(y);
	static_cast<void>(toPrint);
	static_cast<void>(col);
}

std::string arc::sdl::textField()
{
	std::string	str("");

	return str;
}

bool arc::sdl::windowIsOpen() const
{


	if (this->isOpen == true) {
		return true;
	}
	return false;
}

extern "C" arc::IGraphicalLibrary *GraphicalLibLauncher() {
	return new arc::sdl();
}