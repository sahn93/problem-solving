class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist=x^y;
        int count=0;
        cout << dist << endl;
        while (dist>0) {
            if (dist&1)
                count++;
            dist = dist >> 1;
        }
        return count;
    }
};
