// KMP - String


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void constructLps(string pat, vector<int> &lps)
{
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                    lps[i] = 0;
                    i++;
            }
        }
    }
}

vector<int> search(string txt, string pat)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);

    // for(auto i : lps)
    //     cout << i << " ";

    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(txt[i] == pat[j]){
            i++;
            j++;

            if(j == m)
            {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else{
            if(j != 0)
                j = lps[j - 1];
            else   
                i++;
        }
    }
    return res;
}

int main()
{
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    // aabaacaadaabaaba
    // aaba

    vector<int> res = search(txt, pat);

    for(auto i : res)
        cout << i <<  " ";
    return 0;
}