//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    
    // VARIABLE SIZE SLIDING WINDOW
    
    // unordered_map<char,int>mp;
    
    // int i=0;
    // int j=0;
    // int ans=INT_MIN;
    // while(j<S.size())
    // {
    //     // do calculation
    //     mp[S[j]]++;
        
    //     // finding answer from calculations
        
    //     if(mp.size()==j-i+1)
    //     {
    //         ans=max(ans,j-i+1);
    //         j++;
            
    //     }
    //     else if(j-i+1>mp.size())
    //     {
    //         // remove the previous calcuations or (calculations of i)  and slide the window
            
    //         while(mp.size()<j-i+1)
    //         {
    //             mp[S[i]]--;
    //             if(mp[S[i]]==0){
    //                 mp.erase(S[i]);
    //             }
    //             i++;
            
    //         }
    //     j++;
    //   }
    // }
    // return ans;
    
    
    // another way to write code
       
    //   unordered_map<char,int>mp;
       
    //   int i=0;
      
    //   int n=S.length();
    //   int ans=1;
       
    //   int num=0;
       
    //   while(i<n)
    //   {
    //       if(mp.find(S[i])==mp.end())
    //       {
    //           mp[S[i]]++;
    //           i++;
    //       }
    //     //   else
    //       if(mp.find(S[i])!=mp.end() )
    //       {
    //           num=mp.size();
    //           mp.clear();
               
    //       }
    //       ans=max(ans,num);
           
    //   }
    //   return ans;
       
    // NOTE -> THIS APPROACH COMES 
    
//     unordered_map<char,int>mp;
//   for(char c='a'; c<='z';c++)
//   {
//       mp[c]=0;
//   }
   
//   int res=0;
//   int i=0;
//   int j=0;
//   while(j<S.size())
//   {
//       if(mp[S[j]]==0)
//       {
//           mp[S[j]]++;
//           j++;
//       }
       
//       else
//       {
           
//           mp[S[i]]--;
//           i++;
//           res=max(j-i+1,res);
//       }
//   }
//   res= max(j-i,res);
//   return res;


    //   int mp[26]={0};
    //     int i=0;
    //     int j=0;
    //     int ans=0;
    //     while(i<S.size()){
    //         if(mp[S[i]-'a']!=0){
    //             mp[S[j]-'a']--;
    //             j++;
    //         }
    //         else{
    //             mp[S[i]-'a']++;
    //             ans=max(ans,i-j+1);
    //             i++;
    //         }
    //     }
    //     return ans;
   
         unordered_map<char,int>mp;

            int i=0,j=0,len=INT_MIN;

       while(j<S.length())

       {

          

           if(mp.find(S[j])==mp.end())

           {

                mp[S[j]]++;

              len=max(len,(j-i+1));

               j++;

           }

           else

           {

               mp.erase(S[i]);

               i++;

           }

         //  if(len>(S.length()-i))

       //    break;

          

       }

       return len;
}