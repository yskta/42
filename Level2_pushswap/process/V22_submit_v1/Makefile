NAME = push_swap

CC	= cc
CFLAGS = -Wall -Wextra -Werror

LIB		  = ./lib/libft.a

SRCS_DIR		= ./srcs/
SRCS 			= $(addprefix $(SRCS_DIR),\
			0_push_swap.c		\
			1_1_set_array.c		\
			1_2_set_array.c		\
			2_1_init_data.c		\
			2_2_init_data.c		\
			3_0_sort.c			\
			3_1_sort_6_or_less.c	\
			3_2_sort_7_or_more.c	\
			3_3_sort_7_or_more.c	\
			4_confirm_sorted.c		\
			5_free_all.c		\
			6_1_ft_utils.c		\
			6_2_ft_utils.c 		\
			7_1_ops_pa_pb.c			\
			7_2_ops_ra_rb.c			\
			7_3_ops_rra_rrb.c		\
			7_4_ops_sa_sb.c			\
			8_error.c)

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C  ./lib/
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	make clean -C ./lib/
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./lib/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re