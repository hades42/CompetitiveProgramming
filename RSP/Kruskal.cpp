#include <bits/stdc++.h>
#define ll long long

using namespace std;

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

struct DSU{
    vector<ll> e;
    DSU(ll N){
        e = vector<ll>(N, -1);
    } 
    ll get(ll x){
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool same_set(ll x, ll y){
        return get(x) == get(y);
    }
    ll size(ll x){
        return -e[get(x)];
    }
    bool unite(ll x, ll y){
        x = get(x);
        y = get(y);
        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y);
        e[x]+= e[y];
        e[y] = x;
        return true;
    }
};

ll cnt = 0;
template<class T> T kruskal(ll N, vector<pair<T, pr>> edge){
    sort(edge.begin(), edge.end());
    T ans = 0; DSU dsu(N+1); 
    for(auto &a : edge){
        if(dsu.unite(a.second.first, a.second.second)){
            ans += a.first;
            cnt++;
        }
    }
    return ans;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, m; cin >> n >> m;
    vector<pair<ll, pr>> road(m);
    for(ll i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        road[i] = {c, {a, b}};
    }
    ll ans = kruskal(n, road);
    if(cnt == n - 1){
        cout << ans << endl;
    } else{
        cout << "IMPOSSIBLE" << endl;
    }
}
