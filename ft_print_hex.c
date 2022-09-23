/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:07:22 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:07:22 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_minus(unsigned int number, t_flags *flags)
{
	int	ans;

	ans = 0;
	if (flags->two_flags != '#')
		ans += ft_putchar_len('0', flags->accuracy - ft_len_of_hex(number));
	if (number && flags->two_flags == '#')
		ans += ft_putchar('0') + ft_putchar(flags->type_specifier);
	if (flags->two_flags == '#')
		ans += ft_putchar_len('0', flags->accuracy - ft_len_of_hex(number));
	if (number || flags->accuracy)
		ans += ft_putstr(ft_dec_to_hex(number, flags->type_specifier == 'X'));
	else if (flags->accuracy != 0)
		ans += ft_putchar(' ');
	ans += ft_putchar_len(' ', flags->width - ans);
	return (ans);
}

static int	ft_print_hex_zero(unsigned int number, t_flags *flags)
{
	int	ans;

	if (flags->accuracy == -1 && flags->width != 0)
		flags->accuracy = flags->width;
	if (ft_len_of_hex(number) > flags->accuracy)
		ans = ft_putchar_len(' ', flags->width - ft_len_of_hex(number));
	else
		ans = ft_putchar_len(' ', flags->width - flags->accuracy);
	ans += ft_putchar_len('0', flags->accuracy - ft_len_of_hex(number));
	if (number || flags->accuracy)
		ans += ft_putstr(ft_dec_to_hex(number, flags->type_specifier == 'X'));
	else if (flags->width > 0)
		ans += ft_putchar(' ');
	return (ans);
}

static int	ft_print_hex_none(unsigned int number, t_flags *flags)
{
	int	ans;

	if (ft_len_of_hex(number) > flags->accuracy)
		ans = ft_putchar_len(' ', flags->width - ft_len_of_hex(number)
				- 2 * (flags->flag == '#' && number));
	else
		ans = ft_putchar_len(' ', flags->width - flags->accuracy
				- 2 * (flags->flag == '#' && number));
	if (flags->flag != '#')
		ans += ft_putchar_len('0', flags->accuracy - ft_len_of_hex(number));
	if (number && flags->flag == '#')
		ans += ft_putchar('0') + ft_putchar(flags->type_specifier);
	if (flags->flag == '#')
		ans += ft_putchar_len('0', flags->accuracy - ft_len_of_hex(number));
	if (number || flags->accuracy)
		ans += ft_putstr(ft_dec_to_hex(number, flags->type_specifier == 'X'));
	else if (flags->width != 0)
		ans += ft_putchar(' ');
	return (ans);
}

int	ft_print_hex(va_list args, t_flags *flags)
{
	unsigned int	number;

	number = va_arg(args, unsigned int);
	if (flags->flag == '-')
		return (ft_print_hex_minus(number, flags));
	if (flags->flag == '0')
		return (ft_print_hex_zero(number, flags));
	return (ft_print_hex_none(number, flags));
}
