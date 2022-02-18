/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvt_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:30:12 by flormich          #+#    #+#             */
/*   Updated: 2021/08/01 22:29:25 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*	write(1, "\nAFTER PUSH\n", 12);
	ft_print_stack(stack_a, 'A');
	ft_print_stack(stack_b, 'B');*/

static void	ft_push(t_stack *from, t_stack *to)
{
	int	i;

	i = 0;
	while (i < to->size)
	{
		to->elt[to->size - i] = to->elt[to->size - 1 - i];
		i++;
	}
	to->elt[0] = from->elt[0];
	to->size++;
	from->size--;
	i = 0;
	while (i < from->size)
	{
		from->elt[i] = from->elt[i + 1];
		i++;
	}
	from->elt[from->size] = '\0';
}

void	ft_pilote_push(t_stack *a, t_stack *b, int which, int print)
{
	if (which == PA)
		ft_push(b, a);
	if (which == PB)
		ft_push(a, b);
	if (print == 1)
	{
		if (which == PA)
			write(1, "pa\n", 3);
		else if (which == PB)
			write(1, "pb\n", 3);
	}
}
