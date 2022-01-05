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
ll n; 
vector<string> arr;
vector<vector<bool>> visited;
vector<ll> dR{-1, 0, 0, 1};
vector<ll> dC{0, 1, -1, 0};

ll area = 0;
ll premeter = 0;

ll currA = 0;
ll currP = 0;

void search(ll r, ll c){
    if(r >= n || r < 0 || c >= n || c < 0){
        currP++;
        return;
    }
    
    if(visited[r][c]) return;
    if(arr[r][c] == '.'){
        currP++;
        return;
    }
    visited[r][c] = true;
    if(arr[r][c] == '#'){
        currA++;
    }

    for(ll i = 0; i < dR.size(); i++){
        search(r + dR[i], c + dC[i]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("perimeter");
    cin >> n;
    arr.resize(n);
    visited.resize(n, vector<bool>(n));
    for(ll i = 0; i < n; i++){
        string input; cin >> input;
        arr[i] = input;
    }
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(!visited[i][j] && arr[i][j] == '#'){
                search(i, j);
                if(area == currA){
                    premeter = min(currP, premeter);
                } else if(area < currA){
                    area = currA;
                    premeter = currP;
                }

                currA = currP = 0;
            }
        }
    }

    cout << area << " " << premeter << endl;
}
