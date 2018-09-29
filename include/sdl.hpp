/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by ouranos27,
*/
#ifndef CPP_ARCADE_SDL_HPP
	# define CPP_ARCADE_SDL_HPP

	# include <IGraphicalLibrary.hpp>
	# include <string>
	# include <SDL2/SDL.h>
	# include <SDL2/SDL_ttf.h>

namespace arc {
	class sdl :  public IGraphicalLibrary {
	public:
		sdl();
		sdl(const int &width, const int &height);
		sdl(const sdl &sdl);
		virtual ~sdl();

	public:
		sdl	&operator=(const sdl &sdl);

	public:
		virtual void initWindow(const int &width, const int &height);
		virtual void closeWindow();
		virtual void refreshWindow();
		virtual IGraphicalLibrary::keys getKey();
		virtual bool windowIsOpen() const;
		virtual void printText(const std::string &toPrint, const int &
		, const int &y, const int &color);
		virtual std::string	textField();

	public:
		int	getWidth() const;
		int 	getHeight() const;

	public:
		SDL_Window	*window;
		SDL_Surface	*surface;
		SDL_GLContext 	context;
		bool		isOpen = true;

	private:
		int	_width;
		int 	_height;
	};
}

#endif /* !CPP_ARCADE_SDL_HPP */
