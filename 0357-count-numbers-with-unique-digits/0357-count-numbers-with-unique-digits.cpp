class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; // Only one number: 0
        if (n == 1) return 10; // Numbers: 0-9

        int ans = 10; // Start with count for 1 digit (0-9)
        int max_poss = 9; // First digit can be from 1-9
        int uniqueDigits = 9; // Start with 9 options for the first digit

        for (int k = 2; k <= n && max_poss > 0; k++) {
            uniqueDigits *= max_poss; // Multiply by available options for current digit
            ans += uniqueDigits; // Add to the total count
            max_poss--; // Decrease available choices for the next digit
        }

        return ans; // No need to add 1 for 0 again, it's already counted
    }
};
