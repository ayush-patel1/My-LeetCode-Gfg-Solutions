class Solution {
public:
    int maxDepth(string s) {
        int c=0,n=s.size();
        int max_depth=0;
        for(auto &ch:s){
            if(ch=='(') c++;
            else if(ch==')')c--;
            max_depth=max(max_depth,c);
        }
        return max_depth;
    }
};