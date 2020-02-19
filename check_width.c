/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:05:10 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/19 17:03:24 by mamaquig         ###   ########.fr       */
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
	if (ft_atoi(str2) != 0)
	{
		(void)ap;
		data->width = ft_atoi(str2);
		tmp = ft_strlen(ft_itoa(data->width));
		if (str2[i] == '0')
			tmp++;
		*str = ((str2) + tmp);
	}
	else if (str2[i] == '*')
	{
		data->width = (va_arg(ap, int));
		*str = ++str2;
	}
}
