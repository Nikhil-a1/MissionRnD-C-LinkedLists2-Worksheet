/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head==NULL)
	return -1;
	else
	{
		int len = 0, count = 1, median = 0;
		struct node *temp;
		temp = head;
		while (temp)
		{
			temp = temp->next;
			len++;
		}
		if (len % 2 == 0)
		{
			temp = head;
			while (temp)
			{
				if (count==(len / 2 ))
					median = temp->num;
				else if ((count==((len / 2) + 1)))
				{
					median += temp->num;
					median /= 2;
					break;
				}
				temp = temp->next;
				count++;
			}
		}
		else
		{
			temp = head;
			while (temp)
			{
				if ((count==((len / 2) + 1)))
				{
					median += temp->num;
					break;
				}
				temp = temp->next;
				count++;
			}
		}
		return median;
	}
}
