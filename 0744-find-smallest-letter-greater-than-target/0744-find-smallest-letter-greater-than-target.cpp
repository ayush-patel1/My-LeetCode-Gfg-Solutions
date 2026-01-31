class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       char res=letters[0];
       sort(letters.begin(),letters.end());
       for(auto &ch:letters){
        if(ch>target){
            return ch;
        }
       }
       return res;
    }
};