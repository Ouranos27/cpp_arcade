/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include "pacman.hpp"

arc::pacman::pacman()
{}

arc::pacman::pacman(const pacman &pac)
{
	static_cast<void>(pac);
}

arc::pacman::~pacman()
{}

arc::pacman	&arc::pacman::operator=(const pacman &pac)
{
	static_cast<void>(pac);
	return *this;
}

extern "C" arc::IGameLibrary *GameLibLauncher() {
	return new arc::pacman();
}