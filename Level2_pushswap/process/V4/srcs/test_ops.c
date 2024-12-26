/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:50:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/24 18:12:38 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void    do_move_elem_b(t_info *info, t_cost *cost)
{
    size_t  i;

    i = 0;
    while (i++ < cost->ra)
        op_rb(info);
    i = 0;
    while (i++ < cost->rb)
        op_ra(info);
    i = 0;
    while (i++ < cost->rra)
        op_rrb(info);
    i = 0;
    while (i++ < cost->rrb)
        op_rra(info);
    op_pa(info);
}

long    calc_pos_bigger_b(t_info *info, t_elem *to, t_elem *elem)
{
    t_elem  *tmp;
    size_t  i;
    size_t  min;
    size_t  min_pos;

    min = info->stack_t_len;
    if (to == NULL)
        return (0);
    tmp = to;
    i = 0;
    while (true)
    {
        if (elem->pos < tmp->pos && tmp->pos - elem->pos < min)
        {
            min = tmp->pos - elem->pos;
            min_pos = i;
        }
        if (tmp->is_end == true)
            break ;
        tmp = tmp->next;
        i++;
    }
    return (min_pos);
}

size_t  calc_dest_index_b(t_info *info, t_elem *to, t_elem *elem)
{
    long    max;
    long    min;
    size_t  index_max;
    size_t  index_min;

    max = stackmaxnum(to);
    min = stackminnum(to);
    index_max = index_of_stack(to, max);
    index_min = index_of_stack(to, min);
    if (elem->num > max)
        return (index_max + 1);
    if (elem->num < min)
        return (index_min);
    return (calc_pos_bigger_b(info, to, elem));
}

void    calc_cost_b(t_cost *cost, t_elem *elem, t_info *i)
{
    size_t  index;
    size_t  to_pos;
    t_cost  cost_tmp;

    cost_tmp = (t_cost){0};
    index = index_of_stack(i->stack_b, elem->num);
    cost_tmp.ra = index;
    cost_tmp.rra = stacklen(i->stack_b) - index;
    if (i->stack_a == NULL)
        to_pos = 0;
    else
        to_pos = calc_dest_index_b(i, i->stack_a, elem) % stacklen(i->stack_a);
    cost_tmp.rb = to_pos;
    cost_tmp.rrb = stacklen(i->stack_a) - to_pos;
    cost_tmp.cost = calc_min_cost(&cost_tmp);
    if (cost_tmp.cost < cost->cost)
        copy_cost(cost, &cost_tmp);
}

void    move_elem_b(t_info *info, t_elem *from)
{
    t_elem  *tmp;
    t_cost  cost;

    cost = (t_cost){0};
    cost.cost = stacklen(info->stack_a) + stacklen(info->stack_b);
    tmp = from;
    while (true)
    {
        calc_cost_b(&cost, tmp, info);
        if (tmp->is_end == true)
            break ;
        tmp = tmp->next;
    }
    do_move_elem_b(info, &cost);
}
*/
//test① sa：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement sa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    operation_sa(data);
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    return(0);
}
*/
/*
//test② ra：OK
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    printf("<implement ra>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    operation_ra(data);
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    return(0);
}
*/

//test③ rra：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    printf("<implement rra>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    operation_rra(data);
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    return(0);
}
*/

//test④ pb：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=create_stack_b();
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", &(data->stack_b));
    operation_pb(data);
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%d/", data->stack_b->value);
    printf("end:%d\n", data->stack_b->end);
    return(0);
}
*/

//test⑤ pb→pa：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=NULL;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb→pa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", data->stack_b);
    
    operation_pb(data);
    operation_pa(data);
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%p", data->stack_b);
    return(0);
}
*/

/*
//test pb→pa→pb
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=NULL;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb→pa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", data->stack_b);
    
    operation_pb(data);
    operation_pa(data);
    operation_pb(data);
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%d/", data->stack_b->value);
    printf("end:%d", data->stack_b->end);
    return(0);
}
*/
//test pb→pb：Ok
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=NULL;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb→pa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", data->stack_b);
    
    operation_pb(data);
    operation_pb(data);

    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%d/", data->stack_b->value);
    printf("end:%d\n", data->stack_b->end);
    printf("value:%d/", data->stack_b->next->value);
    printf("end:%d\n", data->stack_b->next->end);
    return(0);
}
*/

//test：pb→pb→pb→sb：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=NULL;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb→pa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", data->stack_b);
    
    operation_pb(data);
    operation_pb(data);
    operation_pb(data);
    operation_sb(data);
    
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%d/", data->stack_b->value);
    printf("end:%d\n", data->stack_b->end);
    printf("value:%d/", data->stack_b->next->value);
    printf("end:%d\n", data->stack_b->next->end);
    printf("value:%d/", data->stack_b->next->next->value);
    printf("end:%d\n", data->stack_b->next->next->end);
    return(0);
}
*/
//test：pb→pb→pb→rb：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=NULL;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb→pa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", data->stack_b);
    
    operation_pb(data);
    operation_pb(data);
    operation_pb(data);
    operation_rb(data);
    
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%d/", data->stack_b->value);
    printf("end:%d\n", data->stack_b->end);
    printf("value:%d/", data->stack_b->next->value);
    printf("end:%d\n", data->stack_b->next->end);
    printf("value:%d/", data->stack_b->next->next->value);
    printf("end:%d\n", data->stack_b->next->next->end);
    return(0);
}
*/

//test：pb→pb→pb→rrb：OK
/*
int main()
{
    t_data *data;
    t_node *current_node;

    int array[]={1,2,3,4,5};

    data=(t_data *)malloc(sizeof(t_data));
    data->stack_a=create_stack(array, 5);
    data->stack_b=NULL;
    data->stack_len=ft_stack_size(data->stack_a);
    ft_stack_last(data->stack_a);
    printf("stack size:%d\n", (int)data->stack_len);
    current_node=data->stack_a;
    
    printf("<implement pb→pa>\n");
    printf("---before swap---\n");
    printf("[result of stack_a]\n");
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("%p\n", data->stack_b);
    
    operation_pb(data);
    operation_pb(data);
    operation_pb(data);
    operation_rrb(data);
    
    printf("---after swap---\n");
    printf("[result of stack_a]\n");
    current_node=data->stack_a;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_a);
    printf("[result of stack_b]\n");
    printf("value:%d/", data->stack_b->value);
    printf("end:%d\n", data->stack_b->end);
    printf("value:%d/", data->stack_b->next->value);
    printf("end:%d\n", data->stack_b->next->end);
    printf("value:%d/", data->stack_b->next->next->value);
    printf("end:%d\n", data->stack_b->next->next->end);
    return(0);
}
*/
