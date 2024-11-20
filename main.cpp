#include <algorithm>
#include <iostream>
#include <cassert>
struct treeNode 
{
    treeNode* left;
    treeNode* right;
    int data;
};
bool bst_lookup(treeNode* T, int elt)
{
    if (T==nullptr) return false;
    if (elt==T->data) return true;
    if (elt<T->data) return bst_lookup(T->left,elt);
    return bst_lookup(T->right,elt);
}
//we have the height hich defines the o order
//and the size of the tree,the number of elements

int treeHeight(treeNode* T){
    if (!T) return 0;
    return 1+std::max(treeHeight(T->left),treeHeight(T->right));
}
int treeSize(treeNode* T){
    if (!T) return 0;
    return 1+treeSize(T->left)+treeSize(T->right);
}

void treePrint_core(treeNode* T){
    if (!T) return;
    treePrint_core(T->left);
    std::cout<<" "<<T->data<<" ";
    std::cout.flush();
    treePrint_core(T->right);
}
// void treePrint(treeNode* T){ //dont really need this here 
//     treePrint_core(T);
//     std::cout<<std::endl;
// }

bool is_ordered(treeNode* T, int* lo, int* hi){
    if (!T) return true;
    if( (lo == nullptr || T->data > *lo) && (hi == nullptr || T->data < *hi))
        return is_ordered(T->left, lo, &T->data) &&
                is_ordered(T->right, &T->data, hi);
    return false;
} //the way is to discard the falses when happening since true is the goal.

int max(treeNode* T){
    assert(is_ordered(T, nullptr, nullptr));
    if (!T->right) return T->data;
    return max(T->right);
}