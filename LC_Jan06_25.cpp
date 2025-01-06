#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> pos, ans;
        int len = boxes.size();

        for (int i = 0; i < len; i++)
            if (boxes[i] == '1')
                pos.push_back(i);

        for (int i = 0; i < len; i++)
        {
            int sum = 0;
            for (int idx : pos)
            {
                int dst = abs(i - idx);
                sum += dst;
            }
            ans.push_back(sum);
        }
        return ans;
    }

    void print(vector<int> arr)
    {
        for(auto i : arr)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    string boxes = "110";
    Solution sol;

    vector<int>ans = sol.minOperations(boxes);
    sol.print(ans);
    return 0;
}