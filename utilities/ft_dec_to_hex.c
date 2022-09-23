/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcomic <kcomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 23:08:12 by kcomic            #+#    #+#             */
/*   Updated: 2021/12/15 23:08:13 by kcomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_dec_to_hex(unsigned long long dec, int upper)
{
	char	*str;
	int		i;
	size_t	len;

	len = ft_len_of_hex(dec);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		if (dec % 16 > 9)
			str[i] = 'a' - ('a' - 'A') * upper + (dec % 16 - 10);
		else
			str[i] = '0' + (dec % 16);
		dec /= 16;
		i--;
	}
	return (str);
}
