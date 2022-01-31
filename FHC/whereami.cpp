#include "bits/stdc++.h"

using namespace std;
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
}
int main()
{
    setIO("whereami", 1);
    int n;
    string str;
    cin>>n>>str;
    set<string> sequence;


    for (int i = 1; i < n; i++)
    {
        bool failed = false;
        for(int j=0; j<n-i+1; j++){
            //start a string from j with length i
            string newStr = str.substr(j, i);
            if(sequence.find(newStr) != sequence.end()) failed=true;
            sequence.insert(newStr);
        }
        if (!failed)
        {
            cout << i << endl;
            return 1;
        }
    }
}