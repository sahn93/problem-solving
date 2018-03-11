class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (word.size() > board.size()*board[0].size()) return false;
        bool res = false;
        for (int row=0; row<board.size(); row++) {
            for (int col=0; col<board[0].size(); col++) {
                if (word[0] == board[row][col]) {
                    char c = board[row][col];
                    board[row][col] = '#';
                    res = backtrack(board, word, row, col, 0);
                    if (res) {
                        return res;
                    }
                    board[row][col] = c;
                } 
            }
        }
        return res;
    }
    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int i) {
        if (i == word.size() - 1)
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if (row > 0 && board[row-1][col] == word[i+1]) {
            char c = board[row-1][col];
            board[row-1][col] = '#';
            if (backtrack(board, word, row-1, col, i+1)) return true;
            board[row-1][col] = c;
        }
        if (row < board.size() - 1 && board[row+1][col] == word[i+1]) {
            char c = board[row+1][col];
            board[row+1][col] = '#';
            if(backtrack(board, word, row+1, col, i+1)) return true;
            board[row+1][col] = c;
        }
        if (col > 0 && board[row][col-1] == word[i+1]) {
            char c = board[row][col-1];
            board[row][col-1] = '#';
            if (backtrack(board, word, row, col-1, i+1)) return true;
            board[row][col-1] = c;
        }
        if (col < board[0].size()-1 && board[row][col+1] == word[i+1]) {
            char c = board[row][col+1];
            board[row][col+1] = '#';
            if (backtrack(board, word, row, col+1, i+1)) return true;
            board[row][col+1] = c;
        }
        return false;
    }
};
