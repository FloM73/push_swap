/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:26:41 by flormich          #+#    #+#             */
/*   Updated: 2021/07/25 22:47:54 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Sort bis zu 5 numbers
void	ft_quick_sort(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->elt[0] > stack->elt[1])
			ft_pilote_swap(stack, NULL, SA);
	}
	else if (stack->size == 3)
		ft_quick_sort_3(stack);
}

void	ft_quick_sort_3(t_stack *stack)
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
