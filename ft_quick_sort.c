/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:26:41 by flormich          #+#    #+#             */
/*   Updated: 2021/08/01 22:01:36 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_quick_sort_3(t_stack *stack)
{
	if (stack->elt[0] > stack->elt[1] && stack->elt[1] < stack->elt[2]
		&& stack->elt[0] < stack->elt[2])
		ft_pilote_swap(stack, NULL, SA, 1);
	else if (stack->elt[0] > stack->elt[1] && stack->elt[1] < stack->elt[2]
		&& stack->elt[0] > stack->elt[2])
		ft_pilote_rotate(stack, NULL, RA, 1);
	else if (stack->elt[0] > stack->elt[1] && stack->elt[1] > stack->elt[2])
	{
		ft_pilote_swap(stack, NULL, SA, 1);
		ft_pilote_rrotate(stack, NULL, RRA, 1);
	}
	else if (stack->elt[0] < stack->elt[1] && stack->elt[1] > stack->elt[2]
		&& stack->elt[0] < stack->elt[2])
	{
		ft_pilote_swap(stack, NULL, SA, 1);
		ft_pilote_rotate(stack, NULL, RA, 1);
	}
	else if (stack->elt[0] < stack->elt[1] && stack->elt[1] > stack->elt[2])
		ft_pilote_rrotate(stack, NULL, RRA, 1);
}

// Sort bis zu 3 numbers ascending (stack_a)
void	ft_quick_sort(t_stack *a)
{
	if (ft_check_order(a) == 0)
	{
		if (a->size == 2)
		{
			if (a->elt[0] > a->elt[1])
				ft_pilote_swap(a, NULL, SA, 1);
		}
		else if (a->size == 3)
			ft_quick_sort_3(a);
	}
}

static void	ft_insert_b_in_a(t_stack *a, t_stack *b)
{
	while (a->elt[0] < b->elt[0])
		ft_pilote_rotate(a, NULL, RA, 1);
	ft_pilote_push(a, b, PA, 1);
	while (a->elt[a->size - 1] < a->elt[0])
		ft_pilote_rrotate(a, NULL, RRA, 1);
	ft_pilote_push(a, b, PA, 1);
}

// Can be 4 or 5 element
void	*ft_quick_sort_5(t_stack *a, t_stack *b, t_chunk *chk)
{
	if (a->elt[0] > a->elt[1])
		ft_pilote_swap(a, NULL, SA, 1);
	if (a->elt[a->size - 1] < a->elt[0])
		ft_pilote_rrotate(a, NULL, RRA, 1);
	while (a->elt[0] != chk->min && a->elt[1] != chk->min)
		ft_pilote_rrotate(a, NULL, RRA, 1);
	if (a->elt[0] > a->elt[1])
		ft_pilote_swap(a, NULL, SA, 1);
	ft_pilote_push(a, b, PB, 1);
	if (a->size == 4)
	{
		if (a->elt[0] > a->elt[1])
			ft_pilote_swap(a, NULL, SA, 1);
		ft_pilote_push(a, b, PB, 1);
	}
	ft_quick_sort(a);
	if (b->size == 1)
		ft_pilote_push(a, b, PA, 1);
	else
		ft_insert_b_in_a(a, b);
	free(b);
	return (NULL);
}
