class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> M(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> temp(numCourses, false);
        
        // Make an adj list to represent the directed graph.
        for (const auto& p: prerequisites) {
            M[p.second].push_back(p.first);
        }
        
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && findCycle(M, visited, temp, i)) 
                return false; // Cycle found.
        }
        return true; // No cycle found.
    }
    
    bool findCycle(vector<vector<int>> &M, vector<bool> &visited, vector<bool> &temp, int i) {
        visited[i] = true;
        temp[i] = true;
        
        for (int j: M[i]) {
            if (temp[j] || findCycle(M, visited, temp ,j)) return true;
        }
        temp[i] = false;
        
        return false;
    }
};
