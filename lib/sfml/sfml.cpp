/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include <iostream>
#include "sfml.hpp"

arc::sfml::sfml()
: _width(), _height()
{}

arc::sfml::sfml(const int &width, const int &height)
: _width(width), _height(height)
{}

arc::sfml::sfml(const sfml &sf)
{
	_width = sf.getWidth();
	_height = sf.getHeight();
}

arc::sfml::~sfml()
{}

arc::sfml	&arc::sfml::operator=(sfml &sf)
{
	_width = sf.getWidth();
	_height = sf.getHeight();
	return *this;
}

int	arc::sfml::getWidth() const
{
	return _width;
}

int 	arc::sfml::getHeight() const
{
	return _height;
}

void	arc::sfml::initWindow(const int &width, const int &height)
{
	this->window = new sf::RenderWindow(sf::VideoMode(width, height),
	"Arcade", sf::Style::Close | sf::Style::Resize);
}

void	arc::sfml::refreshWindow()
{
	this->window->display();
}

void	arc::sfml::closeWindow()
{
	this->window->close();
}

static arc::IGraphicalLibrary::keys	switchKeys(sf::Event &event)
{
	switch (event.key.code) {
	case sf::Keyboard::Escape :
		return arc::IGraphicalLibrary::ESC;
	case sf::Keyboard::Z :
		return arc::IGraphicalLibrary::UP;
	case sf::Keyboard::S :
		return arc::IGraphicalLibrary::DOWN;
	case sf::Keyboard::Q :
		return arc::IGraphicalLibrary::LEFT;
	case sf::Keyboard::D :
		return arc::IGraphicalLibrary::RIGHT;
	case sf::Keyboard::Right :
		return arc::IGraphicalLibrary::NEXT_LIB;
	case sf::Keyboard::Left :
		return arc::IGraphicalLibrary::PREV_LIB;
	case sf::Keyboard::RShift :
		return arc::IGraphicalLibrary::NEXT_GAME;
	case sf::Keyboard::LShift :
		return arc::IGraphicalLibrary::PREV_GAME;
	case sf::Keyboard::F12 :
		return arc::IGraphicalLibrary::GO_BACK_TO_MENU;
	case sf::Keyboard::Up :
		return arc::IGraphicalLibrary::MENU_UP;
	case sf::Keyboard::Down :
		return arc::IGraphicalLibrary::MENU_DOWN;
	case sf::Keyboard::F5 :
		return 	arc::IGraphicalLibrary::RESTART_GAME;
	case sf::Keyboard::Return :
		return arc::IGraphicalLibrary::ENTER;
	case sf::Keyboard::BackSpace :
		return arc::IGraphicalLibrary::BACKSPACE;
	default:
		return arc::IGraphicalLibrary::NO_KEY_ENTERED;
	}
}

arc::IGraphicalLibrary::keys	arc::sfml::getKey()
{
	IGraphicalLibrary::keys	key = IGraphicalLibrary::NO_KEY_ENTERED;
	sf::Event event;

	if (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		} else if (event.type == sf::Event::KeyPressed) {
			key = switchKeys(event);
		}
	}
	return key;
}

bool	arc::sfml::windowIsOpen() const
{
	if (window->isOpen()) {
		this->window->clear(sf::Color::Black);
		return true;
	}
	return false;
}

void arc::sfml::printText(const std::string &toPrint, const int &x,
const int &y, const int &color)
{
	sf::Font font;
	sf::Text text;
	bool check;

	check = font.loadFromFile("./lib/fonts/04B_30__.TTF");
	if (!check)
		throw std::runtime_error("Couldn't load the font");
	text.setFont(font);
	text.setString(toPrint);
	text.setCharacterSize(30);
	if (color == 0)
		text.setColor(sf::Color::White);
	else if (color == 1)
		text.setColor(sf::Color::Yellow);
	text.setPosition(static_cast<float>(x), static_cast<float>(y));
	text.setStyle(sf::Text::Regular);
	window->draw(text);
}

std::string arc::sfml::textField()
{
	sf::Event event;
	std::string str;

	if (window->pollEvent(event)) {
		if (event.type == sf::Event::TextEntered
		&& event.text.unicode >= 32 && event.text.unicode <= 126) {
				str += static_cast<char>(event.text.unicode);
				std::cout << str << std::endl;
			}
	}
	return str;
}

extern "C" arc::IGraphicalLibrary *GraphicalLibLauncher() {
	return new arc::sfml();
}