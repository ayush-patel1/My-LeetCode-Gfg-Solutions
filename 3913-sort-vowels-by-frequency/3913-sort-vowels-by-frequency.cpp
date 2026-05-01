class Solution {
public:
    bool isVow(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }

    string sortVowels(string s) {
        int n = s.size();

        unordered_map<char,int> mp, first;
        vector<char> v;

        for(int i=0;i<n;i++){
            if(isVow(s[i])){
                mp[s[i]]++;
                if(first.find(s[i])==first.end()){
                    first[s[i]] = i;
                }
                v.push_back(s[i]);
            }
        }

        // sort based on freq desc, first occurrence asc
        sort(v.begin(), v.end(), [&](char a, char b){
            if(mp[a] != mp[b]) return mp[a] > mp[b];
            return first[a] < first[b];
        });

     
        int j = 0;
        for(int i=0;i<n;i++){
            if(isVow(s[i])){
                s[i] = v[j++];
            }
        }

        return s;
    }
};