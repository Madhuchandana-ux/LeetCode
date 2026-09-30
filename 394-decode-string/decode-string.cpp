#include <string>
#include <stack>

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                // Accumulate digits (e.g., '1' and '2' -> 12)
                currentNum = currentNum * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                // Save current repetition count and surrounding string context
                countStack.push(currentNum);
                stringStack.push(currentString);
                
                // Reset active values for the inside of brackets
                currentNum = 0;
                currentString = "";
            } 
            else if (ch == ']') {
                // Retrieve outer context
                int repeatTimes = countStack.top();
                countStack.pop();
                
                string prevString = stringStack.top();
                stringStack.pop();

                // Expand current segment and append to outer string
                while (repeatTimes > 0) {
                    prevString += currentString;
                    repeatTimes--;
                }

                currentString = prevString;
            } 
            else {
                // Normal letter: add to current string segment
                currentString += ch;
            }
        }

        return currentString;
    }
};