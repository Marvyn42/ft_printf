/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:20:52 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/27 11:46:20 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*str_add(t_liste *data, char *s1)
{
	char *str;

	(void)data;
	str = ft_strjoin("0x", s1);
	free(s1);
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
	else
	{
		while ((data->width-- - ft_strlen(s1)) != 0)
			write(1, " ", 1);
		write(1, s1, ft_strlen(s1));
	}
}

void	print_add(va_list ap, char type, t_liste *data)
{
	long	nb;
	char	*s1;

	(void)type;
	nb = va_arg(ap, unsigned long);
	if (nb == 0)
		s1 = ft_strdup((data->pre_on_off) ? "0x" : "0x0");
	else
		s1 = ft_itoa_base(nb, "0123456789abcdef");
	if (nb != 0)
		s1 = str_add(data, s1);
	nb_char(data, ft_strlen(s1));
	if (data->width && (unsigned int)data->width > ft_strlen(s1))
		width_add(data, s1);
	else
		write(1, s1, ft_strlen(s1));
	free(s1);
}
