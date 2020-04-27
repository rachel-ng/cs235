#include <iostream>
#include "Node.h"
#include "Challenges.h"

int num_nodes (Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return nnodes(root);
    }
}

int nnodes (Node* n) {
    int nodes = 0;
    if (n->getLeft() != nullptr) {
        nodes += nnodes (n->getLeft());
    }
    if (n->getRight() != nullptr) {
        nodes += nnodes (n->getRight());
    }
    return nodes + 1;
}
