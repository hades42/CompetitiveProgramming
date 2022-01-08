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
    setIO("family");
    ll n;
    vector<string> c(3);
    cin >> n >> c[1] >> c[2];
    vector<map<string, int>> dist(3);
    dist[1][c[1]] = 0;
    dist[2][c[2]] = 0;

    map<string, string> edge;
    for(ll i = 0; i < n; i++){
        string u, v; cin >> u >> v;
        edge[v] = u;
    }

    for(ll i = 1; i <= 2; i++){
        // BFS on the directed tree know the distance from one cow to all their ancestor
        string curr = c[i];
        while(true){
            auto anc = edge.find(curr);
            if(anc != edge.end()){
                dist[i][anc-> second] = dist[i][curr] + 1;
                curr = anc -> second;
            } else break;
        }
    }

    string ancestor;
    ll d1 = 105; ll d2 = 105;
    // get the common ancestor with shortest path;
    for(auto& D1 : dist[1]){
        auto D2 = dist[2].find(D1.first);
        if(D2 != dist[2].end() && (d1 > D1.second || d2 > D2->second)){
            ancestor = D1.first;
            d1 = D1.second; 
            d2 = D2->second;
        }
    }

    if(ancestor.empty()){
        cout << "NOT RELATED" << endl;
    } else if(ancestor == c[1] || ancestor == c[2]){
        if(ancestor ==  c[1]){
            swap(c[1], c[2]);
            swap(d1, d2);
        }
        cout << c[2] << " is the ";
        if(d1 >= 2){
            for(ll i = 0; i < d1 - 2; i++) cout << "great-";
            cout << "grand-";
        }
        cout << "mother of" << c[1] << endl;
    } else{
        if(d2 < d1) {
            swap(d2, d1);
            swap(c[2], c[1]);
        }
        if(d1 == 1){
            if(d2 == 1){
                cout << "SIBLINGS" << endl;
            } else{
                cout << c[1] << " is the ";
                for(ll i = 0; i < d2 - 2; i++) cout << "great-";
                cout << "aunt of " << c[2] << endl; 
            }
        } else{
            cout << "COUSINS" << endl;
        }
    }
}
