// solution to leet code problem: https://leetcode.com/problems/daily-temperatures/
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures_0(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++){ // n times
            for(int j = i + 1; j < temperatures.size(); j++){ // n - i - 1
                if(temperatures[j] > temperatures[i]){
                    result[i] = j - i;
                    break;
                }
            }
        } 
        // Running time =  O(n^2)
        // More careful analyis:
        // T(n) = (n - 1 + n - 2 + n - 3 ...+ 3 + 2 + 1 ) * c
        //      = (n-1)* n / 2 = n^2/2 - n/2
        // T(n) = O(n^2) (worst case)
        return result;     
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> days; 
        days.push(temperatures.size() - 1);
        for (int i = temperatures.size() - 2; i >=0 ; i--){ 
            while(!days.empty() && 
                temperatures[i] >= temperatures[days.top()]){
                    days.pop();
            } 
            if(!days.empty()){
                result[i] = days.top() - i;
            }
            days.push(i);
        }
        return result;   
    }
};