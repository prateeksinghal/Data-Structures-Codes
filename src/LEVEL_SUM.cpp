/* This Program prints the SUM OF LEVELS of Binary Tree
    By: Prateek Singhal */


#include<stdio.h>
#include<stdlib.h>
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

void levelsum(struct node* root)
{
    queue<struct node*> q;
    int sum;
    struct node* temp;
    q.push(root);
    q.push(NULL);
    sum=0;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            if(!q.empty())
                q.push(NULL);
            printf("%d\n",sum);
            sum=0;
        }
        else
        {
            sum=sum+(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
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
    printf("Sum of levels are: \n");
    levelsum(root);
}

