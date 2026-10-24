class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;

        string current = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                counts.push(num);
                strings.push(current);

                num = 0;
                current = "";
            }
            else if (c == ']') {
                int repeat = counts.top();
                counts.pop();

                string previous = strings.top();
                strings.pop();

                while (repeat--) {
                    previous += current;
                }

                current = previous;
            }
            else {
                current += c;
            }
        }

        return current;
    }
};
