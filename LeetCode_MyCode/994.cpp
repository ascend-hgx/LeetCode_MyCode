#include "Solution.h"
#include "vector"
#include<queue>             // 使用queue需要，先入先出和vector相反

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int> > q;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) count++;
                if (grid[i][j] == 2) q.push(make_pair(i, j));
            }
        }
        if (q.size() == count) return 0;
        int res = 0;
        vector<pair<int, int> > directs = { {-1,0},{0,-1},{1,0},{0,1} };
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto t = q.front();
                q.pop();
                count--;
                for (auto direct : directs) {
                    int x = t.first + direct.first, y = t.second + direct.second;
                    if (x < 0 || y < 0 || x >= m || y >= n) continue;
                    if (grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    q.push(make_pair(x, y));
                }
            }
            res++;
        }
        return count == 0 ? res - 1 : -1;
    }
};
