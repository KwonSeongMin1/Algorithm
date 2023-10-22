#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	int number;
	struct node* next;
}node;

void makenode(struct node* head, int num);

int main(void) {

	// head 
	node* head = (node*)malloc(sizeof(node));
	head->number = 0;
	head->next = NULL;

	int student = 0;
	int l = 0;

	scanf("%d", &student);
	node* target;
	for (int i = 0; i < student; i++) {
		target = head;
		scanf("%d", &l);
		for (int j = 0; j < i - l; j++)
			target = target->next;
		makenode(target, i + 1);
	}

	target = head->next;
	while (1) {
		printf("%d ", target->number);
		if (target->next == NULL)
			break;
		target = target->next;
	}
	free(target);
	free(head);
	return 0;
}
void makenode(node* target, int num) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->number = num;
	if (target->next == NULL) {
		newnode->next = NULL;
		target->next = newnode;
	}
	else {
		node* back = target->next;
		target->next = newnode;
		newnode->next = back;
	}
}