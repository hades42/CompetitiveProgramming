#include <bits/stdc++.h>
//#include <iostream>
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

ll attribute;

bool comp(vector<string> a, vector<string> b){
    return a[attribute] < b[attribute];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    string s, t; 
    getline(cin, s);
    stringstream x(s);

    vector<string> split;
    while(getline(x, t, ' ')){
        split.push_back(t);
    }

    ll n; cin >> n;
    vector<vector<string>> arr;
    for(ll i = 0; i < n; i++){
        vector<string> temp;
        for(ll i = 0; i < split.size(); i++){
            string attr; cin >> attr;
            temp.push_back(attr);
        }
        arr.push_back(temp);
    }
    ll q; cin >> q;
    while(q--){
        string command; cin >> command;
        attribute = find(split.begin(), split.end(), command) - split.begin();

        stable_sort(arr.begin(), arr.end(), comp);

        for(auto s : split){
            cout << s << " ";
        }
        cout << endl;

        for(auto music : arr){
            for(auto att : music){
                cout << att << " ";
            }
            cout << endl;
        }
        if(q >= 1){
            cout << endl;
        }
    }
}
