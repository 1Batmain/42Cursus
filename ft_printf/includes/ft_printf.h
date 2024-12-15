/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <bduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:50:50 by bduval            #+#    #+#             */
/*   Updated: 2024/12/05 18:34:26 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_atrib
{
	size_t	right_padding;
	size_t	left_padding;
	size_t	zero_padding;
	char	right_on;
	char	left_on;
	char	zero_on;
	size_t	precision;
	size_t	precision_on;
	size_t	sign;
	size_t	space;
	size_t	sharp;
	char	signing[3];
	size_t	is_char;
	size_t	hex;
	char	c;
	char	*padding;
	char	*content;
}	t_atrib;

void	ft_put_atrib(t_atrib *a);
size_t	ft_special_strlen(const char *a);
void	ft_initatrib(t_atrib *a);
int		is_specifier(char c);
int		is_flag(char c);
int		is_digit(char c);
char	*ft_init_buf(char **bf, size_t len);
char	to_buf_null(t_atrib *a);
char	to_buf_nil(t_atrib *a);
char	ft_tobuffstr(char *s, t_atrib *atrib);
char	ft_tobuffchar( int c, t_atrib *atrib);
size_t	ft_nbrlen(long nb, int base);
size_t	ft_unbrlen(unsigned long nb, int base);
char	ft_get_hexa(char n, int lowcase);
char	ft_tobuffnbp(void *p, t_atrib *atrib);
char	ft_tobuffnbd(int n, t_atrib *atrib);
char	ft_tobuffnbu(unsigned nb, t_atrib *atrib);
char	ft_tobuffnbx(unsigned nb, t_atrib *atrib, char lowcase);
int		ft_putchar(char c);
void	ft_putstr(char *bf);
size_t	ft_print_buff(char err, t_atrib *a);
size_t	ft_print_arg(const char **c, va_list args, t_atrib *atrib);
void	get_value(const char **s, t_atrib *atrib);
void	ft_get_atrib(const char **s, t_atrib *atrib);
int		ft_printf(const char *str, ...);
int		ft_special_atoi(const char **ptr);
void	*ft_memset(void *mem, int fill, size_t bytes);
#endif
