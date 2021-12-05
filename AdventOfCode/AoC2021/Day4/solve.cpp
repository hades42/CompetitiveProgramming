#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
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

void read_stdin(vector<vector<string>> &buffer) {
  string line;
  while (getline(cin, line)) {
    vector<string> temp;
    stringstream check1(line);
    string num;
    while (getline(check1, num, ' ')) {
      temp.push_back(num);
    }
    buffer.push_back(temp);
  }
}

vector<ll> bingo;

bool checkForBingo(vector<vector<ll>> arr) {
  // check for row
  for (ll i = 0; i < arr.size(); i++) {
    ll count = 0;
    for (ll j = 0; j < arr.size(); j++) {
      if (arr[i][j] == -1) {
        count++;
      }
    }

    if (count == 5) {
      return true;
    }
  }

  // check for column
  for (ll j = 0; j < arr.size(); j++) {
    ll count = 0;
    for (ll i = 0; i < arr.size(); i++) {
      if (arr[i][j] == -1) {
        count++;
      };
    }
    if (count == 5) {
      return true;
    }
  }

  return false;
}

ll sumOfBoard(vector<vector<ll>> board) {
  ll sum = 0;
  for (ll i = 0; i < board.size(); i++) {
    for (ll j = 0; j < board.size(); j++) {
      if (board[i][j] != -1) {
        sum += (board[i][j]);
      }
    }
  }
  return sum;
}

int main() {
  string input;
  cin >> input;
  stringstream check1(input);
  string num;
  while (getline(check1, num, ',')) {
    bingo.push_back(stoll(num));
  }

  vector<pair<ll, ll>> board;
  vector<vector<ll>> arr;
  ll qty;
  cin >> qty;
  for (ll i = 0; i < qty * 5; i++) {
    vector<ll> temp;
    for (ll i = 0; i < 5; i++) {
      ll val;
      cin >> val;
      temp.push_back(val);
    }
    arr.push_back(temp);
  }

  for (ll i = 0; i < arr.size() - 4; i += 5) {
    map<ll, pair<ll, ll>> check;
    vector<vector<ll>> mapForBingo(5, vector<ll>(5));
    for (ll j = i; j < i + 5; j++) {
      for (ll z = 0; z < 5; z++) {
        check[arr[j][z]] = {j % 5, z % 5};
        mapForBingo[j % 5][z % 5] = arr[j][z];
      }
    }

    ll j;
    for (j = 0; j < bingo.size(); j++) {
      if (check.count(bingo[j])) {
        pr pos = check[bingo[j]];
        mapForBingo[pos.first][pos.second] = -1;
      }
      if (checkForBingo(mapForBingo)) {
        ll sum = sumOfBoard(mapForBingo);
        board.push_back({j, sum * bingo[j]});
        break;
      }
    }
  }

  sort(board.begin(), board.end());
  for (auto pr : board) {
    cout << pr.first << " " << pr.second << endl;
  }
}
