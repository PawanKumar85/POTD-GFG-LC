//  Unique Length-3 Palindromic Subsequences

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void print(unordered_set<char> ch)
    {
        cout << ch.size() << endl;
        for (auto i : ch)
            cout << i << " ";
        cout << endl;
    }

public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> first(26, INT_MAX);
        vector<int> last(26, INT_MIN);

        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = max(last[x], i);
            // cout << "Character: " << s[i] << ", Index: " << x << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (first[i] == INT_MAX || last[i] == INT_MIN)
            {
                // cout << "Continue" << endl;
                continue;
            }

            unordered_set<char> ch;

            for (int j = first[i] + 1; j < last[i]; j++)
            {
                // cout << "Insert" << endl;
                ch.insert(s[j]);
            }

            // print(ch);
            result += ch.size();
            // cout << "Result : " << result << endl;
        }
        return result;
    }
};

int main()
{
    string s = "aabca";
    Solution s1;
    cout << "Result : " << s1.countPalindromicSubsequence(s) << endl;
    return 0;
}