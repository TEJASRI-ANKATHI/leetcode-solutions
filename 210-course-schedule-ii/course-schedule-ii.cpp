class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath,
                    vector<vector<int>> &adj, vector<int> &ans) {

        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (isCycleDFS(v, vis, recPath, adj, ans))
                    return true;
            }
            else if (recPath[v]) {
                return true;
            }
        }

        recPath[src] = false;
        ans.push_back(src);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build adjacency list
        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath, adj, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};