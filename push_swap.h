/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:12:54 by flormich          #+#    #+#             */
/*   Updated: 2021/07/23 20:26:07 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include"libft/libft.h"

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

//ft_check_argv
int		*ft_check_argv(int argc, char **argv, t_chunk *chunk);
// ft_link_chunk.c: function dealing with the link-list
void	ft_lstclear(t_chunk **lst);
void 	ft_implemente_chunk(t_chunk *chunk, int nb);
void	ft_initialise_chunk(t_chunk *chunk, char *name);
// ft_print_chunk    A NE PAS SOUMETTRE
void	ft_print_chunk(t_chunk *chunk);
void	ft_print_stack(int	*stack_a, int argc);
#endif
