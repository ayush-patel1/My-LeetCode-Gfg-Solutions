class Solution {
public:
    long solve(long n){
       if(n==1) return 0;
        else if(n&1){
            long op1=solve(n-1);
            long op2=solve(n+1);
            return 1+min(op1,op2);
        }
        else{
            return 1+solve(n/2);
        }
    }
    int integerReplacement(int n) {
      return int(solve(n));
    }
};