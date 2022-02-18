/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_link_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:32:12 by flormich          #+#    #+#             */
/*   Updated: 2021/08/01 22:41:50 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*
* Delete all the element after the one pointed by **lst
*/

void	ft_lstclear(t_chunk **lst)
{
	t_chunk	*mem_next;

	if (!lst)
		return ;
	mem_next = (*lst)->next;
	while (*lst)
	{
		mem_next = (*lst)->next;
		free(*lst);
		*lst = mem_next;
	}
	*lst = NULL;
}

// Only for the first chunk, NB element = summe
void	ft_implemente_chunk(t_chunk *chunk, int nb)
{
	if (nb < chunk->min)
		chunk->min = nb;
	if (nb > chunk->max)
		chunk->max = nb;
	if (nb < chunk->min_ist)
		chunk->min_ist = nb;
	if (nb > chunk->max_ist)
		chunk->max_ist = nb;
	chunk->nb_elt_total = chunk->nb_elt_total + 1;
	chunk->sum = chunk->sum + nb;
	chunk->average = chunk->sum / chunk->nb_elt_total;
}

void	ft_initialise_chunk(t_chunk *chunk, int chk_nr, t_chunk *prev)
{
	chunk->chk_nr = chk_nr;
	chunk->min = 32768;
	chunk->max = -32767;
	chunk->min_ist = 32768;
	chunk->max_ist = -32767;
	chunk->sum = 0;
	chunk->average = 0;
	chunk->nb_elt_total = 0;
	chunk->nb_elt_curent = 0;
	chunk->nb_a_rotate = 0;
	chunk->nb_b_rotate = 0;
	chunk->previous = prev;
	chunk->next = NULL;
}

t_chunk	*ft_find_last(t_chunk *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

// Display error message and free Chunk_Liste
void	ft_error(t_chunk *chunk)
{
	write(1, "Error\n", 6);
	if (chunk)
		ft_lstclear(&chunk);
}
