/* This Program prints all ROOT to LEAF paths of Binary Tree
    By: Prateek Singhal */

#include<stdio.h>
#include<stdlib.h>
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

void printpath(int arr[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(i<len-1)
            printf("%d -> ",arr[i]);
        else
            printf("%d\n",arr[i]);
    }
}


void allpaths(struct node* root,int arr[],int len)
{
    arr[len++]=root->data;
    if(!root->left && !root->right)
        printpath(arr,len);
    if(root->left)
        allpaths(root->left,arr,len);
    if(root->right)
        allpaths(root->right,arr,len);
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
    printf("All ROOT to LEAF paths are: \n");
    allpaths(root,arr,0);
}
