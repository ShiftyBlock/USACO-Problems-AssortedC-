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

int main() {
    setIO("", 0);
    long N, K;
    cin >> N >> K;
    v<int> arr;
    map<long, int> m;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        m[num]++;
    }
    for (auto x:m) {
        arr.push_back(x.first);
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = (int) arr.size() - 1;
    while (i < j) {
        bool notwork = false;
        if (m[arr[j]] <= m[arr[i]]) {
            long diff = arr[j] - arr[j - 1];
            long t = m[arr[j]];
            if (K >= diff * t) {
                K -= diff * t;
                m[arr[j - 1]] += m[arr[j]];
                m[arr[j]] = 0;
                j--;
            } else {
                notwork = true;
            }

        }
        if(notwork || m[arr[j]] > m[arr[i]]){
            long diff = abs(arr[i] - arr[i + 1]);
            long t = m[arr[i]];
            if (K >= diff * t) {
                K -= diff * t;
            } else break;
            m[arr[i + 1]] += m[arr[i]];
            m[arr[i]] = 0;
            i++;
        }
    }
    if (K > 0 && i != j) {
        if (m[arr[i]] < m[arr[j]]) {
            long shift = arr[i] + K / m[arr[i]];
            if (shift != arr[i]) {
                m[shift] = m[arr[i]];
                m[arr[i]] = 0;
            }
        } else if (m[arr[i]] >= m[arr[j]]) {
            long shift = arr[j] - K / m[arr[j]];
            if (shift != arr[j]) {
                m[shift] = m[arr[j]];
                m[arr[j]] = 0;
            }
        }
    }
    long mi = 1 << 30;
    long ma = 0;
    for (auto x: m) {
        if (x.second > 0) {
            mi = min(mi, x.first);
            ma = max(ma, x.first);
        }
    }
    cout << ma - mi << endl;
    return 0;
}