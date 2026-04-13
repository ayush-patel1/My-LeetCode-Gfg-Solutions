class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int cnt_a=count(s.begin(),s.end(),'a');
        int cnt_b=count(s.begin(),s.end(),'b');
        int cnt_c=count(s.begin(),s.end(),'c');

        if(cnt_a<k || cnt_b<k || cnt_c<k) return -1; 

        int cur_a=0,cur_b=0,cur_c=0;
        int max_len=0;
        while(r<n){
            if(s[r]=='a') cur_a++;
            else if(s[r]=='b') cur_b++;
            else cur_c++;

            while(l<=r && (cnt_a-cur_a<k || cnt_b-cur_b<k || cnt_c-cur_c<k)){
                if(s[l]=='a') cur_a--;
                else if(s[l]=='b') cur_b--;
                else cur_c--;
                l++;
            }

            max_len=max(max_len,r-l+1);
            r++;
        }
        return n-max_len;
    }
};