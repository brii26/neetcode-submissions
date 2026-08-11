class Solution {
public:

    // O(RxC)
    void dfsMark(vector<vector<char>>& grid, int r, int c) {
        if (grid[r][c]!= '1') return;
        grid[r][c] = '0';
        int r_max = grid.size();
        int c_max = grid[0].size();
        
        //prev row
        if (r>0) dfsMark(grid,r-1,c);
        //next row
        if (r<r_max-1) dfsMark(grid,r+1,c);
        //prev col
        if (c>0) dfsMark(grid,r,c-1);
        //next col
        if (c<c_max-1) dfsMark(grid,r,c+1);
    }

    // O(RxC)
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int col = grid[0].size();
        int row = grid.size();

        for (int r = 0 ; r < row ; r++) {
            for (int c = 0 ; c < col; c++) {
                if (grid[r][c] == '1') {
                    dfsMark(grid,r,c);
                    count++;
                }
            }
        }
        
        return count;
    }
};
