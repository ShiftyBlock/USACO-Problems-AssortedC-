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
const int MAXN= 100001;
v<int> adj[MAXN];
int ti=0;
int in[MAXN], out[MAXN];
void dfs(int cur, int par){
	in[cur]=ti++;
	for(int next: adj[cur]){
		if(next==par) continue;
		dfs(next, cur);
	}
	out[cur]=ti++;
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
    setIO("promote", 1);

  	int N;
  	cin>>N;
  	v<pii> temp;
  	for (int i = 0; i < N; ++i)
  	{
  		int num; cin>>num;
  		temp.emplace_back(num, i);
  		/* code */
  	}
  	sort(temp.begin(), temp.end());
  	v<int> cost; cost.assign(N, 0);
  	//cor compress
  	for (int i = 0; i < N; ++i)
  	{
  		cost[temp[i].s]=i;
  	}
  	//dfs
  	for (int i = 1; i < N; ++i)
  	{
  		int par; cin>>par; par--;
  		adj[par].push_back(i); adj[i].push_back(par);
  	}
  	dfs(0,-1);
  	//init segtree
  	segtree st= segtree(2*N);
  	// process elements in descending order of cost
  	v<int> res; res.assign(N,0);
  	for (int i=N-1; i>=0; i--)
  	{
  		pii cur= temp[i];
  		int query= st.sum(in[cur.s], out[cur.s]);
  		st.update(in[cur.s], 1);
  		res[cur.s]=query;

  	}
  	for(int num:res) cout<<num<<endl;



    return 0;
}














