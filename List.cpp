#include "stdafx.h"
#include "list.h"

int pop(PNode*);
Node* getn(Node*, int);
void pushback(Node*, upoint_t);
int popback(PNode*);
int deleten(PNode*, int);
int length(Node*);
Node* getendn(Node*, int);
PList predlist(PNode, pred);

int main()
{
	SetConsoleOutputCP(1251);
	Node* head = NULL;
	PList list;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	fromarray(&head, arr, 11);
	printf("Список:\n");
	printlist(head);
	printf("Длина списка - %d\n", length(head));
	printf("Вставили число:\n");
	insert(head, 4, (upoint_t)333);
	printlist(head);
	int i, j, k, n;
	printf("Сколько элементов хотите добавить в конец списка?\n");
	scanf_s("%d", &j);
	for (i = 0; i < j; i++) {
		printf("Введите число: ");
		scanf_s("%d", &n);
		pushback(head, (upoint_t)n);
		printf("Добавили %d в конец списка:\n", n);
		printlist(head);
	}
	printf("Сколько элементов хотите удалить?\n");
	scanf_s("%d", &k);
	for (i = 0; i < k; i++) {
		printf("Введите по порядку число, чтобы удалить его: ");
		scanf_s("%d", &n);
		n = n - 1;
		deleten(&head, n);
		printf("Удаление %d элемента:\n", n + 1);
		printlist(head);
	}
	printf("%d\n", pop(&head));
	printf("%d\n", popback(&head));
	printf("Удаление первого и последнего элемента:\n");
	printlist(head);
	printf("Длина списка после преобразований - %d\n", length(head));
	printf("Вывели 1 элемент: %d\n", *getn(head, 0));
	printf("Вывели %d элемент с конца: %d\n", 9 + j - k, *getendn(head, 9 + j - k));
	printf("Вывели 5 элемент: %d\n", *getn(head, 4));
	printf("Вывели %d элемент с конца: %d\n", 5 + j - k, *getendn(head, 5 + j - k));
	list = predlist(head, predicate);
	printplist(list);
	deletelist(&head);
	system("pause");
	return 0;
}

int pop(PNode *head) {
	Node* prev = NULL;
	int val = 0;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head);
	prev->value = (upoint_t)val;
	(*head) = (*head)->next;
	free(prev);
	return val;
}

Node* getn(Node* head, int n) {
	int i = 0;
	while (i < n && head) {
		head = head->next;
		i++;
	}
	return head;
}

void pushback(Node *head, upoint_t value) {
	Node *last = getlast(head);
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

int popback(PNode *head) {
	Node *pFwd = NULL;
	Node *pBwd = NULL;
	if (!head) {
		exit(-1);
	}
	if (!(*head)) {
		exit(-1);
	}
	pFwd = *head;
	while (pFwd->next) {
		pBwd = pFwd;
		pFwd = pFwd->next;
	}
	if (pBwd == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		free(pFwd->next);
		pBwd->next = NULL;
	}
}

int deleten(PNode *head, int n) {
	if (n == 0) {
		return pop(head);
	}
	else {
		Node *prev = getn(*head, n - 1);
		Node *elm = prev->next;
		int val = 0;
		elm->value = (upoint_t)val;
		prev->next = elm->next;
		free(elm);
		return val;
	}
}

int length(Node* head) {
	struct Node* current = head;
	int i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return i;
}

Node* getendn(Node* head, int n) {
	Node* node = head;
	Node* node2 = head;
	if (node2 == NULL) {
		return NULL;
	}
	for (int i = 0; i < n - 1; i++) {
		node2 = node2->next;
	}
	while (node2->next != NULL) {
		node = node->next;
		node2 = node2->next;
	}
	return node;
}

PList  predlist(PNode head, pred f) {
	if (head == NULL) {
		exit(-1);
	}
	PList nlist = createlist();
	PNode node = head;
	while (node) {
		if (f(node)) {
			pushplist(nlist, node->value);
		}
		node = node->next;
	}
	return nlist;
}