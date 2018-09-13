NAME	=		blockchain

SRC		= 		main.cpp\
				sources/block.cpp\
				sources/blockchain.cpp\
				resources/SHA256/sh256.cpp\
				

OBJ		=       $(SRC:.cpp=.o)

LDFLAGS		+=	

CXXFLAGS	+=	-Wall -ggdb3 -I ./includes -I ./resources -std=c++11

CXX			=	clang++

all			:	$(NAME) 

$(NAME)		:	$(OBJ)
				$(CXX) $^ -o $@ $(LDFLAGS)

clean		:
				rm -vf $(OBJ) 

fclean		:	clean
				rm -vf $(NAME)

re			:	fclean all

.PHONY		:	clean fclean re
