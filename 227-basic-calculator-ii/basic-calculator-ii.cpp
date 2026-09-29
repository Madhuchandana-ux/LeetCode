#include <string>
#include <stack>
#include <numeric>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<long long> st;
        long long currentNumber = 0;
        char lastOperator = '+';
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            char ch = s[i];

            // Build multi-digit numbers
            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }

            // Process operator or end of string (ignore whitespace)
            if ((!isdigit(ch) && !isspace(ch)) || i == n - 1) {
                if (lastOperator == '+') {
                    st.push(currentNumber);
                } else if (lastOperator == '-') {
                    st.push(-currentNumber);
                } else if (lastOperator == '*') {
                    long long top = st.top();
                    st.pop();
                    st.push(top * currentNumber);
                } else if (lastOperator == '/') {
                    long long top = st.top();
                    st.pop();
                    st.push(top / currentNumber);
                }

                lastOperator = ch;
                currentNumber = 0;
            }
        }

        // Sum all numbers remaining in the stack
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};