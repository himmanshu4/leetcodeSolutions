class Solution {
public:
   
    int findDuplicate(vector<int>& arr) {
      
        for (const int& x : arr) {
            auto y=abs(x);
            if(arr[y]<0){
                return y;
            }
            arr[y]*=-1;
        }
        return 0;
    }
};