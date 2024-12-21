#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void display2D(vector<vector<int>> &mat)
    {
        for (auto i : mat)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl
             << endl;
    }

    void display1D(vector<int> mat)
    {
        for (auto i : mat)
            cout << i << " ";
        cout << endl;
    }

    public : 
    void spirallyTraverse(vector<vector<int>> &mat)
    {
        display2D(mat);
        int row = mat.size();
        int col = mat[0].size();

        int top, down, left, right, dir, i;

        top = 0;
        down = row - 1;
        left = 0;
        right = col - 1;
        dir = 0;

        vector<int> res;

        while (top <= down && left <= right)
        {
            // top_left -> top_right
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                    res.push_back(mat[top][i]);
                top++;
            }

            // top_right -> down_right
            else if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                    res.push_back(mat[i][right]);
                right--;
            }

            // down_right -> down_left
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                    res.push_back(mat[down][i]);
                down--;
            }

            // down_left -> top_left
            else if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                    res.push_back(mat[i][left]);
                left++;
            }
            dir = (dir + 1) % 4;
        }
        display1D(res);
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    Solution s;
    s.spirallyTraverse(mat);
    return 0;
}