#include <stdio.h>
#include <stdlib.h>
                         // linked list insertion at Index!
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

struct Node* InsertAtIndex(struct Node* head, int data,int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head;
    int i=0;
    while(i!= index-1){
    	p = p->next;
    	i++;
	}
	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;
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

    head = InsertAtIndex(head, 77,3);

    printf("\nLinked List after insertion:\n");
    linkedListTraversal(head);

    system("pause");   // ?? Add this line in Dev-C++
    return 0;
}
