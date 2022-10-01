/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclerico <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:47:40 by mclerico          #+#    #+#             */
/*   Updated: 2021/11/13 18:15:40 by mclerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_args(char *s, char c)
{
	int	fletter;
	int	i;
	int	count;

	fletter = -1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (fletter == -1 && s[i] != c)
			fletter = i;
		else if (fletter != -1 && s[i] == c)
		{
			fletter = -1;
			count++;
		}
		i++;
	}
	if (fletter != -1)
		count++;
	return (count);
}

int	ft_atoicheck(const char *str)
{
	int		i;
	int		cont;
	int		a;

	i = 0;
	cont = 0;
	a = 0;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			cont = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
			return (-1);
	}
	return (1);
}

int	ft_atoinum(const char *str)
{
	int		i;
	int		cont;
	int		a;

	i = 0;
	cont = 0;
	a = 0;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			cont = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			a = (a * 10 + (str[i] - 48));
		i++;
	}
	if (cont != 0)
		a = a * -1;
	return (a);
}

int	ft_nparams(char **argv)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (argv[i])
		n += ft_args(argv[i++], ' ');
	return (n);
}

int	ft_reps(int	*nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[j])
		{
			if (nums[i] == nums[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
