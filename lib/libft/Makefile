# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trecomps <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 16:45:26 by trecomps          #+#    #+#              #
#    Updated: 2016/02/23 17:05:58 by trecomps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=				gcc
CFLAGS=			-Wall -Wextra -Werror
NAME=			libft.a
SRC_NAME=		ft_abs.c\
				ft_atoi.c\
				ft_bzero.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd.c\
				ft_lstaddend.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_memalloc.c\
				ft_memdel.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendln.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstrn.c\
				ft_putstr_fd.c\
				ft_strnew.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnequ.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_strpos.c\
				ft_putwchar.c\
				ft_putwstr.c\
				ft_wstrlen.c\
				count_byte.c\
				print_c.c\
				print_d.c\
				print_i.c\
				print_o.c\
				print_p.c\
				print_per.c\
				print_s.c\
				print_u.c\
				print_x.c\
				ft_pow.c\
				ft_printchar.c\
				ft_printwchar.c\
				sizewchar.c\
				ft_printstr.c\
				sizewstr.c\
				ft_printwstr.c\
				ft_print_int.c\
				max.c\
				int_toa_base.c\
				size_int_base.c\
				print_nb_str.c\
				char_toa_base.c\
				llong_toa_base.c\
				short_toa_base.c\
				uchar_toa_base.c\
				uint_toa_base.c\
				ullong_toa_base.c\
				ulong_toa_base.c\
				long_toa_base.c\
				ushort_toa_base.c\
				what_conv.c\
				ft_strupper.c\
				size_long_base.c\
				size_char_base.c\
				size_llong_base.c\
				size_short_base.c\
				ft_printf.c\
				ft_str_empty.c\
				new_get_flag.c
SRC_PATH=		src
OBJ_PATH=		objects
OBJ_NAME=		$(SRC_NAME:.c=.o)
SRC=			$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ= 			$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
IDIR=			./include

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(IDIR)

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
