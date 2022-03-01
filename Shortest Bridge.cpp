class Solution {
public:
    int dir[4][2]= {{0,1},{-1,0},{1,0},{0,-1}};
    bool vis[100][100];
    int shortestBridge(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        int flag=true;
        queue <pair <int,int>> q;
        for(int i=0;i<grid.size() and flag;i++){
            for(int j=0;j<grid[0].size() and flag;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,q);
                    flag=false;
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                pair <int,int> node=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int row=node.first+dir[i][0];
                    int col=node.second+dir[i][1];
                    if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size() or vis[row][col]==true)
                         continue;
                    if(grid[row][col]==1)
                        return level;
                    q.push(make_pair(row,col));
                    vis[row][col]=true;
                }
            }
             level++;
        }
        return -1;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,queue <pair <int,int>> &q){
        vis[i][j]=true;
        q.push(make_pair(i,j));
        for(int k=0;k<4;k++){
            int row=i+dir[k][0];
            int col=j+dir[k][1];
            if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size() or vis[row][col]==true or grid[row][col]==0)
                continue;
            dfs(row,col,grid,q);
        }
    }
};