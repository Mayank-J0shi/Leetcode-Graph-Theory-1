class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc,int prevColor ,int newColor){
        if(sr<0 or sr>=image.size() or sc<0 or sc>=image[0].size() or image[sr][sc]!=prevColor){
            return ;
        }
        image[sr][sc]=newColor;
        solve(image,sr+1,sc,prevColor,newColor);
        solve(image,sr,sc+1,prevColor,newColor);
        solve(image,sr-1,sc,prevColor,newColor);
        solve(image,sr,sc-1,prevColor,newColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor){
            return image;
        }
        
        solve(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};