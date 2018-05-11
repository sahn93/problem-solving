class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0: 0 to 0, 1: 1 to 0, 2: 0 to 1, 3: 1 to 1
        int rows = board.size();
        int cols = board[0].size();
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                int curr = board[i][j];
                int surr = -board[i][j];
                int left = max(j-1, 0);
                int right = min(j+1, cols-1);
                int bot = min(i+1, rows-1);
                int top = max(i-1, 0);
                for (int k = top; k<=bot; k++) {
                    for (int l = left; l<=right; l++) {
                        surr += board[k][l] % 2;
                    }
                }
                if (curr == 0) {
                    if (surr == 3) {
                        board[i][j] = 2;
                    }
                } else if (curr == 1) {
                    if (surr < 2) {
                        board[i][j] = 1;
                    } else if (surr < 4) {
                        board[i][j] = 3;
                    } else {
                        board[i][j] = 1;
                    }
                }
            }
        }
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                board[i][j] /= 2;
            }
        }
    }
};
