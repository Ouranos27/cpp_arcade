##
## EPITECH PROJECT, 2018
## arcade
## File description:
## arcade project
##

SRC		        =	src/main.cpp \
                    src/handler.cpp \

OBJ		        =	$(SRC:.cpp=.o)

NAME            =	arcade


SRC_SFML	    =	./lib/sfml/sfml.cpp	\

SRC_NCURSES     =   ./lib/ncurses/ncurses.cpp \

SRC_SDL			=	./lib/sdl/sdl.cpp \

OBJ_SFML	    =	$(SRC_SFML:.cpp=.o)

OBJ_NCURSES     =   $(SRC_NCURSES:.cpp=.o)

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

NAME_SFML	    =	./lib_arcade_sfml.so

NAME_NCURSES   =   ./lib_arcade_ncurses.so

NAME_SDL		=	./lib_arcade_sdl.so


SRC_PACMAN		=	./games/pacman/pacman.cpp \

OBJ_PACMAN		=	$(SRC_PACMAN:.cpp=.o)

NAME_PACMAN		=	./lib_arcade_pacman.so

SRC_NIBBLER		=	./games/nibbler/nibbler.cpp \

OBJ_NIBBLER		=	$(SRC_NIBBLER:.cpp=.o)

NAME_NIBBLER		=	./lib_arcade_nibbler.so

SRC_QIX			=	./games/qix/qix.cpp \

OBJ_QIX			=	$(SRC_QIX:.cpp=.o)

NAME_QIX		=	./lib_arcade_qix.so

SRC_CENTIPEDE		=	./games/centipede/centipede.cpp \

OBJ_CENTIPEDE		=	$(SRC_CENTIPEDE:.cpp=.o)

NAME_CENTIPEDE		=	./lib_arcade_centipede.so

SRC_SOLARFOX		=	./games/solarfox/solarfox.cpp \

OBJ_SOLARFOX		=	$(SRC_SOLARFOX:.cpp=.o)

NAME_SOLARFOX		=	./lib_arcade_solarfox.so


CXXFLAGS	    +=	-W -Wall -Wextra -Werror -fPIC -std=c++11 -I./include -I./lib/interfaces

LDFLAG	        +=	-ldl

SFMLFLAGS	    =	-lsfml-graphics -lsfml-window -lsfml-system

SDLFLAGS		= 	-lSDL2 -lSDL2_ttf


NCURSESFLAGS    =   -lncurses

CXX 	=	g++



all:	$(NAME) $(NAME_SFML) $(NAME_NCURSES) $(NAME_SDL) $(NAME_PACMAN) $(NAME_NIBBLER) $(NAME_QIX) $(NAME_CENTIPEDE) $(NAME_SOLARFOX)

core:	$(NAME)

graphicals: $(NAME_SFML) $(NAME_NCURSES) $(NAME_SDL)

games:	$(NAME_PACMAN) $(NAME_NIBBLER) $(NAME_QIX) $(NAME_CENTIPEDE) $(NAME_SOLARFOX)



$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAG)

$(NAME_SFML): $(OBJ_SFML)
	$(CXX) -shared $(OBJ_SFML) -o $(NAME_SFML) $(SFMLFLAGS)
	mv $(NAME_SFML) ./lib

$(NAME_NCURSES): $(OBJ_NCURSES)
	$(CXX) -shared $(OBJ_NCURSES) -o $(NAME_NCURSES) $(NCURSESFLAGS)
	mv $(NAME_NCURSES) ./lib

$(NAME_SDL): $(OBJ_SDL)
	$(CXX) -shared $(OBJ_SDL) -o $(NAME_SDL) $(SDLFLAGS)
	mv $(NAME_SDL) ./lib

$(NAME_PACMAN): $(OBJ_PACMAN)
	$(CXX) -shared $(OBJ_PACMAN) -o $(NAME_PACMAN)
	mv $(NAME_PACMAN) ./games

$(NAME_NIBBLER): $(OBJ_NIBBLER)
	$(CXX) -shared $(OBJ_NIBBLER) -o $(NAME_NIBBLER)
	mv $(NAME_NIBBLER) ./games

$(NAME_QIX): $(OBJ_QIX)
	$(CXX) -shared $(OBJ_QIX) -o $(NAME_QIX)
	mv $(NAME_QIX) ./games

$(NAME_CENTIPEDE): $(OBJ_CENTIPEDE)
	$(CXX) -shared $(OBJ_CENTIPEDE) -o $(NAME_CENTIPEDE)
	mv $(NAME_CENTIPEDE) ./games

$(NAME_SOLARFOX): $(OBJ_SOLARFOX)
	$(CXX) -shared $(OBJ_SOLARFOX) -o $(NAME_SOLARFOX)
	mv $(NAME_SOLARFOX) ./games

clean:
	rm -f $(OBJ) $(OBJ_SFML) $(OBJ_NCURSES) $(OBJ_SDL) $(OBJ_PACMAN) $(OBJ_NIBBLER) $(OBJ_QIX) $(OBJ_CENTIPEDE) $(OBJ_SOLARFOX)

fclean: clean
	rm -f $(NAME) ./lib/$(NAME_SFML) ./lib/$(NAME_NCURSES) ./lib/$(NAME_SDL) ./games/$(NAME_PACMAN) ./games/$(NAME_NIBBLER) ./games/$(NAME_QIX) ./games/$(NAME_CENTIPEDE) ./games/$(NAME_SOLARFOX)

re: fclean all

debug: CXXFLAGS += -g -g3
debug:	fclean
debug: all

.PHONY: all clean fclean re debug
