#include<stdio.h>
#include<stdlib.h>
                            // Circular Linked List insertion at first!...(similar for insert last and index element)
struct Node{
	int data;
	struct Node*next;
};
        // Declared a Traversal Function:
void linkedListTraversal(struct Node*head){
	struct Node*ptr = head;
	do{
		printf("Element: %d\n",ptr->data);
		ptr = ptr->next;	
	}while(ptr!=head);
}

struct Node* InsertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*p = head->next;
    while(p->next!=head){
    	p = p->next;
	}
	p->next = ptr;
	ptr->next = head;
	head = ptr;
    return head;
}
       
int main(){
	struct Node*head;
	struct Node*second;
	struct Node*third;
	struct Node*forth;
	
	// Allocate memory for nodes in Linked list...
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	forth = (struct Node*)malloc(sizeof(struct Node));
	
	// Linked first and second nodes:
	head -> data = 1;
	head -> next = second;
	
	// Linked second and third nodes:
	second -> data = 2;
	second -> next = third;
	
	// Linked third and forth nodes:
	third -> data = 3;
	third -> next = forth;
	
	// Linked list end:
	forth -> data = 4;
	forth -> next = head;
	
	printf("Linked List before insertion:\n");
    linkedListTraversal(head);

    head = InsertAtFirst(head, 77);

    printf("\nLinked List after insertion:\n");
    linkedListTraversal(head);
    
	system("pause");
	return 0;
}
