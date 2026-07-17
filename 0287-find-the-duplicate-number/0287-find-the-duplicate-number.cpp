class Solution {
public:
    void setFreq(int x,bool arr[]) {
        arr[x]=true;

    }
    int findDuplicate(vector<int>& nums) {
        bool arr[100001]={};
        for (int& x : nums) {
            if(arr[x]){
                return x;
            }
            setFreq(x,arr);
        }
        return 0;
    }
};