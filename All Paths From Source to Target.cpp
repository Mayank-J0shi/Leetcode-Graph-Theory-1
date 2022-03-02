class Solution {
public:
    int target;
    vector<vector<int>> res;
    vector <int> ds;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target=graph.size()-1;
        dfs(graph,0);
        return res;
    }
    void dfs(vector<vector<int>>& graph,int node){
        ds.push_back(node);
        if(node==target)
             res.push_back(ds);
        else for(auto it : graph[node]){
            dfs(graph,it);
        }
        ds.pop_back();
    }
};