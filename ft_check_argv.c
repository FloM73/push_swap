/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/25 22:31:43 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Fill the stack & Check if there are double
static int	ft_fill_stack_a(t_stack *stack, int position, int nb)
{
	int	i;

	i = 0;
	while (i < position)
	{
		if (stack->elt[i] == nb)
		{
			ft_free(1, stack);
			return (0);
		}
		else
			i++;
	}
	stack->elt[position] = nb;
	stack->size = position + 1;
	return (1);
}

// Extract number von argv
static int	ft_extract_number(char *argv, int	*nb)
{
	int		j;
	int		sign;

	j = 0;
	*nb = 0;
	sign = 1;
	if (argv[j] == '+' || argv[j] == '-')
	{
		if (argv[j] == '-')
			sign = -1;
		j++;
	}
	while (argv[j] != '\0')
	{
		if (ft_isdigit(argv[j]) == 1)
		{
			*nb = *nb * 10 + (argv[j] - 48);
			j++;
		}
		else
			return (0);
	}
	j++;
	*nb = *nb * sign;
	return (1);
}

// Screen argv, create first Chunk, fill stack_a
static t_stack	*ft_check_argv(int argc, char **argv, t_chunk *chunk)
{
	int		i;
	int		nb;
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->elt = ft_calloc(argc, sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (ft_extract_number(argv[i], &nb) == 0)
		{
			ft_free(1, stack);
			return (NULL);
		}
		else
		{
			ft_implemente_chunk(chunk, nb);
			if (ft_fill_stack_a(stack, i - 1, nb) == 0)
				return (NULL);
			i++;
		}
	}
	return (stack);
}

// If arguments are OK: evtl. exit if already sorted other create all the chunks
t_stack	*ft_import_argv(t_chunk	*chunk, int argc, char **argv)
{
	t_stack	*stack_a;

	ft_initialise_chunk(chunk, "TOTAL");
	stack_a = ft_check_argv(argc, argv, chunk);
	if (!stack_a)
	{
		ft_error(chunk);
		exit(0);
	}
	else
	{
		ft_print_stack(stack_a);
		if (ft_check_order(stack_a) == stack_a->size)
		{
			ft_free(1, stack_a);
			exit (0);
		}
		ft_pilote_create_chunk(chunk, stack_a);
	}
	return (stack_a);
}
