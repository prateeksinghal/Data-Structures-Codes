/* This Program prints the ZIG-ZAG TRAVERSAL of Binary Tree
    By: Prateek Singhal */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
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

void zigzag(struct node* root)
{
    if(root==NULL)
        return;
    struct node* temp;
    stack<struct node*> s1;
    stack<struct node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            temp=s1.top();
            s1.pop();
            printf("%d -> ",temp->data);
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }
        
        while(!s2.empty())
        {
            temp=s2.top();
            s2.pop();
            printf("%d -> ",temp->data);
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
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
    printf("Zig-Zag Traversal: \n");
    zigzag(root);
    printf("NULL\n");
}
