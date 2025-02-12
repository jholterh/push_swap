/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:37:36 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/11 15:33:10 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list2 *ft_lstnew2(int content)
{
    t_list2 *new_node = (t_list2 *)malloc(sizeof(t_list2));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->steps = 0;
    new_node->together = 0;
    new_node->option = 0;
    new_node->rotate_a = 0;
    new_node->rotate_b = 0;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
