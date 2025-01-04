#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void print(vector<int> arr)
    {
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
    }

public:
    int countTriplets(vector<int> &arr, int &target)
    {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++)
        {
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            {
                int sum = arr[i] + arr[start] + arr[end];

                if (sum < target)
                    start++;
                else if (sum > target)
                    end--;
                else
                {
                    count++;
                    int leftStart = start + 1;
                    while (leftStart < end && arr[leftStart] == arr[start])
                    {
                        count++;
                        leftStart++;
                    }
                    end--;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;
    Solution s1;
    cout << s1.countTriplets(arr, target) << endl;
    return 0;
}