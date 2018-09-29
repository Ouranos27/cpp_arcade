/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_QIX_HPP
	# define CPP_ARCADE_QIX_HPP

	# include <vector>
	# include "IGameLibrary.hpp"
	# include "IGraphicalLibrary.hpp"

namespace arc {
	class qix : public arc::IGameLibrary {
	public:
		qix();

		qix(const qix &q);

		virtual ~qix();

		/**public:
			void	ghostCell(const int &width, const int &height);*/

	public:
		qix &operator=(const qix &q);

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

#endif /* !CPP_ARCADE_QIX_HPP */
