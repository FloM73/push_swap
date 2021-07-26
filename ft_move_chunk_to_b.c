/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_chunk_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:25:28 by flormich          #+#    #+#             */
/*   Updated: 2021/07/26 20:55:49 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	ft_find_first_member(t_stack *s, t_chunk *chk)
{
	int	i;

	i = 0;
	while ((s->elt[i] < chk-> min || s->elt[i] > chk->max) && i < s-> size -1)
		i++;
	return (i);
}

static int	ft_find_last_member(t_stack *s, t_chunk *chk)
{
	int	i;

	i =  s->size -1;
	while ((s->elt[i] < chk-> min || s->elt[i] > chk->max) && i >= 0)
		i--;
	return (s->size - 1 - i);
}

static void ft_move_from_top(t_stack *a, t_stack *b, t_chunk *chk)
{
	while (chk->nb_elt_curent < chk->nb_elt_total)
	{
		if (a->elt[0] < chk->min || a->elt[0] > chk->max)
			ft_pilote_rotate(a, NULL, RA);
		else
		{
			ft_pilote_push(a, b, PB);
			chk->nb_elt_curent++;
		}
	}
}

static void ft_move_from_bottom(t_stack *a, t_stack *b, t_chunk *chk)
{
	int	i;

	while (chk->nb_elt_curent < chk->nb_elt_total)
	{
		i = a->size - 1;
		if (a->elt[i] < chk->min || a->elt[i] > chk->max)
			ft_pilote_rrotate(a, NULL, RRA);
		else
		{
			ft_pilote_rrotate(a, NULL, RRA);
			ft_pilote_push(a, b, PB);
			chk->nb_elt_curent++;
		}
	}
}

void	ft_move_chk_a_to_b(t_stack *a, t_stack *b, t_chunk *chk)
{
	int	index_first;
	int	index_last;

	index_first = ft_find_first_member(a, chk);
	index_last = ft_find_last_member(a, chk);
	if (index_first <= index_last)
		ft_move_from_top(a, b, chk);
	else
		ft_move_from_bottom(a, b, chk);
}
