#include <bits/stdc++.h>

class Solution {
    public:
        int numTrees(int n) {
            std::vector<int> uniqtree(n + 1, 1);
            //if(n == 0 || n == 1 || n == 2)
            //    return n;
            for(int node = 2; node <= n; node++){
                int total = 0;
                for(int root = 1; root <= node; root++){
                    total += uniqtree[root - 1] * uniqtree[node-root];
                }
                uniqtree[node] = total;
            }
            return uniqtree[n];   
        }
};

int main()
{
    Solution s;
    int n = 3;
    std::cout<<"Unique Binary Search Trees Of "<<n<<": "<<s.numTrees(n);
    return 0;
}
