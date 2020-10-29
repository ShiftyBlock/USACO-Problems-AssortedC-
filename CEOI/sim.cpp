#include <bits/stdc++.h>
using namespace std;
#define long long long
//im not playing memory games, my solution is correct so i dont care
void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
string pattern, full;
int pref[2000000][26];
int main() {
    setIO("sim", 0);
    cin >> patern>> full;

   	int dlen= pattern.length();
   	int alen= full.length();
   	int e = alen-dlen;
   	
   	for (int i = 1; i <= dlen; ++i)
   	{
   		for (int j = 0; j < 26; ++j)
   		{
   			pref[i][j]+=pref[i-1][j];
   			pref[i][j]+=  pattern[i-1]=='a'+j? 1:0;
   		}
   	}
   	long sum=0;
   	for (int i = 1; i <= alen; ++i)
   	{
   		int c= full[i-1]-'a';
   		

   		int cur= pref[min(i, dlen)][c];
   		int extra= pref[max(0, i-e-1)][c];
   		sum+=cur-extra;
   		//cout <<cur-extra<<endl;
   	}
   	cout <<sum<<endl;
   

    return 0;
}
