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
    };

    ll get(ll x){ 
        return e[x] < 0 ? x : e[x] = get(e[x]);
    };

    ll sameSet(ll a, ll b){
        return get(a) == get(b);
    }

    ll size(ll x){
        return -e[get(x)];
    };

    bool unite(ll a, ll b){
        ll x = get(a); 
        ll y = get(b);
        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y); 
        e[x] += e[y]; e[y] = x;
        return true;
    };
};

ll n, m;

struct Edge{
    ll a, b, w; 
};

vector<ll> pos(2e5);
vector<Edge> hole(2e5);

bool check(ll num){
    DSU dsu(n);
    for(ll i = 0; i < m; i++){
        if(hole[i].w >= num){
            dsu.unite(hole[i].a, hole[i].b);
        }
    }

    for(ll i = 1; i <= n; i++){
        if(!dsu.sameSet(pos[i], i)) return false;
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("wormsort");
    cin >> n >> m;
    
    for(ll i = 1; i <= n; i++){
        cin >> pos[i];
    }

    for(ll i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        hole[i] = {a, b, c};
    }

    ll left = 0;
    ll right = INF;
    ll ans = -1;
    while(left <= right){
        //cout << left << " " << right << endl;
        ll mid = left + (right - left)/2;
        if(check(mid)){
            ans = max(ans, mid);
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    } 

    if(ans == INF){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }
}
