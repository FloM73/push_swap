/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:12:54 by flormich          #+#    #+#             */
/*   Updated: 2021/07/25 21:54:23 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include"libft/libft.h"
# include<stdarg.h>

typedef struct s_chunk
{
	char			*name;
	int				min;
	int				max;
	int				nb_elt_total;
	int				nb_elt_curent;
	int				nb_rotate;
	int				nb_chunk;
	struct s_chunk	*next;
	struct s_chunk	*previous;
} t_chunk;

typedef struct s_stack
{
	int	*elt;
	int	size;
} t_stack;

enum e_mouvement
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

// Main
void	ft_error(t_chunk *chunk);
void	ft_free(int how_many, ...);
//ft_check_argv + 4 static
t_stack	*ft_import_argv(t_chunk *chunk, int argc, char **argv);
// ft_link_chunk.c: function dealing with the link-list and the first chunk
void	ft_lstclear(t_chunk **lst);
void 	ft_implemente_chunk(t_chunk *chunk, int nb);
void	ft_initialise_chunk(t_chunk *chunk, char *name);
t_chunk	*ft_find_last(t_chunk *lst);
//ft_create_all_chunk: create the other chunks + statics
void	ft_pilote_create_chunk(t_chunk *first, t_stack *stack);
t_chunk	*ft_create_chk(t_chunk *first, int nb, int min, int max);
//ft_check_order
int		ft_check_order(t_stack *stack);
// ft_print_HELP    A NE PAS SOUMETTRE
void	ft_print_chunk(t_chunk *chunk);
void	ft_print_stack(t_stack	*stack_a);
//ft_sort
void	ft_quick_sort(t_stack *stack);
void	ft_quick_sort_3(t_stack *stack);
//ft_swap
void	ft_pilote_swap(t_stack *stack_a, t_stack *stack_b, int	which);
//ft_rotate
void	ft_pilote_rotate(t_stack *stack_a, t_stack *stack_b, int	which);
//ft_rrotate
void	ft_pilote_rrotate(t_stack *stack_a, t_stack *stack_b, int	which);
//ft_push
void	ft_pilote_push(t_stack *stack_a, t_stack *stack_b, int	which);
#endif
