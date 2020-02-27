/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:53:21 by mamaquig          #+#    #+#             */
/*   Updated: 2020/02/26 09:58:21 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*str_precision(t_liste *data, char *s1, char sign)
{
	char	*str;
	char	*str2;
	int		tmp;

	tmp = (data->prec - ft_strlen(s1));
	str = ft_calloc(tmp + 1, sizeof(char));
	str = ft_memset(str, '0', tmp);
	str2 = ft_strjoin(str, s1);
	free(str);
	str = str2;
	if (sign == '-')
	{
		str2 = ft_strjoin("-", str2);
		free(str);
	}
	return (str2);
}
