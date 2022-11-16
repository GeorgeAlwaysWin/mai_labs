#include <bits//stdc++.h>
using namespace std;

struct tnode {
    int field=0;           // поле данных
    int deep=0;            // глубина узла
    struct tnode *parent=NULL;
    vector <tnode *> children;

};

void CountDepth(tnode *tree, vector<int> *depth){
    if (depth->size()<=tree->deep){
        depth->push_back(1);
    } else {
        ++(*depth)[tree->deep];
    }

    if (tree->children.empty()== false) {
        for (int i = 0; i < tree->children.size(); ++i) {
            CountDepth(tree->children[i], depth);
        }
    }
}

void CheckIncrease(tnode *tree) {
    vector<int> depth;
    CountDepth(tree, &depth);
    for (int i=1; i<depth.size(); ++i){
        if (depth[i]<=depth[i-1]){
            cout << "Not increasing\n";
            return;
        }
    }
    cout << "Increasing\n";
    return;
}

void AddNode(tnode *tree, int field){
    tnode *new_leaf = new tnode;
    new_leaf->parent=tree;
    new_leaf->deep=tree->deep+1;
    new_leaf->field=field;
    tree->children.push_back(new_leaf);
}

void DelNode(tnode *tree){
    if (tree->children.empty()== false) {
        for (int i = 0; i < tree->children.size(); ++i) {
            DelNode(tree->children[i]);
        }
    }
    tree->parent->children.erase(find(tree->parent->children.begin(), tree->parent->children.end(), tree));
    delete tree;
}

string DeepIndent(int depth){
    string indent = "";
    for (int i=0; i<depth; ++i){
        indent +=" ";
    }
    return indent;
}

void ShowTree(tnode *tree){
    cout << DeepIndent(tree->deep) << tree->field << "\n";
    if (tree->children.empty()== false) {
        for (int i = 0; i < tree->children.size(); ++i) {
            ShowTree(tree->children[i]);
        }
    } else return;
}

int main() {
    tnode* proot=new tnode;
    proot->field = 1;
    AddNode(proot, 2);
    AddNode(proot, 3);
    AddNode(proot->children[0], 4);
    AddNode(proot->children[1], 5);
    ShowTree(proot);
    CheckIncrease(proot);
    AddNode(proot->children[0], 6);
    ShowTree(proot);
    CheckIncrease(proot);
    return 0;
}
