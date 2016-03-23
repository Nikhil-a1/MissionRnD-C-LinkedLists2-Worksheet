/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
//time complexity O(n)
#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	if (head == NULL || K < 0)
		return head;
	struct node *temp, *link, *new_node;
	int count = 1, len = 0;
	temp = head;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	if (K > len)
		return head;
	else
	{
		temp = head;
		while (temp)
		{
			if (count == K)
			{
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->num = K;
				link = temp->next;
				temp->next = new_node;
				new_node->next = link;
				temp = new_node;
				count = 0;
			}
			count++;
			temp = temp->next;
		}
	}
	return head;
}