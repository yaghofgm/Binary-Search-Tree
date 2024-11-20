template <typename T>
class BinarySearchTree {
    public:
    BinarySearchTree();
    //Big Three
    BinarySearchTree(const BinarySearchTree &other); //copy
    BinarySearchtree& operator=(const BinarySearchTree& other) //overloaded assign
    ~BinarySearchTree(); //destructor

    bool empty() const;
    int size() const;
    bool contains(const T& item) const;
    vois insert(const T& item);

    private:
    struct treeNode 
    {
        treeNode* left;
        treeNode* right;
        int data;
    };
    tree_node* root;
};