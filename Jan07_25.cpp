#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPair(vector<int> &arr, int &target)
    {
        int start = 0;
        int end = arr.size() - 1;
        int count = 0;

        while (start < end)
        {
            int sum = arr[start] + arr[end];

            if (sum == target)
            {
                count++;

                int left = start + 1;
                while (left < end && arr[left] == arr[start])
                {
                    count++;
                    left++;
                }
                int right = end - 1;
                while (right > start && arr[right] == arr[end])
                {
                    count++;
                    right--;
                }
                start++;
                end--;
            }
            else if (start < target)
                start++;
            else
                end--;
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {-1, 1, 5, 5, 7};
    int target = 6;

    Solution s1;
    cout << s1.countPair(arr,target) << endl;
    return 0;
}