class Solution {
public:
    bool isPrimeNum(int x){
        if(x <= 1) return false;
        for(int i = 2; 1LL * i * i <= x; i++){
            if(x % i == 0) return false;
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);

        string temp = "";
        for(int i = 0; i < s.size(); i++){
            temp += s[i];
            if(!isPrimeNum(stoi(temp))) return false;
        }

        temp = "";
        for(int i = s.size() - 1; i >= 0; i--){
            temp = s[i] + temp;
            if(!isPrimeNum(stoi(temp))) return false;
        }

        return true;
    }
};
