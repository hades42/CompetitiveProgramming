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

bool good(double num){
    ll s = 0;
    for(ll i = 0; i < arr.size(); i++){
        s += floor(arr[i]/num);
    }
    return s >= k;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    arr.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    double left = 0; 
    double right = 1e8;
    for(ll i = 0; i <= 100; i++){
        double mid = (left + right)/2;
        if(good(mid)){
            left = mid;
        } else{
            right = mid;
        }
    }
    cout << setprecision(20) << left << endl;
}
