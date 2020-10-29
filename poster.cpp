#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)
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
struct segtree{
    int N;
    vector<long> arr;
    segtree(int n){
        N=n;
        arr.assign(4*N, 0LL);
    }
    void update(int i, int val){
        update(i, val, 0, 0, N);
    }
    void update(int i, int val, int cur, int lx, int rx){
        if(rx-lx==1){
            arr[cur]=val; return;
        }
        int mid= (lx+rx)/2;
        if(mid>i) update(i, val, 2*cur+1, lx, mid);
        else update(i, val, 2*cur+2, mid, rx);
        arr[cur]= arr[cur*2+1]+arr[cur*2+2];
    }
    long sum(int l, int r){
        return sum(l,r,0, 0, N);
    }
    long sum(int l, int r, int cur, int lx, int rx){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r) return arr[cur];
        int mid= (lx+rx)/2;
        return sum(l,r,2*cur+1, lx, mid)+sum(l,r,2*cur+2, mid, rx);
    }
};

int main() {
    setIO("", 0);

    int N;
    cin>>N;
    v<pii> arr;
    for (int i = 0; i < N; ++i)
    {
    	int a, b;
    	cin>>a>>b;
    	arr.emplace_back(b,i);
    }
    sort(arr.begin(), arr.end());
    segtree cow= segtree(N);
    int res=0;
    for (int i = 0; i < N;)
    {
    	int idx=i;
    	int j=i+1;
    	while(j<N && arr[i].f==arr[j].f){
    		int sum= cow.sum(arr[i].s, arr[j].s+1);
    		if(sum==0) {
    			res++;
    		}
    		i++;
    		j++; 
    	}
    	while(idx<j){
    		cow.update(arr[idx].s,1); idx++;
    	}
    	i=idx;
    }
    cout<<N-res<<endl;
    

    return 0;
}









