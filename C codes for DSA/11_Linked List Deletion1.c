#include<stdio.h>
#include<stdlib.h>
                            // Linked List Deletion at Index...
struct Node{
	int data;
	struct Node*next;
};
        // Declared a Traversal Function:
void linkedListTraversal(struct Node*ptr){
	
	while(ptr!=NULL){
		printf("Element: %d\n",ptr->data);
		ptr = ptr->next;	
	}
}
         // Create Function Of Deletion:
struct Node*deleteATIndex(struct Node*head,int index){
	struct Node* p = head;
	struct Node* q = head->next;
	for(int i = 0; i< index-1;i++){
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
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
	forth -> next = NULL;
	printf("Linkedlist before Deletion!\n");
	// Function Call:
	linkedListTraversal(head);
	
	head = deleteATIndex(head,2);  // For deleting Elements:
	
	printf("Linkedlist after Deletion!\n");
	linkedListTraversal(head);
	
	system("pause");

	return 0;
}
