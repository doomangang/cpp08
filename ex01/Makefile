NAME    = span

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

SRCS    = main.cpp Span.cpp

OBJS    = $(SRCS:.cpp=.o)

DEPS    = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re