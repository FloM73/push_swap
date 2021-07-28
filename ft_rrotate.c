/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:30:12 by flormich          #+#    #+#             */
/*   Updated: 2021/07/28 18:28:59 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_rrotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size - 1;
	tmp = stack->elt[i];
	while (i > 0)
	{
		stack->elt[i] = stack->elt[i - 1];
		i--;
	}
	stack->elt[0] = tmp;
}

void	ft_pilote_rrotate(t_stack *stack_a, t_stack *stack_b, int	which)
{
	if (which == RRA || which == RRR)
		ft_rrotate(stack_a);
	if (which == RRB || which == RRR)
		ft_rrotate(stack_b);
	if (which == RRA)
		write(1, "rra\n", 4);
	else if (which == RRB)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}
