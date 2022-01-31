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

long MOD = 1e9+7;

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
long solve(int prefix, v<long> arr){
    v<long> a;
    for(int i=prefix; i<arr.size(); i++){
        a.push_back(arr[i]);
    }
    int N = a.size();

    long max_so_far = LONG_MIN, max_ending_here = 0,
            start =0, end = 0, s=0;
    for (int i=0; i< N; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    start+=prefix;
    end+=prefix;
    long minus = 0;
    long plus = 0;
    if(max_ending_here<0) end--;
    for(int i=0; i<prefix; i++){
        plus+=arr[i];
    }
    for(int i=prefix; i<start; i++){
        minus-=arr[i];
    }
    for(int i=start; i<=end; i++){
        plus+=arr[i];
    }
    for(int i=end+1; i<arr.size(); i++){
        minus-=arr[i];
    }
    return plus+minus;
}
void print(long prefix, v<long> arr){
    v<long> a;
    for(int i=prefix; i<arr.size(); i++){
        a.push_back(arr[i]);
    }
    int N = a.size();

    long max_so_far = LONG_MIN, max_ending_here = 0,
            start =0, end = 0, s=0;
    for (int i=0; i< N; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    start+=prefix;
    end+=prefix;
    if(max_so_far<0){
        cout<<prefix<<" "<<start<<" "<<end<<endl;
    }
    else cout<<prefix<<" "<<start<<" "<<end+1<<endl;
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<long> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr.push_back(num);
    }
    long best = -1e18;
    int idx = -1;
    for(int i=0; i<N; i++){
        long cur = solve(i,arr);
        if(cur>best){
            best = cur;
            idx = i;
        }
    }
    print(idx, arr);
    return 0;
}

