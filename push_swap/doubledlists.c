/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubledlists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pebarbos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:37:08 by pebarbos          #+#    #+#             */
/*   Updated: 2024/01/29 15:10:19 by pebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct	node 
{
	int data;
	struct	node* next;
	struct	node* prev;
};

void	printdata(struct node* head)
{
	struct node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

struct node*	createnode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
		return (NULL);
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

struct node*	insertnode(struct node** head, int data)
{
	struct node* newnode = createnode(data);
	if (*head == NULL) // head e o primeiro, se a lista estiver vazia o valor fica para o primeiro
		*head = newnode;
	else
	{
		struct node* temp = *head;
		while (temp->next != NULL) //ir ate ao fim dos nodes para alterar o ultimo 
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
	}
	return (*head);
}

int	main(int argc, char **argv)
{
	size_t	i;
	unsigned int data;

	i = 1;
	struct node* head = NULL;
	if (argc < 2)
		printf("Invalid number of args, nothing created");
	else
		while (i < argc)
		{
			data = atoi(argv[i]);
			insertnode(&head, data);
			i++;
		}
	printdata(head);
}
