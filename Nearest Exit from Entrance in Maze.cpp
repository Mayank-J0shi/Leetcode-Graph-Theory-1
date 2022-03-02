class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue <vector <int>> q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]]='+';
        int level=1;
        int dir[4][2]= {{0,1},{-1,0},{1,0},{0,-1}};

        while(!q.empty()){
            int size=q.size();
            while(size-->0){
                vector <int> node = q.front();
                q.pop();
                for(auto it : dir){
                    int row=node[0]+it[0];
                    int col=node[1]+it[1];
                    
                    if(row<0 or col<0 or row>=maze.size() or col>=maze[0].size() or maze[row][col]=='+')
                        continue;
                    if(row==0 or col==0 or row==maze.size()-1 or col==maze[0].size()-1)
                        return level;
                    q.push({row,col});
                    maze[row][col]='+';
                }
            }
            level++;
        }
        return -1;
    }
};