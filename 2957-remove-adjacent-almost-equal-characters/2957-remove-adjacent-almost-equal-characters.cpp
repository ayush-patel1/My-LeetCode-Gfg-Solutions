class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int cnt = 0;
        int i=0;
        while(i < word.size() - 1){
            if(abs(word[i+1] - word[i]) <= 1){
                cnt++;
                i = i + 2;
            } else i++;
        }
        return cnt;
    }
};