NAME=	libasm.a

SRCS=	ft_strlen.s		ft_strcpy.s		ft_strcmp.s		\
		 ft_write.s		ft_read.s		ft_strdup.s		\


OBJS= 	$(SRCS:%.s=%.o)

CC= 	nasm

CFLAGS=	-f elf64

%.o:	%.s
		${CC} ${CFLAGS} -D LINUX=1 $<


all: $(NAME)
	clang main.c -I. -L. -lasm

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all