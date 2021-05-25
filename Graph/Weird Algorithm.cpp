#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#define M 1000000007
#define ll long long int
#define pb push_back

#define pf push_front
#define all(x) x.begin(), x.end()
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

#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
//#define endl '\n'
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
typedef pair<int, int>		pii;
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
//-------------------------------Template--Above-----------------------------------------------
void solve(){
   ll n,m;cin>>n>>m;
   multiset<ll,greater<ll> >ms;
   for(ll i=0;i<n;i++){
    ll x;
    cin>>x;
    //debug1(x)
    ms.insert(x);
   }
   vector<ll>v(m);
   for(ll i=0;i<m;i++){
    cin>>v[i];
   // debug1(i)
   }
   vector<ll>ans;
   for(ll i=0;i<m;i++){
       // debug1(i)
     auto it=ms.lower_bound(v[i]);
     if(it==ms.end())
        ans.pb(-1);
     else{
        ans.pb(*it);
        ms.erase(ms.find(*it));
     }
   }
   for(ll i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;

}
int main()
{
    boost
    ll t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
