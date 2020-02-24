/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:33:30 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/24 16:01:51 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_char(va_list ap, char type, t_liste *data)
{
	char	c;

	(void)type;
	c = va_arg(ap, int);
	nb_char(data, 1);
	if (data->f_less)
	{
		write(1, &c, 1);
		if (data->width)
			while ((data->width-- - 1) != 0)
				write(1, " ", 1);
	}
	else
	{
		if (data->width && data->width > 1)
			while ((data->width-- - 1) != 0)
				write(1, " ", 1);
		write(1, &c, 1);
	}
}
