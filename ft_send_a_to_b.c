/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:25:28 by flormich          #+#    #+#             */
/*   Updated: 2021/07/27 18:02:32 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Find the first position of a value belonging to the chunk
static int	ft_find_member(t_stack *s, t_chunk *chk, int first)
{
	int	i;

	if (first == 1)
	{
		i = 0;
		while ((s->elt[i] < chk->min || s->elt[i] > chk->max) && i < s->size -1)
			i++;
		return (i);
	}
	else
	{
		i =  s->size -1;
		while ((s->elt[i] < chk-> min || s->elt[i] > chk->max) && i >= 0)
			i--;
		return (s->size - 1 - i);
	}
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

static void	ft_move_chk(t_stack *a, t_stack *b, t_chunk *chk)
{
	int	index_first;
	int	index_last;

	if (chk->nb_elt_total > 0)
	{
		index_first = ft_find_member(a, chk, 1);
		index_last = ft_find_member(a, chk, 0);
		if (index_first == 0 && index_last == 0 && chk->next != NULL)
		{
			//ft_print_stack(a, 'A');
			while (a->elt[a->size -1] >= chk->min && a->elt[a->size -1] <= chk->max)
			{
				ft_pilote_rrotate(a, NULL, RRA);
				//ft_print_stack(a, 'A');
			}
		}
		if (index_first <= index_last)
			ft_move_from_top(a, b, chk);
		else
			ft_move_from_bottom(a, b, chk);
	}
	if (chk->nb_elt_total == 2 && b->elt[0] < b->elt[1])
		ft_pilote_swap(NULL, b, SB);
	//ft_print_stack(a, 'A');
	//ft_print_stack(b, 'B');
}

// Send a to b, chunk after chunk
t_stack	*ft_send_a_to_b(t_stack *a, t_chunk *chunk)
{
	t_chunk	*chk;
	t_stack	*b;

	b = ft_create_stack_b(a);
	if (!b || !b->elt)
	{
		ft_free(1, a);
		ft_lstclear(&chunk);
		return (NULL);
	}
	chk = chunk->next;
	while (chk)
	{
		if (chk->nb_elt_total <= 3 && chk->next == NULL)
		{
			ft_quick_sort(a);
			break;
		}
		else
			ft_move_chk(a, b, chk);
		if (chk->next != NULL)
			chk = chk->next;
		else
			break;
	}
	return (b);
}
