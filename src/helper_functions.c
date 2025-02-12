/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:48:27 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/10 15:43:58 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// void	del(int content)
// {
// 	free(content);
// }

void	print_int(int content)
{
	int	n;

	n = content;
	ft_printf("%d\n", n);
}

void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}