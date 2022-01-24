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

int curr;
vector<ll> person
vector<bool> seen;
void dfs(i, vector<vector<int>>& statements){
   seen[i] = true; 
   for(int j = 0; j < statements[i].size; j++){
       if(!seen[j]){
           if(person[i] == 1){
                person[j] = statements[i][j];
                curr += person[j] == 1;
                dfs(j, statements);
           } else if(person[i] == 0){
                person[j] = statements[i][j];
                curr += person[j] == 1;
                dfs(j, statements);


           }
       }
   }
}
int maximumGood(vector<vector<int>>& statements) {
    person.resize(statements.size(), 2);
    for(int i = 0; i < statements.size(); i++){
        curr = 0;
        vector<bool> temp(statements.size());
        seen = temp;
        // Good person
        person[i] = 1;
        curr += 1;
        dfs(i, statements);

        curr = 0;
        vector<bool> temp2(statements.size());
        seen = temp2;
        person[i] = 0;
        dfs(i, statements);

        person[i] = 2; 
    } 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vector<int> test{11, 7, 2, 15};
    countElements(test);
}
