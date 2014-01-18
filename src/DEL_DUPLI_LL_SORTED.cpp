/* This Program Removes Duplicates from Sorted Linked List.
    By: Prateek Singhal */


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void del_dupli(struct node* current)
{
    struct node* temp;
    struct node* head=current;
    if(head==NULL)
        return;
        
    while(head->next!=NULL)
    {
            if(head->next->data==head->data)
            {
                temp=head->next->next;
                free(head->next);
                head->next=temp;
            }
            else
                head=head->next;
    }
}

void push(struct node** head,int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=(*head);
    (*head)=newnode;
}

void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main()
{
     //small input data for testing
     // 11->11->11->13->13->20->NULL
    struct node* head=NULL;
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
    printf("Original LL :\n");
    print(head);
    del_dupli(head);
    printf("LL after deleting duplicates :\n");
    print(head);
    return 0;
}
    
