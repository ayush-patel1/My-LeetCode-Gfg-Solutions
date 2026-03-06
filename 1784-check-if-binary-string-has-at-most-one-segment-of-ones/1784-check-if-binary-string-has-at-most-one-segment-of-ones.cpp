class Solution {
public:
    bool checkOnesSegment(string s) {
       int cur=0;
       int seg=0;
       for(auto &ch:s){
          if(ch=='1'){
            cur++;
          }else{
            if(cur>=1)seg++;
            cur=0;
          }
       }
       if(cur){
         seg++;
       }
       cout<<seg<<endl;
       return seg<=1;
    }
};