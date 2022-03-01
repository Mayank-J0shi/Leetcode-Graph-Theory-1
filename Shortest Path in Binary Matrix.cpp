class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        int m=grid.size();
        int n=grid[0].size();
        queue <vector <int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                vector <int> point=q.front();
                q.pop();
                if(point[0]==m-1 and point[1]==n-1)
                    return point[2];
                for(auto it : dir){
                    int r=point[0]+it[0];
                    int c=point[1]+it[1];
                    if(r<0 or c<0 or r>=m or c>=n or grid[r][c]==1){
                        continue;
                    }
                    q.push({r,c,point[2]+1});
                    grid[r][c]=1;
                }
            }
        }
        return -1;
    }
};