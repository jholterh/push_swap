/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:37 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/10 15:46:44 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *head, void (*f)(void *))
{
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

void	ft_lstiter2(t_list2 *head, void (*f)(int))
{
	t_list2	*tmp;

	tmp = head;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
