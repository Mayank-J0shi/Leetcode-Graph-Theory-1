class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector <bool> vis(n,false);
        vis[0]=true;
        queue <int> q;
        q.push(0);
        while(!q.empty()){
           int t=q.front();
           // res.push_back(t);
           q.pop();
           for(auto it: rooms[t]){
               if(!vis[it]){
                   vis[it]=true;
                   q.push(it);
               }
           }
       }
       
       for(bool flag : vis){
           if(flag==false)
               return false;
       }
        return true;
    }
    
};