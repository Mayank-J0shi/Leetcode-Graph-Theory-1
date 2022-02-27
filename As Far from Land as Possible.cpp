class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        queue <pair<int,int>> q;        
        //inserting all the 1 in a queue
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1){
                    q.push(make_pair(i,j));
                }
            }
        }      
        //base condition if all are zeroes either all are ones
        //so returning -1
        if(q.size()==0 or q.size()==(arr.size()*arr[0].size()))
            return -1;
        
        //the direction to rotated the bfs direction of the bfs
        // top right down left
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        //initializing the result variable
        int res=-1;
        while(!q.empty()){
            res++;
            int size=q.size();
            while(size-->0){
                pair <int,int> rem=q.front();
                q.pop();    
                //inserting the neibour element of the previous poped element
                for(int i=0;i<4;i++){
                    int row=rem.first+dir[i][0];
                    int cols=rem.second+dir[i][1];                
                    if(row<0 or cols<0 or row>=arr.size() or cols>=arr[0].size() or arr[row][cols]==1){
                        continue;
                    }
                    q.push(make_pair(row,cols));
                    arr[row][cols]=1;
                }
            }
        }
        return res;
    }
};