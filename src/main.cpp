/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include "sfml.hpp"
#include "handler.hpp"

int		main(int ac, char **av)
{
	arc::handler	*launch;

	if (ac != 2) {
		return 84;
	}
	if (fopen(av[1], "r") && av[1][0] == '.' && av[1][1] == '/') {
		try {
			launch = new arc::handler(std::string(av[1]));
			launch->launcher(1080, 720);
		} catch (const std::exception &exception) {
			std::runtime_error(exception.what());
		}
		return 0;
	}
	return 84;
}