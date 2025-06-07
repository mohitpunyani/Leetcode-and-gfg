// User function template for C++

// User function template for C++

class Solution {
  public:
    int missingNum(vector<int>& arr) {
       
       int arrSize = arr.size()+1;
       
       vector<int> dummy(arrSize+1, 0);
       
       for(int i=0; i<arr.size(); i++){
            dummy[arr[i]]++;
       }
       
       for(int i=1; i<arrSize+1; i++){
           if(dummy[i] == 0){
               return i;
           }
       }
       return -1;
    }
};