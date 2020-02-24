/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:13:39 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/20 14:58:39 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(t_liste *data, const char **str)
{
	int			i;
	const char	*tmp;

	i = 0;
	tmp = *str;
	while (tmp[i] == '0' || tmp[i] == '-')
	{
		if (tmp[i] == '0')
			data->f_zero = 1;
		else if (tmp[i] == '-')
			data->f_less = 1;
		*str = ((tmp) + (i + 1));
		i++;
	}
	if (data->f_less && data->f_zero)
		data->f_zero = 0;
}
