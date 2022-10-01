/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:59:02 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/29 17:42:56 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_binsort(int num, int index)
{
	num >>= index;
	if (num & 1)
		return (1);
	else
		return (0);
}

int	ft_issorted(t_list *list)
{
	t_list	*aux;

	if (!list)
		return (0);
	while (list->next)
	{
		aux = list;
		list = list->next;
		if ((*(int *)(list->content)) < (*(int *)(aux->content)))
			return (0);
	}
	return (1);
}

void	ft_radix_sort(t_list **stacka, t_list **stackb)
{
	int	i;
	int	u;

	i = ft_lstsize(*stacka);
	u = 0;
	while (!ft_issorted(*stacka))
	{
		while (i > 0)
		{
			if (ft_binsort(*(int *)(*stacka)->content, u) == 0)
				ft_push(stackb, stacka, "pb\n");
			else
				ft_rotate(stacka, "ra\n");
			i--;
		}
		while (*stackb)
			ft_push(stacka, stackb, "pa\n");
		i = ft_lstsize(*stacka);
		u++;
	}
}

int	ft_tryrotate(t_list **stack, int max, int flag, char *str)
{
	int	cont;
	int	t;

	cont = 0;
	t = 0;
	while (*(int *)(*stack)->content != max && flag == 0)
	{
		cont++;
		ft_rotate(stack, NULL);
	}
	if (flag == 0)
	{
		while (t < cont)
		{
			ft_rrotate(stack, NULL);
			t++;
		}
	}
	while (*(int *)(*stack)->content != max && flag == 1)
	{
		cont++;
		ft_rotate(stack, str);
	}
	return (cont);
}

int	ft_tryrrotate(t_list **stack, int max, int flag, char *str)
{
	int	cont;
	int	t;

	cont = 0;
	t = 0;
	while (*(int *)(*stack)->content != max && flag == 0)
		cont += ft_rrotate(stack, NULL);
	if (flag == 0)
	{
		while (t < cont)
			t += ft_rotate(stack, NULL);
	}
	while (*(int *)(*stack)->content != max && flag == 1)
		cont += ft_rrotate(stack, str);
	return (cont);
}
