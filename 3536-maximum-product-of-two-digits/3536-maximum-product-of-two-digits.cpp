namespace ye{};
class Solution {
public:
    int maxProduct(int n) {
        using namespace ye;
        int max=0,submax=0;
        while(n){
            if(n%10<=max){
                submax=std::max(submax,n%10);
            } else{
                submax=max;
                max=n%10;
            }
            n/=10;
        }
        return max*submax;
    }
};