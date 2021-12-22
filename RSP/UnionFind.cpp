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
        print(e);
        return e[x] < 0 ? x : e[x] = get(e[x]);
    };

    ll size(ll x){
        return -e[get(x)];
    };

    bool unite(ll a, ll b){
        ll x = get(a); 
        ll y = get(b);
        cout << x << " " << y << endl;
        if(x == y) return false;
        if(e[x] > e[y]) swap(x, y); 
        e[x] += e[y]; e[y] = x;
        return true;
    };
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    DSU dsu(6);
    dsu.unite(3, 1);
    dsu.unite(3, 2);

    //dsu.unite(3, 4);
    //dsu.unite(4, 5);

    print(dsu.e);
}
