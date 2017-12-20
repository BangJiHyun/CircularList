#include <stdio.h>

typedef struct __node {
	int data;
	struct __node *next;
}Node;

void InsertList(Node **pStart, int data)
{
	Node *ptr = (*pStart);
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if ((*pStart) == NULL)
	{
		(*pStart) = newNode;
		newNode->next = (*pStart);
		return;
	}
	do {
		ptr = ptr->next;
	} while (ptr->next != (*pStart));
	ptr->next = newNode;
	newNode->next = (*pStart);
}

void DeleteList(Node **pStart, int data)
{
	Node *ptr = (*pStart), *target = (*pStart);

	if (compareData(pStart, data))
	{
		if ((*pStart)->data == data)
		{
			if ((*pStart)->next == (*pStart))
			{
				free((*pStart));
				(*pStart) = NULL;
				return;
			}
			do {
				ptr = ptr->next;
			} while (ptr->next != (*pStart));
			(*pStart) = (*pStart)->next;
			ptr->next = (*pStart);
			free(target);
			return;
		}
		do {
			if (ptr->next->data == data)
				break;
			ptr = ptr->next;
		} while ((ptr->next != (*pStart)));
		target = ptr->next;
		ptr->next = target->next;
		free(target);
	}
	else
		printf("Cannot delete because there is no matching information\n");

}
int SearchList(Node **pStart, int data)
{
	if (compareData(pStart, data))
		printf("Match Info\n");
	else
		printf("No match Info\n");
}

int compareData(Node **pStart, int data)
{
	Node *prev = (*pStart);
	do {
		if (prev->data == data)
			return 1;
		prev = prev->next;
	} while (prev != (*pStart));
	return 0;
}

void SortInsertList(Node **pStart, int data)
{
	Node *prev = (*pStart);
	Node *after = (*pStart);
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if ((*pStart) == NULL)
	{
		(*pStart) = newNode;
		newNode->next = (*pStart);
		return;
	}
	else if (data < (*pStart)->data)
	{
		do {
			prev = prev->next;
		} while (prev->next != (*pStart));

		prev->next = newNode;
		newNode->next = (*pStart);
		(*pStart) = newNode;
		return;
	}
	do {
		if (prev->next->data > data)
			break;
		prev = prev->next;
	} while (prev->next != (*pStart));
	after = prev->next;
	prev->next = newNode;
	newNode->next = after;
}

void PrintList(Node *pStart)
{
	Node *ptr = pStart;
	if (pStart == NULL)
	{
		printf("pStart == NULL\n");
		return;
	}
	do {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	} while (ptr != pStart);
	printf("\n");
}

void main()
{
	Node *pStart = NULL;
	
	printf("<<InsertSort>>\n");
	SortInsertList(&pStart, 5);
	SortInsertList(&pStart, 2);
	SortInsertList(&pStart, 1);
	SortInsertList(&pStart, 12);
	SortInsertList(&pStart, 10);
	SortInsertList(&pStart, 8);
	PrintList(pStart);

	printf("\n<<Delete 1, 5 and Print>>\n");
	DeleteList(&pStart, 1);
	DeleteList(&pStart, 5);
	PrintList(pStart);

	printf("\n<<Search 12 and Check>>\n");
	SearchList(&pStart, 12);

	printf("\n<<Insert and Print>>\n");
	InsertList(&pStart, 3);
	InsertList(&pStart, 1);
	InsertList(&pStart, 5);
	InsertList(&pStart, 7);
	PrintList(pStart);
}