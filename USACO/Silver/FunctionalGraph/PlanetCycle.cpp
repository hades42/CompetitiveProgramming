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

vector<ll> dest(200005);
vector<bool> visited(200005);
vector<ll> pathLength(200005);
queue<ll> q;
ll step;

void dfs(ll u){
    q.push(u);
    if(visited[u]){
        step += pathLength[u];
        return;
    }
    visited[u] = true;
    step++;
    dfs(dest[u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> dest[i]; dest[i]--;
    }

    for(ll i = 0; i < n; i++){
        if(!visited[i]){
            step = 0;
            dfs(i);
            //cout << i << " " << step << endl;
            ll decrease = 1;
            while(!q.empty()){
                //cout << q.front() << " " << q.back() << endl;
                if(q.front() == q.back()){
                    decrease = 0;
                }
                //cout << step << endl;
                pathLength[q.front()] = step;
                //cout << q.front() << " " << pathLength[q.front()] << endl;
                step -= decrease;
                q.pop();
            }
            //cout << endl;
        }
    }

    for(ll i = 0; i < n; i++){
        cout << pathLength[i] << " ";
    }
}
