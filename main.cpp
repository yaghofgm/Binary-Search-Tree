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