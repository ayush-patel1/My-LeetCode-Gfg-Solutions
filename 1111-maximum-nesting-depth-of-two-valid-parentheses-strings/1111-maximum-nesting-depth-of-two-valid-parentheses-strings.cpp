class Solution {
public:
    bool canSplit(string &seq, int mid){
        int depth = 0, maxDepth = 0;
        for(int i=0; i<seq.size(); i++){
            if(seq[i] == '(') depth++;
            else depth--;

            maxDepth = max(maxDepth, depth);
        }

        return maxDepth <= 2*mid;
    }
    vector<int> maxDepthAfterSplit(string seq) {
        int low = 1, high = seq.size()/2;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(canSplit(seq, mid)){
                ans = min(ans, mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        vector<int> v(seq.size());
        int depth = 0;
        for(int i=0; i<seq.size(); i++){
            if(seq[i] == '(') depth++;
            else depth--;

            if(depth < ans){
                v[i] = 0;
            }
            if(depth == ans){
                if(seq[i] == ')'){
                    v[i] = 1;
                }else{
                    v[i] = 0;
                }
            }
            if(depth > ans){
                v[i] = 1;
            }
        }

        return v;
    }
};