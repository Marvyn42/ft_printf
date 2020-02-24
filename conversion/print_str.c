/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:15:28 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/24 18:47:37 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*init_str(va_list ap)
{
	char *str;

	if ((str = va_arg(ap, char *)))
		return (str);
	else
		str = "(null)";
	return (str);
}

void	width_str(t_liste *data, char *s1, int tmp)
{
	if (data->f_less == 1)
	{
		write(1, s1, tmp);
		while ((data->width-- - tmp) != 0)
			write(1, " ", 1);
	}
	else if (data->f_zero == 1 && data->pre_on_off == 0)
	{
		while ((data->width-- - tmp) != 0)
			write(1, "0", 1);
		write(1, s1, tmp);
	}
	else
	{
		while ((data->width-- - tmp) != 0)
			write(1, " ", 1);
		write(1, s1, tmp);
	}
}

void	print_str(va_list ap, char type, t_liste *data)
{
	char	*str;
	int		tmp;

	(void)type;
	str = init_str(ap);
	if (data->pre_on_off && (unsigned)data->prec < ft_strlen(str))
		tmp = data->prec;
	else
		tmp = ft_strlen(str);
	nb_char(data, tmp);
	if (data->width && data->width > tmp)
		width_str(data, str, tmp);
	else
		write(1, str, tmp);
}
