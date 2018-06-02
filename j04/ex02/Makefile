CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = fixed

SRC =  AssaultTerminator.cpp TacticalMarine.cpp Squad.cpp  main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all