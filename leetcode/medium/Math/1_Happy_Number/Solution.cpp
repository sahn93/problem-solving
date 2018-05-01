class Solution {
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = nextNum(slow);
            fast = nextNum(fast);
            fast = nextNum(fast);
        } while (slow != fast);
        if (slow == 1) return true;
        else return false;
    }
    
    int nextNum(int n) {
        int next = 0;
        while (n > 0) {
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        return next;
    }
};
