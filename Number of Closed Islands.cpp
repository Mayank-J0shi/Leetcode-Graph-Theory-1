class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size()){
            return false ;
        }
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j]=1;
        bool dfs1=dfs(grid,i-1,j);
        bool dfs2=dfs(grid,i+1,j);
        bool dfs3=dfs(grid,i,j-1);
        bool dfs4=dfs(grid,i,j+1);
        return dfs1 and dfs2 and dfs3 and dfs4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.size()==0 or grid[0].size()==0){
            return 0;
        }
        int closedIslands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    //if dfs end in false means it is not surrounded by water
                    //if dfs end in true means it is surrounded by water as we have checked for every dfs trversal
                    if(dfs(grid,i,j))
                        closedIslands++;
                }
            }
        }
        return closedIslands;
    }
};