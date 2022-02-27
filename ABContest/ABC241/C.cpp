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
    ll n; cin >> n;   
    vector<string> arr(n);
    for(ll i = 0; i < n; i++){
        string s; cin >> s;
        arr[i] = s;
    }
    bool flag = false;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            // Check for every column
            if(i + 5 < n){
                ll cnt = 0;
                for(ll k = 0; k < 6; k++){
                    if(arr[i+k][j] == '#') cnt++;
                }
                if(cnt >= 4) flag = true;
            }

            // Check for every row
            if(j + 5 < n){
                ll cnt = 0;
                for(ll k = 0; k < 6; k++){
                    if(arr[i][j + k] == '#') cnt++;
                }
                if(cnt >= 4) flag = true;
            }

            // check for diagnol from left to right
            if((i + 5) < n && (j + 5) < n){
                ll cnt = 0;
                for(ll k = 0; k < 6; k++){
                    if(arr[i+k][j+k] == '#') cnt++;
                }
                if(cnt >= 4) flag = true;
            }

            // Check for diagnol from right to left;
            if((i + 5) < n && (j - 5) >= 0){
                ll cnt = 0;
                for(ll k = 0; k < 6; k++){
                    if(arr[i+k][j - k]== '#') cnt++;
                }
                if(cnt >= 4) flag = true;
            }
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
