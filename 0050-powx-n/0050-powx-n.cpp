class Solution {
public:
    double myPow(double x, long long int n ) {
        if( n==0 ){
            return 1;
        }
        if(n<0){
            n*=-1;
            x=1/x;
        }
        if(n&1){
            return x*myPow(x*x,n/2);
        }
        else{
            return myPow(x*x,n/2);
        }
    }
};