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
    ll n, x; cin >> n >> x;
    vector<ll> arr(n);
    vector<ll> visited(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll i = 0; ll j = n - 1;
    ll ans = 0;
    while(i < j){
        ll left = arr[i];
        ll right = arr[j];
        if(left + right <= x){
            visited[i] = visited[j] = true;
            i++;
            j--;
            ans++;
        } else{
            j--;
        }
    }
    for(ll i = 0; i < n; i++){
        if(visited[i] == false){
            ans++;
        }
    }
    cout << ans << endl;
}
