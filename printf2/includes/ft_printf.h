#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


typedef struct	s_atrib
{
	size_t	right_padding;
	size_t	left_padding;
	size_t	zero_padding;
	size_t	precision;
	size_t	sign;
	size_t	space;
	size_t	sharp;
}	t_atrib;

size_t	ft_strlen(const char *s);
void	ft_initatrib(t_atrib *s);
int	is_specifier(char c);
int	is_flag(char c);
int	is_digit(char c);
void	get_value(char **s, t_atrib *atrib);
void	ft_get_atrib(char **s, t_atrib *atrib);
char	*ft_init_buf(char **bf, size_t len);
char	*ft_tobuffstr(char *s, t_atrib *atrib);
char	*ft_tobuffchar( int c, t_atrib *atrib);
size_t	ft_nbrlen(long n, int base);
size_t	ft_unbrlen(unsigned long nb, int base);
char	ft_get_hexa(char n, int lowcase);
char	*ft_tobuffnbp(void *p, t_atrib *atrib);
char	*ft_tobuffnbd(int n, t_atrib *atrib);
char	*ft_tobuffnbu(unsigned nb);
char	*ft_tobuffnbx(unsigned nb, t_atrib *atrib, char lowcase);
void	ft_putstr(char *bf);
size_t	ft_print_buff(char *buf, t_atrib *atrib);
size_t	ft_print_arg(char c, va_list args, t_atrib *atrib);
int	ft_printf(const char *s, ...);
int	ft_atoi(char **ptr);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *mem, int fill, size_t bytes);
#endif
