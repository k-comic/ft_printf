/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:10:55 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:10:55 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	char	flag;
	int		width;
	int		accuracy;
	char	type_specifier;
	char	two_flags;
}			t_flags;

void		ft_check_flags(const char *str, int *pos,
				t_flags *flags, va_list args);
int			ft_print_argument(va_list args, t_flags *flags);
int			ft_print_char(va_list args, t_flags *flags);
int			ft_print_dec(va_list args, t_flags *flags);
int			ft_print_hex(va_list args, t_flags *flags);
int			ft_print_per(t_flags *flags);
int			ft_print_ptr(va_list args, t_flags *flags);
int			ft_print_str(va_list args, t_flags *flags);
int			ft_printf(const char *format, ...);

int			ft_putchar(char c);
int			ft_putchar_len(char c, int len);
int			ft_isalpha(int c);
size_t		ft_strlen(const char *s);
int			ft_putstr(char *str);
int			ft_len_of_hex(unsigned long long dec);
char		*ft_dec_to_hex(unsigned long long dec, int upper);
int			ft_declen(long long number);
int			ft_putnbr_ll(long long nb);
int			ft_atoi(const char *str);
int			ft_max(int a, int b);
long long	ft_abs_ll(long long a);

#endif