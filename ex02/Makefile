NAME = identifier
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/
SRCS = $(SRC_DIR)Base.cpp $(SRC_DIR)main.cpp
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
HEADERS = $(INC_DIR)Base.hpp $(INC_DIR)A.hpp $(INC_DIR)B.hpp $(INC_DIR)C.hpp

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
