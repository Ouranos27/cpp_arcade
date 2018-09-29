/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#ifndef CPP_ARCADE_ILIBRARY_HPP
	# define CPP_ARCADE_ILIBRARY_HPP

	# include <string>

namespace arc {
	class IGraphicalLibrary {

	public:
		virtual ~IGraphicalLibrary() = default;

	public:
		enum keys {
			ESC,
			UP,
			DOWN,
			LEFT,
			RIGHT,
			NEXT_LIB,
			PREV_LIB,
			NEXT_GAME,
			PREV_GAME,
			GO_BACK_TO_MENU,
			MENU_UP,
			MENU_DOWN,
			ENTER,
			RESTART_GAME,
			BACKSPACE,
			NO_KEY_ENTERED
		};

	public:
		virtual void initWindow(const int &width,
		const int &height) = 0;
		virtual void closeWindow() = 0;
		virtual void refreshWindow() = 0;
		virtual keys getKey() = 0;
		virtual bool windowIsOpen() const = 0;
		virtual void printText(const std::string &toPrint, const int &x
		, const int &y, const int &color) = 0;
		virtual std::string	textField() = 0;
	};
}

#endif /* !CPP_ARCADE_ILIBRARY_HPP*/