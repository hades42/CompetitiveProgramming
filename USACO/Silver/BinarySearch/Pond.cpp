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

#define N 805

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, k; cin >> n >> k;
    vector<vector<ll>> arr(N, vector<ll>(N));
    vector<vector<ll>> sum(N, vector<ll>(N));
    for(ll i = 0; i < n; i++){
        sum[0][i] = 0;
        sum[i][0] = 0;
    }
    ll left = -1;
    ll right = INF;
    bool ext;
    ll limit = ((k*k)/2) + 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    // We binary search based on the median, and choosing the one with smalleset number before the value of median
    // inside the K*K
    while(left < right){
        ll mid = left + (right - left)/2;
        for(ll i = 0 ; i < n; i++){
            for(ll j = 0; j < n; j++){
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j];
                if(arr[i][j] > mid) sum[i+1][j+1]++;
            }
        }

         ext = false;
         for(ll i = 0; i < n - k + 1; i++){
             for(ll j = 0; j < n - k + 1; j++){
                 ll curr = sum[i+k][j+k] - sum[i][j+k] - sum[i+k][j] + sum[i][j];
                 if(curr < limit) ext = true;
             }
         }

         if(ext){
             right = mid;
         } else{
             left = mid + 1;
         }
    }
    cout << left << endl;
}
