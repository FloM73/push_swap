/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/23 21:13:27 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Print Error and free the chunk_linked_list
//		ft_lstclear(&chunk);
static void	ft_error(t_chunk *chunk)
{
	write(1, "Error\n", 6);
	if (chunk)
		ft_lstclear(&chunk);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	t_chunk	*chunk;

	if (argc == 1)
		return (0);
	chunk = malloc(sizeof(t_chunk));
	ft_initialise_chunk(chunk, "TOTAL");
	stack_a = ft_check_argv(argc, argv, chunk);
	if (!stack_a)
		ft_error(chunk);
	else
	{
		ft_print_chunk(chunk);
		ft_print_stack(stack_a, argc);
	}
	stack_b = ft_calloc(argc, sizeof(int));
	if (!stack_b)
	{
		free(stack_a);
		return (NULL);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
