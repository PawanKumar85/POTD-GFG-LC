#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        vector<string> result;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && words[j].find(words[i]) != string::npos)
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }

    void print(vector<string> words)
    {
        for (auto i : words)
            cout << i << " ";
        cout << endl;
    }
};

int main()
{
    vector<string> words = {"mass", "as", "hero", "superhero"};
    Solution s1;

    vector<string> ans = s1.stringMatching(words);
    s1.print(ans);
    return 0;
}