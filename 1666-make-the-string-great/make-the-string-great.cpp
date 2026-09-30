class Solution {
public:
    string makeGood(string s) {
        string t = "";
        for (char c : s) {
            // Check if the current character forms a bad pair with the last character in 't'
            if (!t.empty() && abs(t.back() - c) == 32) {
                t.pop_back(); // Remove the bad pair
            } else {
                t.push_back(c);
            }
        }
        return t;
    }
};