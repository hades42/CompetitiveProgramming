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

int n;
int ans = 0;

bool valid(vector<vector<int>>& S, string curr){
    for(ll i = 0; i < n; i++){
        if(curr[i] == '1'){
            for(ll j = 0; j < n; j++){
                if(S[i][j] != 2 && S[i][j] != curr[j] - '0') return false;
            }
        }
    }
    return true;
}

void dfs(vector<vector<int>>& S, int i, int cnt, string curr){
    if(i == n){
        if(valid(S, curr)) ans = max(ans, cnt);
        return;
    }

    curr.append(1, '0'); // this is bad person
    dfs(S, i + 1, cnt, curr);
    curr.back() = '1'; // This is good person
    dfs(S, i + 1, cnt+1, curr);
    curr.pop_back();
}

int maximumGood(vector<vector<int>>& S) {
   n = S.size(); 
   string curr = "";
   dfs(S, 0, 0, curr);
   return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
