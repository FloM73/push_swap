/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:26:41 by flormich          #+#    #+#             */
/*   Updated: 2021/07/28 18:28:37 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_quick_sort_3(t_stack *stack)
{
	if (stack->elt[0] > stack->elt[1] && stack->elt[1] < stack->elt[2]
		&& stack->elt[0] < stack->elt[2])
		ft_pilote_swap(stack, NULL, SA);
	else if (stack->elt[0] > stack->elt[1] && stack->elt[1] < stack->elt[2]
		&& stack->elt[0] > stack->elt[2])
		ft_pilote_rotate(stack, NULL, RA);
	else if (stack->elt[0] > stack->elt[1] && stack->elt[1] > stack->elt[2])
	{
		ft_pilote_swap(stack, NULL, SA);
		ft_pilote_rrotate(stack, NULL, RRA);
	}
	else if (stack->elt[0] < stack->elt[1] && stack->elt[1] > stack->elt[2]
		&& stack->elt[0] < stack->elt[2])
	{
		ft_pilote_swap(stack, NULL, SA);
		ft_pilote_rotate(stack, NULL, RA);
	}
	else if (stack->elt[0] < stack->elt[1] && stack->elt[1] > stack->elt[2])
		ft_pilote_rrotate(stack, NULL, RRA);
}

// Sort bis zu 3 numbers ascending (stack_a)
void	ft_quick_sort(t_stack *a)
{
	if (ft_check_order(a) == 0)
	{
		if (a->size == 2)
		{
			if (a->elt[0] > a->elt[1])
				ft_pilote_swap(a, NULL, SA);
		}
		else if (a->size == 3)
			ft_quick_sort_3(a);
	}
}
