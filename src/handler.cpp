/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/

#include <dlfcn.h>
#include <iostream>
#include "handler.hpp"

arc::handler::handler()
: _lib(), _currentLibName(std::string()), _handleLib(), _handleGame(), _width()
, _height()
{
	this->setlibsNames();
}

arc::handler::handler(const handler &handle)
{
	_lib = handle.getLib();
	_currentLibName = handle.getLibName();
	_handleLib = handle.getHandleLib();
	_handleGame = handle.getHandleGame();
	_width = handle.getWidth();
	_height = handle.getHeight();
	this->setlibsNames();
}

arc::handler::handler(const std::string &name)
: _lib(), _currentLibName(name), _handleLib(), _handleGame(), _width()
, _height()
{
	this->setlibsNames();
	this->loadGraphicalLibrary(name);
}

arc::handler	&arc::handler::operator=(const arc::handler &handle)
{
	_lib = handle.getLib();
	_currentLibName = handle.getLibName();
	_handleLib = handle.getHandleLib();
	_handleGame = handle.getHandleGame();
	_width = handle.getWidth();
	_height = handle.getHeight();
	this->setlibsNames();
	return *this;
}

arc::handler::~handler()
{}

void	arc::handler::loadGraphicalLibrary(const std::string &name)
{
	void		*handle;
	IGraphicalLibrary	*(*libTemp)();

	try {
		handle = dlopen(name.c_str(), RTLD_LAZY);
		this->setHandleLib(handle);
	} catch (const std::exception &exception) {
		throw std::runtime_error(dlerror());
	}
	try {
		libTemp = reinterpret_cast<IGraphicalLibrary *(*)()>(dlsym(
			handle, "GraphicalLibLauncher"));
	} catch (const std::exception &exception) {
		throw std::runtime_error(dlerror());
	}
	this->setLib(libTemp());
	this->setCurrentLibName(name);
}

void	arc::handler::loadGameLibrary(const std::string &name)
{
	void	*handle;
	IGameLibrary *(*libTemp)();

	try {
		handle = dlopen(name.c_str(), RTLD_LAZY);
		this->setHandleGame(handle);
	} catch (const std::exception &exception) {
		throw std::runtime_error(dlerror());
	}
	try {
		libTemp = reinterpret_cast<IGameLibrary *(*)()>(dlsym(handle,
		"GameLibLauncher"));
	} catch (const std::exception &exception) {
		throw std::runtime_error(dlerror());
	}
	this->setGame(libTemp());
	this->setCurrentGame(name);
}

std::string	arc::handler::getLibName() const
{
	return _currentLibName;
}

arc::IGraphicalLibrary	*arc::handler::getLib() const
{
	return _lib;
}

void *arc::handler::getHandleLib() const
{
	return _handleLib;
}

void *arc::handler::getHandleGame() const
{
	return _handleGame;
}

int arc::handler::getWidth() const
{
	return _width;
}

int arc::handler::getHeight() const
{
	return _height;
}

std::string arc::handler::getUserName() const
{
	return _userName;
}

void 	arc::handler::setLib(arc::IGraphicalLibrary *lib)
{
	this->_lib = lib;
}

void 	arc::handler::setCurrentLibName(const std::string &name)
{
	this->_currentLibName = name;
}

void arc::handler::setGame(arc::IGameLibrary *game)
{
	this->_Game = game;
}

void arc::handler::setCurrentGame(const std::string &name)
{
	this->_currentGame = name;
}

void	arc::handler::setlibsNames()
{
	this->_GraphicLibsNames.push_back("./lib_arcade_sfml.so");
	this->_GraphicLibsNames.push_back("./lib_arcade_ncurses.so");
	this->_GraphicLibsNames.push_back("./lib_arcade_sdl.so");

	this->_GameLibsNames.push_back("./lib_arcade_pacman.so");
}

void arc::handler::setHandleLib(void *handle)
{
	this->_handleLib = handle;
}

void arc::handler::setHandleGame(void *handle)
{
	this->_handleGame = handle;
}

void arc::handler::setWidth(const int &width)
{
	this->_width = width;
}

void arc::handler::setHeight(const int &height)
{
	this->_height = height;
}

void arc::handler::setUserName(const std::string &userName)
{
	this->_userName = userName;
}

static size_t	libNum(std::vector<std::string> libs, std::string currentLib)
{
	size_t i = 0;

	for (; i < libs.size(); i++) {
		if (libs.at(i).compare(currentLib) == 0)
			return (i);
	}
	return (i);
}

void	arc::handler::changeGraphicLib(arc::IGraphicalLibrary::keys key)
{
	std::size_t i = libNum(_GraphicLibsNames, _currentLibName);

	_lib->closeWindow();
	delete(_lib);
	try {
		dlclose(_handleLib);
	} catch (const std::exception &exception) {
		throw std::runtime_error(dlerror());
	}
	if (key == arc::IGraphicalLibrary::NEXT_LIB) {
		i++;
		if (i == 3)
			i = 0;
		this->loadGraphicalLibrary(_GraphicLibsNames.at(i));
	} else if (key == arc::IGraphicalLibrary::PREV_LIB) {
		if (i == 0)
			i = 2;
		else
			i--;
		this->loadGraphicalLibrary(_GraphicLibsNames.at(i));
	} else {
		this->loadGraphicalLibrary(_GraphicLibsNames.at(0));
	}
	_lib->initWindow(_width, _height);
}

void arc::handler::changeGameLib(const arc::IGraphicalLibrary::keys key)
{
	//std::size_t i = libNum(_GraphicLibsNames, _currentLibName);
	delete(_Game);
	try {
		dlclose(_handleGame);
	} catch (const std::exception &exception) {
		throw std::runtime_error(dlerror());
	}
	static_cast<void>(key);
}

static int	keyExitCheck(arc::IGraphicalLibrary::keys key) noexcept
{
	switch (key) {
	case  arc::IGraphicalLibrary::ESC :
		return 1;
	case arc::IGraphicalLibrary::NEXT_LIB :
		return 2;
	case arc::IGraphicalLibrary::PREV_LIB :
		return 2;
	case arc::IGraphicalLibrary::NEXT_GAME :
		return 3;
	case arc::IGraphicalLibrary::PREV_GAME :
		return 3;
	default:
		return 0;
	}
}

bool	arc::handler::modeleController(arc::IGraphicalLibrary::keys key,
arc::IGraphicalLibrary *lib)
{
	int	check;

	this->menu(key);
	check = keyExitCheck(key);
	switch (check) {
	case 1 :
		lib->closeWindow();
		return true;
	case 2 :
		this->changeGraphicLib(key);
		break;
	case 3:
		this->changeGameLib(key);
		break;
	default:
		return false;
	}
	return false;
}

void arc::handler::third_menu(arc::IGraphicalLibrary::keys key)
{
	static bool check = true;
	static int pacman = 1;

	if (check == true) {
		this->getLib()->printText(std::string("WELCOME "
		+ this->getUserName() + " IN THE ARCADE") ,100, 1, 0);
		this->getLib()->printText(std::string("Select Your Game Below"),
			100, 90, 0);
		this->getLib()->printText(std::string("Pacman"), 100, 230
		, pacman);
		if (key == arc::IGraphicalLibrary::ENTER) {
			check = false;
			this->loadGameLibrary(_GameLibsNames.at(0));
		}
	}
}

void arc::handler::second_menu(arc::IGraphicalLibrary::keys key)
{
	static bool libCheck = true;
	static int	i = 0;
	static int	sfml = 1;
	static int	ncurses = 0;
	static int	sdl = 0;

	if (libCheck == true) {
		this->getLib()->printText(std::string("WELCOME "
		+ this->getUserName() + " IN THE ARCADE") ,100, 1, 0);
		this->getLib()->printText(std::string("Select Your Graphical library Below"),
			100, 90, 0);
		this->getLib()->printText(std::string("SFML"),100, 230, sfml);
		this->getLib()->printText(std::string("NCURSES"),100, 290, ncurses);
		this->getLib()->printText(std::string("SDL"), 100, 350, sdl);
			if (sfml == 1 && key == arc::IGraphicalLibrary::MENU_DOWN) {
			i++;
			std::cout << i << std::endl;
			ncurses = 1;
			sfml = 0;
		} else if (ncurses == 1 && key == arc::IGraphicalLibrary::MENU_DOWN) {
			i++;
			std::cout << i << std::endl;
			sdl = 1;
			ncurses = 0;
		} else {
			if (i == 2 && sdl == 1
			&& key == arc::IGraphicalLibrary::MENU_DOWN) {
				i = 0;
				std::cout << i << std::endl;
				sfml = 1;
				sdl = 0;
			}
		}
		if (sfml == 1 && key == arc::IGraphicalLibrary::MENU_UP) {
			i = 2;
			std::cout << i << std::endl;
			sfml = 0;
			sdl = 1;
		} else if (ncurses == 1 && key == arc::IGraphicalLibrary::MENU_UP) {
			i--;
			std::cout << i << std::endl;
			ncurses = 0;
			sfml = 1;
		} else {
			if (i == 2 && sdl == 1
			&& key == arc::IGraphicalLibrary::MENU_UP) {
				i--;
				std::cout << i << std::endl;
				ncurses = 1;
				sdl = 0;
			}
		}
		if (key == arc::IGraphicalLibrary::ENTER) {
			libCheck = false;
			if (this->getLibName().compare(_GraphicLibsNames.at(i)) != 0)
				this->loadGraphicalLibrary(_GraphicLibsNames.at(i));
		}
	} else
		third_menu(key);
}

void arc::handler::menu(arc::IGraphicalLibrary::keys key)
{
	static std::string str;
	static bool first_menu = true;

	if (first_menu == true) {
		this->getLib()->printText(std::string("WELCOME IN THE ARCADE"),
			_width / 3 - 100, 1, 0);
		this->getLib()->printText(
			std::string("Please Your UserName Below"),
			_width / 3 - 150, 90, 0);
		static_cast<void>(key);
		str += this->getLib()->textField();
		if (key == arc::IGraphicalLibrary::BACKSPACE && str.size() >= 1)
			str.erase(str.size() - 1);
		this->getLib()->printText(std::string(str), _width / 3 - 150,
			190, 0);
		if (key == arc::IGraphicalLibrary::ENTER) {
			this->setUserName(str);
			first_menu = false;
		}
	} else {
		second_menu(key);
	}
}

void	arc::handler::launcher(const int &width, const int &height)
{
	IGraphicalLibrary::keys	key;

	this->setWidth(width);
	this->setHeight(height);
	this->getLib()->initWindow(width, height);
	while (this->getLib()->windowIsOpen()) {
		key = this->getLib()->getKey();
		if (modeleController(key, this->getLib()) == true)
			break;
		this->getLib()->refreshWindow();
	}
}
