class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        return 1+dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 or grid[0].size()==0){
            return 0;
        }
        int max_area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    //if dfs end in false means it is not surrounded by water
                    //if dfs end in true means it is surrounded by water as we have checked for every dfs                       trversal
                    max_area=max(max_area,dfs(grid,i,j));
                }
            }
        }
        return max_area;
    }
};