/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:28:34 by mmartin           #+#    #+#             */
/*   Updated: 2020/02/26 20:53:00 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *str)
{
	int					x;
	int					esnegativo;

	esnegativo = 1;
	x = 0;
	while (*str == '\f' || *str == '\n' || *str == '\r'
	|| *str == '\t' || *str == '\v' || *str == ' ')
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '+')
			++str;
		else
		{
			esnegativo *= -1;
			++str;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - 48);
		++str;
	}
	return (x * esnegativo);
}

int		is_first_line_ok(char *map, char *num_lines)
{
	int c;
	int i;
	int *not_num;

	not_num = malloc(sizeof(int));
	*not_num = 0;
	c = is_first_line_ok2(map, not_num);
	i = 0;
	while (map[i] != '\n')
	{
		if (map[0] >= 48 && map[0] <= 57)
		{
			while (i < c - 3)
			{
				num_lines[i] = map[i];
				i++;
			}
		}
		else
			return (0);
		i++;
	}
	return (*not_num <= 3) ? 1 : 0;
}

int		are_number_lines_ok(char *map, char *num_lines)
{
	int i;
	int lines;

	i = 0;
	lines = -1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			lines++;
		i++;
	}
	return (lines == ft_atoi(num_lines)) ? 1 : 0;
}

int		are_chars_ok(char *map)
{
	int		chars;
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i] != '\0')
	{
		chars = 0;
		if (map[i - 1] == '\n')
			while (map[i] != '\n')
			{
				chars++;
				i++;
			}
		if (chars != get_char(map))
			return (0);
		i++;
	}
	return (1);
}

int		are_lines_ok(char *map)
{
	char *num_lines;

	num_lines = (char*)malloc(2700000);
	if (is_first_line_ok(map, num_lines) && are_number_lines_ok(map, num_lines)
	&& are_chars_ok(map))
		return (1);
	return (0);
}
