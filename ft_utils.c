/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:03:14 by flormich          #+#    #+#             */
/*   Updated: 2021/07/27 13:13:10 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check asceding order from the stack
int	ft_check_order(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->elt[i] < stack->elt[i + 1])
			i++;
		else
			return (0);
	}
	return (i + 1);
}

// Create stack b
t_stack	*ft_create_stack_b(t_stack *stack_a)
{
	t_stack	*b;

	b = ft_calloc(1, sizeof(t_stack));
	b->elt = ft_calloc(stack_a->size, sizeof(int *));
	b->size = 0;
	return (b);
}

// Display error message and free Chunk_Liste
void	ft_error(t_chunk *chunk)
{
	write(1, "Error\n", 6);
	if (chunk)
		ft_lstclear(&chunk);
}

// Free the stacks
void	ft_free(int how_many, ...)
{
	va_list	args;

	va_start(args, how_many);
	while (how_many > 0)
	{
		free(va_arg(args, int *));
		how_many--;
	}
	va_end(args);
}
