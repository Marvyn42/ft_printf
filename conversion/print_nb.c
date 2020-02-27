/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:53:02 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/27 11:47:09 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long int	init_nb(va_list ap, char type)
{
	long nb;

	if (type == 'u')
		return (nb = va_arg(ap, unsigned int));
	else
		return (nb = va_arg(ap, int));
}

char		*isless(char *s1)
{
	char *str;

	str = ft_strjoin("-", s1);
	free(s1);
	return (str);
}

void		w_num(t_liste *data, char *s1, int tmp)
{
	if (data->f_less == 1)
	{
		write(1, s1, tmp);
		while ((data->width-- - tmp) != 0)
			write(1, " ", 1);
	}
	else if (data->f_zero == 1 && data->pre_on_off == 0)
	{
		if (s1[0] == '-')
		{
			write(1, "-", 1);
			++s1;
		}
		while ((data->width-- - tmp) != 0)
			write(1, "0", 1);
		write(1, s1, ft_strlen(s1));
	}
	else
	{
		while ((data->width-- - tmp) != 0)
			write(1, " ", 1);
		write(1, s1, tmp);
	}
}

void		width_nb(t_liste *data, char *s1, int tmp)
{
	if (tmp == 0)
		while (data->width-- != 0)
			write(1, " ", 1);
	else
		w_num(data, s1, tmp);
}

void		print_nb(va_list ap, char type, t_liste *data)
{
	long	nb;
	char	*s1;

	nb = init_nb(ap, type);
	if (nb < 0)
	{
		nb *= -1;
		type = '-';
	}
	s1 = ft_itoa_base(nb, "0123456789");
	if (data->pre_on_off && (unsigned int)data->prec > ft_strlen(s1))
		s1 = str_precision(data, s1, type);
	else if (data->pre_on_off && data->prec == 0 && nb == 0 && data->width == 0)
		return ;
	if (type == '-' && !(s1[0] == '-'))
		s1 = isless(s1);
	nb_char(data, ft_strlen(s1));
	if (data->width && data->pre_on_off && data->prec == 0 && nb == 0)
		width_nb(data, NULL, 0);
	else if (data->width && (unsigned int)data->width > ft_strlen(s1))
		width_nb(data, s1, ft_strlen(s1));
	else
		write(1, s1, ft_strlen(s1));
	free(s1);
}
