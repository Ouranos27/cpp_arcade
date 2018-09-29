/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_SOLARFOX_HPP
	# define CPP_ARCADE_SOLARFOX_HPP

	# include <vector>
	# include "IGameLibrary.hpp"
	# include "IGraphicalLibrary.hpp"

namespace arc {
	class solarfox : public arc::IGameLibrary {
	public:
		solarfox();

		solarfox(const solarfox &sol);

		virtual ~solarfox();

		/**public:
			void	ghostCell(const int &width, const int &height);*/

	public:
		solarfox &operator=(const solarfox &sol);

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
