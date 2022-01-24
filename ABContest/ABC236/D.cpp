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

vector<vector<ll>> grid(20, vector<ll>(20));
vector<bool> used(20);
vector<pair<ll, ll>> vec;
ll n; 
ll res = 0;

void compute(){
    if(vec.size() == n){
        ll temp = 0;
        for(auto p : vec){
            temp ^= (grid[p.first][p.second]);
        }
        res = max(res, temp);
        return;
    }

    ll l;
    for(ll i = 1; i <= 2*n; i++){
        if(!used[i]){
            l = i;
            break;
        }
    }
    used[l] = true;

    for(ll i = 1; i <= 2*n; i++){
        if(!used[i]){
            vec.push_back({l, i});
            used[i] = true;
            compute();
            vec.pop_back();
            used[i] = false;
        }
    }

    used[l] = false;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    ll amount = (2*n) * (2*n - 1) / 2;
    cout << amount << endl;
    for(ll i = 1; i <= 2*n - 1; i++){
        for(ll j = i + 1; j <= n*2; j++){
            ll num; cin >> num;
            grid[i][j] = num;
        }
    }
    compute();
    cout << res << endl;
}
