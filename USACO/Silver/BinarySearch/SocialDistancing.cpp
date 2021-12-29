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

vector<pr> arr;
ll n,m; 

bool check(ll D){
    ll c = 1;
    ll curr = arr[0].first;
    for(ll i = 0; i < m; i++){
        if(curr + D <= arr[i].first){
            curr = arr[i].first;
            c++;
        }
        while(curr + D >= arr[i].first && curr + D <= arr[i].second){
            curr = curr + D;
            c++;
        }
    }
    // This mean that there is more cow than normal (the D is too small)
    return c >= n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("socdist");
    cin >> n >> m;
    arr.resize(m); 
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        arr[i] = {a,b};
    }
    sort(arr.begin(), arr.end());
    ll left = 0;
    ll right = arr[m-1].second;
    while(left < right){
        ll mid = left + (right - left + 1)/2;
        if(check(mid)){
            left = mid;
        } else{
            right = mid - 1; 
        }
    }
    cout << left << endl;
}
