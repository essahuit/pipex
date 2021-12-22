CFILES = child_proc_two.c child_proc.c ft_access.c ft_free_two.c ft_path.c ft_split.c \
		 ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		 ft_strstr.c ft_substr.c pipex.c
OFILES = $(CFILES:.c=.o)
CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = pipex.h
AR = ar rcs
RM = rm -rf
NAME = pipex.a

%.o : %.c
	$(CC) $(FLAGS) $< -c 
	$(AR) $(NAME) $@

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) main.c $(NAME) -o pipex
all : $(NAME)
	

clean :
	$(RM) $(OFILES) $(OFILES_B)

fclean : clean
	$(RM) $(NAME) pipex

re : fclean all