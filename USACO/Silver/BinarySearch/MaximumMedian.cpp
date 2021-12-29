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

bool check(ll num){
    ll need = 0;
    for(ll i = (n-1)/2; i < n; i++){
        need += max((ll)0, num - arr[i]);
    }
    //cout << need << " " << k << endl;
    return need <= k;
}

// 
ll bs(ll left, ll right){
    left--;
    while(left < right){
        ll mid = left + (right - left + 1)/2;
        if(check(mid)){
            left = mid;
        } else{
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    arr.resize(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = bs(1, 2e9);
    cout << ans << endl;
}
