class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> digits;
        int num;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                digits.clear();
                for (int r=0; r<3; r++) {
                    for (int c=0; c<3; c++) {
                        num = board[i*3+r][j*3+c];
                        if( num != '.') {
                            if (digits.find(num) != digits.end()) {
                                return false;    
                            } else {
                                digits.insert(num);
                            }
                        }
                    }
                }
            }
        }
        // rows
        for (int i=0; i<9; i++) {
            digits.clear();
            for (int j=0; j<9; j++) {
                num = board[i][j];
                if( num != '.') {
                    if (digits.find(num) != digits.end()) {
                        return false;    
                    } else {
                        digits.insert(num);
                    }
                }
            }
        }
        // cols
        for (int i=0; i<9; i++) {
            digits.clear();
            for (int j=0; j<9; j++) {
                num = board[j][i];
                if( num != '.') {
                    if (digits.find(num) != digits.end()) {
                        return false;    
                    } else {
                        digits.insert(num);
                    }
                }
            }
        }
        
        return true;
    }
};
