/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_all_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:06:54 by flormich          #+#    #+#             */
/*   Updated: 2021/07/25 22:46:33 by flormich         ###   ########.fr       */
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
		next_chk->nb_elt_total = next_chk->nb_elt_total + 1;
		i++;
	}
}

t_chunk	*ft_create_chk(t_chunk *first, int nb, int min, int max)
{
	int		i;
	t_chunk	*chunk_new;
	t_chunk	*chunk_last;

	i = 1;
	while (i <= nb)
	{
		chunk_new = (t_chunk *)malloc(sizeof(t_chunk));
		if (chunk_new)
		{
			chunk_last = ft_find_last(first);
			if (i == 1)
				chunk_new->min = min;
			else
				chunk_new->min = chunk_last->max + 1;
			if (i == nb)
				chunk_new->max = max;
			else
				chunk_new->max = chunk_new->min + (max - min) / nb;
			chunk_new->previous = chunk_last;
			chunk_last->next = chunk_new;
			i++;
		}
	}
	return (chunk_new);
}

void	ft_pilote_create_chunk(t_chunk *first, t_stack *stack)
{
	int		average;
	int		nb_chk;
	t_chunk	*mid_chk;

	average = first->nb_elt_curent / first->nb_elt_total;
	if (first->nb_elt_total >= 50)
		nb_chk = first->nb_elt_total / 10;
	else if (first->nb_elt_total >= 20)
		nb_chk = first->nb_elt_total / 5;
	else if (first->nb_elt_total >= 9)
		nb_chk = 3;
	else if (first->nb_elt_total >= 6)
		nb_chk = 1;
	else
	{
		ft_quick_sort(stack);
		nb_chk = 0;
	}
	if (nb_chk > 1)
	{
		mid_chk = ft_create_chk(first, nb_chk / 2, first->min, average);
		nb_chk = (nb_chk) / 2 + (nb_chk % 2);
		ft_create_chk(mid_chk, nb_chk, average + 1, first->max);
		ft_fill_chunk(first, stack);
		ft_print_chunk(first);	//norme OK sans elle
	}
}