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

ll n;
vector<ll> ticket;
ll x, a, y, b, k;

bool check(ll val){
    vector<ll> percent(val);
    for(ll i = a - 1; i < val; i += a){
        percent[i] += x;
    }
    for(ll i = b - 1; i < val; i += b){
        percent[i] += y;
    }
    //print(percent);
    sort(percent.begin(), percent.end(), greater<ll>());
    
    ll get = 0;
    for(ll i = 0; i < val; i++){
        get += percent[i] * ticket[i] / 100; 
    }
    return get >= k;
}

void solve(){
    ll n; cin >> n;
    ticket.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> ticket[i];
    }
    sort(ticket.begin(), ticket.end(), greater<ll>());
    cin >> x >> a >> y >> b >> k;
    ll left = 0; ll right = n; ll ans = -1;

    while(left < right){
        ll mid = left + (right - left)/2;
        if(check(mid)){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    if(check(left)){
        cout << left << endl;
    } else{
        cout << -1 << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll q; cin >> q;
    while(q--){
        solve();
    }
}
