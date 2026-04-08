// Solução 1
// Algoritmo de Kahn

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (!indegree[i]) q.push(i);
        
        vector<int> result;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            result.push_back(curr);

            for (int next : adj[curr])
                if (!(--indegree[next])) q.push(next);
        }
        
        if (result.size() != numCourses) return {};
        return result;
    }
};


// Solução 2
// Usando DFS

class Solution {
public:
    bool hasCycle(int src, vector<vector<int>> &adj, vector<int> &vis, unordered_set<int> &st, vector<int> &ans) {
        vis[src] = 2;

        for (auto v : adj[src]) {
            if (vis[v] == 0) {
                vis[v] = 2;
                if (hasCycle(v, adj, vis, st, ans)) return true;
            } else if (vis[v] == 2)
                return true;
        }

        vis[src] = 1;
        if (st.find(src) == st.end()) {
            ans.push_back(src);
            st.insert(src);
        }

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        for (auto &v : prerequisites)
            adj[v[0]].push_back(v[1]);

        vector<int> ans;
        unordered_set<int> st;
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; ++i)
            if (hasCycle(i, adj, visited, st, ans)) return {};

        return ans;
    }
};
