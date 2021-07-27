/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_b_to_a_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:25:28 by flormich          #+#    #+#             */
/*   Updated: 2021/07/27 21:27:43 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//Send at first the batch from the > average numbers

int	ft_count_elt_big(t_stack *s, t_chunk*chk)
{
	int	average;
	int	i;
	int	count;

	if (chk->nb_elt_total != 0)
		average = chk->summe / chk->nb_elt_total;
	i = 0;
	count = 0;
	while (i < chk->nb_elt_total)
	{
		if (s->elt[i] > average)
			count++;
		i++;
	}
	return (count);
}

void	ft_move_chk_b_to_a_big(t_stack *a, t_stack *b, t_chunk *chk)
{

	int	nb_big;
	int	count_big;

	nb_big = ft_count_elt_big(b, chk);
	count_big = 0;
	while(chk->nb_elt_curent != 0)
	{
		//ft_print_stack(a, 'A');
		//ft_print_stack(b, 'B');
		if (count_big < nb_big && b->elt[0] <= chk->summe / chk->nb_elt_total)
		{
			ft_pilote_rotate(NULL, b, RB);
			chk->nb_rotate++;
			//ft_print_stack(b, 'B');
		}
		else if (count_big == nb_big && chk->nb_rotate > 0 && chk->nb_rotate < b->size)
		{
			while (chk->nb_rotate > 0)
			{
				ft_pilote_rrotate(NULL, b, RRB);
				chk->nb_rotate--;
				//ft_print_stack(b, 'B');
			}
		}
		else
		{
			if (b->elt[0] < b->elt[1] && b->size > 1)
				ft_pilote_swap(NULL, b, SB);
			if (b->elt[0] > a->elt[0] && a->size > 0)
			{
				if (b->size > 1)
					ft_pilote_rotate(NULL, b, RB);
				while (a->elt[0] < b->elt[b->size -1] && a->size > 0)
				{
					if(a->elt[0] > chk->summe / chk->nb_elt_total)
						count_big--;
					ft_pilote_push(a, b, PB);
					chk->nb_elt_curent++;

				}
				ft_pilote_rrotate(NULL, b, RRB);
			}
			ft_pilote_push(a, b, PA);
			chk->nb_elt_curent--;
			count_big++;
			//ft_print_stack(a, 'A');
			//ft_print_stack(b, 'B');
		}
	}
	//ft_print_stack(a, 'A');
	//ft_print_stack(b, 'B');
}

