/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:50:10 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/20 16:23:01 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

//test⑤ pb→pa
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
    printf("p\n", data->stack_b);
    
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
    printf("%d\n", data->stack_b->value);
    return(0);
}
/*
//test⑥ pb→pb
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
    
    printf("<implement pb→pb→pa>\n");
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
    current_node=data->stack_b->prev;
    do{
        printf("value:%d/", current_node->value);
        printf("end:%d\n", current_node->end);
        current_node=current_node->next;
    }while(current_node != data->stack_b);
    return(0);
}

/*
//test⑦：pb→pb→pb→rb
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
    
    //printf("<implement sa>\n");
    //printf("<implement ra>\n");
    //printf("<implement rra>\n");
    
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
    //push_swap_sa(&data->stack_a);
    //push_swap_sa(&data->stack_a->next);
    //push_swap_ra(&data->stack_a);
    //push_swap_rra(&data->stack_a);
    push_swap_pb(data);
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

//test⑧：pb→pb→pb→rrb
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
    
    //printf("<implement sa>\n");
    //printf("<implement ra>\n");
    //printf("<implement rra>\n");
    
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
    //push_swap_sa(&data->stack_a);
    //push_swap_sa(&data->stack_a->next);
    //push_swap_ra(&data->stack_a);
    //push_swap_rra(&data->stack_a);
    push_swap_pb(data);
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