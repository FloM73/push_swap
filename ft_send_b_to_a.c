/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:25:28 by flormich          #+#    #+#             */
/*   Updated: 2021/07/28 19:26:58 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	ft_count_elt_big(t_stack *s, t_chunk*chk)
{
	int	average;
	int	i;
	int	count;

	if (chk->nb_elt_total != 0)
		average = chk->sum / chk->nb_elt_total;
	i = 0;
	count = 0;
	while (i < chk->nb_elt_total)
	{
		if (s->elt[i] > average)
			count++;
		i++;
	}
	return (count);
}

static void	ft_search_big(t_stack *b, t_chunk *chk)
{
	ft_pilote_rotate(NULL, b, RB);
	chk->nb_b_rotate++;
}

static void	ft_rotate_too_small_a(t_stack *a, t_stack *b, t_chunk *chk)
{
	while (a->size > 1 && b->elt[0] > a->elt[0])
	{
		ft_pilote_rotate(a, NULL, RA);
		chk->nb_a_rotate++;
	}
}

static void	ft_move_chk_b_to_a(t_stack *a, t_stack *b, t_chunk *chk, int nb_big)
{
	int	count_big;

	count_big = 0;
	while (chk->nb_elt_curent != 0)
	{
		while (count_big < nb_big && b->elt[0] <= chk->sum / chk->nb_elt_total)
			ft_search_big(b, chk);
		if (b->elt[0] > chk->min && b->elt[0] < b->elt[1] && b->size > 1)
			ft_pilote_swap(NULL, b, SB);
		while (chk->nb_b_rotate > 0 && b->elt[b->size - 1] > b->elt[0])
		{
			ft_pilote_rrotate(NULL, b, RRB);
			chk->nb_b_rotate--;
		}
		if (b->elt[0] > a->elt[0] && a->size > 0)
			ft_rotate_too_small_a(a, b, chk);
		while (chk->nb_a_rotate > 0 && a->elt[a->size - 1] > b->elt[0])
		{
			ft_pilote_rrotate(a, NULL, RRA);
			chk->nb_a_rotate--;
		}
		ft_pilote_push(a, b, PA);
		chk->nb_elt_curent--;
		count_big++;
	}
}

// Pilote: Bring the chunk back from b to a, chunk after chunk
void	ft_send_b_to_a(t_stack *a, t_stack *b, t_chunk *chunk)
{
	t_chunk	*chk;

	chk = chunk;
	{
		while (chk->previous != NULL)
		{
			if (chk->nb_elt_curent != 0)
			{
				ft_move_chk_b_to_a(a, b, chk, ft_count_elt_big(b, chk));
				while (chk->nb_a_rotate > 0)
				{
					ft_pilote_rrotate(a, NULL, RRA);
					chk->nb_a_rotate--;
				}
			}
			chk = chk->previous;
		}
	}
}
