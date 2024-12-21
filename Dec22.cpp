// Search in a Row-Column sorted matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void display(vector<vector<int>>& a)
    {
        for (auto i : a)
        {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }

public:
    void matSearch(vector<vector<int>>& a, int x, bool& ans) {
        display(a);
        
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] == x) {
                    ans = true;
                    return; // Exit function as the element is found
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> a = {
        {3, 30, 38}, {20, 52, 54}, {35, 60, 69}
    };
    int x = 63;
    bool ans = false;

    Solution s;
    s.matSearch(a, x, ans);
    cout << "Output : " << (ans ? "true" : "false"); 
    return 0;
}
