#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
    void print(unordered_map<int, int> mp)
    {
        for (auto i : mp)
            cout << i.first << " -> " << i.second << endl;
        cout << endl;
    }

public:
    int countSubArray(vector<int> arr, int target)
    {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int preSum = 0, current = 0;

        for (auto i : arr)
        {
            preSum += i;

            int remove = preSum - target;

            current += mp[remove];

            mp[preSum]++;
        }
        return current;
    }
};

int main()
{
    vector<int> arr = {10, 2, -2, -20, 10};
    int target = -10;

    Solution s1;

    cout << "Answer : " << s1.countSubArray(arr, target) << endl;
    return 0;
}