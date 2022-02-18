/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 23:28:16 by flormich          #+#    #+#             */
/*   Updated: 2021/08/01 23:29:40 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_write_result(t_stack *a, t_stack *b)
{
	if (ft_check_order(a) != 0 && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
