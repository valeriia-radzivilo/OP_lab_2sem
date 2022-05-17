#include "header.h"

Product::Product() {
    name = " ";
    price = 0;
    amount = 0;
    total = 0;
}

Product::Product(string name, int price, int amount) {
    this->name = name;
    this->price = price;
    this->amount = amount;
    this->total = price * amount;
}

void Product::setProduct() {
    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter price: ";
    cin >> price;
    cout <<"Enter amount: ";
    cin >> amount;
}
void Product::output_product() {
    cout << name << " - "<< price <<" - "<< amount<< endl;
}

void Product::countTotal() {
    total = price*amount;
}

void sort_by_name(vector <Product> &prods)
{
    sort(prods.begin(), prods.end(), [](const Product& lhs, const Product& rhs) {
        return lhs.name < rhs.name;
    });
}

void output_arr(vector <Product> prods)
{
    for (auto & prod : prods)
        prod.output_product();
}

void one_num_tree(Product pr) {
    cout << pr.name<< ":"<< endl;
    cout <<pr.price<< endl;
}

void printLevelOrder(TreeNode* root) // print tree in a level order
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        cout <<"Level "<<i<<": ";
        printCurrentLevel(root, i);
        cout << endl;
    }
}

// Prints current level of tree
void printCurrentLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->val << "   ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Compute the "height" of a tree - number of levels
int height(TreeNode* tree)
{
    if (tree == NULL)
        return 0;
    else {
        // compute the height of each subtree(left/right)
        int lheight = height(tree->left);
        int rheight = height(tree->right);

        // use the biggest
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
void createTree(TreeNode* tree, int i, vector<string>& arr) { // used in levelOrderCreateTree
    if (tree != NULL) {
        if (2 * i + 1 < arr.size()) {
            if (arr[2 * i + 1] == "null")
                tree->left = NULL;
            else
                tree->left = new TreeNode(stoi(arr[2 * i + 1]));
            createTree(tree->left, 2 * i + 1, arr);
        }

        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == "null")
                tree->right = NULL;
            else
                tree->right = new TreeNode(stoi(arr[2 * i + 2]));
            createTree(tree->right, 2 * i + 2, arr);
        }
    }
}
TreeNode* levelOrderCreateTree(vector<string>& arr) { // used in make_trees
    if (arr.size() == 0)
        return nullptr;
    TreeNode *head = new TreeNode(stoi(arr[0]));
    createTree(head, 0, arr);
    return head;
}

void make_trees(vector<Product>prods, int am_prods)
{
    for(int i =0; i< am_prods;i++) {
        cout << endl;
        if(prods[i].name!=prods[i+1].name) // if one object in a tree
            one_num_tree(prods[i]);
        else {
            vector<string>tmp;
            while(prods[i].name==prods[i+1].name) // find objects with the same name to make one tree
            {
                tmp.push_back(to_string(prods[i].price));
                i++;
            }
            tmp.push_back(to_string(prods[i].price));
            if(prods[i].name!=prods[i+1].name) // if the next object doesn't belong to the tree
            {
                TreeNode* tree = levelOrderCreateTree(tmp); // create the tree and write array in
                cout<< prods[i].name<<":"<< endl;
                printLevelOrder(tree); // output the tree

            }

        }
        cout<< endl;
    }
}

int check_same(vector<Product>prods, Product good) // check if object is already in a list
{
    int i =0;
    for (auto it = prods.begin();it!=prods.end();it++) {
        if(it->name ==good.name && it->price == good.price)
            return i;
        i++;
    }
    return -1;
}

int find_total(vector<Product>prods, string good) // count total for the product
{
    int total_cost =0;
    for (auto it = prods.begin();it!=prods.end();it++) {
        if(it->name ==good)
            total_cost+=it->total;
    }
    return total_cost;
}