/* This Program checks whether Binary Tree is BST
    By: Prateek Singhal */


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int d)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int IsBST(struct node* root,int min,int max)
{
    if(!root)
        return 1;
    return(root->data > min && root->data < max && IsBST(root->left,min,root->data) && IsBST(root->right,root->data,max));
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
    int ans=IsBST(root,INT_MIN,INT_MAX);
    if(ans==0)
        printf("Its not a BST.\n");
    else
        printf("Its a BST.\n");
}

