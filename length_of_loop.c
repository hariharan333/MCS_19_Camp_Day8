/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//structure of linked list
struct node
{
    int data;
    struct node* next;
};
int count(struct node* n)
{
    int result = 1;
    struct node* temp = n;
    while(temp->next!= n)
    {
        result++;
        temp = temp->next;
    }
    return result;
}
int loop(struct node* head)
{
    struct node*p = head;
    struct node*q = head;
    while(p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if(p == q)
        {
            return count(p);
            printf("%d",p->data);
        }
    }
    return 0;
}
struct node* push(int key)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next =NULL;
    return temp;
}
int main()
{
    struct node* head =push(1);
    head->next = push(2);
    head->next->next = push(3);
    head->next->next->next = push(4);
    head->next->next->next->next = push(5);
    printf("loop is craeting:");
    head->next->next->next->next->next = head->next;
    printf("%d",loop(head));
    return 0;
}

