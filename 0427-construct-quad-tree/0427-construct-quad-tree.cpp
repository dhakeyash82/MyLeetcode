class Solution {
public:

    Node* construct(vector<vector<int>>& grid) {

        return solve(grid, 0, 0, grid.size());
    }

    Node* solve(vector<vector<int>>& grid,
                int r, int c, int n) {

        int value = grid[r][c];
        bool same = true;

        for (int i = r; i < r + n; i++) {
            for (int j = c; j < c + n; j++) {

                if (grid[i][j] != value) {
                    same = false;
                    break;
                }
            }

            if (!same)
                break;
        }

        if (same) {
            return new Node(value, true);
        }

        int half = n / 2;

        Node* root = new Node(true, false);

        root->topLeft =
            solve(grid, r, c, half);

        root->topRight =
            solve(grid, r, c + half, half);

        root->bottomLeft =
            solve(grid, r + half, c, half);

        root->bottomRight =
            solve(grid, r + half, c + half, half);

        return root;
    }
};
