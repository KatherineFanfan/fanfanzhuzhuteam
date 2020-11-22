/*************************************************************************
# File Name: 1631_path_with_minimum_effort.cpp
# Author : Wenjing Fan  
# Email: fwjfan@ucdavis.edu
# Created Time: Sun Nov 22 02:55:59 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    // Dijstra算法  有权图中，顶点到其余各顶点的最短路径
    // 时间：o(ElogV) o(mnlogmn)
    // space: o(V)
    /*
    Dijkstra算法采用的是一种贪心的策略，声明一个数组dis来保存源点到各个顶点的最短距离和一个保存已经找到了最短路径的顶点的集合：T，初始时，原点 s 的路径权重被赋为 0 （dis[s] = 0）。若对于顶点 s 存在能直接到达的边（s,m），则把dis[m]设为w（s, m）,同时把所有其他（s不能直接到达的）顶点的路径长度设为无穷大。初始时，集合T只有顶点s。
然后，从dis数组选择最小值，则该值就是源点s到该值对应的顶点的最短路径，并且把该点加入到T中，OK，此时完成一个顶点，
然后，我们需要看看新加入的顶点是否可以到达其他顶点并且看看通过该顶点到达其他点的路径长度是否比源点直接到达短，如果是，那么就替换这些顶点在dis中的值。
然后，又从dis中找出最小值，重复上述动作，直到T中包含了图的所有顶点。
*/

    int minimumEffortPath(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return 0;
        int m = heights.size(), n = heights[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
        vector<int> dist(m * n, INT_MAX);
        dist[0] = 0;
        que.push({0, 0});
        while (!que.empty()) {
            vector<int> cur = que.top();
            que.pop();
            if (cur[1] == m * n - 1) {
                return cur[0];
            }
            int x = cur[1] / n;
            int y = cur[1] % n;
            for (int i = 0; i < 4; ++i) {
                int dx = x + dir[i];
                int dy = y + dir[i + 1];  // 新结点
                if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                int v = dx * n + dy;
                int diff = abs(heights[x][y] - heights[dx][dy]);
                if (dist[v] > max(dist[cur[1]], diff)) {
                    dist[v] = max(dist[cur[1]], diff);
                    que.push({dist[v], v});
                }
                
            }
        }
        return 0;
    }
};
