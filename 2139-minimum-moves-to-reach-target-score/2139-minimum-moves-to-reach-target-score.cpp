class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ops=0;
        while(maxDoubles && target>1){
            if(target%2==0 && maxDoubles){
                 target/=2;
                 maxDoubles--;
            }
            else{
                target--;
            }
            ops++;
        }
        return ops+target-1;
    }
};