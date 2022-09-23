/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:08:08 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:08:09 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	atoi_number(char *str, int sign)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
		if (number < 0)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ans;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] == '-') || (str[i] == '+'))
		i++;
	ans = sign * atoi_number((char *)str + i, sign);
	return (ans);
}
