/*           1
         2       3
      4    5    6
      
      
      
4251063 
0124536
4526310

*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

void assignParent(Node *n, Node *parent) {
    n->parent = parent;
}

void nodeInit(Node *n, int data, Node *left, Node *right) {
    n->data = data;
    n->left = left;
    n->right = right;
    n->parent = NULL;
}

Node* lowestCommonAncestor(Node *n1, Node *n2) {
    int i;
    vector<Node*> path1, path2;
    
    while (n1 != NULL) {
        path1.push_back(n1);
        n1 = n1->parent;
    }
    while (n2 != NULL) {
        path2.push_back(n2);
        n2 = n2->parent;
    }
    
    for (i = 0; i < min(path1.size(), path2.size());) {
        if (path1[path1.size() - i - 1]->data == path2[path2.size() - i - 1]->data) {
            cout << path1[path1.size() - i - 1]->data << endl;
            i++;
        } else {
            break;
        }
    }
    return path1[path1.size() - i];
    
}

int main() {
   Node *r = new Node(), *rl = new Node(), *rr = new Node(), *rlr = new Node(), *rll = new Node(), *rrl = new Node();
    nodeInit(rrl, 6, NULL, NULL);
    nodeInit(rr, 5, rrl, NULL);
    nodeInit(rlr, 4, NULL, NULL);
    nodeInit(rll, 3, NULL, NULL);
    nodeInit(rl, 2, rll, rlr);
    nodeInit(r, 1, rl, rr);
    assignParent(rrl, rr);
    assignParent(rr, r);
    assignParent(rll, rl);
    assignParent(rlr, rl);
    assignParent(rl, r);


    cout << lowestCommonAncestor(rrl, rl)->data << endl;
    return 0;
}