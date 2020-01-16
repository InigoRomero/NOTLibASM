
NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ =  ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o
CC = nasm -f macho64
CCTWO = ar rcs libasm.a
RM = rm -f
all: $(NAME)
$(NAME): 
	${CC} ft_strlen.s && ${CC} ft_strcpy.s && ${CC} ft_strcmp.s && ${CC} ft_write.s && ${CC} ft_read.s && ${CC} ft_strdup.s
	${CCTWO} ${OBJ}      
bonus:
	${CC}  ${SRC} ${SRCBONUS}
	${CCTWO} ${OBJ} ${OBJBONUS}
fclean:
	${RM} ${OBJ} ${OBJBONUS}
	${RM} ${NAME} ${OBJBONUS}
clean:
	${RM} ${OBJ} ${OBJBONUS}
re: fclean all
.PHONY: all clean fclean re bonus