#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<"   "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<"   "<<#y<<" "<<y<<"   "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define sz(x)	(ll)x.size()
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
#define flush fflush(stdout);
//#define endl '\n'
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
//-------------------------------Template--Above-----------------------------------------------
void dfs(int node,bool visited[],vector<ll>adj[]){
    visited[node]=true;
    for(ll child:adj[node]){
        if(!visited[child])
            dfs(child,visited,adj);
    }
    return;
}
int main()
{
	boost
	ll n,m;cin>>n>>m;
	vector<ll>adj[n+1];
	bool visited[n+1];
	memset(visited,false,sizeof(visited));
	for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
	}
	ll count=0;vector<ll>ans;
	for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,visited,adj);
            count++;
           // debug2(i,count)
            ans.pb(i);
        }
	}
	cout<<count-1<<endl;
	if(count-1>0){
        ll l=ans.size();
     for(ll i=1;i<l;i++){
        cout<<ans[0]<<" "<<ans[i]<<endl;
     }
	}
	return 0;
}
