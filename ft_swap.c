/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:30:12 by flormich          #+#    #+#             */
/*   Updated: 2021/07/26 22:40:47 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->elt[0];
	stack->elt[0] = stack->elt[1];
	stack->elt[1] = tmp;
}

void	ft_pilote_swap(t_stack *stack_a, t_stack *stack_b, int	which)
{
	if (which == SA || which == SS)
		ft_swap(stack_a);
	if (which == SB || which == SS)
		ft_swap(stack_b);
	if (which == SA)
		write(1, "sa\n", 3);
	else if (which == SB)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
/*	write(1, "\nAFTER SWAP\n", 12);
	if (stack_a)
		ft_print_stack(stack_a, 'A');
	if (stack_b)
		ft_print_stack(stack_b, 'B');*/
}
