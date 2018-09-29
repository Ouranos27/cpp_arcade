/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include "centipede.hpp"

arc::centipede::centipede()
{}

arc::centipede::centipede(const centipede &cen)
{
	static_cast<void>(cen);
}

arc::centipede::~centipede()
{}

arc::centipede	&arc::centipede::operator=(const centipede &cen)
{
	static_cast<void>(cen);
	return *this;
}

extern "C" arc::IGameLibrary *GameLibLauncher() {
	return new arc::centipede();
}
