/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 21:00:09 by flormich          #+#    #+#             */
/*   Updated: 2021/07/23 21:09:11 by flormich         ###   ########.fr       */
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

void	ft_implemente_chunk(t_chunk *chunk, int nb)
{
	if (nb < chunk->min)
		chunk->min = nb;
	else if (nb > chunk->max)
		chunk->max = nb;
	chunk->nb_elt_total = chunk->nb_elt_total + 1;
	chunk->next = NULL;
}

void	ft_initialise_chunk(t_chunk *chunk, char *name)
{
	chunk->name = name;
	chunk->min = 32768;
	chunk->max = -32767;
	chunk->nb_elt_total = 0;
	chunk->nb_elt_curent = 0;
	chunk->next = NULL;
}

/*
t_list	*ft_lstnew(void *content)
{
	t_list	*mylist;

	mylist = (t_list *)malloc(sizeof(t_list));
	if (mylist)
	{
		mylist->content = content;
		mylist->next = NULL;
		return (mylist);
	}
	return (NULL);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 1;
		while ((lst->next) != NULL)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
*/
