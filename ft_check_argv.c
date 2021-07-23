/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:37:46 by flormich          #+#    #+#             */
/*   Updated: 2021/07/23 21:00:18 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Fill the stack & Check if there are double
static int	ft_fill_stack_a(int *stack, int position, int nb)
{
	int	i;

	i = 0;
	while (i < position)
	{
		 if (stack[i] == nb)
			return (0);
		else
			i++;
	}
	stack[position] = nb;
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
int	*ft_check_argv(int argc, char **argv, t_chunk *chunk)
{
	int	i;
	int	nb;
	int	*stack;

	stack = ft_calloc(argc, sizeof(int));
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (ft_extract_number(argv[i], &nb) == 0)
			return (NULL);
		else
		{
			ft_implemente_chunk(chunk, nb);
			if (ft_fill_stack_a(stack, i - 1, nb) == 0)
			{
				free(stack);
				return (NULL);
			}
			i++;
		}
	}
	return (stack);
}
