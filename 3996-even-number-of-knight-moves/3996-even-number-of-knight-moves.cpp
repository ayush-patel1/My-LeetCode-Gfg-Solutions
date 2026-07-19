class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dif1=abs(start[0]-target[0]);
        int dif2=abs(start[1]-target[1]);
        if(dif1%2==dif2%2) return true;
        return false;
    }
};