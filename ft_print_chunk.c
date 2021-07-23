// Pour la programmation NE PAS SOUMETTRE

#include"push_swap.h"
#include<stdio.h>

void	ft_print_chunk(t_chunk *chunk)
{
	printf("CHUNK:                %s\n", chunk->name);
	printf("- NB element_total  = %d\n", chunk->nb_elt_total);
	printf("- NB element_actuel = %d\n", chunk->nb_elt_curent);
	printf("- Value min         = %d\n", chunk->min);
	printf("- Value max         = %d\n", chunk->max);
	printf("- NB chunk          = %d\n", chunk->nb_chunk);
	printf("- Previous chunk    = %p\n", chunk->previous);
	printf("- Next chunk        = %p\n", chunk->next);
}

void	ft_print_stack(int *stack, int argc)
{
	int	i;
	int	nb;

	i = 0;
	write(1, "Stack: ", 7);
	while (i < argc - 1)
	{
		nb = stack[i];
		ft_putnbr_fd(nb, 1);
		write(1, ", ", 2);
		i++;
	}
	write(1, "\n", 1);
}
