/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
//time complexity:O(n)
//algorithm: merge algorithm
#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL && head2 != NULL)
		return head2;
	else if (head2 == NULL && head1 != NULL)
		return head1;
	else
	{
		int start = 0, k = 0, len1 = 0, len2 = 0, count = 0;
		struct node* head, *temp1, *temp2, *link, *temp;
		temp1 = head1;
		temp2 = head2;
		while (temp1)
		{
			len1++;
			temp1 = temp1->next;
		}
		temp1 = head1;
		while (temp2)
		{
			len2++;
			temp2 = temp2->next;
		}
		temp2 = head2;
		while (start < len1 && k < len2)
		{
			if (temp1->num >= temp2->num)
			{
				if (count == 0)
				{
					head = (struct node*)malloc(sizeof(struct node));
					temp = head;
					temp->num = temp2->num;
					temp->next = NULL;
					temp2 = temp2->next;
					count++;
				}
				else
				{
					link = (struct node*)malloc(sizeof(struct node));
					link->num = temp2->num;
					temp->next = link;
					temp = link;
					temp2 = temp2->next;
				}
				k++;
			}
			else
			{
				if (count == 0)
				{
					head = (struct node*)malloc(sizeof(struct node));
					temp = head;
					temp->num = temp1->num;
					temp->next = NULL;
					temp1 = temp1->next;
					count++;
				}
				else
				{
					link = (struct node*)malloc(sizeof(struct node));
					link->num = temp1->num;
					temp->next = link;
					temp = link;
					temp1 = temp1->next;
				}
				start++;
			}
		}
		if (start >= len1)
		{
			for (; k < len2; k++)
			{
				link = (struct node*)malloc(sizeof(struct node));
				link->num = temp2->num;
				temp->next = link;
				temp = link;
				temp2 = temp2->next;
			}
			temp->next = NULL;
		}
		else if (k >= len2)
		{
			for (; start < len1; start++)
			{
				link = (struct node*)malloc(sizeof(struct node*));
				link->num = temp1->num;
				temp->next = link;
				temp = link;
				temp1 = temp1->next;
			}
			temp->next = NULL;
		}
		return head;
	}
}

