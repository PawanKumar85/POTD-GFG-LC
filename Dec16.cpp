#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& a,vector<int>& b,int key)
{
    int n = b.size();

    for(int i = n - 1;i >= 0;i--)
    {
        a.push_back(b[i]);
        b.pop_back();
    }
    sort(begin(a), end(a));
    
    return a[key - 1];
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};

    cout << solve(a, b,5);
}