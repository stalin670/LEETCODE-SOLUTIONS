class Solution {
public:
    #define N 9

    bool isSafe(vector<vector<int>>&grid, int row, 
					int col, int num)
    {
        for (int x = 0; x <= 8; x++)
            if (grid[row][x] == num)
                return false;

        for (int x = 0; x <= 8; x++)
            if (grid[x][col] == num)
                return false;

        int startRow = row - row % 3, 
                startCol = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i + startRow][j + 
                                startCol] == num)
                    return false;

        return true;
    }

    bool solveSudoku1(vector<vector<int>>&grid, int row, int col)
    {

        if (row == N - 1 && col == N)
            return true;

        if (col == N) {
            row++;
            col = 0;
        }

        if (grid[row][col] > 0)
            return solveSudoku1(grid, row, col + 1);

        for (int num = 1; num <= N; num++) 
        {
            
            if (isSafe(grid, row, col, num)) 
            {
                grid[row][col] = num;
            
                if (solveSudoku1(grid, row, col + 1))
                    return true;
            }
        
            grid[row][col] = 0;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> grid(N,vector<int>(N));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]!='.'){
                    grid[i][j]=board[i][j]-'0';
                }
                else grid[i][j]=0;
            }
        }
        bool ok=solveSudoku1(grid,0,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='.'){
                    board[i][j]=grid[i][j]+'0';
                }
            }
        }
    }
};