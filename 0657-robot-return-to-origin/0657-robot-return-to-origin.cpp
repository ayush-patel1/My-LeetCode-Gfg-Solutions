class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> mp;
        mp['U'] = {0, 1};
        mp['D'] = {-1, 0};
        mp['R'] = {1, 0};
        mp['L'] = {-1, 0};
        int x=0,y=0;
        for(auto &ch:moves){
            if(ch=='U'){
               y++;
            }else if(ch=='D'){
                y--;
            }else if(ch=='R'){
                x++;
            }else x--;
        }
        return x==0 && y==0;
    }
};