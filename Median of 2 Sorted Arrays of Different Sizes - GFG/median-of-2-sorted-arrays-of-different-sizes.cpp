//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here

        // int n=ar1.size();
        // int m=ar2.size();
        //  int low=0;
        //     int high=n;

        //   if(n>m){

        //     return MedianOfArrays(ar2,ar1);

        // }
        
        
          
        //     // when length are different then apply binary search on shortest array to avoid index out of board
            
        //     while(low<=high)
        //     {
        //         // initialize the cut or partitions
                
                
        //         int cut1=low+(high-low)/2;
                
        //         // total required - already present
                
        //         int cut2=(n+m+1)/2-cut1;
                
        //         // initialize l1,l2,r1,r2
        //         int l1=cut1==0?INT_MIN:ar1[cut1-1];
        //         int l2=cut2==0?INT_MIN:ar2[cut2-1];
        //         int r1=cut1==n?INT_MAX:ar1[cut1];
        //         int r2=cut2==m?INT_MAX:ar2[cut2];
                
        //         // we get always even length 
                
                
        //         if(l1<=r2 and l2<=r1)
        //         {
        //             if((n+m)%2==0)
        //                 return (max(l1,l2)+min(r1,r2))/2.0;
        //             else{
        //                 return (double)max(r1,r2);
        //             }
        //         }
                
                
        //         else if(l1>r2)
        //         {
        //             high=cut1-1;
                    
        //         }
                
        //         else if(l2>r1)
        //         {
        //             low=cut1+1;
                    
        //         }
            
                
        //     }
        //     return 0.0;
            
            
            
        // int n1=array1.size();

        // int n2=array2.size();

        // int begin=0,end=n1;

        if(array1.size()>array2.size()){

            // return MedianOfArrays(array2,array1);
            swap(array2,array1);

        }
              
        int n1=array1.size();

        int n2=array2.size();

        int begin=0,end=n1;


        while(begin<=end){

            int i1=(begin+end)/2;

            int i2=(n1+n2+1)/2-i1;

            int min1=(i1==n1)?INT_MAX:array1[i1];

            int max1=(i1==0)?INT_MIN:array1[i1-1];

            int min2=(i2==n2)?INT_MAX:array2[i2];

            int max2=(i2==0)?INT_MIN:array2[i2-1];

            if(max1<=min2 and max2<=min1){

                if((n1+n2)%2==0){

                    return (max(max1,max2)+min(min1,min2))/2.0;

                }

                else{

                    return (double)max(max1,max2);

                }

            }

            else if(max1>min2){

                    end=i1-1;

            }

            else{

                begin=i1+1;

            }

        }

        return 0.0;


    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends