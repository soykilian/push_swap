/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:53:36 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/29 17:34:49 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max(t_list *list)
{
	int		max;
	t_list	*first;

	first = list;
	max = *(int *)(first->content);
	while (first->next)
	{
		first = first->next;
		if ((*(int *)(first->content)) > max)
			max = *(int *) first->content;
	}
	return (max);
}

void	ft_pushmaxb(t_list **stacka, t_list **stackb)
{
	int	max;

	max = ft_get_max(*stacka);
	if (ft_tryrotate(stacka, max, 0, "") > ft_tryrrotate(stacka, max, 0, ""))
		ft_tryrrotate(stacka, max, 1, "rra\n");
	else
		ft_tryrotate(stacka, max, 1, "ra\n");
	ft_push(stackb, stacka, "pb\n");
}

void	ft_sort3a(t_list **stacka)
{
	int	third;
	int	second;
	int	first;

	third = *(int *)(ft_lstlast(*stacka)->content);
	second = *(int *)((*stacka)->next)->content;
	first = *(int *)(*stacka)->content;
	if (first > second && second > third && third < first)
	{
		ft_rotate(stacka, "ra\n");
		ft_swap(stacka, "sa\n");
	}
	else if (first > second && second < third && first > third)
		ft_rotate(stacka, "ra\n");
	else if (first < second && second > third && first < third)
	{
		ft_rrotate(stacka, "rra\n");
		ft_swap(stacka, "sa\n");
	}
	else if (first < second && second > third && first > third)
		ft_rrotate(stacka, "rra\n");
	else if (first > second && second < third && first < third)
		ft_swap(stacka, "sa\n");
}

void	ft_sort5(t_list **stacka, t_list **stackb)
{
	int	i;
	int	size;

	i = ft_lstsize(*stacka);
	size = ft_lstsize(*stacka);
	while (i - 3 > 0)
	{
		ft_pushmaxb(stacka, stackb);
		i--;
	}
	ft_sort3a(stacka);
	i = size;
	while (i - 3 > 0)
	{
		ft_push(stacka, stackb, "pa\n");
		ft_rotate(stacka, "ra\n");
		i--;
	}
}
