/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:07:38 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:07:38 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list args, t_flags *flags)
{
	char	*str;
	int		ans;

	str = va_arg(args, char *);
	ans = 0;
	if (!str)
		str = "(null)";
	if (flags->accuracy == -1 || flags->accuracy > (int)ft_strlen(str))
		flags->accuracy = ft_strlen(str);
	if (flags->flag != '-')
	{
		ans += ft_putchar_len(' ', flags->width - flags->accuracy);
		ans += write(1, str, flags->accuracy);
	}
	else
	{
		ans += write(1, str, flags->accuracy);
		ans += ft_putchar_len(' ', flags->width - flags->accuracy);
	}
	return (ans);
}
