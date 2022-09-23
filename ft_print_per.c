/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:07:28 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:07:29 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_per(t_flags *flags)
{
	char	c;
	int		ans;

	c = '%';
	ans = 0;
	if (flags->flag == '-')
	{
		ans += ft_putchar(c);
		ans += ft_putchar_len(' ', flags->width - 1);
	}
	else
	{
		if (flags->flag == '0')
			ans += ft_putchar_len('0', flags->width - 1);
		else
			ans += ft_putchar_len(' ', flags->width - 1);
		ans += ft_putchar(c);
	}
	return (ans);
}
