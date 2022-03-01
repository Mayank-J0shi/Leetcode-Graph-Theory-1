class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue <vector <int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }else{
                    grid[i][j]=-1;
                }
            }   
        }
        int level=0;
        int dir[4][2]= {{0,1},{-1,0},{1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            level++;
            while(size-->0){
                vector <int> node =q.front();
                q.pop();
                for(auto it : dir){
                    int r =node[0]+it[0];
                    int c=node[1]+it[1];
                    if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c]!=-1)
                        continue;
                    q.push({r,c});
                    grid[r][c]=level;
                }
            }
        }
        return grid;
    }
};