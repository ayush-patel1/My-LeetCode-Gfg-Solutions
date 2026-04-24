class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=count(moves.begin(),moves.end(),'L');
        int r=count(moves.begin(),moves.end(),'R');
        int b=moves.size()-l-r;
        return max(l,r)+b-min(l,r);
    }
};