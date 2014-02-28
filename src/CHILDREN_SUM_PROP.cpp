/* This Program checks CHILDREN SUM PROPERTY of Binary Tree
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

int children_sum(struct node* tree)
{
    int ldata=0;
    int rdata=0;
    if((tree == NULL) || (tree->left==NULL && tree->right==NULL))
        return 1;
    else
    {
        if(tree->left != NULL)
            ldata=tree->left->data;
        if(tree->right != NULL)
            rdata=tree->right->data;
        if((rdata+ldata)==(tree->data) && children_sum(tree->left) && children_sum(tree->right))
            return 1;
        else
            return 0;
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
    int x=children_sum(root);
    if(x==1)
        printf("Tree satisfy CHILDREN SUM PROPERTY.\n");
    else
        printf("Tree does not satisfy CHILDREN SUM PROPERTY.\n");
    return 0;
}
