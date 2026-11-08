#include <stdio.h>
#include <stdlib.h>
                         // linked list insertion after Node!
struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* InsertAfterNode(struct Node* head,struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*p = head;
    while(p->next!=NULL){
    	p = p->next;
	}
	ptr->next = prevNode->next;
	prevNode->next = ptr; 
	return head;
    
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* forth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = NULL;

    printf("Linked List before insertion:\n");
    linkedListTraversal(head);

    head = InsertAfterNode(head,second, 77);

    printf("\nLinked List after insertion:\n");
    linkedListTraversal(head);

    system("pause");   // ?? Add this line in Dev-C++
    return 0;
}
