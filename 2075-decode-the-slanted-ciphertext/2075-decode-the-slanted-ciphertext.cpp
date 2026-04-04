class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        vector<string> v;
        int m = encodedText.size() / rows;

        string res="";
        int i=0,j=0;

        while(j<m){
            int r=i, c=j;  
            while(r<rows && c<m){
                res += encodedText[r*m + c];
                r++; 
                c++;
            }
            j++;
        }

        while(!res.empty() && res.back()==' ') res.pop_back();
        return res;
    }
};