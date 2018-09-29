/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_PACMAN_HPP
	# define CPP_ARCADE_PACMAN_HPP

	# include <vector>
	# include "IGameLibrary.hpp"
	# include "IGraphicalLibrary.hpp"

namespace arc {
	class pacman : public arc::IGameLibrary {
	public:
		pacman();

		pacman(const pacman &pac);

		virtual ~pacman();

		/**public:
			void	ghostCell(const int &width, const int &height);*/

	public:
		pacman &operator=(const pacman &pac);

	public:
		virtual size_t getScore() const;

	public:
		virtual void	setPosition();
		virtual void	setMoves(arc::IGraphicalLibrary::keys key);

	public:
		virtual void	stopTheGame();

	public:
		void	setGhostsMoves();

	};
}

#endif /* !CPP_ARCADE_PACMAN_HPP */