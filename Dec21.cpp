#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void display(vector<vector<int>> a)
    {
        for (auto i : a)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
    }

    void rotateby90(vector<vector<int>> &a)
    {
        int n = a.size();

        // step : 1 Reverse
        for (int i = 0; i < n; i++)
        {
            reverse(a[i].begin(), a[i].end());
        }

        // step : 2 Transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
                swap(a[i][j], a[j][i]);
        }
    }
};

int main()
{
    vector<vector<int>> a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    Solution s;
    s.display(a);
    s.rotateby90(a);
    s.display(a);
    return 0;
}