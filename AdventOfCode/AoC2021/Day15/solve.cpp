#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
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

struct Node{
    pair<ll,ll> pos;
    ll val;

    //Node(pr init, ll val): pos(init), val(val){};
};

vector<string> arr;
vector<vector<ll>> dist;
vector<vector<bool>> visited;
vector<vector<ll>> wholeMap;
vector<ll> dC{-1, 1, 0 , 0};
vector<ll> dR{0, 0, -1, 1};

bool isValid(ll x, ll y){
    return x >= 0 && y >= 0 && x < dist.size() && y < dist[0].size();
}
struct compare{
  public:
  bool operator()(Node &a,Node &b)  
  {
      return a.val < b.val; 
   }
};

// i : Row
// j : Column
void bfs(ll i, ll j){
    priority_queue<Node, vector<Node>, compare> q;
    dist[i][j] = wholeMap[i][j];
    q.push({{i,j}, wholeMap[i][j]});
    while(!q.empty()){
        // Row
        ll x = q.top().pos.first;
        // Column
        ll y = q.top().pos.second;
        q.pop();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        for(ll dir = 0; dir < 4; dir++){
            ll nextX = x + dR[dir];
            ll nextY = y + dC[dir];
            if(isValid(nextX, nextY)){
                if(wholeMap[nextX][nextY] + dist[x][y] < dist[nextX][nextY]){
                    dist[nextX][nextY] = wholeMap[nextX][nextY] + dist[x][y]; 
                    q.push({{nextX, nextY},-dist[nextX][nextY]});
                }
            }
        }
    }
}

int main() {
    string line;
    while(getline(cin, line)){
        arr.push_back(line);
    }
    dist.resize(arr.size()*5);
    visited.resize(arr.size()*5);
    wholeMap.resize(arr.size()*5);
    for(ll i = 0; i < arr.size()*5; i++){
        vector<ll> temp(arr[0].size()*5, INF);
        vector<bool> temp2(arr[0].size()*5, false);
        vector<ll> temp3(arr[0].size()*5, 0);
        dist[i] = temp;
        visited[i] = temp2;
        wholeMap[i] = temp3;
    }
    // Construct the first field
    for(ll i = 0; i < arr.size(); i++){
        for(ll j = 0; j < arr[i].size(); j++){
            //cout << wholeMap[i][j] << endl;
            wholeMap[i][j] = arr[i][j] - '0';
        }
    }

    ll bigRow = arr.size() * 5;
    ll bigColumn = arr[0].size()*5;
    ll stepRow = arr.size();
    ll stepColumn = arr[0].size();

    // Filling the first row 
    for(ll step = stepColumn; step < bigColumn; step += stepColumn){
        for(ll i = 0; i < arr.size(); i++){
            for(ll j = step; j < step + arr[0].size(); j++){
                if(wholeMap[i][j - stepColumn] == 9){
                    wholeMap[i][j] = 1;
                } else{
                    wholeMap[i][j] = wholeMap[i][j - stepColumn] + 1;
                }
            }
        }
    }

    // Filling the first column 
    for(ll step = stepRow; step < bigRow; step += stepRow){
        for(ll i = step; i < step + arr.size(); i++){
            for(ll j = 0; j < arr[0].size(); j++){
                if(wholeMap[i - stepRow][j] == 9){
                    wholeMap[i][j] = 1;
                } else{
                    wholeMap[i][j] = wholeMap[i - stepRow][j] + 1;
                }
            }
        }
    }
    
    for(ll goDown = stepRow; goDown < bigRow; goDown += stepRow){
        for(ll goRight = stepColumn; goRight < bigColumn; goRight += stepColumn){
            for(ll i = goDown; i < goDown + stepRow; i++){
                for(ll j = goRight; j < goRight + stepColumn; j++){
                    if(wholeMap[i][j - stepColumn] == 9){
                        wholeMap[i][j] = 1;
                    } else{
                        wholeMap[i][j] = wholeMap[i][j - stepColumn] + 1;
                    }
                }
            }
        }
    }

    bfs(0,0);
    cout << dist[bigRow - 1][bigColumn - 1] - dist[0][0] << endl;
}
