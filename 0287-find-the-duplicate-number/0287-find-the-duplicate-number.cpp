class Solution {
public:
   
    int findDuplicate(vector<int>& arr) {
      
        for (const int& x : arr) {
            if(arr[abs(x)]<0){
                return abs(x);
            }
            arr[abs(x)]*=-1;
        }
        return 0;
    }
};