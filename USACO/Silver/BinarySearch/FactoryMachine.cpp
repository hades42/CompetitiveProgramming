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
ll n, t; 
vector<ll> arr;

bool check(ll time){
    ll make = 0; 
    for(ll i = 0; i < n; i++){
        make += time / arr[i];
        if(make >= t){
            return true;
        }
    }

    // This mean there is not enough time 
    return make >= t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> t;
    arr.resize(n);
    for(ll i =  0; i < n; i++){
        cin >> arr[i];
    }
    ll low = 1;
    ll high = 1e18;
    while(low < high){
        //cout << low << " " << high << endl;
        ll mid = low + (high - low) /2;
        if(check(mid)){
            high = mid; 
        }else{
            low = mid + 1;
        }
    }
    cout << low << endl;
}
