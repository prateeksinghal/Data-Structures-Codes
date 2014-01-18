/* This Program prints the COUSINS of Given node in Binary Tree
    By: Prateek Singhal */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

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

void cousin(struct node* root,int key)
{
    queue<struct node*> Q;
    int qsize=0;
    bool flag=true;
    struct node* temp;
    Q.push(root);
    while(!Q.empty())
    {
        if(qsize==0)
            qsize=Q.size();
        if(!flag)
        {
                while(!Q.empty())
                {
                    printf("%d-> ",Q.front()->data);
                    Q.pop();
                }
                return;
        }
        while(qsize>0)
        {
            qsize--;
            temp=Q.front();
            Q.pop();
            if(((temp->left != NULL) && ((temp->left)->data==key)) || ((temp->right != NULL) && ((temp->right)->data==key)))
            {
                flag=false;
                continue;
            }
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
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
    printf("Cousins: \n");
    cousin(root,4);
    printf("NULL\n");
}
