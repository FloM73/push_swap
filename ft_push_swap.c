/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/26 22:41:48 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Print Error and free the chunk_linked_list
//		ft_lstclear(&chunk);
static t_stack	*ft_create_stack_b(t_stack *stack_a)
{
	t_stack	*b;

	b = ft_calloc(1, sizeof(t_stack));
	b->elt = ft_calloc(stack_a->size, sizeof(int *));
	b->size = 0;
	return (b);
}

void	ft_error(t_chunk *chunk)
{
	write(1, "Error\n", 6);
	if (chunk)
		ft_lstclear(&chunk);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_chunk		*chunk;

	if (argc == 1)
		return (0);
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (0);
	stack_a = ft_import_argv(chunk, argc, argv);
	stack_b = ft_create_stack_b(stack_a);
	if (!stack_b || !stack_b->elt)
	{
		ft_free(1, stack_a);
		ft_lstclear(&chunk);
		return (0);
	}
	if (ft_check_order(stack_a) == 0)
		ft_send_chk_to(stack_a, stack_b, chunk);
//	write(1, "\nEND RESULT\n", 12);
//	ft_print_stack(stack_a, 'A');
//	ft_print_stack(stack_b, 'B');
	ft_free(2, stack_a, stack_b);
	ft_lstclear(&chunk);
	return (1);
}

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
