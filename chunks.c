/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:49:32 by mclerico          #+#    #+#             */
/*   Updated: 2021/10/29 17:44:42 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_list **stacka)
{
	if (!ft_issorted(*stacka))
		ft_swap(stacka,"sa\n");
}

void	fill_stacka(t_list **stacka, t_list **stackb)
{
	while (ft_lstsize(*stackb))
	{
		ft_return_max(stackb);
		ft_push(stacka, stackb, "pa\n");
	}
}

void	ft_inchunk(t_list **stacka, t_list **stackb)
{
	int	i;
	int	c;

	i = 20;
	c = 1;
	while (c)
	{
		c = ft_pushrank(stacka, stackb, i);
		i += 20;
	}
	fill_stacka(stacka, stackb);
}
