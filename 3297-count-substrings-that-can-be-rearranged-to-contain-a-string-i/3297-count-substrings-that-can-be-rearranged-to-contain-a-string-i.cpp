class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>freq2(26);
        for(int i=0;i<word2.size();i++){
            freq2[word2[i]-'a']++;
        }
        vector<int>freq1(26,0);
        long long ans=0;
        int left=0;
        int right=0;
        while(right<n){
            bool flag=true;
            freq1[word1[right]-'a']++;
            for(int i=0;i<26;i++){
                if(freq1[i]<freq2[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                while(left<=right){
                    freq1[word1[left]-'a']--;
                    if(freq1[word1[left]-'a']<freq2[word1[left]-'a']){
                        freq1[word1[left]-'a']++;
                        break;
                    }
                    left++;
                }
                ans+=left+1;
            }
            right++;
        }
        return ans;
    }
};