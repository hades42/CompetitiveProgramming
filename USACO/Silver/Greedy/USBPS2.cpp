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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // a is only USB
    // b is only PS2
    // c is both
    ll a, b, c; cin >> a >> b >> c;
    ll m; cin >> m;
    vector<pair<ll, string>> arr(m);
    for(ll i = 0; i < m; i++){
        ll val; string name;
        cin >> val >> name;
        arr[i] = {val, name};
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    ll sum = 0;
    for(ll i = 0; i < m; i++){
        if(arr[i].second == "USB"){
            if(a > 0){
                a--;
                ans++;
                sum += arr[i].first;
            } else if(c > 0){
                c--;
                ans++;
                sum += arr[i].first;
            } 
        } else{
            if(b > 0){
                b--;
                ans++;
                sum += arr[i].first;
            } else if(c > 0){
                c--;
                ans++;
                sum += arr[i].first;
            } 
        }
    }
    cout << ans << " " << sum << endl;
}
