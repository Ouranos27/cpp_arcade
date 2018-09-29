/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include "nibbler.hpp"

arc::nibbler::nibbler()
{}

arc::nibbler::nibbler(const nibbler &nib)
{
	static_cast<void>(nib);
}

arc::nibbler::~nibbler()
{}

arc::nibbler	&arc::nibbler::operator=(const nibbler &nib)
{
	static_cast<void>(nib);
	return *this;
}

extern "C" arc::IGameLibrary *GameLibLauncher() {
	return new arc::nibbler();
}
