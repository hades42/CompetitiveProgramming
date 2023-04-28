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

string input;
set<char> st;
char mid;
vector<string> ans;

bool check(string temp){
    ll cnt = 0;
    bool midCheck = false;
    bool onlyCheck = true;
    for(ll i = 0; i < temp.size(); i++){
        if(!st.count(temp[i])){
            onlyCheck = false;
        }
        if(temp[i] == mid){
            midCheck = true;
        }
    }
    //cout << temp << " " << temp.size() << " " << midCheck << " " << onlyCheck << endl;
    if(temp.size() >= 4 && midCheck && onlyCheck){
        return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> input;
    mid = input[0];

    for(ll i = 0; i < input.size(); i++){
        st.insert(input[i]);
    }

    int n; cin >> n;

    for(ll i = 0; i < n; i++){
        string temp; cin >> temp;
        if(check(temp)){
            ans.push_back(temp);
        }
    }
    for(auto str : ans){
        cout << str << endl;
    }
}
