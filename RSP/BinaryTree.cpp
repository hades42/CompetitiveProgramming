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

struct Node{
    ll data;
    struct Node* left;
    struct Node* right;

    Node(ll val){
       data = val; 
       left = NULL;
       right = NULL;
    }
};

void travel(Node *node){
    if(node == NULL){
        return;
    }

    travel(node -> left);
    cout << node -> data << " ";
    travel(node -> right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    struct Node* root = new Node(1);
    
    struct Node* first = new Node(2);
    first -> left = new Node(4);
    first -> right = new Node(5);
   
    struct Node* second = new Node(3);
    second -> left = new Node(6); 

    root -> left = first;
    root -> right = second;

    /*
     *      1
     *    /   \
     *   2     3
     *  / \    / 
     * 4   5   6
     *
     * */

    travel(root);
}
