class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> tempi;
        while (temp) {
            tempi.push_back(temp->val);
            temp = temp->next;
        }
        int n = tempi.size();
        vector<int> ans(n, 0); // Correctly allocated with size n and default 0
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= tempi[i]) { // Changed < to <= for strictly greater values
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(tempi[i]);
        }
        return ans;
    }
};