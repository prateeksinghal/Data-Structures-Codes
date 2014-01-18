/* This Program Merge 2 sorted Arrays without using extra SPACE
    By: Prateek Singhal */

#include<stdio.h>
void merge(int a[],int b[],int longin);
int main()
{
    int i;
    int a[]={1,3,5,7,0,0,0};
    int b[]={2,4,6};
    int longin=4;
    merge(a,b,longin);
    printf("Final Array :\n");
    for(i=0;i<7;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}

void merge(int a[],int b[],int longin)
{
    int tailLong=longin-1;
    int tailShort=2;
    while(tailLong>=0 && tailShort>=0)
    {
        if(a[tailLong]>b[tailShort])
        {
            a[tailLong+tailShort+1]=a[tailLong];
            tailLong--;
        }
        else
        {
            a[tailLong+tailShort+1]=b[tailShort];
            tailShort--;
        }
    }
    
    while(tailShort>=0)
    {
        a[tailShort]=b[tailShort];
        tailShort--;
    }
}
    
