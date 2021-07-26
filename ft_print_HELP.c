// Pour la programmation NE PAS SOUMETTRE

#include"push_swap.h"
#include<stdio.h>

void	ft_print_chunk(t_chunk *chunk)
{
	while (chunk)
	{
		printf("CHUNK:                  %s\n", chunk->name);
		printf("- Adresse             = %p\n", *&chunk);
		printf("- NB element / total  = %6d / %6d\n", chunk->nb_elt_curent, chunk->nb_elt_total);
		printf("- Value min / max     = %6d / %6d\n", chunk->min, chunk->max);
		printf("- Somme / Moyenne     = %6ld / %6ld\n", chunk->summe, chunk->summe / chunk->nb_elt_total);
		if (chunk->nb_chunk != 0)
			printf("- NB chunk            = %d\n", chunk->nb_chunk);
		printf("- Previous <-> next   = %p <-> %p\n\n", chunk->previous, chunk->next);
		chunk = chunk->next;
	}
	printf("______________________________________________________\n");
}

void	ft_print_stack(t_stack *stack, char laquelle)
{
	int	i;
	int	nb;

	i = 0;
	write(1, "Stack ", 6);
	write(1, &laquelle, 1);
	write(1, ": ", 2);
	while (i < stack->size)
	{
		nb = stack->elt[i];
		ft_putnbr_fd(nb, 1);
		if (i < stack->size - 1)
			write(1, ", ", 2);
		i++;
	}
	write(1, "\n\n", 2);
}
