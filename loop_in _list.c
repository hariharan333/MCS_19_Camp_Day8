#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list node 
struct node 
{ 
  int data; 
  struct node *next; 
}; 
  
struct node* push(int key)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
//this function is detected the loop
int checkloop(struct node* head)
{
    struct node* p = head;
    struct node* q = head;
    
    while(p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
        
        if(p == q)
	{
        return p->data;
		break;
	}
    }
    return NULL;
}

int main()
{
    struct node* head = push(1);
    head->next = push(2);
    head->next->next =push(3);
    head->next->next->next =push(4);
    head->next->next->next->next=push(5);
    head->next->next->next->next->next=push(6);
    head->next->next->next->next->next->next=push(7);
    head->next->next->next->next->next->next->next=push(8);
    head->next->next->next->next->next->next->next->next=push(9);
    head->next->next->next->next->next->next->next->next->next=push(10);
    printf("creating a loop:\n");
   
    head->next->next->next->next->next->next->next->next->next->next = head->next->next;
    printf("same point = %d",checkloop(head));
    return 0;
}
