#include "push_swap.h"

void    sort_2_numbers(t_link *link);

int    check_done(t_list2 *head_a)
{
    t_list2 *tmp;

    if (!head_a || !head_a->next)
        return 0;
    tmp = head_a;
    while (tmp->next)
    {
        if (tmp->content > tmp->next->content)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    sort_3_numbers(t_link *link)
{
    if ((link->head_a)->content > (link->head_a)->next->content && (link->head_a)->content > (link->head_a)->next->next->content)
        rotate_a(link, 1);
    if (check_done(link->head_a) == 0)
        return ;
    sort_2_numbers(link);
    if (check_done(link->head_a) == 0)
        return ;
    reverse_rotate_a(link, 1);
    if (check_done(link->head_a))
        swap_a(link, 1);
    return;
}

void    sort_2_numbers(t_link *link)
{
    if ((link->head_a)->content > (link->head_a)->next->content)
        swap_a(link, 1);
}

int     find_bottom(t_list2 *head)
{
    int bottom;
    t_list2 *tmp;

    bottom = head->content;
    tmp = head->next;
    while (tmp)
    {
        if (bottom > tmp->content)
            bottom = tmp->content;
        tmp = tmp->next;
    }
    return (bottom);
}

int     find_top(t_list2 *head)
{
    int top;
    t_list2 *tmp;

    top = head->content;
    tmp = head->next;
    while (tmp)
    {
        if (top < tmp->content)
            top = tmp->content;
        tmp = tmp->next;
    }
    return (top);
}

int     calc_forward_a(t_link link, int value)
{
    t_list2 *current;
    int steps;

    steps = 0;
    current = link.head_a;
    while (current)
    {
        if (value != current->content)
            steps++;
        else
            return (steps);
        current = current->next;
    }
    return (steps);
}

int     calc_forward_b(t_link link, t_list2 *head_a)
{
    int value;
    int steps_b;
    int flag;
    t_list2 *current;       

    flag = 0;
    steps_b = 0;
    value = head_a->content;
    current = link.head_b;
    while (current)
    {
        if (current->content < value && flag == 0)
        {
            steps_b++;
            current = current->next;
        }
        else
        {
            flag = 1;
            if (current->content > value)
            {
                steps_b++;
                current = current->next;
            }
            else
                break ;
        }
    }
    return (steps_b);
}

int     calc_forward_b_special(t_link link, t_list2 *head_a, int top)
{
    int value;
    int steps_b;
    t_list2 *current;       

    steps_b = 0;
    value = head_a->content;
    current = link.head_b;
    while (current)
    {
        if (current->content == top)
        {
            return (steps_b);
        }
        else
        {
            steps_b++;
            current = current->next;
        }
    }
    return (steps_b);
}

int     calc_back_b(t_link link, t_list2 *head_a)
{
    int value;
    int steps_b;
    t_list2 *current;       

    steps_b = 0;
    value = head_a->content;
    current = link.tail_b;
    while (current)
    {
        if (current->content < value)
        {
            steps_b++;
            current = current->prev;
        }     
        else
            break ;
    }
    return (steps_b);
}

void    find_value(t_link *link, t_list2 *head_a)
{
    int number;
    int forward_a;
    int forward_b;
    int back_a;
    int back_b;
    int top;
    int bottom;
    int tmp;
    int tmp_active;

    // should do this before only once, then it should work
    tmp_active = 0;
    top = find_top(link->head_b);
    // ft_printf("number: %d\n", head_a->content);
    bottom = find_bottom(link->head_b);

    forward_a = calc_forward_a(*link, head_a->content);
    if (head_a->content < bottom || head_a->content > top)
    {
        forward_b = calc_forward_b_special(*link, head_a, top);
    }
    else
        forward_b = calc_forward_b(*link, head_a);
    back_a = ft_lstsize2(link->head_a) - forward_a;
    back_b = ft_lstsize2(link->head_b) - forward_b;
    // ft_printf ("forward_a: %d, forward_b: %d, back_a: %d, back_b: %d, top: %d, bottom: %d\n", forward_a, forward_b, back_a, back_b, top, bottom);
    if (forward_a < forward_b)
    {
        number = forward_b;
        head_a->together = forward_a;
        head_a->rotate_b = forward_b - head_a->together;
        head_a->rotate_a = 0;
    }    
    else
    {
        number = forward_a;
        head_a->together = forward_b;
        head_a->rotate_a = forward_a - head_a->together;
        head_a->rotate_b = 0;
    }
    head_a->option = 1;
    if (back_a <= back_b && back_b < number)
    {
        number = back_b;
        head_a->together = back_a;
        head_a->rotate_b = back_b - head_a->together;
        head_a->rotate_a = 0;
        head_a->option = 2;
    }
    if (back_b <= back_a && back_a < number)
    {
        number = back_a;
        head_a->together = back_b;
        head_a->rotate_a = back_a - head_a->together;
        head_a->rotate_b = 0;
        head_a->option = 2;
    }
    if (forward_a + back_b < number)
    {
        number = forward_a + back_b;
        head_a->together = 0;
        head_a->rotate_a = forward_a;
        head_a->rotate_b = back_b;
        head_a->option = 3;
    }
    if (back_a + forward_b < number)
    {
        number = back_a + forward_b;
        head_a->together = 0;
        head_a->rotate_a = back_a;
        head_a->rotate_b = forward_b;
        head_a->option = 4;
    }
    head_a->steps = number;
    // ft_printf("For the number %d it takes %d steps, with option: %d, together: %d, rotate_a: %d, rotate_b: %d\n", head_a->content, head_a->steps, head_a->option, head_a->together, head_a->rotate_a, head_a->rotate_b);

}

void    instruct(t_link *link, t_list2 head_a)
{
    // ft_printf("option: %d, together %d, \n", head_a.option, head_a.together);
    if (head_a.option == 1)
    {
        while (head_a.together)
        {
            rotate_r(link);
            head_a.together--;
        }
        while (head_a.rotate_a)
        {
            rotate_a(link, 0);
            head_a.rotate_a--;
        }
        while (head_a.rotate_b)
        {
            rotate_b(link, 0);
            head_a.rotate_b--;
        }
    }
    if (head_a.option == 2)
    {
        while (head_a.together)
        {
            reverse_rotate_r(link);
            head_a.together--;
        }
        while (head_a.rotate_a)
        {
            reverse_rotate_a(link, 0);
            head_a.rotate_a--;
        }
        while (head_a.rotate_b)
        {
            reverse_rotate_b(link, 0);
            head_a.rotate_b--;
        }
    }
    if (head_a.option == 3)
    {
        while (head_a.rotate_a)
        {
            rotate_a(link, 0);
            head_a.rotate_a--;
        }
        while (head_a.rotate_b)
        {
            reverse_rotate_b(link, 0);
            head_a.rotate_b--;
        }
    }
    if (head_a.option == 4)
    {
        while (head_a.rotate_a)
        {
            reverse_rotate_a(link, 0);
            head_a.rotate_a--;
        }
        while (head_a.rotate_b)
        {
            rotate_b(link, 0);
            head_a.rotate_b--;
        }
    }
    push_b(link);
}

void    move_back_to_a(t_link *link)
{
    int top;
    int steps;
    t_list2 *head_b;

    steps = 0;
    head_b = link->head_b;
    top = find_top(link->head_b);
    while (head_b)
    {
        if (head_b->content == top)
            break ;
        steps++;
        head_b = head_b->next;
    }
    head_b = link->head_b;
    if (steps < ft_lstsize2(link->head_b))
    {
        while (steps)
        {
            rotate_b(link, 0);
            steps--;
        }
    }
    else
    {
        steps = ft_lstsize2(link->head_b) - steps;
        while (steps)
        {
            reverse_rotate_b(link, 0);
            steps--;
        }
    }
    while (ft_lstsize2(link->head_b))
    {
        push_a(link);
    }
}

void    sort_all(t_link *link)
{
    int bottom;
    int top;
    int lowest_steps;
    int tmp;
    int tmp_active;
    t_list2 *head_a;
    int answers[4] = {0, 0, 0, 0};

    push_b(link);
    push_b(link);
    // ft_lstiter2(link->head_a, print_int);
    //     ft_printf("\n");
    //     ft_lstiter2(link->head_b, print_int);
    tmp_active = 0;
    while (ft_lstsize2(link->head_a))
    {
        
        head_a = link->head_a;
        find_value(link, head_a);
        head_a = head_a->next;
        lowest_steps = link->head_a->steps;
        while (head_a)
        {
            find_value(link, head_a);
            if (head_a->steps < lowest_steps)
                lowest_steps = head_a->steps;
            head_a = head_a->next;
        }
        head_a = link->head_a;
        while (head_a->steps != lowest_steps)
        {
            head_a = head_a->next;
        }
        
        if (tmp_active == 1)
        {
            head_a->content = tmp;
            tmp_active = 0;
        }
        if (head_a->option == 1)
        {
            answers[0]++;
        }
        
            
        if (head_a->option == 2)
            answers[1]++;
        if (head_a->option == 3)
            answers[2]++;
        if (head_a->option == 4)
            answers[3]++;
         
            
            instruct(link, *head_a);
        //     ft_printf("\n");
        // ft_lstiter2(link->head_a, print_int);
        // ft_printf("\n");
        // ft_lstiter2(link->head_b, print_int);     
    }
    move_back_to_a(link);
    // ft_printf("\n");
    //     ft_lstiter2(link->head_a, print_int);
    //     ft_printf("\n");
    //     ft_lstiter2(link->head_b, print_int);
    // printf("option 1: %d\noption 2: %d\noption 3: %d\noption 4: %d\n", answers[0], answers[1], answers[2], answers[3]);
        
}

void    sort_numbers(t_link *link)
{
    int size;

    size = ft_lstsize2(link->head_a);
    if (size == 1)
        return ;
    else if (size == 2)
        sort_2_numbers(link);
    else if (size == 3)
        sort_3_numbers(link);
    else
        sort_all(link);
}
