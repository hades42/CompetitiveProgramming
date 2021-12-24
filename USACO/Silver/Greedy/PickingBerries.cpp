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
ll mod;

bool cmp(ll a, ll b){
    return (a % mod) > (b % mod);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("berries");
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    ll M = 0;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        M = max(M, arr[i]);
    }

    ll ans = 0;
    for(ll b = 1; b <= M; b++){
        ll full = 0;
        for(ll i = 0; i < n; i++){
            full += arr[i]/b;
        }
        if(full < k /2){
            break;
        }
        if(full >= k){
            ans = max(ans, b * k/2);
            continue;
        }

        mod = b;
        sort(arr.begin(), arr.end(), cmp);
        //print(arr);
        ll berries = b * (full - k/2);
        //cout << berries <<" " << b << " " << full << endl;
        for(ll i = 0; i < n && i + full < k; i++){
            berries += (arr[i] % b);
        }
        //cout << berries << endl;
        ans = max(ans, berries);
    }
    cout << ans << endl;
}
