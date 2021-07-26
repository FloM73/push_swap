/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:26:41 by flormich          #+#    #+#             */
/*   Updated: 2021/07/27 01:04:31 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Sort bis zu 3 numbers
void	ft_quick_sort(t_stack *stack)
{
	if (ft_check_order(stack) == 0)
	{
		if (stack->size == 2)
		{
			if (stack->elt[0] > stack->elt[1])
				ft_pilote_swap(stack, NULL, SA);
		}
		else if (stack->size == 3)
			ft_quick_sort_3(stack);
	}
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

// Send a to b, chunk after chunk
void	ft_send_chk_to(t_stack *a, t_stack *b, t_chunk *chunk)
{
	t_chunk	*chk;

	chk = chunk->next;
	while (chk)
	{
		if (chk->nb_elt_total != 0 && chk->next != NULL)
			ft_move_chk_a_to_b(a, b, chk);
		if (chk->next != NULL)
			chk = chk->next;
		else
		{
			if (chk->nb_elt_total <= 3)
			{
				ft_quick_sort(a);
				chk = chk->previous;
			}
			else
				ft_move_chk_a_to_b(a, b, chk);
			break;
		}
	}
	//ft_print_stack(a, 'A');
	//ft_print_stack(b, 'B');
	ft_send_chk_back(a, b, chk);
}

// Bring the chunk back from b to a, chunk after chunk
void	ft_send_chk_back(t_stack *a, t_stack *b, t_chunk *chunk)
{
	t_chunk	*chk;

	chk = chunk;
	while (chk->previous != NULL)
	{
		if (chk->nb_elt_total != 0)
			ft_move_chk_b_to_a(a, b, chk);
		chk = chk->previous;
	}
	if (ft_check_order(a) == 0)
		write(1, "ZUT\n", 4);
	else
		write(1, "TRI OK!\n", 8);
}
