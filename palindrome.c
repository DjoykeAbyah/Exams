/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   palindrome.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dreijans <dreijans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:21:47 by dreijans      #+#    #+#                 */
/*   Updated: 2023/01/27 19:34:58 by dreijans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "palindrome.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check(char *str, int i, int j)
{
	int	x;

	x = 0;
	while (str[i] == str[j] && i != j)
	{
		i++;
		if (j != i)
			j--;
	}
	if (str[i] != str[j])
		return (0);
	return (1);
}

void	ft_printstr(char *s, int i, int j)
{
	int	len;
	int	x;

	len = j - i;
	x = 0;
	while (x <= len)
	{
		write(1, &s[x], 1);
		x++;
	}
}

int	*ft_loop(char *str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] != '\0' && j != 0)
	{
		if (str[i] == str[j])
		{
			x = ft_check(str, i, j);
			if (x == 1)
			{
				ft_printstr(&str[i], i, j);
				return (0);
			}
			if (x == 0)
			{
				i++;
				j = ft_strlen(str) - 1;
			}
		}
		j--;
		if (j == i)
		{
			j = ft_strlen(str) - 1;
			i++;
		}	
	}
	return (0);
}