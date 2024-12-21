#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthMissing(vector<int> a, int k)
    {
        int start = 0;
        int end = a.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int missing = a[mid] - (mid + 1);

            if (missing >= k)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start + k;
    }
};

int main()
{
    vector<int> a = {2, 3, 4, 7, 11};
    int k = 5;
    Solution s;
    cout << s.kthMissing(a, k);
    return 0;
}
