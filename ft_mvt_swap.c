/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvt_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:30:12 by flormich          #+#    #+#             */
/*   Updated: 2021/08/01 22:30:19 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->elt[0];
	stack->elt[0] = stack->elt[1];
	stack->elt[1] = tmp;
}

void	ft_pilote_swap(t_stack *a, t_stack *b, int which, int print)
{
	if (which == SA || which == SS)
		ft_swap(a);
	if (which == SB || which == SS)
		ft_swap(b);
	if (print == 1)
	{
		if (which == SA)
			write(1, "sa\n", 3);
		else if (which == SB)
			write(1, "sb\n", 3);
		else
			write(1, "ss\n", 3);
	}
}
