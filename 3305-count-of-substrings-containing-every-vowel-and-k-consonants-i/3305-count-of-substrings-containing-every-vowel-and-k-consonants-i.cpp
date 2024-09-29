class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    
    int countOfSubstrings(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int res=0;
        int left=0;
        int right=0;
        int count_vowel=0;
        
        while(right<n){
            if(isVowel(s[right])){
               mp[s[right]]++;
                count_vowel++;
            }
            while((right-left+1)-count_vowel>k ){
                if(isVowel(s[left])){
                    mp[s[left]]--;
                    count_vowel--;
                    if(mp[s[left]]==0){
                        mp.erase(s[left]);
                    }
                }
                left++;
            }
            if (mp.size() == 5 && (right-left+1)-count_vowel == k) {
                res++;
                int dup_l = left;
                auto dup_vowel = mp;
                int dup_cont = (right-left+1)-count_vowel;

                while (dup_vowel.size() == 5) {
                    if (dup_vowel.count(s[dup_l])) {
                        dup_vowel[s[dup_l]]--;
                        if (dup_vowel[s[dup_l]] == 0) dup_vowel.erase(s[dup_l]);
                    } else {
                        dup_cont--;
                    }
                    dup_l++;
                    if (dup_cont== k && dup_vowel.size() == 5) res++;
                    if (dup_cont < k) break;
                }
            }
            right++;
        }
        return res;
    }
};