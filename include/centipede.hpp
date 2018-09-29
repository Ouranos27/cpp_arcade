/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_CENTIPEDE_HPP
	# define CPP_ARCADE_CENTIPEDE_HPP

	# include <vector>
	# include "IGameLibrary.hpp"
	# include "IGraphicalLibrary.hpp"

namespace arc {
	class centipede : public arc::IGameLibrary {
	public:
		centipede();

		centipede(const centipede &cen);

		virtual ~centipede();

		/**public:
			void	ghostCell(const int &width, const int &height);*/

	public:
		centipede &operator=(const centipede &cen);

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

#endif /* !CPP_ARCADE_NIBBLER_HPP */
