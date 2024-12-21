// Book Allocation Problem

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool isPossible(vector<int> a, int k, int mid)
    {
        int student = 1;
        int pageCount = 0;

        for (int i = 0; i < a.size(); i++)
        {
            if ((pageCount + a[i]) <= mid)
                pageCount += a[i];
            else
            {
                student++;

                if (student > k || a[i] > mid)
                    return false;

                pageCount = a[i];
            }
        }
        return true;
    }

    int totalSum(vector<int> a)
    {
        int sum = 0;
        for (auto i : a)
            sum += i;
        return sum;
    }

public:
    int bookAllocation(vector<int> a, int k)
    {
        int start = 0;
        int end = totalSum(a);

        int ans = -1;

        while (start < end)
        {
            int mid = start + (mid - start) / 2;

            if (isPossible(a, k, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int m = 2;

    Solution s;
    cout << s.bookAllocation(a, m);
    return 0;
}