/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:    
    int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        map<pair<int, int>, int> slope; // pair (<dx, dy>, count)
        
        for (int i=0; i<points.size(); i++) {
            slope.clear();
            Point p1 = points[i];
            int duplicated = 0;
            int vertical = 0;
            int max_slope = 0;
            for (int j=i+1; j<points.size(); j++) {
                Point p2 = points[j];
                // case 1: duplicated point
                if (p1.x == p2.x && p1.y == p2.y) {
                    duplicated++;
                } else if (p1.x == p2.x) {
                // case 2: vertical line.
                    vertical++;
                } else {
                // case 3: others.
                    int dx = p2.x - p1.x;
                    int dy = p2.y - p1.y;
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    
                    auto pair = make_pair(dx, dy);
                    slope[pair]++;

                    // update max_slope.
                    max_slope = max(max_slope, slope[pair]);
                }
                max_slope = max(max_slope, vertical);
            }
            
            // update global max.
            if (res < max_slope + duplicated + 1) {
                res = max_slope + duplicated + 1;
            }
        }
        return res;
    }
};
