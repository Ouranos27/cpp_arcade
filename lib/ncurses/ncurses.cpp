/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by muffwin,
*/

#include <iostream>
#include <ncurses.h>
#include "ncurses.hpp"

arc::ncurses::ncurses()
	: _width(), _height()
{}

arc::ncurses::ncurses(const int &width, const int &height)
	: _width(width), _height(height)
{}

arc::ncurses::ncurses(const ncurses &nc)
{
	_width = nc.getWidth();
	_height = nc.getHeight();
}

arc::ncurses::~ncurses()
{}

arc::ncurses	&arc::ncurses::operator=(ncurses &nc)
{
	_width = nc.getWidth();
	_height = nc.getHeight();
	return *this;
}

int	arc::ncurses::getWidth() const
{
	return _width;
}

int 	arc::ncurses::getHeight() const
{
	return _height;
}

void	arc::ncurses::initWindow(const int &width, const int &height)
{
	initscr();
	this->window = newwin(height, width, 0, 0);
	keypad(this->window, true);
	this->isOpen = true;
}

void	arc::ncurses::refreshWindow()
{
	wrefresh(this->window);
	wrefresh(this->window);
}

void	arc::ncurses::closeWindow()
{
	wrefresh(this->window);
	delwin(this->window);
	endwin();
	this->isOpen = false;
}

static arc::IGraphicalLibrary::keys	switchKeys(int &ch)
{
	switch (ch) {
	case 'z' :
		return arc::IGraphicalLibrary::UP;
	case 's' :
		return arc::IGraphicalLibrary::DOWN;
	case 'q' :
		return arc::IGraphicalLibrary::LEFT;
	case 'd' :
		return arc::IGraphicalLibrary::RIGHT;
	case 27 :
		return arc::IGraphicalLibrary::ESC;
	case KEY_LEFT :
		return arc::IGraphicalLibrary::PREV_LIB;
	case KEY_RIGHT :
		return arc::IGraphicalLibrary::NEXT_LIB;
	default:
		return arc::IGraphicalLibrary::NO_KEY_ENTERED;
	}
}

arc::IGraphicalLibrary::keys	arc::ncurses::getKey()
{
	IGraphicalLibrary::keys	key = IGraphicalLibrary::NO_KEY_ENTERED;
	int ch;

	ch = wgetch(this->window);
	key = switchKeys(ch);
	return key;
}

bool	arc::ncurses::windowIsOpen() const
{
	return this->isOpen;
}

void printText(const std::string &toPrint, const int &x,
	const int &y, const int &color)
{
	static_cast<void>(toPrint);
	static_cast<void>(x);
	static_cast<void>(y);
	static_cast<void>(color);
}

std::string arc::ncurses::textField()
{
	return NULL;
}

extern "C" arc::IGraphicalLibrary *GraphicalLibLauncher() {
	return new arc::ncurses();
}
