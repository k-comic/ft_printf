/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:06:45 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:06:45 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flag(char c, t_flags *flags)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		flags->flag = c;
		return (1);
	}
	flags->flag = -1;
	return (0);
}

static int	ft_check_width(const char *str, t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	flags->width = ft_atoi(str);
	while (str[i] != '*' && str[i] != '.' && str[i] != '%'
		&& !ft_isalpha(str[i]))
		i++;
	if (str[i] == '*')
	{
		flags->width = va_arg(args, int);
		i++;
	}
	flags->two_flags = 'n';
	if (flags->width < 0)
	{
		if (flags->flag != -1 && flags->flag != '-')
			flags->two_flags = flags->flag;
		flags->flag = '-';
		flags->width = -flags->width;
		if (flags->flag == '-' && flags->two_flags == '0')
			flags->two_flags = 'n';
	}
	return (i);
}

static int	ft_check_accuracy(const char *str, t_flags *flags, va_list args)
{
	int	i;

	if (*str == '.')
	{
		if (str[1] == '*')
		{
			flags->accuracy = va_arg(args, int);
			if (flags->accuracy < 0)
				flags->accuracy = -1;
			return (2);
		}
		flags->accuracy = ft_atoi(&str[1]);
		if (flags->accuracy < 0)
			flags->accuracy = -1;
		i = 1;
		while (!ft_isalpha(str[i]) && (str[i] != '%'))
			i++;
		return (i);
	}
	flags->accuracy = -1;
	return (0);
}

static int	ft_check_type_specifier(char c, t_flags *flags)
{
	flags->type_specifier = c;
	return (1);
}

void	ft_check_flags(const char *str, int *pos, t_flags *flags, va_list args)
{
	int	i;

	i = 1;
	i += ft_check_flag(str[i], flags);
	i += ft_check_width(&str[i], flags, args);
	i += ft_check_accuracy(&str[i], flags, args);
	i += ft_check_type_specifier(str[i], flags);
	*pos += i;
}
