class Solution {
public:
    int find_set(int *parent, int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
//    void uni(int *parent, int x, int y) {
//        parent[find_set(parent, x)] = find_set(parent, y);
//    }
    
    int findCircleNum(vector<vector<int>>& M) {
        // initialize
        int num = M.size();
        int parent[num];
        for (int i=0; i<num; i++) {
            parent[i] = i;
        }
        
        for (int i=0; i<M.size()-1; i++) {
            for (int j=i+1; j<M.size(); j++) {
                int set_i = find_set(parent, i);
                int set_j = find_set(parent, j);
                if (M[i][j]==1 && (set_i != set_j) ) {
                    parent[set_i] = set_j;
                    num--;
                }
            }
        }
        return num;
    }
};
