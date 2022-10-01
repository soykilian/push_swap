/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:51:23 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/29 16:59:59 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_existless(t_list *stacka, int max)
{
	while (stacka)
	{
		if (*(int *)(stacka)->content < max)
			return (1); stacka = stacka->next;
	}
	return (-1);
}

int	try_rot(t_list **stack, int max, int flag, char *str)
{
	int	cont;
	int	t;
	int	size;

	cont = 0;
	t = 0;
	size = ft_lstsize(*stack);
	while (*(int *)(*stack)->content > max && flag == 0 && cont <= size)
		cont += ft_rotate(stack, NULL);
	if (flag == 0)
	{
		while (t < cont)
			t += ft_rrotate(stack, NULL);
	}
	while (*(int *)(*stack)->content > max && flag == 1 && cont <= size)
		cont += ft_rotate(stack, str);
	return (cont);
}

int	try_rrot(t_list **stack, int max, int flag, char *str)
{
	int	cont;
	int	t;
	int	size;

	cont = 0;
	t = 0;
	size = ft_lstsize(*stack);
	while (*(int *)(*stack)->content > max && flag == 0 && cont <= size)
		cont += ft_rrotate(stack, NULL);
	if (flag == 0)
	{
		while (t < cont)
			t += ft_rotate(stack, NULL);
	}
	while (*(int *)(*stack)->content > max && flag == 1 && cont <= size)
		cont += ft_rrotate(stack, str);
	return (cont);
}

int	ft_pushrank(t_list **stacka, t_list **stackb, int max)
{
	while (ft_existless(*stacka, max) == 1)
	{
		if (try_rot(stacka, max, 0, "") > try_rrot(stacka, max, 0, ""))
			try_rrot(stacka, max, 1, "rra\n");
		else
			try_rot(stacka, max, 1, "ra\n");
		ft_push(stackb, stacka, "pb\n");
	}
	if (ft_lstsize(*stacka) == 0)
		return (0);
	return (1);
}

void	ft_return_max(t_list **stackb)
{
	int	max;

	max = ft_get_max(*stackb);
	if (ft_tryrotate(stackb, max, 0, "") > ft_tryrrotate(stackb, max, 0, ""))
		ft_tryrrotate(stackb, max, 1, "rrb\n");
	else
		ft_tryrotate(stackb, max, 1, "rb\n");
}
