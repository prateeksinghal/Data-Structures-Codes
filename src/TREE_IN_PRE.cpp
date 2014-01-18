/* This Program Construct tree from INORDER and PREORDER
    By: Prateek Singhal */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int Search(int inOrder[],int key,int start,int end)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(inOrder[i]==key)
            return i;
    }
    return -1;
}

struct node* construct(int inOrder[],int preOrder[],int start,int end)
{
    if(start>end)
        return NULL;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    static int preIn=0;
    newnode->data=preOrder[preIn];
    preIn++;
    /*if(start==end)
        return newnode;*/
    int x=Search(inOrder,newnode->data,start,end);
    newnode->left=construct(inOrder,preOrder,start,x-1);
    newnode->right=construct(inOrder,preOrder,x+1,end);
    return newnode;
}

void display(struct node* root)
{
    queue<struct node*> Q;
    struct node* temp;
    Q.push(root);
    while(!Q.empty())
    {
        temp=Q.front();
        printf("%d->",temp->data);
        Q.pop();
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
}

int main()
{
    // small test data for input
    int inorder[]={4,2,5,1,6,3};
    int preOrder[]={1,2,4,5,3,6};
    struct node* tree;
    tree=construct(inorder,preOrder,0,5);
    display(tree);
    printf("NULL\n");
}
    
