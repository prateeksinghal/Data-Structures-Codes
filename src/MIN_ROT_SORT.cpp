/* This Program finds MINIMUM in rotated sorted array in O(log n)
    By: Prateek Singhal */

#include<stdio.h>

int min(int x, int y) { return (x < y)? x :y; }

int find(int arr[],int start,int end)
{
    if(end<start)
        return arr[0];
    if(end==start)
        return arr[start];
        
    int mid=start+(start+end)/2;
    
    if(mid<end && arr[mid]>arr[mid+1])
        return arr[mid+1];

    if((arr[start]==arr[mid]) && (arr[end]==arr[mid]))
        return min(find(arr,start,mid-1),find(arr,mid+1,end));
        
    if(mid>start && arr[mid-1]>arr[mid])
        return arr[mid];
        
    if(arr[end] > arr[mid])
        return find(arr,start,mid-1);
    return find(arr,mid+1,end);
}

int main()
{
    // small input test data
    int arr[]={5,6,7,8,9,10,11,1,2,3,4};
    int start=0;
    int end=10;
    int min=find(arr,start,end);
    printf("Minimum element = %d\n",min);
}

    
