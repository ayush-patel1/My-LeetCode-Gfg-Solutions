class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1=coordinate1[0]-'a';
        int x2=coordinate2[0]-'a';
        int y1=coordinate1[1]-'1';
        int y2=coordinate2[1]-'1';
        if(x1%2==x2%2){
            if(y1%2==y2%2){
                return true;
            }
            return false;
        }
        else{
            if(y1%2!=y2%2){
                return true;
            }
            return false;
        }
    }
};