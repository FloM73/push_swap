/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:46:43 by flormich          #+#    #+#             */
/*   Updated: 2021/08/02 10:45:57 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	ft_free(t_lst_move **lst, t_stack *a)
{
	t_lst_move	*mem_next;

	free(a);
	if (!lst)
		return ;
	mem_next = (*lst)->next;
	while (*lst)
	{
		mem_next = (*lst)->next;
		free(*lst);
		*lst = mem_next;
	}
	*lst = NULL;
}

static t_mouvement	ft_find_mvt(char	*input)
{
	if (ft_strncmp(input, "sa", 2) == 0)
		return (SA);
	else if (ft_strncmp(input, "sb", 2) == 0)
		return (SB);
	else if (ft_strncmp(input, "ss", 2) == 0)
		return (SS);
	else if (ft_strncmp(input, "pa", 2) == 0)
		return (PA);
	else if (ft_strncmp(input, "pb", 2) == 0)
		return (PB);
	else if (ft_strncmp(input, "rra", 3) == 0)
		return (RRA);
	else if (ft_strncmp(input, "rrb", 3) == 0)
		return (RRB);
	else if (ft_strncmp(input, "rrr", 3) == 0)
		return (RRR);
	else if (ft_strncmp(input, "ra", 2) == 0)
		return (RA);
	else if (ft_strncmp(input, "rb", 2) == 0)
		return (RB);
	else if (ft_strncmp(input, "rr", 2) == 0)
		return (RR);
	else
		return (NOK);
}

static int	ft_read_cmd(t_lst_move	*to_do, int loop)
{
	t_lst_move	*mvt;
	char		buff[5];
	int			move;

	while (loop > 1)
	{
		loop = read(1, buff, 5);
		if (loop > 1)
		{
			mvt = ft_calloc(1, sizeof(t_lst_move));
			if (mvt)
			{
				to_do->next = mvt;
				move = ft_find_mvt(buff);
				if (move == NOK)
				{
					write(1, "Error\n", 6);
					return (0);
				}
				mvt->move = move;
				to_do = mvt;
			}
		}
	}
	return (1);
}

static int	ft_apply_to_do(t_stack *a, t_stack *b, t_lst_move *mvt, int size)
{
	while (mvt)
	{
		if (mvt->move == SA || mvt->move == SB || mvt->move == SS)
			ft_pilote_swap(a, b, mvt->move, 0);
		else if (mvt->move == RA || mvt->move == RB || mvt->move == RR)
			ft_pilote_rotate(a, b, mvt->move, 0);
		else if (mvt->move == RRA || mvt->move == RRB || mvt->move == RRR)
			ft_pilote_rrotate(a, b, mvt->move, 0);
		else if (mvt->move == PA || a-> size < size)
			ft_pilote_push(a, b, mvt->move, 0);
		else if (mvt->move == PB || b->size < size)
			ft_pilote_push(a, b, mvt->move, 0);
		mvt = mvt->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_lst_move	*to_do;
	int			size_max;

	if (argc == 1)
		return (0);
	stack_a = ft_z_import_argv(argc, argv);
	if (stack_a)
	{
		size_max = stack_a->size;
		to_do = ft_calloc(1, sizeof(t_lst_move));
		if (ft_read_cmd(to_do, 2) == 1)
		{
			stack_b = ft_create_stack_b(stack_a);
			if (stack_b)
			{
				ft_apply_to_do (stack_a, stack_b, to_do->next, size_max);
				ft_write_result(stack_a, stack_b);
				free(stack_b);
			}
		}
		ft_free(&to_do, stack_a);
	}
	return (0);
}
