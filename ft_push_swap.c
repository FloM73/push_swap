/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/29 16:38:17 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_chunk		*chunk;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (0);
	stack_a = ft_import_argv(chunk, argc, argv);
//	ft_print_stack(stack_a, 'A');
	if (ft_check_order(stack_a) == 0)
	{
		ft_pilote_create_all_chunk(chunk, stack_a);
		stack_b = ft_send_a_to_b(stack_a, chunk);
		if (stack_b)
			ft_send_b_to_a(stack_a, stack_b, ft_find_last(chunk));
	}
//	ft_print_stack(stack_a, 'A');
/*	if (ft_check_order(stack_a) == 0)
		write(1, "ZUT\n", 4);
	else
		write(1, "TRI OK!\n", 8);*/
	free(stack_a);
	free(stack_b);
	ft_lstclear(&chunk);
	return (1);
}

/*
	if (ft_check_order(stack_a) == 0)
		write(1, "ZUT\n", 4);
	else
		write(1, "TRI OK!\n", 8);
		*/
