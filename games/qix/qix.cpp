/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include "qix.hpp"

arc::qix::qix()
{}

arc::qix::qix(const qix &q)
{
	static_cast<void>(q);
}

arc::qix::~qix()
{}

arc::qix	&arc::qix::operator=(const qix &q)
{
	static_cast<void>(q);
	return *this;
}

extern "C" arc::IGameLibrary *GameLibLauncher() {
	return new arc::qix();
}
