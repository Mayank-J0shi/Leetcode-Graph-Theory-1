class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &A){
        if( i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j]==0)
            return 0;
        
        A[i][j] = 0;
        
        return 1+dfs(i-1,j,A)+dfs(i+1,j,A)+dfs(i,j-1,A)+dfs(i,j+1,A);
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int all_one=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++)
                    all_one+=A[i][j];
        }
        int close_one = 0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if((i==0 || j==0 || i==A.size()-1 || j==A[0].size()-1) && A[i][j]==1)
                   { cout<<i<<" "<<j; close_one+= dfs(i,j,A);}
            }
        }
        cout<<"End Result"<<all_one<<" "<<close_one;
        return all_one - close_one;
    }
};