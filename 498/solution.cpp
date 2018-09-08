class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        // 初始遍历方向为右上方
        int row = matrix.size(), col = matrix[0].size();
        int sum = 0, x = 0, y = 0, dx = -1, dy = 1;

        while (x < row && y < col) {
            result.push_back(matrix[x][y]);
            x += dx;
            y += dy;
            if (x < 0 || y < 0 || x >= row || y >= col) {
                ++sum;
                if (x < 0) {
                    if (y < 0) {
                        // 这种情况不会发生
                    } else if (y >= col) {
                        // 遍历接触到右侧边界线
                        x += 2;
                        y = col - 1;
                    } else {
                        // 遍历接触到上侧边界线
                        x = 0;
                    }
                } else if (x >= row) {
                    x = row - 1;
                    if (y < 0) {
                        // 遍历接触到下侧边界线
                        y += 2;
                    } else if (y >= col) {
                        // this condition won't happen
                    } else {
                        // 遍历接触到下侧边界线
                        y += 2;
                    }
                } else {
                    if (y < 0) {
                        // 遍历接触到左侧边界线
                        y = 0;
                    } else if (y >= col) {
                        // 遍历接触到右侧边界线
                        y = col - 1;
                        x += 2;
                    }
                }

                // 根据奇偶性确定下一次的遍历方向
                if (sum % 2 == 1) {
                    dx = 1;
                    dy = -1;
                } else {
                    dx = -1;
                    dy = 1;
                }

            }
        }
        return result;
    }
};