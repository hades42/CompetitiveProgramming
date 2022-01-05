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

struct PCL{
    ll r1, c1, r2, c2;
};

vector<vector<ll>> grid(21, vector<ll>(21));
vector<vector<bool>> visited(21, vector<bool>(21));
vector<PCL> pcl;
ll minR, maxR, minC, maxC;

map<ll, ll> color;

void floodfill(ll r, ll c, ll co){
    if(r < minR || r > maxR || c < minC || c > maxC || visited[r][c] || co != color[grid[r][c]]){
        return;
    }
    visited[r][c] = true;
    floodfill(r-1, c, co);
    floodfill(r+1, c, co);
    floodfill(r, c-1, co);
    floodfill(r, c+1, co);
}

bool check(ll r1, ll c1, ll r2, ll c2){
    // Check for only 2 colors inside the rect
    vector<bool> hasColor(27, 0);
    vector<ll> colorCount(2, 0);
    ll colors = 0;
    color.clear();
    
    for(ll i = r1; i <= r2; i++){
        for(ll j = c1; j <= c2; j++){
            if(!hasColor[grid[i][j]]){
                color[grid[i][j]] = colors;
                colors++;
                hasColor[grid[i][j]] = true;
            }
        }
    }

    if(colors != 2) {
        return false;
    }
    minR = r1; 
    maxR = r2;
    minC = c1;
    maxC = c2;

    for(ll i = 0; i <= 20; i++){
        for(ll j = 0; j <= 20; j++){
            visited[i][j] = false;
        }
    }
    // Check for contiguous block and multiple block
    for(ll i = r1; i <= r2; i++){
        for(ll j = c1; j <= c2; j++){
            if(!visited[i][j]){
                floodfill(i, j, color[grid[i][j]]);
                colorCount[color[grid[i][j]]]++;
            }
        }
    }

    if((colorCount[0] == 1 && colorCount[1] > 1) || (colorCount[1] == 1 && colorCount[0] > 1)){
        return true;
    } else{
        return false;
    }
}

bool is_subset(ll a, ll b){
    return (pcl[a].r1 >= pcl[b].r1) && (pcl[a].r2 <= pcl[b].r2) && (pcl[a].c1 >= pcl[b].c1) && (pcl[a].c2 <= pcl[b].c2);
}

bool optimalPCL(ll a){
    for(ll i = 0; i < pcl.size(); i++){
        if(i != a && is_subset(a, i)){
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("where");
    ll n; cin >> n;
    for(ll i = 0; i < n; i++){
        string input; cin >> input;
        for(ll j = 0; j < input.size(); j++){
            grid[i][j] = (input[j] - 'A' + 1);
        }
    }

    for(ll r1 = 0; r1 < n; r1++){
        for(ll c1 = 0; c1 < n; c1++){
            for(ll r2 = r1; r2 < n; r2++){
                for(ll c2 = c1; c2 < n; c2++){
                    if(check(r1, c1, r2, c2)){
                        pcl.push_back({r1, c1, r2, c2});
                    }
                }
            }
        }
    }

    ll totalPCL = 0;
    for(ll i = 0; i < pcl.size(); i++){
        if(optimalPCL(i)){
            totalPCL++;
        }
    }

    cout << totalPCL << endl;
}
