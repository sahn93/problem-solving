class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int l, r;
        for (string &s : tokens) {
            if (s == "+") {
                r = stk.top();
                stk.pop();
                l = stk.top();
                stk.pop();
                stk.push(l+r);
            } else if (s == "-") {
                r = stk.top();
                stk.pop();
                l = stk.top();
                stk.pop();
                stk.push(l-r);
            } else if (s == "*") {
                r = stk.top();
                stk.pop();
                l = stk.top();
                stk.pop();
                stk.push(l*r);
            } else if (s == "/") {
                r = stk.top();
                stk.pop();
                l = stk.top();
                stk.pop();
                stk.push(l/r);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
