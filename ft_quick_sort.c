/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:26:41 by flormich          #+#    #+#             */
/*   Updated: 2021/07/29 16:33:01 by flormich         ###   ########.fr       */
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

static void	ft_insert_b_in_a(t_stack *a, t_stack *b)
{
	while (a->elt[0] < b->elt[0])
		ft_pilote_rotate(a, NULL, RA);
	ft_pilote_push(a, b, PA);
	while (a->elt[a->size - 1] < a->elt[0])
		ft_pilote_rrotate(a, NULL, RRA);
	ft_pilote_push(a, b, PA);
}

// Can be 4 or 5 element
void	*ft_quick_sort_5(t_stack *a, t_stack *b, t_chunk *chk)
{
	if (a->elt[0] > a->elt[1])
		ft_pilote_swap(a, NULL, SA);
	if (a->elt[a->size - 1] < a->elt[0])
		ft_pilote_rrotate(a, NULL, RRA);
	while (a->elt[0] != chk->min && a->elt[1] != chk->min)
		ft_pilote_rrotate(a, NULL, RRA);
	if (a->elt[0] > a->elt[1])
		ft_pilote_swap(a, NULL, SA);
	ft_pilote_push(a, b, PB);
	if (a->size == 4)
	{
		if (a->elt[0] > a->elt[1])
			ft_pilote_swap(a, NULL, SA);
		ft_pilote_push(a, b, PB);
	}
	ft_quick_sort(a);
	if (b->size == 1)
		ft_pilote_push(a, b, PA);
	else
		ft_insert_b_in_a(a, b);
	free(b);
	return (NULL);
}
