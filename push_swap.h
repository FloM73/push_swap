/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:12:54 by flormich          #+#    #+#             */
/*   Updated: 2021/08/02 11:50:33 by flormich         ###   ########.fr       */
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
	int				chk_nr;
	int				min;
	int				max;
	int				min_ist;
	int				max_ist;
	long int		sum;
	int				average;
	int				nb_elt_total;
	int				nb_elt_curent;
	int				nb_a_rotate;
	int				nb_b_rotate;
	struct s_chunk	*next;
	struct s_chunk	*previous;
}	t_chunk;

typedef struct s_stack
{
	int	*elt;
	int	size;
}	t_stack;

typedef enum e_mouvement
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
	RRR,
	NOK
}	t_mouvement;

typedef struct s_lst_move
{
	t_mouvement			move;
	struct s_lst_move	*next;
}	t_lst_move;

// Main (ft_push_swap.c)

//ft_check_argv & if already sorted (incl. 3 statics)
t_stack	*ft_import_argv(t_chunk *chunk, int argc, char **argv);

//ft_create_all_chunk: create the other chunks (incl. 1 static)
void	ft_pilote_create_all_chunk(t_chunk *first, t_stack *stack);
//t_chunk	*ft_create_chk(t_chunk *first, int nb, int min, int max);

//ft_send_a-to_b (incl. 3 statics)
t_stack	*ft_send_a_to_b(t_stack *a, t_chunk *chk);

// ft_send_b_to_a (incl. 2 statics)
void	ft_send_b_to_a(t_stack *a, t_stack *b, t_chunk *chk);

//ft_quick_sort to sort <= 3 numbers (incl. 2 statics)
void	ft_quick_sort(t_stack *a);
void	*ft_quick_sort_5(t_stack *a, t_stack *b, t_chunk *chk);

//Movement (each one file)
void	ft_pilote_swap(t_stack *a, t_stack *b, int which, int print);
void	ft_pilote_rotate(t_stack *a, t_stack *b, int which, int print);
void	ft_pilote_rrotate(t_stack *a, t_stack *b, int which, int print);
void	ft_pilote_push(t_stack *a, t_stack *b, int which, int print);

//ft_utils
t_stack	*ft_create_stack_b(t_stack *stack_a);
int		ft_check_order(t_stack *stack);

// ft_util_link_chunk.c: function dealing with the link-list and the first chunk
void	ft_lstclear(t_chunk **lst);
void	ft_implemente_chunk(t_chunk *chunk, int nb);
void	ft_initialise_chunk(t_chunk *chunk, int chk_nr, t_chunk *prev);
t_chunk	*ft_find_last(t_chunk *lst);
void	ft_error(t_chunk *chunk);

// BONUS: ft_z_checker
t_stack	*ft_z_import_argv(int argc, char **argv);
void	ft_write_result(t_stack *a, t_stack *b);

#endif
