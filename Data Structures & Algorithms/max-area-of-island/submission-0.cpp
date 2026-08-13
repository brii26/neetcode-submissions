class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int max_i = grid.size();
        int max_j = grid[0].size();
        if (i<0 || j<0 || i>=max_i || j>=max_j) return 0;
        if (grid[i][j]==1) {
            grid[i][j]=0;
            return 1 + dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1);
        }
        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int max_area = 0;
        // O(rowxcol) time complexity
        // O(rowxcol) space for matrix 
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col ;j++) {
                if (grid[i][j]==1) {
                    int max_temp = dfs(grid,i,j);
                    max_area = (max_area < max_temp) ? max_temp : max_area;
                }
            }
        }
        return max_area;
    }
};
