// Search in a sorted Matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    void searchMatrix(vector<vector<int>>&a,int target)
    {
        int rows = a.size();
        int cols = a[0].size();

        int start = 0;
        int end = rows * cols - 1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int row = mid / rows;
            int col = mid % cols;

            int value = a[row][col];

            cout << value << " ";
        }

    }
};

int main()
{
    vector<vector<int>> a = {
        {1, 5, 9},
        {14, 20, 21},
        {30, 34, 43}};

    int target = 14;

    Solution s;
    s.searchMatrix(a,target);
    return 0;
}