class Solution {
public:
    vector<string> result;

    vector<string> letters = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string &current) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string chars = letters[digits[index] - '0'];

        for (char c : chars) {
            current.push_back(c);
            backtrack(digits, index + 1, current);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string current;
        backtrack(digits, 0, current);

        return result;
    }
};