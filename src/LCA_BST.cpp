/* This Program prints LCA of 2 given nodes(assuming they exists) in Binary Search Tree
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

struct node* LCA(struct node* tree,int n1,int n2)
{
    if(tree == NULL)
        return NULL;
    if((n1 > tree->data) && (n2 > tree->data))
        return LCA(tree->right,n1,n2);
    if((n1 < tree->data) && (n2 < tree->data))
        return LCA(tree->left,n1,n2);
    return tree;
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
    /*              20
                   /  \
                  8    22
                 / \
                4   12
                   /  \
                  10  14            */
                    
                
    struct node *root=createnode(20);
    root->left=createnode(8);
    root->right=createnode(22);
    root->left->left=createnode(4);
    root->left->right= createnode(12);
    root->left->right->left=createnode(10);
    root->left->right->right=createnode(14);
    int n1,n2;
    display(root);
    printf("NULL\n");
    printf("Enter two nodes:\n");
    scanf("%d %d",&n1,&n2);
    printf("LCA of %d %d is: \n",n1,n2);
    struct node* x=LCA(root,n1,n2);
    printf("%d\n",x->data);
    return 0;
}
