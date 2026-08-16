class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char el : s) {
            if (el == '(' || el == '[' || el == '{') {
                st.push(el);
            } else {
                if (st.empty()) return false;
                if ((el == ')' && st.top() == '(') || 
                (el == ']' && st.top() == '[') || 
                (el == '}' && st.top() == '{')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
