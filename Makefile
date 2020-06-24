# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 14:23:06 by twitting          #+#    #+#              #
#    Updated: 2020/03/15 23:03:11 by ebednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42run
SRC =	./src/main.cpp \
		./src/application.cpp \
		./src/render.cpp \
		./src/shader.cpp \
		./src/utils.cpp
OBJECTS = $(SRC:.cpp=.o)
FLAGS = -std=c++11 -Wall -Wextra -Werror
INCLUDES = -I include -I GLFW/include
FRAMEWORKS = -framework OpenGL -framework Cocoa -framework IOKit
LIBGLFW = -L./GLFW/lib-macos -lglfw3

all: $(NAME)

$(NAME): $(OBJECTS)
	g++ $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBGLFW) $(FRAMEWORKS) -o $(NAME)

%.o: %.cpp
	g++ $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
