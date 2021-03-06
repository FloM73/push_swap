/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_all_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:06:54 by flormich          #+#    #+#             */
/*   Updated: 2021/07/29 20:01:52 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_fill_chunk(t_chunk *first, t_stack *stack)
{
	int		i;
	int		nb_tot;
	t_chunk	*next_chk;

	i = 0;
	nb_tot = first->nb_elt_total;
	while (i < nb_tot)
	{
		next_chk = first->next;
		while (stack->elt[i] < next_chk->min || stack->elt[i] > next_chk-> max)
		{
			next_chk = next_chk->next;
		}
		ft_implemente_chunk(next_chk, stack->elt[i]);
		i++;
	}
}

static int	ft_find_min(int	chk_pos, int min, int last_max)
{
	if (chk_pos == 1)
		return (min);
	else
		return (last_max + 1);
}

static t_chunk	*ft_create_chk(t_chunk *first, int how_many, int min, int max)
{
	int		i;
	int		nb_is;
	t_chunk	*chunk_new;
	t_chunk	*chunk_last;

	nb_is = first->chk_nr;
	i = 1;
	while (i <= how_many)
	{
		chunk_new = (t_chunk *)malloc(sizeof(t_chunk));
		if (chunk_new)
		{
			chunk_last = ft_find_last(first);
			ft_initialise_chunk(chunk_new, i + nb_is, chunk_last);
			chunk_new->min = ft_find_min(i, min, chunk_last->max);
			if (i == how_many)
				chunk_new->max = max;
			else
				chunk_new->max = chunk_new->min + (max - min) / how_many;
			chunk_last->next = chunk_new;
			i++;
		}
	}
	return (chunk_new);
}

void	ft_pilote_create_all_chunk(t_chunk *first, t_stack *stack_a)
{
	int		nb_chk;
	t_chunk	*mid_chk;

	if (first->nb_elt_total <= 3)
	{
		ft_quick_sort(stack_a);
		return ;
	}
	if (first->nb_elt_total > 499)
		nb_chk = first->nb_elt_total / 30;
	else if (first->nb_elt_total > 399)
		nb_chk = first->nb_elt_total / 20;
	else if (first->nb_elt_total > 50)
		nb_chk = first->nb_elt_total / 11;
	else if (first->nb_elt_total >= 20)
		nb_chk = first->nb_elt_total / 5;
	else
		nb_chk = 2;
	mid_chk = ft_create_chk(first, nb_chk / 2, first->min, first->average);
	if (mid_chk)
	{
		nb_chk = (nb_chk) / 2 + (nb_chk % 2);
		ft_create_chk(mid_chk, nb_chk, first->average + 1, first->max);
		ft_fill_chunk(first, stack_a);
	}
}
