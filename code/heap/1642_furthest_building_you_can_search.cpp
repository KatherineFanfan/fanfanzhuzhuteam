#include <numeric>  //accumulate()

class Solution {
public:
    // online，time: NlogL, space:logL
    // min heap
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i < n; ++i) {
            int delta = heights[i] - heights[i - 1];
            if (delta <= 0) continue;
            q.push(delta);
            if (q.size() <= ladders) continue;
            bricks -= q.top();
            q.pop();
            if (bricks < 0) return i - 1;
        }
        return n - 1;
    }

};
