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

#define HOOF 0
#define SCISSOR 2
#define PAPER 1 

ll n, k;
const ll maxv = 1e7;
vector<ll> arr(maxv);

ll addOne(ll a, ll b){
    if(a == HOOF && arr[b] == SCISSOR){
        return 1;
    } else if(a == SCISSOR && arr[b] == PAPER){
        return 1;
    } else if(a == PAPER && arr[b] == HOOF){
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("hps");
    cin >> n >> k;
    for(ll i = 1; i < n+1; i++){
        char a; cin >> a;
        if(a == 'P'){
            arr[i] = PAPER;
        } else if(a == 'H'){
            arr[i] = HOOF;
        } else{
            arr[i] = SCISSOR;
        }
    }

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 2, vector<ll>(3, 0)));
    ll ans = 0;

    for(ll i = 1; i < n + 1; i++){
        for(ll j = 1; j < k + 2; j++){
            ll add = addOne(HOOF, i);
            dp[i][j][HOOF] = max(dp[i-1][j][HOOF] + add, max(dp[i-1][j-1][PAPER] + add, dp[i-1][j-1][SCISSOR] + add));

            add = addOne(PAPER, i);
            dp[i][j][PAPER] = max(dp[i-1][j][PAPER] + add, max(dp[i-1][j-1][HOOF] + add, dp[i-1][j-1][SCISSOR] + add));

            add = addOne(SCISSOR, i);
            dp[i][j][SCISSOR] = max(dp[i-1][j][SCISSOR] + add, max(dp[i-1][j-1][HOOF] + add, dp[i-1][j-1][PAPER] + add));

            if(i == n){
                ans = max(ans, max(dp[i][j][HOOF], max(dp[i][j][SCISSOR], dp[i][j][PAPER])));
            }
        }
    }

    cout << ans << endl;
}
