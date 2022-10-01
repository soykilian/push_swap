/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:43:16 by mclerico          #+#    #+#             */
/*   Updated: 2021/12/06 17:00:03 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int *num)
{
	int	min;
	int	i;
	int	index;

	min = num[0];
	i = 1;
	index = 0;
	while (num[i])
	{
		if (num[i] < min)
		{
			min = num[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	*ft_mapping(int *nums, int len)
{
	int	i;
	int	j;
	int	cont;
	int	*copy;

	i = 0;
	cont = 0;
	copy = malloc(len * sizeof(int));
	nums[ft_min(nums)] = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (nums[j] < nums[i] && j != i)
				cont++;
			j++;
		}
		copy[i] = cont;
		cont = 0;
		i++;
	}
	free(copy);
	return (copy);
}	

void	ft_add(t_list **nums, int *new, int len)
{
	int	i;

	i = 0;
	while (i < len)
		ft_lstadd_back(nums, ft_lstnew(&new[i++]));
}

void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	ft_fstack(t_list **nums, char **argv, int argc, int n)
{
	int		i;
	int		k;
	char	**splitted;
	int		*new;

	i = 1;
	k = 0;
	new = ft_calloc(ft_nparams(argv) + 1, sizeof(int));
	while (i < argc)
	{
		n = 0;
		splitted = ft_split(argv[i], ' ');
		while (splitted[n])
		{
			if (ft_atoicheck(splitted[n]) != -1)
				new[k++] = ft_atoi(splitted[n++]);
			else
				return (0);
		}
		ft_free_split(splitted);
		i++;
	}
	if (!ft_reps(new))
		return (0);
	ft_add(nums, ft_mapping(new, k), k);
	free(new);
	return (1);
}
