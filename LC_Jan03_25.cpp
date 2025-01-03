// 2270. Number of Ways to Split Array

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> arr)
    {
        int sum = 0, left = 0, result = 0;

        for (auto i : arr)
            sum += i;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            left += arr[i];
            if (left >= sum - left)
                result++;
        }
        return result;
    }
};

int main()
{
    vector<int> a = {10, 4, -8, 7};
    Solution s1;
    cout << s1.waysToSplitArray(a);
    return 0;
}