#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;
const ll INF = 1e18;

template <typename T> void print(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}

template <typename T> void print2d(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n,m;
    cin >> n >> m;
    vector<ll> city(n);
    //vector<ll> tower(m);
    set<ll> tower;
    for(ll i = 0; i < n; i++){
        cin >> city[i];
    }
    for(ll i = 0; i < m; i++){
        ll num; cin >> num;
        tower.insert(num);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll dist = INF;
        auto closetTower = tower.lower_bound(city[i]);

        if(closetTower != tower.end()){
            dist = abs(city[i] - *closetTower);
        }
        if(closetTower != tower.begin()){
            closetTower--;
            dist = min(dist, abs(city[i] - *closetTower));
        }
        ans = max(ans, dist);
    }
    cout << ans << endl;
    //vector<ll> dist(1e5 + 5, INF);
    //ll c1 = 0;
    //for(ll i = 0; i < n; i++){
        //while(tower[c1+1] <= city[i] && c1 < m-1) c1++;
        //dist[i] = min(dist[i], abs(city[i] - tower[c1]));
    //}
    //c1 = m -1;
    //for(ll i = n - 1; i >= 0; i--){
        //while(c1 >= 0 && tower[c1 -1] >= city[i]){
            //c1--;
        //}
        //dist[i] = min(dist[i], abs(city[i] - tower[c1]));
    //}
    //ll ans = 0;
    //for(ll i = 0; i < n; i++){
        //ans = max(ans, dist[i]);
    //}
    //cout << ans << endl;
}
