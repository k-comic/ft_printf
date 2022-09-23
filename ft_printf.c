/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:10:33 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:10:33 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ans;
	va_list	args;
	t_flags	flags;

	i = 0;
	ans = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ans += ft_putchar(format[i]);
			i++;
		}
		else
		{
			ft_check_flags(&format[i], &i, &flags, args);
			ans += ft_print_argument(args, &flags);
		}
	}
	va_end(args);
	return (ans);
}
