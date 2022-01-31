/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, L, R; cin>>N>>L>>R;
        v<int> socksL, socksR;
        for(int i=0; i<L; i++){
            int color;cin>>color;
            socksL.push_back(color);
        }
        for(int i=0; i<R; i++){
            int color;cin>>color;
            socksR.push_back(color);
        }
        sort(socksL.begin(), socksL.end());
        sort(socksR.begin(), socksR.end());
        int matches=0;
        int i=0;
        int j=0;
        v<int> tempL, tempR;
        while(i<L){
            if(j==R) break;
            if(socksL[i] == socksR[j]){
                j++; matches++;
                i++;
                continue;
            }
            if(socksL[i] < socksR[j]){
                tempL.push_back(socksL[i]);
                i++;
                continue;
            }
            if( socksL[i] > socksR[j] ){
                tempR.push_back(socksR[j]);
                j++;
            }
        }
        while(i<L) {
            tempL.push_back(socksL[i]);
            i++;
        }
        while(j<R) {
            tempR.push_back(socksR[j]);
            j++;
        }
        if(L==R){
            cout<<N/2-matches<<endl;
        }
        if(L<R){
            int nonpairs = 0;
            int pairs = 0;
            for(int k=0; k<tempR.size()-1; k++){
                if(tempR[k] == tempR[k+1]){
                    pairs++;
                    k++;
                }
                else nonpairs++;
            }
            int colorL = tempL.size();
            nonpairs -= colorL;
            int ans = 0;
            ans+=max(0, min(N/2-L, nonpairs)) + N/2-L + L-matches;
            cout<<ans<<endl;
        }
        if(L>R){
            int nonpairs = 0;
            int pairs = 0;
            for(int k=0; k<tempL.size()-1; k++){
                if(tempL[k] == tempL[k+1]){
                    pairs++;
                    k++;
                }
                else nonpairs++;
            }
            int colorR = tempR.size();
            nonpairs -= colorR;
            int ans = 0;
            ans+=max(0, min(N/2-R, nonpairs)) + N/2-R + R-matches;
            cout<<ans<<endl;
        }


    }
    return 0;
}

