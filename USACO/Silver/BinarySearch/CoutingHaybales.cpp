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

ll n, q; 
vector<ll> arr;

ll firstTrue(ll left, ll right, ll num){
    while(left < right){
        ll mid = left + (right - left)/2;
        if(arr[mid] > num){
            right = mid;
        } else{
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("haybales");
    cin >> n >> q;
    arr.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    //print(arr);
    for(ll i = 0; i < q; i++){
        ll a, b; cin >> a >> b;
        //cout << upper_bound(arr.begin(), arr.end(), b) - lower_bound(arr.begin(), arr.end(), a) << endl;
        cout << firstTrue(0, n, b) - firstTrue(0, n, a - 1) << endl;
    }
}
