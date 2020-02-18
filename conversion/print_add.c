/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:20:52 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/18 15:36:44 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*str_add(t_liste *data, char *s1)
{
	char *str;

	(void)data;
	str = "0x7ffe";
	str = ft_strjoin(str, s1);
	return (str);
}

void	width_add(t_liste *data, char *s1)
{
	if (data->f_less == 1)
	{
		write(1, s1, ft_strlen(s1));
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, " ", 1);
	}
	else if (data->f_zero == 1 && data->pre_on_off == 0)
	{
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, "0", 1);
		write(1, s1, ft_strlen(s1));
	}
	else
	{
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, " ", 1);
		write(1, s1, ft_strlen(s1));
	}
}

void	print_add(va_list ap, char type, t_liste *data)
{
	int		nb;
	char	*s1;

	(void)type;
	nb = va_arg(ap, int);
	if (!(s1 = ft_itoa_base(nb, 16)))
		return ;
	s1 = str_add(data, s1);
	if (data->pre_on_off && (unsigned)data->prec > ft_strlen(s1))
		s1 = str_precision(data, s1);
	else if (data->pre_on_off && data->prec == 0 && nb == 0)
		return ;
	nb_char(data, ft_strlen(s1));
	if (data->width && (unsigned)data->width > ft_strlen(s1))
		width_add(data, s1);
	else
		write(1, s1, ft_strlen(s1));
	free(s1);
}
