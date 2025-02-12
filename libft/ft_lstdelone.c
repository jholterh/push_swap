/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:00 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/10 15:45:55 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *head, void (*del)(void *))
{
	if (!head || !del)
		return;
	del(head->content);
	free(head);
}

void ft_lstdelone2(t_list2 *node) {
    if (!node)
        return;
    free(node);
}

