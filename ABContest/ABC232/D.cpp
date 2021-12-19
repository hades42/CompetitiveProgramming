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

ll H, W;
vector<vector<ll>> dist(105, vector<ll>(105));
vector<vector<bool>> visited(105, vector<bool>(105));
vector<ll> dx{0, 1};
vector<ll> dy{1, 0};
vector<string> input;

bool valid(ll x, ll y){
    return x >= 0 && x < H && y >= 0 && y < W && input[x][y] != '#';
}
ll res = 0;
// x is row
// y is column
void move(ll x, ll y){
    //cout << dist[x][y] << endl;
    queue<pr> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        //cout << "Ahihi" << endl;
        auto curr = q.front();
        q.pop();
        for(ll i = 0; i < 2; i++){
            ll moveX = curr.first + dx[i];
            ll moveY = curr.second + dy[i];
            //cout << moveX << " " << moveY << endl;
            if(valid(moveX, moveY)){
                //cout << moveX << " " << moveY << endl;
                if(visited[moveX][moveY]) continue;
                visited[moveX][moveY] = true;
                dist[moveX][moveY] = dist[curr.first][curr.second] + 1;
                res = max(dist[moveX][moveY], res);
                q.push({moveX, moveY});
            }
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> H >> W;
    for(ll i = 0; i < H; i++){
        string s; cin >> s;
        input.push_back(s); 
    }
    //dist[0][0] = 1; 
    move(0, 0);
    //ll ans = 0;
    //for(ll i = 0; i < H; i++){
        //for(ll j = 0; j < W; j++){
            //cout << dist[i][j] << " ";
            //ans  = max(ans, dist[i][j]);
        //}
        //cout << endl;
    //}
    //cout << ans << endl;
    cout << res + 1 << endl;
}
