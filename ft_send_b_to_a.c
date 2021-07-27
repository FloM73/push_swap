/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:25:28 by flormich          #+#    #+#             */
/*   Updated: 2021/07/28 00:56:41 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_move_chk_b_to_a_test(t_stack *a, t_stack *b, t_chunk *chk)
{

	int	nb_big;
	int	count_big;
	int	a_rotate;

	nb_big = ft_count_elt_big(b, chk);
	count_big = 0;
	a_rotate = 0;
	//ft_print_stack(a, 'A');
	//ft_print_stack(b, 'B');
	while(chk->nb_elt_curent != 0)
	{
		while (count_big < nb_big && b->elt[0] <= chk->summe / chk->nb_elt_total)
		{
			ft_pilote_rotate(NULL, b, RB);
			chk->nb_rotate++;
			//ft_print_stack(b, 'B');
		}
		if (b->elt[0] > chk->min && b->elt[0] < b->elt[1] && b->size > 1)
			ft_pilote_swap(NULL, b, SB);
		while (chk->nb_rotate > 0 && b->elt[b->size - 1] > b->elt[0])
		{
			ft_pilote_rrotate(NULL, b, RRB);
			chk->nb_rotate--;
			//ft_print_stack(b, 'B');
		}
		if (b->elt[0] > a->elt[0] && a->size > 0)
		{
			while (a->size > 1 && b->elt[0] > a->elt[0])
			{
				ft_pilote_rotate(a, NULL, RA);
				a_rotate++;
			}
		}
		while ( a_rotate > 0 && a->elt[a->size - 1] > b->elt[0])
		{
			ft_pilote_rrotate(a, NULL, RRA);
			a_rotate--;
		}
		ft_pilote_push(a, b, PA);
		chk->nb_elt_curent--;
		count_big++;
		//ft_print_stack(a, 'A');
		//ft_print_stack(b, 'B');
		if (a->size == 2 && a->elt[0] > a->elt[1])
			ft_pilote_swap(a, NULL, SA);
	}
	while (a_rotate > 0)
	{
		ft_pilote_rrotate(a, NULL, RRA);
		a_rotate--;
	}
}

// Bring the chunk back from b to a, chunk after chunk
void	ft_send_b_to_a(t_stack *a, t_stack *b, t_chunk *chunk)
{
	t_chunk	*chk;

	chk = chunk;
	if (b->size > 10000)
	{
		while (chk->previous != NULL)
		{
			if (chk->nb_elt_curent != 0)
				ft_move_chk_b_to_a_biggest(a, b, chk);
			chk = chk->previous;
		}
	}
	else if (b->size == 0)
	{
		while (chk->previous != NULL)
		{
			if (chk->nb_elt_curent != 0)
				ft_move_chk_b_to_a_big(a, b, chk);
			chk = chk->previous;
		}
	}
	else
	{
		while (chk->previous != NULL)
		{
			if (chk->nb_elt_curent != 0)
				ft_move_chk_b_to_a_test(a, b, chk);
			chk = chk->previous;
		}
	}
}
