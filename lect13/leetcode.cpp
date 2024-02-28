//https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> explorekeys;
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        explorekeys.push(0);
        int numvisited = 1;
        while(!explorekeys.empty()){
            int u = explorekeys.front();
            for(auto e : rooms[u]){
                if(!visited[e]){
                    visited[e] = true;
                    numvisited++;
                    explorekeys.push(e);
                }
            }
            explorekeys.pop();
        }

        return numvisited == rooms.size();
        
    }
};