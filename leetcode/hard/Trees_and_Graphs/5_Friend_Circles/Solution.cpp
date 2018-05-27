class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> visited(M.size(), false);
        int res = 0;
        
        for (int i=0; i<M.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                res++;
                dfs(M, visited, i);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& M, vector<bool>& visited, int idx) {
        vector<int> friends = M[idx];
        for (int i=0; i<friends.size(); i++) {
            if (friends[i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(M, visited, i);
            }
        }
    }
};
