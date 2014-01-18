/* This Program Converts Binary Tree to its Mirror Image.
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

struct node* createnode(int d)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void display(struct node* root)
{
    struct node* temp;
    queue<struct node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        if(temp!=NULL)
            printf("%d -> ",temp->data);
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
}

void mirror(struct node* root)
{
    struct node* temp;
    if(root==NULL)
        return;
        
    mirror(root->left);
    mirror(root->right);
    
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}



int main()
{
    //small input data for testing
    /*                    1
                        /   \
                       2     3
                      /       \
                     4         8
                    /        /  \
                   5        9   11
                  / \       \
                 6   7      10
                            / \
                           13  12
                            \
                            14        */
    int arr[1000];
    struct node *root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    (root->left)->left=createnode(4);
    (root->left)->left->left=createnode(5);
    (root->left)->left->left->left=createnode(6);
    (root->left)->left->left->right=createnode(7);
    (root->right)->right=createnode(8);
    (root->right)->right->left=createnode(9);
    (root->right)->right->left->right=createnode(10);
    (root->right)->right->right=createnode(11);
    (root->right)->right->left->right->right=createnode(12);
    (root->right)->right->left->right->left=createnode(13);
    (root->right)->right->left->right->left->right=createnode(14);
    printf("Original tree: \n");
    display(root);
    printf("NULL\n");
    mirror(root);
    printf("Mirror Image tree: \n");
    display(root);
    printf("NULL\n");
}
        
