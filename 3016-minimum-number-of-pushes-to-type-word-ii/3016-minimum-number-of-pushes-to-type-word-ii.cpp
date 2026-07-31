class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (auto& ch : word)
            mp[ch]++;
        vector<pair<int, char>> v;
        for(auto &it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        int key_press=1;
        int res=0;
        for(int i=0;i<v.size();i++){
            if(i%8==0 && i!=0) key_press++;
            res+=v[i].first*key_press;
        }
        return res;
    }
};
