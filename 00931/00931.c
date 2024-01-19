#define MIN(A, B) (((A) < (B)) ? (A) : (B))

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    int sum[n][n];
    for (size_t i = 0; i < n; ++i)
        sum[0][i] = matrix[0][i];
    for (size_t row = 1; row < n; ++row) {
        for (size_t col = 0; col < n; ++col) {
            if (col == 0) {
                sum[row][0] = matrix[row][0] + MIN(sum[row - 1][0], sum[row - 1][1]);
            }
            else if (col == n - 1) {
                sum[row][n-1] = matrix[row][n-1] + MIN(sum[row - 1][n - 1], sum[row - 1][n - 2]);
            } else {
                sum[row][col] =
                    matrix[row][col] + MIN(sum[row - 1][col - 1], MIN(sum[row - 1][col], sum[row - 1][col + 1]));
            }
        }
    }
    int min = sum[n - 1][0];
    for (size_t i = 1; i < n; ++i)
        min = MIN(min, sum[n - 1][i]);

    return min;
}