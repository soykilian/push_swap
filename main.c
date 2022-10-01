/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:33:43 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/29 19:52:23 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_null(void *param)
{
	param = NULL;
}

int main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	if (argc == 1)
	{
		return (-1);
	}
	stackb = NULL;
	if (ft_fstack(&stacka, argv, argc, 0) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (ft_lstsize(stacka) == 1)
		return (1);
	else if (ft_lstsize(stacka) == 2)
		ft_sort2(&stacka);
	else if (ft_lstsize(stacka) < 6)
		ft_sort5(&stacka, &stackb);
	else if (ft_lstsize(stacka) < 101)
		ft_inchunk(&stacka, &stackb);
	else 
		ft_radix_sort(&stacka, &stackb);
	ft_lstclear(&stacka, ft_set_null);
	ft_lstclear(&stackb, ft_set_null);
	free(stacka);
	free(stackb);
	system("leaks push_swap");
}

void ft_printstack(t_list *stack)
{
	while (stack)
	{
		printf("%i\n", *(int *)(stack->content));
		stack = stack->next;
	}
}
