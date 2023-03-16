//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
  public:
    string convertToRoman(int n)
    {
        // code here
        map<int,string> mp;
        // mp.insert({1,"I"});
        // mp.insert({4,"IV"});
        // mp.insert({5,"V"});
        // mp.insert({9,"IX"});
        // mp.insert({10,"X"});
        // mp.insert({40,"XL"});
        // mp.insert({50,"L"});
        // mp.insert({90,"XC"});   
        // mp.insert({100,"C"});
        // mp.insert({400,"CD"});
        // mp.insert({500,"D"});
        
        // mp.insert({900,"CM"});
        // mp.insert({1000,"M"});    
        
        mp.insert({1000,"M"});
        mp.insert({900,"CM"});
        mp.insert({500,"D"});
        mp.insert({400,"CD"});
        mp.insert({100,"C"});
        mp.insert({90,"XC"});   
        mp.insert({50,"L"});
        mp.insert({40,"XL"});
        mp.insert({10,"X"});
        mp.insert({9,"IX"});
        mp.insert({5,"V"});
        mp.insert({4,"IV"});
        mp.insert({1,"I"});


        
        
        string result="";
        // for(auto it=mp.rbegin();it!=mp.rend();it++)
        // {
        //     while(n>=it->first)
        //     {
                
        //             result=result+it->second;
        //             n=n-it->first;
                    
            
        //     }
            
            
        // }
        // return result;
    // }
// }
        
        while(n!=0)
        {
            for(auto it=mp.rbegin();it!=mp.rend();it++)
            {
                // we do use this loop from rbegin to r end because
                int value=it->first;
                if(n>=value)
                {
                    result=result+it->second;
                    n=n-value;
                    break;
                    
                    
                }
            }
        }
        return result;
        }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}
// } Driver Code Ends