class Solution {
public:
vector<string> phoneMap = {
    "",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(string& digits, string& current, int index, vector<string>& combinations) {
    if (index == digits.length()) {
        combinations.push_back(current);
        return;
    }

    string letters = phoneMap[digits[index] - '0'];
    for (char letter : letters) {
        current.push_back(letter);
        backtrack(digits, current, index + 1, combinations);
        current.pop_back();  // backtrack
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }

    vector<string> combinations;
    string current;
    backtrack(digits, current, 0, combinations);
    return combinations;
}
};
