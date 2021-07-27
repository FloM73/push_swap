/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_b_to_a_biggest.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:25:28 by flormich          #+#    #+#             */
/*   Updated: 2021/07/27 21:37:38 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// Send at first the biggest

void	ft_move_chk_b_to_a_biggest(t_stack *a, t_stack *b, t_chunk *chk)
{
	int	biggest;

	biggest = 0;
	while(chk->nb_elt_curent != 0)
	{
		//ft_print_stack(a, 'A');
		//ft_print_stack(b, 'B');
		if (biggest == 0)
		{
			while (biggest == 0 && b->elt[0] != chk->max_ist)
			{
				ft_pilote_rotate(NULL, b, RB);
				chk->nb_rotate++;
				//ft_print_stack(b, 'B');
			}
			biggest = 1;
		}
		else
		{
			if (b->elt[0] > chk->min && b->elt[0] < b->elt[1] && b->size > 1)
				ft_pilote_swap(NULL, b, SB);
			while (chk->nb_rotate > 0 && b->elt[b->size - 1] > b->elt[0])
			{
				ft_pilote_rrotate(NULL, b, RRB);
				chk->nb_rotate--;
				//ft_print_stack(b, 'B');
			}
			if (b->elt[0] > a->elt[0] && a->size > 0)
			{
				if (b->size > 1)
					ft_pilote_rotate(NULL, b, RB);
				while (a->elt[0] < b->elt[b->size -1] && a->size > 0)
				{
					ft_pilote_push(a, b, PB);
					chk->nb_elt_curent++;
					//ft_print_stack(a, 'A');
					//ft_print_stack(b, 'B');
				}
				ft_pilote_rrotate(NULL, b, RRB);
				//ft_print_stack(b, 'B');
			}
		}
		ft_pilote_push(a, b, PA);
		chk->nb_elt_curent--;
		//ft_print_stack(a, 'A');
		//ft_print_stack(b, 'B');
	}
	//ft_print_stack(a, 'A');
	//ft_print_stack(b, 'B');
}
