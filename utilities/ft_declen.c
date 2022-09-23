/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:08:17 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:08:18 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_declen(long long number)
{
	int	len;

	if (number == 0)
		return (1);
	len = 0;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}
