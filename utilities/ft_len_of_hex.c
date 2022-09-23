/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:08:26 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:08:27 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_len_of_hex(unsigned long long dec)
{
	int	len;

	if (dec == 0)
		return (1);
	len = 0;
	while (dec > 0)
	{
		dec /= 16;
		len++;
	}
	return (len);
}
