#pragma once

typedef void* upoint_t;

typedef struct Node {
	upoint_t value;
	struct Node *next;
} Node, *PNode;

typedef struct List {
	PNode head;
	PNode tail;
} List, *PList;

typedef int(*pred)(PNode);

void push(PNode*, upoint_t);
void pushplist(PList, upoint_t);
Node* getlast(Node*);
void insert(Node*, unsigned, upoint_t);
void deletelist(PNode*);
void fromarray(PNode*, int*, size_t);
void printlist(const Node*);
void printplist(PList);
PList createlist();
int predicate(PNode);