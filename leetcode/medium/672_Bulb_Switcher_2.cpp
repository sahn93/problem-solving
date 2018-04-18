class Solution {
public:
    int flipLights(int n, int m) {
        if (m > 4) {
            m = m % 4;
            while (m <= 2) {
                m+=2;
            }
        }
        int stats = 0;
        if (n == 2) {
            // 3 ops
            while (m >= 0) {
                if (m == 3) {
                    stats++;
                } else if (m == 2) {
                    stats += 3;
                } else if (m == 1) {
                    stats += 3;
                } else if (m == 0) {
                    stats++;
                }
                m -= 2;
            }     
        }
        else if (n == 1) {
            // 2 ops
            while (m >= 0) {
                if (m == 2) {
                    stats++;
                } else if (m == 1) {
                    stats += 2;
                } else if (m == 0) {
                    stats++;
                }
                m -= 2;
            }
        }
        else if (n > 2) {
            // 4 ops
            while (m >= 0) {
                if (m == 4) {
                    stats++;
                } else if (m == 3) {
                    stats += 4;
                } else if (m == 2) {
                    stats += 6;
                } else if (m == 1) {
                    stats += 4;
                } else if (m == 0) {
                    stats++;
                }
                m -= 2;
            }
        }
        return stats;
    }
};
