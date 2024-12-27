// Two Sum - Pair with Given Sum

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool twoSum(vector<int> arr, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            int rem = target - arr[i];

            if (mp.find(rem) != mp.end())
                return true;
            mp[arr[i]] = i;
        }
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;

    Solution s;

    if (s.twoSum(arr, target))
        cout << "True";
    else
        cout << "False";
    return 0;
}