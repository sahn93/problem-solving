class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj;
        int count = 0;
        for (int i: nums) {
            if (count == 0) {
                maj = i;
                count++;
            } else {
                if (i == maj) {
                    count++; 
                } else {
                    count--;
                }
            }
        }
        return maj;
    }
};
