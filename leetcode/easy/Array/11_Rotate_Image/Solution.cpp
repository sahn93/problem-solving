class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp;
        for (int i=0; i<matrix.size()/2; i++) {
            for (int j=i; j<matrix.size()-i-1; j++) {
                // rotate
                tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size()-1-j][i];
                matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
                matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
                matrix[j][matrix.size()-1-i] = tmp;
            }
        }
    }

    // another solution
    //void rotate(vector<vector<int>>& matrix) {
        //// horizental flip
        //reverse(matrix.begin(), matrix.end());
        //// flip about y=x
        //for (int i=0;i<matrix.size(); i++){
            //for (jnt j=0;j<matrjx.sjze(); j++){
                //swap(matrix[i][j], matrix[j][i]);
            //}
        //}
    //}
};
