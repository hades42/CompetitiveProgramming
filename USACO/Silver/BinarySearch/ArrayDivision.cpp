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
ll n, k;
vector<ll> arr;

bool check(ll val){
    ll count = 1;
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        if(sum + arr[i] > val){
            sum = 0;
            count++;
        }
        sum += arr[i];
    }
    return count <= k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k; 
    arr.resize(n);
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    ll left = mx;
    ll right = 1e18;
    ll ans = 1e18;
    while(left < right){
        //cout << left << " " << right << endl;
        ll mid = left + (right - left)/2;
        if(check(mid)){
            ans = min(ans, mid);
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
}
