class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        
        for (int i=1; i<=n; i++) {
            string value;
            bool isnumber = true;
            if (i%3==0) {
                value.append("Fizz");
                isnumber = false;
            }
            if (i%5==0) {
                value.append("Buzz");
                isnumber = false;
            }
            if (isnumber) {
                value = to_string(i);
            }
            res[i-1] = value;
        }
        return res;
    }
};
