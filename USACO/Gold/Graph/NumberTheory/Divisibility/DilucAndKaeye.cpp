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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    ll n; cin >> n;
    string input; cin >> input;
    map<pr, ll> mp;
    ll d = 0;
    ll k = 0;
    for(ll i = 0; i < n; i++){
        if(input[i] == 'D') d++;
        else k++;
        ll g = gcd(d, k);
        ll vd = d / g;
        ll vk = k / g;
        pr temp = make_pair(vd, vk);
        mp[temp]++;
        cout << mp[temp] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
