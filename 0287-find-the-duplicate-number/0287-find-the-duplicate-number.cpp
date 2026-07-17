class Solution {
public:
   
    int findDuplicate(vector<int>& arr) {
      
        for (const int& x : arr) {
            auto y=abs(x);
            if(arr[y]<0){
                return y;
            }
            arr[y]=-arr[y];
        }
        return 0;
    }
};