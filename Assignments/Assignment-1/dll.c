#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t* ele = (node_t*)malloc(sizeof(node_t));
	ele->data = data;
	ele->next = NULL;
	ele->prev = NULL;

	list->size++;
	
	if(list->head == NULL)
	{
		list->head = ele;
		list->tail = ele;	
		return;
	}
	list->head->prev = ele;
	ele->next = list->head;
	list->head = ele;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* ele = (node_t*)malloc(sizeof(node_t));
	ele->data = data;
	ele->next = NULL;
	ele->prev = NULL;
	
	list->size++;
	
	if(list->tail == NULL)
	{
		list->head = ele;
		list->tail = ele;
		return;
	}
	list->tail->next = ele;
	ele->prev = list->tail;
	list->tail = ele;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* temp = search(list,prev);

	if(temp == NULL)
		return;
	
	node_t* ele =(node_t*)malloc(sizeof(node_t));
	ele->prev = NULL;
	ele->next = NULL;
	ele->data = data;

	list->size++;

	temp->next->prev = ele;
	ele->next = temp->next;
	temp->next = ele;
	ele->prev = temp;
	
}


void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(list->head == NULL)
		return;
	
	list->size--;

	if(list->head == list->tail)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}
	

	node_t* temp = list->head->next;
	free(list->head);
	list->head = temp;
	temp->prev = NULL;
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if(list->tail == NULL)
		return;

	list->size--;

	if(list->head == list->tail)
	{
		free(list->tail);
		list->tail = NULL;
		list->head = NULL;
		return;
	}

	node_t* temp = list->tail->prev;
	free(list->tail);
	temp->next = NULL;
	list->tail = temp;
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t* temp = search(list,data);
	if(temp==NULL)
		return;
	
	list->size--;

	if(temp == list->head)
	{
		delete_front(list);
		return;
	}

	if(temp == list->tail)
	{
		delete_back(list);
		return;
	}

	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	free(temp);
	
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t* temp = list->head;

	while(temp!=NULL)
	{
		if(temp->data == data)
			break;
		temp = temp->next;
	}
	return temp;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}




