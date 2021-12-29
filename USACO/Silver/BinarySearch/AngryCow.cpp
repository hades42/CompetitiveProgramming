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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("angry");
    cin >> n >> k;
    arr.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll left = 0;
    ll right = 1e9;
    while(left < right){
        ll mid = left + (right - left)/2;
        ll used = 0;
        ll last = 0;
        while(last < n){
            used++;
            ll curr = last+1;
            while(curr < n && arr[curr] - arr[last] <= 2*mid){
                curr++;
            }
            last = curr;
        }
        if(used <= k){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    cout << left << endl;
}
