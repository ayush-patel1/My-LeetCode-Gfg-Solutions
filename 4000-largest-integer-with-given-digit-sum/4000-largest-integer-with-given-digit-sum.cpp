class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>n*9) return -1;
        string res="";
        while(res.size()<n){
            if(s>=9){
                s-=9;
                res+="9";
            }else if(s!=0){
                res+=s+'0';
                s=0;
            }else{
                res+='0';
            }
        }
        return stoi(res);
    }
};