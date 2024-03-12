#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int> > grid2(rows, vector<int>(columns, 1));
        int count = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                if (grid[i][j]=='1' && grid2[i][j]==1) {
                    count++;
                    bfs(rows, columns, i, j, grid, grid2);
                }
            }
        }
        return count;
    }
    void bfs(int rows, int columns, int i, int j, vector<vector<char> >& grid, vector<vector<int> >& grid2) {
        grid2[i][j] = 0;
        queue<vector<int> > q;
        vector<int> vvv;
        vvv.push_back(i);
        vvv.push_back(j);
        q.push(vvv);
        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            // cout << v[0] << " " << v[1] << endl;
            // grid2[v[0]][v[1]] = 0;
            for (int k=max(v[0]-1, 0); k<=min(v[0]+1, rows-1); k++) {
                if (grid[k][v[1]]=='1' && grid2[k][v[1]]==1) {
                    grid2[k][v[1]] = 0;
                    vector<int> vvv;
                    vvv.push_back(k);
                    vvv.push_back(v[1]);
                    q.push(vvv);
                }
            }
            for (int m=max(v[1]-1, 0); m<=min(v[1]+1, columns-1); m++) {
                if (grid[v[0]][m]=='1' && grid2[v[0]][m]==1) {
                    grid2[v[0]][m] = 0;
                    vector<int> vvv;
                    vvv.push_back(v[0]);
                    vvv.push_back(m);
                    q.push(vvv);
                }
            }
        }
    }
};