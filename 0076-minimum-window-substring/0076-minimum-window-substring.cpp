class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";

        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        int left = 0;
        int missing = t.size();
        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (need[c] > 0)
                missing--;

            need[c]--;

            while (missing == 0) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0)
                    missing++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
