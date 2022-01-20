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
    ll a, n; cin >> a >> n;
    ll mx = 1000005;
    vector<ll> dist(mx, -1);
    queue<ll> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        ll curr = q.front(); q.pop();
        ll currDist = dist[curr];

        ll op1 = curr * a;
        if(op1 < mx && dist[op1] == -1){
            dist[op1] = currDist + 1;
            q.push(op1);
        }

        if(curr >= 10 && curr % 10 != 0){
            string conver = to_string(curr); 
            string temp = conver[conver.size() - 1] + conver; 
            temp.pop_back();
            ll newNum = stoll(temp);
            if(newNum < mx && dist[newNum] == -1){
                dist[newNum] = currDist + 1;
                q.push(newNum);
            }
        }
    }
    cout << dist[n] << endl;
}
