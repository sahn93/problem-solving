class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ptri;
        if (numRows < 1)
            return ptri;
        
        ptri.push_back({1});
        for (int i=2; i<=numRows; i++) {
            vector<int> row(i);
            row[0] = 1;
            row[i-1] = 1;
            for (int j=1; 2*j<i; j++) {
                row[j] = ptri.back()[j-1] + ptri.back()[j];
                row[i-1-j] = ptri.back()[j-1] + ptri.back()[j];
            }
            ptri.push_back(row);
        }
        return ptri;
    }
};
