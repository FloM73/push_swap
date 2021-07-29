/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/29 20:33:40 by flormich         ###   ########.fr       */
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
	chunk = malloc(sizeof(t_chunk));
	if (!chunk)
		return (0);
	stack_a = ft_import_argv(chunk, argc, argv);
	if (stack_a)
	{
		if (ft_check_order(stack_a) == 0)
		{
			ft_pilote_create_all_chunk(chunk, stack_a);
			stack_b = ft_send_a_to_b(stack_a, chunk);
			if (stack_b)
				ft_send_b_to_a(stack_a, stack_b, ft_find_last(chunk));
		}
		free(stack_a);
		ft_lstclear(&chunk);
	}
	return (1);
}
