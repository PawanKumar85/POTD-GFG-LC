#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void print(vector<pair<int, int>> arr)
    {
        cout << "All Pair : " << endl;
        for (auto i : arr)
            cout << i.first << " " << i.second << " = " << (i.first + i.second) << endl;
        cout << endl;
    }

public:
    vector<pair<int, int>> sumClosest(vector<int> arr, int target)
    {
        vector<pair<int, int>> ans;

        sort(begin(arr), end(arr));
        int start = 0;
        int end = arr.size() - 1;
        int diff = INT_MAX;

        // 0 < 2
        while (start < end)
        {
            int currentSum = arr[start] + arr[end];

            int currentDiff = abs(currentSum - target);

            if (currentDiff < diff)
            {
                diff = min(currentDiff, diff);
                ans.push_back({arr[start], arr[end]});
                print(ans);
            }

            if (currentSum < target)
                start++;
            else if (currentSum > target)
                end--;
            else
                break;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {10};
    int target = 10;

    Solution s1;
    vector<pair<int, int>> ans = s1.sumClosest(arr, target);

    int n = ans.size();
    if (n)
    {

        cout << "Output : " << endl;
        cout << ans[n - 1].first << " " << ans[n - 1].second << endl;
    }
    else
    {
        cout << "Empty" << endl;
    }

    return 0;
}
