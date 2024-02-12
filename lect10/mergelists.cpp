// leetcode problem: https://leetcode.com/problems/merge-similar-items/

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, 
                                          vector<vector<int>>& items2) {
        vector<vector<int>> result;
        map<int, int> items;
        for(auto e : items1){
            items[e[0]] = e[1];
        }
        for(auto e : items2){
            auto it = items.find(e[0]);
            if(it != items.end()){
                items[e[0]] += e[1]; // + (*it).second;
            }else{
                items[e[0]] = e[1];
            }
        }

        for(auto e : items){
            result.push_back(vector<int> {e.first, e.second});
        }
        return result;

    }
};