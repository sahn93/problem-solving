class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> M(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> temp(numCourses, false);
        stack<int> stk;
        vector<int> res;
        
        for (const auto& p: prerequisites) {
            M[p.second].push_back(p.first);
        }
        
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && findCycle(M, visited, temp, stk, i))
                return res;
        }

        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        
        return res;
    }
    bool findCycle(vector<vector<int>> &M, vector<bool> &visited, 
                   vector<bool> &temp, stack<int> &stk, int i) {
        bool push = visited[i] ? false : true;
        
        visited[i] = temp[i] = true;
        for (int j: M[i]) {
            if (temp[j] || findCycle(M, visited, temp, stk, j))
                return true;
        }
        temp[i] = false;
        
        if (push)
            stk.push(i);
        return false;
    }
};
