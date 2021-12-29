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
ll n, m, c; 
vector<ll> arr;

bool check(ll num){
    ll left = 0;
    ll right = 0;
    ll filled = 0;
    ll buses = 0;
    for(right = 0; right < n; right++){
        if(arr[right] - arr[left] <= num && filled < c){
            filled++;
        } else if(arr[right] - arr[left] > num){
            left = right;
            filled = 1;
            buses++;
        }
        if(filled == c){
            left = right + 1;
            filled = 0;
            buses++;
        }
    }
    if(filled > 0){
        buses++;
    }
    return buses <= m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("convention");
    cin >> n >> m >> c;
    arr.resize(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll left = 0; ll right = 1e9;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(check(mid)){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    cout << left << endl;
}
