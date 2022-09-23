/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:07:15 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:07:15 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_minus(long long number, t_flags *flags)
{
	int	ans;

	ans = 0;
	if (number < 0)
	{
		ans += ft_putchar('-');
		number = -number;
	}
	else if (flags->two_flags != 'n')
		ans += ft_putchar(flags->two_flags);
	ans += ft_putchar_len('0', flags->accuracy - ft_declen(number));
	if (number || flags->accuracy)
		ans += ft_putnbr_ll(number);
	else if (flags->width > 1 && flags->two_flags != '+')
		ans += ft_putchar(' ');
	ans += ft_putchar_len(' ', flags->width - ans);
	return (ans);
}

static int	ft_print_zero(long long number, t_flags *flags)
{
	int	ans;
	int	len;

	ans = 0;
	len = ft_max(ft_declen(number), flags->accuracy);
	len += (number < 0);
	if (flags->accuracy == -1)
	{
		if (number < 0)
			ans += ft_putchar('-');
		ans += ft_putchar_len('0', flags->width - len);
	}
	else
	{
		ans += ft_putchar_len(' ', flags->width - len);
		if (number < 0)
			ans += ft_putchar('-');
	}
	ans += ft_putchar_len('0', flags->accuracy - ft_declen(number));
	if (number || flags->accuracy)
		ans += ft_putnbr_ll(ft_abs_ll(number));
	else if (flags->width > 0)
		ans += ft_putchar(' ');
	return (ans);
}

static int	ft_print(long long number, t_flags *flags)
{
	int	ans;
	int	len;

	ans = 0;
	len = ft_max(ft_declen(number), flags->accuracy);
	len += (number < 0);
	ans += ft_putchar_len(' ', flags->width - len
			- ((flags->flag != -1) && number >= 0));
	if (!(flags->accuracy || number) && flags->flag != -1 && flags->width > 1)
		ans += ft_putchar(' ');
	if (number < 0)
	{
		ans += ft_putchar('-');
		number = -number;
	}
	else if (flags->flag != -1)
		ans += ft_putchar(flags->flag);
	ans += ft_putchar_len('0', flags->accuracy - ft_declen(number));
	if (number || flags->accuracy)
		ans += ft_putnbr_ll(number);
	else if (flags->width > 0 && flags->flag == -1)
		ans += ft_putchar(' ');
	return (ans);
}

int	ft_print_dec(va_list args, t_flags *flags)
{
	long long	number;

	if (flags->type_specifier == 'u')
		number = va_arg(args, unsigned int);
	else
		number = va_arg(args, int);
	if (flags->flag == '-')
		return (ft_print_minus(number, flags));
	if (flags->flag == '0')
		return (ft_print_zero(number, flags));
	return (ft_print(number, flags));
}
