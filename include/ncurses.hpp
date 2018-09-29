/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by muffwin,
*/
#ifndef CPP_ARCADE_NCURSES_HPP
#define CPP_ARCADE_NCURSES_HPP

#include <ncurses.h>
#include "ncurses.hpp"
#include "IGraphicalLibrary.hpp"

namespace arc {
	class ncurses: public IGraphicalLibrary {
		public:
			ncurses();
			ncurses(const int &width, const int &height);
			ncurses(const ncurses &nc);
			virtual ~ncurses();

		public:
			ncurses &operator=(ncurses &nc);

		public:
			virtual void initWindow(const int &width, const int &height);
			virtual void closeWindow();
			virtual void refreshWindow();
			virtual IGraphicalLibrary::keys getKey();
			virtual bool windowIsOpen() const;
			virtual void printText(const std::string &toPrint
			, const int &x, const int &y, const int &color);
			virtual std::string	textField();

		public:
			int getWidth() const;
			int getHeight() const;
			int isOpen;

		public:
			WINDOW *window;

		private:
			int _width;
			int _height;
	};
}

#endif //CPP_ARCADE_NCURSES_HPP
