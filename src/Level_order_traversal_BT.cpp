/* This Program prints the LEVEL ORDER TRAVERSAL of Binary Tree
    By: Prateek Singhal */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
struct node{
    int data;
    node *left;
    node *right;

};

struct node *createnode(int d)
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=d;
    node->left=NULL;
    node->right=NULL;
    return node;

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
    printf("LEVEL Order Traversal: \n");
    display(root);
    printf("NULL\n");
}
