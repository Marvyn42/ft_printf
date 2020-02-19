/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:52:58 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/19 17:04:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_mod(t_liste *data)
{
	if (data->f_less == 1)
	{
		write(1, "%", 1);
		while ((data->width-- - 1) != 0)
			write(1, " ", 1);
	}
	else if (data->f_zero == 1 && data->pre_on_off == 0)
	{
		while ((data->width-- - 1) != 0)
			write(1, "0", 1);
		write(1, "%", 1);
	}
	else
	{
		while ((data->width-- - 1) != 0)
			write(1, " ", 1);
		write(1, "%", 1);
	}
}

void	print_mod(va_list ap, char type, t_liste *data)
{
	(void)ap;
	(void)type;
	nb_char(data, 1);
	if (data->width && data->width > 1)
		width_mod(data);
	else
		write(1, "%", 1);
}
