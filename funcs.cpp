#include "stdafx.h"
#include "list.h"

void push(PNode *head, upoint_t data) {
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

void pushplist(PList list, upoint_t data) {
	PNode node = (PNode)malloc(sizeof(Node));
	node->value = data;
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	}
	list->tail->next = node;
	list->tail = node;
}

Node* getlast(Node *head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void insert(Node *head, unsigned n, upoint_t val) {
	unsigned i = 0;
	Node *tmp = NULL;
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = val;
	if (head->next) {
		tmp->next = head->next;
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

void deletelist(PNode *head) {
	Node* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

void fromarray(PNode *head, int *arr, size_t size) {
	size_t i = size - 1;
	if (arr == NULL || size == 0) {
		return;
	}
	while (i-- != 0) {
		push(head, (upoint_t)arr[i]);
	}
}

void printlist(const Node *head) {
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void printplist(PList list) {
	PNode node = list->head;
	while (node) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
}

PList createlist() {
	PList list = (PList)malloc(sizeof(List));
	list->head = NULL;
	return list;
}

int predicate(PNode head) {
	if (head->value > (upoint_t)5) {
		return 1;
	}
	else {
		return 0;
	}
}