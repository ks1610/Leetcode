#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> adj[numCourses];
        std::vector<int> indegree(numCourses, 0);
        std::vector<int> ans;
        
        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;    
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            auto t = q.front();
            ans.push_back(t);
            q.pop();

            for (auto x : adj[t]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }    
            }
        }

        return ans.size() == numCourses;
    }
};

int main() {
    Solution sol;

    // Example 1: possible schedule
    int numCourses1 = 2;
    std::vector<std::vector<int>> prerequisites1 = {{1, 0}};
    std::cout << "Example 1: " 
              << (sol.canFinish(numCourses1, prerequisites1) ? "Can finish" : "Cannot finish") 
              << std::endl;

    // Example 2: cycle -> cannot finish
    int numCourses2 = 2;
    std::vector<std::vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    std::cout << "Example 2: " 
              << (sol.canFinish(numCourses2, prerequisites2) ? "Can finish" : "Cannot finish") 
              << std::endl;

    // Example 3: larger case
    int numCourses3 = 4;
    std::vector<std::vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    std::cout << "Example 3: " 
              << (sol.canFinish(numCourses3, prerequisites3) ? "Can finish" : "Cannot finish") 
              << std::endl;

    return 0;
}
