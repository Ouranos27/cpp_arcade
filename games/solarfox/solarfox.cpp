/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include "solarfox.hpp"

arc::solarfox::solarfox()
{}

arc::solarfox::solarfox(const solarfox &sol)
{
	static_cast<void>(sol);
}

arc::solarfox::~solarfox()
{}

arc::solarfox	&arc::solarfox::operator=(const solarfox &sol)
{
	static_cast<void>(sol);
	return *this;
}

extern "C" arc::IGameLibrary *GameLibLauncher() {
	return new arc::solarfox();
}
