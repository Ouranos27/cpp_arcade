/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_IGAMELIBRARY_HPP
	#define CPP_ARCADE_IGAMELIBRARY_HPP

	# include <string>
	# include <vector>
	# include "IGraphicalLibrary.hpp"

namespace	arc {

	struct position {
		std::size_t	x;
		std::size_t 	y;
	};

	enum	status {
		WIN,
		GAME_OVER,
		GAME_CONTINUE
	};

	class	IGameLibrary {
	public:
		virtual ~IGameLibrary() = default;

	public:
		virtual size_t	getScore() const = 0;

	public:
		virtual void	setPosition() = 0;
		virtual void	setMoves(arc::IGraphicalLibrary::keys key) = 0;

	public:
		virtual void	stopTheGame() = 0;

	/**public:
		virtual std::vector<std::string, position>	*pos;*/
		//TODO map getter
	};
}

#endif /* !CPP_ARCADE_IGAMELIBRARY_HPP*/