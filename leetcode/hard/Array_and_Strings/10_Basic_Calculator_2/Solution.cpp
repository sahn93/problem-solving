class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int prevop = -1;
        char prevoper = '+';
        int op = 0;
        
        while (op >= 0) {
            op = s.find_first_of("+-*/", prevop+1);
            int num;
            if (op < 0) {
                num = stoi(s.substr(prevop+1, s.size() - prevop - 1));
            } else {
                num = stoi(s.substr(prevop+1, op - prevop - 1));
            }
            
            if (prevoper == '+') {
                stk.push(num);
            } else if (prevoper == '-') {
                stk.push(-num);
            } else if (prevoper == '*') {
                int tmp = num*stk.top();
                stk.pop();
                stk.push(tmp);
            } else if (prevoper == '/') {
                int tmp = stk.top()/num;
                stk.pop();
                stk.push(tmp);
            }
            prevoper = s[op];
            prevop = op;
        };
        
//        while (!stk.empty()) {
//            cout << stk.top() << endl;
//            stk.pop();
//        }
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};
