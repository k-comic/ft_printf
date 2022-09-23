/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:07:33 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:07:33 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list args, t_flags *flags)
{
	unsigned long long	number;
	int					ans;

	number = va_arg(args, unsigned long long);
	ans = 0;
	if (flags->flag != '-')
	{
		ans += ft_putchar_len(' ', flags->width
				- ft_max(ft_len_of_hex(number) + 2, flags->accuracy + 2));
		if (flags->accuracy == 0 && !number && flags->width > 2)
			ans += ft_putchar(' ');
	}
	ans += write(1, "0x", 2);
	ans += ft_putchar_len('0', flags->accuracy - ft_len_of_hex(number));
	if (flags->accuracy != 0 || number)
		ans += ft_putstr(ft_dec_to_hex(number, 0));
	if (flags->flag == '-')
	{
		ans += ft_putchar_len(' ', flags->width
				- ft_max(ft_len_of_hex(number) + 2, flags->accuracy + 2));
		if (flags->accuracy == 0 && !number && flags->width > 2)
			ans += ft_putchar(' ');
	}
	return (ans);
}
