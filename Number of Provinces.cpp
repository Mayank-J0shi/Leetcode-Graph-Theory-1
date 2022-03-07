class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i){
        grid[i][i]=0;
        for(int j=0;j<grid.size();j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                if(grid[j][j]==1){
                    dfs(grid,j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++){
            //if that city is not there
            if(grid[i][i]==0)
                continue;
            //else then there must be a provience
            res++;
            dfs(grid,i);
        }
        return res;
    }
};
