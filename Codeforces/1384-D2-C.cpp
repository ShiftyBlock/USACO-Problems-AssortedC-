/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<char, char>
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
//credits to secondthread
//reduce the problem into only distinct pairs of letters
// and then simulate
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        string a, b;
        cin>>a>>b;
        bool valid= true;
        for(int i=0; i<N; i++){
            if(b[i]< a[i]){
                cout<<-1<<endl;
                valid=false;
                break;
            }
        }
        if(!valid) continue;
        //answer is max distinct elements of A, distinct elements of B
        v<pii> arr;
        for(int i=0; i<N; i++) {
            if(a[i] == b[i]) continue;
            if (find(arr.begin(), arr.end(), make_pair(a[i], b[i])) == arr.end()) {
                arr.emplace_back(a[i], b[i]);
            }
        }
        sort(arr.begin(), arr.end());
        int moves = 0;

        while(true){
            if(arr.size() == 0) break;
            moves++;
            char curSmall = arr[0].first;
            int j=0;
            while(j<N){
                if(arr[j].first != curSmall) break;
                arr[j].first = arr[0].second;
                j++;
            }
            v<pii> temp;
            for(int i=0; i<arr.size(); i++){
                if(arr[i].first != arr[i].second){
                    if(find(temp.begin(), temp.end(), arr[i]) == temp.end()){
                        temp.emplace_back(arr[i]);
                    }
                }
            }
            arr = temp;
            sort(arr.begin(), arr.end());
        }
        cout<<moves<<endl;
    }
    return 0;
}

