/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:47:51 by ssabbah           #+#    #+#             */
/*   Updated: 2018/01/29 13:47:53 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

long long		abs_val(long long nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
