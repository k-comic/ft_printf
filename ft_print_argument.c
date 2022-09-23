/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:07:01 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:07:01 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_argument(va_list args, t_flags *flags)
{
	int	ans;

	if (flags->type_specifier == 'c')
		ans = ft_print_char(args, flags);
	if (flags->type_specifier == 's')
		ans = ft_print_str(args, flags);
	if (flags->type_specifier == 'p')
		ans = ft_print_ptr(args, flags);
	if (flags->type_specifier == 'd'
		|| flags->type_specifier == 'i'
		|| flags->type_specifier == 'u')
		ans = ft_print_dec(args, flags);
	if (flags->type_specifier == 'x'
		|| flags->type_specifier == 'X')
		ans = ft_print_hex(args, flags);
	if (flags->type_specifier == '%')
		ans = ft_print_per(flags);
	return (ans);
}
