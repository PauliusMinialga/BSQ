CC = cc
TARGET = bsq
#CFLAGS = -Wall -Wextra -Werror
SRCS = main.c map_funcs.c map_solver.c
OBJS = $(SRCS:.c=.o)
DEPS = bsq.h

all: $(TARGET)

.PHONY: all clean fclean

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re:	fclean all
