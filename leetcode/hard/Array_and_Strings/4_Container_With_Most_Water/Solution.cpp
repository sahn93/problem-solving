class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int max = 0;
        while (l < r) {
            int area = (r-l) * min(height[l], height[r]);
            if (max < area) max = area;
            height[l] < height[r] ? l++ : r--;
        }
        return max;
    }
};
