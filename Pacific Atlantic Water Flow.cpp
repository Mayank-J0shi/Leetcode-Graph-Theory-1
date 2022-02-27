//JAVA CODE IS HERE I DO NOT KNOW WHY THIS THIS SHOWING ERROR UPDATING WITH JAVA CODE BUT WILL CHANGE IT TO RUNNING C++ CODE IN COMMING DAYS
class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    static int rows,cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.size()==0 or matrix[0].size()==0){
            return res;
        }
        int row=matrix.size(),col=matrix[0].size();
        rows=row; cols=col;
         // vector<vector<int>> vec( n , vector<int> (m, 0));
//        vector<vector<bool>> pacific(row,vector <bool>(col,false));
//        vector<vector<bool>> atlantic(row,vector <bool>(col,false));
        bool pacific[row][col];bool atlantic[row][col];
        
        //DFS
        for(int i=0;i<col;i++){
            dfs(matrix,0,i,INT_MIN,pacific);
            dfs(matrix,row-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<row;i++){
            dfs(matrix,i,0,INT_MIN,pacific);
            dfs(matrix,i,col-1,INT_MIN,atlantic);
        }
        
        //intersection
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& matrix,int i,int j,int prev,bool ocean[][cols]){
        if(i<0 or i>=rows or j<0 or j>=cols)
            return;
        if(matrix[i][j]<prev or ocean[i][j])
            return;
        ocean[i][j] = true;
        for(auto it : dir){
            dfs(matrix,i+it[0],j+it[1],matrix[i][j],ocean);
        }
    }
};

/////JAVA
class Solution {
    int dir[][] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> res = new ArrayList<>();
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) 
            return res;
        
        int row = matrix.length, col = matrix[0].length;
        boolean[][] pacific = new boolean[row][col];
        boolean[][] atlantic = new boolean[row][col];
        
        //DFS
        for(int i = 0; i < col; i++){
            dfs(matrix, 0, i, Integer.MIN_VALUE, pacific);
            dfs(matrix, row-1, i, Integer.MIN_VALUE, atlantic);
        }
        for(int i = 0; i < row; i++){
            dfs(matrix, i, 0, Integer.MIN_VALUE, pacific);
            dfs(matrix, i, col-1, Integer.MIN_VALUE, atlantic);
        }
        
        //preparing the result
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.add(Arrays.asList(i,j));
                }
            }
        }
        
        return res;
    }
    
    public void dfs(int[][] matrix, int i, int j, int prev, boolean[][] ocean){
        if(i < 0 || i >= ocean.length || j < 0 || j >= ocean[0].length) return;
        if(matrix[i][j] < prev || ocean[i][j]) return;
        ocean[i][j] = true;
        for(int[] d : dir){
            dfs(matrix, i+d[0], j+d[1], matrix[i][j], ocean);
        }
        
    }
}