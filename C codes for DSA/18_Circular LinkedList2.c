#include<stdio.h>
#include<stdlib.h>
                            // Circular Linked List Deletion Of First Element... (similar for delete last and index element)
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
       
         // Create Function Of Deletion:
struct Node*deleteFirst(struct Node*head){
	
    struct Node* ptr = head;
    struct Node* p = head;

    while (p->next != head){             // Find last node
        p = p->next;
    }
    p->next = head->next;               // Link last to 2nd node
    head = head->next;                     // Move head
    free(ptr);                            // Delete old head
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
	
	printf("Linkedlist before Deletion!\n");
	// Function Call:
	linkedListTraversal(head);
	
	head = deleteFirst(head);  // For deleting Elements:
	
	printf("Linkedlist after Deletion!\n");
	linkedListTraversal(head);
	
	system("pause");
	return 0;
}
