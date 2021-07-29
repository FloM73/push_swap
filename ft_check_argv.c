/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/28 21:42:44 by flormich         ###   ########.fr       */
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
			free(stack);
			return (0);
		}
		else
			i++;
	}
	stack->elt[position] = nb;
	stack->size = position + 1;
	return (1);
}

// Extract number von argv and check if they are all digits
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

// Pilote: screen argv, create first Chunk, fill stack_a
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
			free(stack);
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

// If arguments are OK return stack_a
// Evtl. exit if error or already sorted
t_stack	*ft_import_argv(t_chunk	*chunk, int argc, char **argv)
{
	t_stack	*stack_a;

	ft_initialise_chunk(chunk, 0, NULL);
	stack_a = ft_check_argv(argc, argv, chunk);
	if (!stack_a || !stack_a->elt)
	{
		ft_error(chunk);
		return (NULL);
	}
	return (stack_a);
}
