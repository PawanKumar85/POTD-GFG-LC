#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int subArrayXor(vector<int> &arr, int &k)
    {
        long x = 0, result = 0;
        map<int, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {

            x = x ^ arr[i];

            result += mp[x ^ k];

            if (x == k)
            {
                result++;
            }

            mp[x]++;
        }

        return result;

        // result = 4
        // x = 2
        // k = 6

        // mp[0] = 0
        // mp[2] = 1
        // mp[4] = 2
        // mp[6] = 2
    }
};
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    Solution s1;
    cout << "Result : " << s1.subArrayXor(a, k) << endl;
    return 0;
}