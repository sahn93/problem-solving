class Solution {
public:
    void floodfill(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = 'x';
        if (row < grid.size() - 1 && grid[row+1][col] == '1')
            floodfill(grid, row+1, col);
        if (col < grid[0].size() - 1 && grid[row][col+1] == '1')
            floodfill(grid, row, col+1);
        if (row > 0 && grid[row-1][col] == '1')
            floodfill(grid, row-1, col);
        if (col > 0 && grid[row][col-1] == '1')
            floodfill(grid, row, col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for (int row=0; row<grid.size(); row++) {
            for (int col=0; col<grid[0].size(); col++) {
                if (grid[row][col]=='1') {
                    ret++;
                    floodfill(grid, row, col);
                }
            }
        }
        return ret;
    }
};
