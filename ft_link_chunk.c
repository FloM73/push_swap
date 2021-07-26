/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:00:09 by flormich          #+#    #+#             */
/*   Updated: 2021/07/26 23:38:56 by flormich         ###   ########.fr       */
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
	else if (nb > chunk->max)
		chunk->max = nb;
	chunk->nb_elt_total = chunk->nb_elt_total + 1;
	chunk->summe = chunk->summe + nb;
}

void	ft_initialise_chunk(t_chunk *chunk, char *name)
{
	chunk->name = name;
	chunk->min = 32768;
	chunk->max = -32767;
	chunk->nb_elt_total = 0;
	chunk->nb_elt_curent = 0;
	chunk->previous = NULL;
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
