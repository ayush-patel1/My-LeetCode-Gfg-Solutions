class Solution {
public:
    string smallestPalindrome(string s) {
        string half="";
        vector<int>v(26,0);
        for(auto ch:s) v[ch-'a']++;
        char odd=' ';
        for(int i=0;i<26;i++){
           if(v[i]&1){
            v[i]--;
             odd=i+'a';
           }
        }
        for(int i=0;i<26;i++){
            int h_freq=v[i]/2;
           if(v[i]%2==0){
              while(h_freq--){
                half+=(i+'a');
              }
           }
        }
        string first_half=half;
        reverse(half.begin(),half.end());
        string res=first_half;
        if(odd!=' ') res+=odd; res+=half;
        return res;
    }
};