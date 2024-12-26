/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:42:59 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/20 14:38:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//nodeを作成する関数
t_node *create_stack_b()
{
    t_node *new_node;

    new_node=(t_node *)malloc(sizeof(t_node));
    new_node->prev=new_node;
    new_node->next=new_node;
    new_node->end=true;
    return(new_node);
}

t_node *create_node(int value)
{
    t_node *new_node;

    new_node=(t_node *)malloc(sizeof(t_node));
    new_node->value=value;
    new_node->prev=NULL;
    new_node->next=NULL;
    return(new_node);
}
//双方向循環リスト作成
t_node *create_stack(int data[],int n)
{
    t_node *head;
    t_node *tail;
    int i;

    i=1;
    head=create_node(data[0]);
    tail=head;
    while(i < n)
    {
        t_node *new_node;
        new_node=create_node(data[i]);
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        i++;
    }
    head->prev=tail;
    tail->next=head;
    return(head);
}