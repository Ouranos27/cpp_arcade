/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_HANDLER_HPP
	# define CPP_ARCADE_HANDLER_HPP

	# include <string>
	# include <vector>
	# include "IGraphicalLibrary.hpp"
	# include "IGameLibrary.hpp"

namespace arc {
	class handler {

	public:
		handler();
		handler(const std::string &name);
		handler(const handler &handle);
		~handler();

	public:
		handler &operator=(const handler &handler);

		/** Getters */
	public:
		std::string		getLibName() const;
		IGraphicalLibrary	*getLib() const;
		void			*getHandleLib() const;
		void			*getHandleGame() const;
		int			getWidth() const;
		int			getHeight() const;
		std::string		getUserName() const;

		/** Setters */
	public:
		void	setLib(arc::IGraphicalLibrary *lib);
		void	setCurrentLibName(const std::string &name);
		void	setGame(arc::IGameLibrary *game);
		void	setCurrentGame(const std::string &name);
		void	setlibsNames();
		void	setHandleLib(void *handle);
		void	setHandleGame(void *handle);
		void 	setWidth(const int &width);
		void	setHeight(const int &height);
		void	setUserName(const std::string &userName);

	public:
		void changeGraphicLib(const arc::IGraphicalLibrary::keys key);
		void changeGameLib(const arc::IGraphicalLibrary::keys key);
		void launcher(const int &width, const int &height);
		void loadGraphicalLibrary(const std::string &name);
		void loadGameLibrary(const std::string &name);
		bool modeleController(arc::IGraphicalLibrary::keys key,
			arc::IGraphicalLibrary *lib);
		void menu(arc::IGraphicalLibrary::keys key);
		void second_menu(arc::IGraphicalLibrary::keys key);
		void third_menu(arc::IGraphicalLibrary::keys key);

	private:
		IGraphicalLibrary *_lib;
		IGameLibrary *_Game;
		std::string _currentLibName;
		std::string _currentGame;
		void *_handleLib;
		void *_handleGame;
		std::string _userName;
		int _width;
		int _height;
		std::vector<std::string> _GraphicLibsNames;
		std::vector<std::string> _GameLibsNames;
	};
}

#endif /* !CPP_ARCADE_HANDLER_HPP */