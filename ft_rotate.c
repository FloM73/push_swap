/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:30:12 by flormich          #+#    #+#             */
/*   Updated: 2021/07/26 22:40:28 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->elt[0];
	while (i < stack->size)
	{
		stack->elt[i] = stack->elt[i + 1];
		i++;
	}
	stack->elt[stack->size - 1] = tmp;
}

void	ft_pilote_rotate(t_stack *stack_a, t_stack *stack_b, int	which)
{
	if (which == RA || which == RR)
		ft_rotate(stack_a);
	if (which == RB || which == RR)
		ft_rotate(stack_b);
	if (which == RA)
		write(1, "ra\n", 3);
	else if (which == RB)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
/*	write(1, "\nAFTER ROTATE\n", 14);
	if (stack_a)
		ft_print_stack(stack_a, 'A');
	if (stack_b)
		ft_print_stack(stack_b, 'B');*/
}
