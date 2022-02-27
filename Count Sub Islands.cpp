class Solution {
public:
    void dfs(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int i,int j,int &flag){
        if(i<0 or j<0 or i>=grid2.size() or j>=grid2[i].size() or grid2[i][j]==0){
            return;
        }
        if(grid2[i][j]==1){
            if(grid1[i][j]==0){
                flag=0;
                return ;
            }
            grid2[i][j]=0;
        }
        dfs(grid1,grid2,i+1,j,flag);
        dfs(grid1,grid2,i-1,j,flag);
        dfs(grid1,grid2,i,j-1,flag);
        dfs(grid1,grid2,i,j+1,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int islands=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){
                        int flag=1;

                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,flag);
                    if(flag){
                        islands++;
                    }
                }
            }
        }
        return islands;
    }
};