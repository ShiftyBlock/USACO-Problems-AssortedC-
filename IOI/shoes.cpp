#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
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
    long sum (int l, int r){
        return sum(l,r,0, 0, N);
    }
    long sum(int l, int r, int cur, int lx, int rx){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r) return arr[cur];
        int mid= (lx+rx)/2;
        return sum(l,r,2*cur+1, lx, mid)+sum(l,r,2*cur+2, mid, rx);
    }
};


int N;
map<int, set<int>> william_lin_is_a_hottie_and_gave_me_good_luck_on_this_problem_so_i_have_a_crush_on_him_ily_tmw;
long count_swaps(vector<int> arr){
	N=arr.size();
	for (int i = 0; i < N; ++i)
	{
		william_lin_is_a_hottie_and_gave_me_good_luck_on_this_problem_so_i_have_a_crush_on_him_ily_tmw[arr[i]].insert(i);
	}

	
	long total=0;
	segtree st= segtree(N);
    for (int i = 0; i < N; ++i)
    {
    	if(arr[i]==0) continue;
    	auto endpt=william_lin_is_a_hottie_and_gave_me_good_luck_on_this_problem_so_i_have_a_crush_on_him_ily_tmw[-arr[i]].lower_bound(i);
    	int end=*endpt; 
    	william_lin_is_a_hottie_and_gave_me_good_luck_on_this_problem_so_i_have_a_crush_on_him_ily_tmw[-arr[i]].erase(end);
    	//cout<<end<<endl;
    	st.update(end, 1);
    	int free= st.sum(i, end);
    	if(arr[i]<0) total--;
    	arr[i]=0;
    	arr[end]=0;
    	total+=end-i-free;
    }
    return total;
}

int main() {
    setIO("shoes", 1);
    
    cin>>N;
   	vector<int> arr; arr.assign(N*2,0);
    for (int i = 0; i < N*2; ++i)
    {cin>>arr[i]; }
    cout<<count_swaps(arr)<<endl;

    return 0;

}









