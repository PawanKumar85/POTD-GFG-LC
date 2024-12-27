// Count pairs with given sum

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> arr, int target)
    {
        unordered_map<int, int> mp;
        int count = 0;

        for (auto i : arr)
        {
            int rem = target - i;

            if (mp.find(rem) != mp.end())
                count += mp[rem];

            mp[i]++;
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;

    Solution s;
    int ans = s.countPairs(arr,target);
    cout << ans;
    return 0;
}
