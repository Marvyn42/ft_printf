/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:05:10 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/20 11:57:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(t_liste *data, const char **str, va_list ap)
{
	int			i;
	int			tmp;
	const char	*str2;

	str2 = *str;
	i = 0;
	tmp = 0;
	if ((data->width = ft_atoi(str2)))
	{
		while (str2[i++] == '0')
			tmp++;
		tmp += ft_strlen(ft_itoa(data->width));
		*str = ((str2) + tmp);
	}
	else if (str2[i] == '0')
	{
			while (str2[i++] == '0')
				tmp++;
		*str = ((str2) + tmp);
	}
	else if (str2[i] == '*')
	{
		data->width = (va_arg(ap, int));
		*str = ++str2;
	}
}
