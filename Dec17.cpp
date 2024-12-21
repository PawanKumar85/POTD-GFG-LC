#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> a,int k,int mid)
{
    int cows = 1,lastCount = a[0];
    for(int i = 1; i < a.size();i++)
    {
        if((a[i] - lastCount) >= mid)
        {
            cows++;
            lastCount = a[i];
        }
        if(cows == k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> a,int k)
{
    int n = a.size();
    sort(a.begin(),a.end());
    int start = 0;
    int mini = a[0],maxi = a[n - 1];
    int end = maxi - mini;
    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start)/2;

        if(isPossible(a,k,mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    vector<int> a = {10, 1, 2, 7, 5};
    int k = 3;
    
    int ans = aggressiveCows(a,k);
    cout << ans;
}