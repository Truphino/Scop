/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:44:32 by trecomps          #+#    #+#             */
/*   Updated: 2016/02/08 18:06:19 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct			s_data
{
	int					printed;
	int					len_for;
	int					flag;
	int					field;
	int					prec;
	int					len_mod;
}						t_data;

int						no_valid_conv(t_data *data, wchar_t c);
int						new_get_flag(char *str, t_data *data);
char					*ft_str_empty(char *str);
void					ft_memdel(void **ap);
int						ft_isnb(int c);
int						ft_min(int a, int b);
size_t					size_ushort_base(unsigned short n, int base);
size_t					size_ulong_base(unsigned long n, int base);
size_t					size_ullong_base(unsigned long long n, int base);
size_t					size_uint_base(unsigned int n, int base);
size_t					size_uchar_base(unsigned char n, int base);
size_t					size_short_base(short n, int base);
size_t					size_llong_base(long long n, int base);
size_t					size_char_base(char n, int base);
size_t					size_long_base(long n, int base);
void					ft_strupper(char *str);
char					*what_conv(va_list arg, t_data *data, int base);
char					*what_uconv(va_list arg, t_data *data, int base);
char					*ullong_toa_base(unsigned long long n, int base);
char					*llong_toa_base(long long n, int base);
char					*ulong_toa_base(unsigned long n, int base);
char					*long_toa_base(long n, int base);
char					*long_toa_base(long n, int base);
char					*short_toa_base(short int n, int base);
char					*ushort_toa_base(unsigned short int n, int base);
char					*uchar_toa_base(unsigned char n, int base);
char					*char_toa_base(char n, int base);
char					*uint_toa_base(unsigned int n, int base);
void					print_nb_str(char *nb, t_data *data, char *mod);
size_t					size_int_base(int n, int base);
size_t					size_int(int n);
char					*int_toa_base(int n, int base);
int						ft_max(int a, int b);
int						ft_len_int(int n, int base);
void					ft_print_int(int n, int base, t_data *data);
void					ft_putnbr_base(int n, int base);
void					ft_printwstr(wchar_t *str, t_data *data);
int						sizewstr(wchar_t *str);
void					ft_printstr(char *str, t_data *data);
int						sizewchar(int c);
void					ft_printwchar(wchar_t c, t_data *data);
void					ft_printchar(char c, t_data *data);
int						ft_isdigit(int c);
int						ft_pow(int a, int b);
void					get_flag(char *str, t_data *data);
int						count_byte(wchar_t c);
size_t					ft_wstrlen(wchar_t *str);
void					ft_putwchar(wchar_t c);
void					ft_putwstr(wchar_t *str);
int						print_s(t_data *data, va_list arg);
int						print_ls(t_data *data, va_list arg);
int						print_p(t_data *data, va_list arg);
int						print_d(t_data *data, va_list arg);
int						print_ld(t_data *data, va_list arg);
int						print_i(t_data *data, va_list arg);
int						print_o(t_data *data, va_list arg);
int						print_lo(t_data *data, va_list arg);
int						print_u(t_data *data, va_list arg);
int						print_lu(t_data *data, va_list arg);
int						print_x(t_data *data, va_list arg);
int						print_lx(t_data *data, va_list arg);
int						print_c(t_data *data, va_list arg);
int						print_lc(t_data *data, va_list arg);
int						print_per(t_data *data, va_list arg);
int						ft_strpos(const char *s, int c);
int						ft_printf(char *src, ...);
int						ft_abs(int c);
int						ft_atoi(const char *s);
char					*ft_itoa(int n);
void					*ft_memalloc(size_t size);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr(const char *s);
void					ft_putstrn(const char *s);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl(const char *s);
void					ft_putendln(const char *s);
void					ft_putendl_fd(const char *s, int fd);
char					*ft_strnew(size_t size);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strdup(const char *str);
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlen(const char *str);
size_t					ft_strnlen(const char *str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
int						ft_printf(char *format, ...);

#endif
