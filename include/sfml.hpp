/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_SFML_HPP
	# define CPP_ARCADE_SFML_HPP

	# include <SFML/Graphics.hpp>
	# include "IGraphicalLibrary.hpp"

namespace arc {
	class sfml : public IGraphicalLibrary {
	public:
		sfml();
		sfml(const int &width, const int &height);
		sfml(const sfml &sf);
		virtual ~sfml();

	public:
		sfml &operator=(sfml &sf);

	public:
		virtual void initWindow(const int &width, const int &height);
		virtual void closeWindow();
		virtual void refreshWindow();
		virtual IGraphicalLibrary::keys getKey();
		virtual bool windowIsOpen() const;
		virtual void printText(const std::string &toPrint, const int &x
		, const int &y, const int &color);
		virtual std::string	textField();
	public:
		int getWidth() const;
		int getHeight() const;

	public:
		sf::RenderWindow *window;

	private:
		int _width;
		int _height;
	};
}

#endif /* !CPP_ARCADE_SFML_HPP */