class Solution {
public:
    double myPow(double x, long long int n, double ans=1 ) {
        if( n==0 ){
            return ans;
        }
        if(n<0){
            n*=-1;
            x=1/x;
        }
        if(n&1){
            return myPow(x*x,n/2,ans*x);
        }
        else{
            return myPow(x*x,n/2,ans);
        }
    }
};