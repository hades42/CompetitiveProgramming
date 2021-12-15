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

vector<pr> dots;
vector<pair<string, ll>> fold;

int main() {
    ll n; cin >> n;
    ll struction; cin >> struction;
    ll mxX = 0;
    ll mxY = 0;
    for(ll i = 0; i < n; i++){
        string line; cin >> line;
        ll j;
        for(j = 0; j < line.size(); j++){
            if(line[j] == ','){
                break;
            }
        }
        ll x = stoll(line.substr(0, j));
        ll y = stoll(line.substr(j+1));
        //cout << x << " " << y << endl;
        mxX = max(x, mxX);
        mxY = max(y, mxY);
        dots.push_back({x, y});
    }
    for(ll i = 0; i < struction; i++){
        string line; cin >> line;
        ll j;
        for(j = 0; j < line.size(); j++){
            if(line[j] == '='){
                break;
            }
        }
        string di = line.substr(0,j);
        ll way = stoll(line.substr(j+1));
        fold.push_back({di, way});
        //cout << di << " " << way << endl;
    }

    vector<vector<char>> arr(20000, vector<char>(20000, '.'));
    for(ll i = 0; i < dots.size(); i++){
        arr[dots[i].second][dots[i].first] = '#';
    } 

    //print2d(arr);
    cout << endl;
    for(ll i = 0; i < fold.size(); i++){
        auto currFold = fold[i];
        if(fold[i].first == "x"){
            ll z = 0;
            for(ll j = 2* currFold.second; j > currFold.second; j--){
                for(ll h = 0; h <= mxX; h++){
                    //cout << h << " " << z << endl;
                    if(arr[h][z] == '.'){
                        arr[h][z] = arr[h][j]; 
                    }
                    arr[h][j] = '.';
                }
                z++;
            }
        } else{
            ll z = 0;
            for(ll j = 2* currFold.second; j > currFold.second; j--){
                for(ll h = 0; h <= mxX; h++){
                    if(arr[z][h] == '.'){
                        arr[z][h] = arr[j][h]; 
                    }
                    arr[j][h] = '.';
                }
                z++;
            }
        }
    }

    ll count = 0;
    for(ll i = 0; i <= mxY; i++){
        for(ll j = 0; j <= mxX; j++){
            if(arr[i][j] == '#'){
                count++;
            }
        }
    }
    //print2d(arr);
    for(ll i = 0; i <= 6; i++){
        for(ll j = 0; j <= 55; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << count << endl;
}
