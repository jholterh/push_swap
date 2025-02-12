/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:55:07 by jholterh          #+#    #+#             */
/*   Updated: 2025/02/12 12:38:57 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    swap_a(t_link *link, int version)
{
    if (!link->head_a || !(link->head_a->next))
        return ;
    t_list2 *first = link->head_a;
    t_list2 *second = first->next;
    link->head_a = second;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    else
        link->tail_a = first;
    second->prev = first->prev;
    first->prev = second;
    second->next = first;
    if (version != 1)
        ft_printf("sa\n");
}

void swap_b(t_link *link, int version)
{
    if (!link->head_b || !(link->head_b->next))
        return ;
    t_list2 *first = link->head_b;
    t_list2 *second = first->next;
    link->head_b = second;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    else
        link->tail_b = first;
    second->prev = first->prev;
    first->prev = second;
    second->next = first;
    if (version != 1)
        ft_printf("sb\n");
}

void    swap_s(t_link *link)
{
    swap_a(link, 1);
    swap_a(link, 1);
    ft_printf("ss\n");
}

void    push_b(t_link *link)
{
    if (!link->head_a)
        return ;
    t_list2 *top = link->head_a;

    link->head_a = top->next;
    if (link->head_a)
    {
        (link->head_a)->prev = NULL;
        if (!(link->head_a)->next)
            link->tail_a = link->head_a;
    }
    else
        link->tail_a = NULL;
    top->next = link->head_b;
    if (link->head_b)
        (link->head_b)->prev = top;
    else
    link->tail_b = top;
    link->head_b = top;
    ft_printf("pb\n");
}

void push_a(t_link *link)
{
    if (!link->head_b)
        return ;
    t_list2 *top = link->head_b;

    link->head_b = top->next;
    if (link->head_b)
    {
        (link->head_b)->prev = NULL;
        if (!(link->head_b)->next)
            link->tail_b = link->head_b;
    }
    else
        link->tail_b = NULL;
    top->next = link->head_a;
    if (link->head_a)
        (link->head_a)->prev = top;
    else
        link->tail_a = top;
    link->head_a = top;
    ft_printf("pa\n");
}


void    rotate_a(t_link *link, int version)
{
    t_list2 *start = link->head_a;
    t_list2 *end = link->tail_a;

    if (!link->head_a || !(link->head_a)->next)
        return ;
    link->head_a = start->next;
    (link->head_a)->prev = NULL;

    start->next = NULL;
    start->prev = end;
    end->next = start;
    link->tail_a = start;
    if (version != 1)
        ft_printf("ra\n");
}

void rotate_b(t_link *link, int version)
{
    t_list2 *start = link->head_b;
    t_list2 *end = link->tail_b;

    if (!link->head_b || !(link->head_b)->next)
        return ;
    link->head_b = start->next;
    (link->head_b)->prev = NULL;

    start->next = NULL;
    start->prev = end;
    end->next = start;
    link->tail_b = start;
    if (version != 1)
        ft_printf("rb\n");
}


void    rotate_r(t_link *link)
{
    rotate_a(link, 1);
    rotate_b(link, 1);
    ft_printf("rr\n");
}

void    reverse_rotate_a(t_link *link, int version)
{
    t_list2 *start = link->head_a;
    t_list2 *end = link->tail_a;
    
    if (!link->head_a || !(link->head_a)->next)
        return ;
    link->tail_a = end->prev;
    (link->tail_a)->next = NULL;

    link->head_a = end;
    (link->head_a)->prev = NULL;
    (link->head_a)->next = start;
    start->prev = end;
    if (version != 1)
        ft_printf("rra\n");
}

void reverse_rotate_b(t_link *link, int version)
{
    t_list2 *start = link->head_b;
    t_list2 *end = link->tail_b;
    
    if (!link->head_b || !(link->head_b)->next)
        return ;
    link->tail_b = end->prev;
    (link->tail_b)->next = NULL;

    link->head_b = end;
    (link->head_b)->prev = NULL;
    (link->head_b)->next = start;
    start->prev = end;
    if (version != 1)
        ft_printf("rrb\n");
}

void    reverse_rotate_r(t_link *link)
{
    reverse_rotate_a(link, 1);
    reverse_rotate_b(link, 1);
    ft_printf("rrr\n");
}