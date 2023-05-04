//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         
         // ls is the left subarray size.
         int ls=m-l+1;
         // rs is the right subarray size.
         int rs=r-m;
         int *left=new int [ls];
         int *right=new int [rs];
         // copy the elements of left subarray in left array, and also copy the elements of right
         // subarray in right array.
         for(int i=0;i<ls;i++){
             left[i]=arr[l+i];
         }
         for(int j=0;j<rs;j++){
             right[j]=arr[j+m+1];
         }
         // now write logic or merge two sorted arrays.
         int i=0,j=0,k=l;
         while(i<ls && j<rs){
             if(left[i]>right[j])
             {
                 arr[k]=right[j];
                 k++;
                 j++;
             }
             else{
                 arr[k]=left[i];
                 k++;
                 i++;
             }
         }
         // extra elements in left subarray.
         while(i<ls)
         {
             arr[k]=left[i];
             i++;
             k++;
             
         }
         while(j<rs)
         {
             arr[k]=right[j];
             j++;
             k++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
        {     // means there will me atleast two elements.
            return;
        }
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends