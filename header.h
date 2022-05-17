//
// Created by leraz on 15-05-22.
//

#ifndef INC_6LAB_HEADER_H
#define INC_6LAB_HEADER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Product {
public:
    string name;
    int price;
    int amount;
    int total;
    void setProduct();
    Product();
    Product(string name, int price, int amount);
    void output_product();
    void countTotal();
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createTree(TreeNode* node, int i, vector<string>& arr); // used in levelOrderCreateTree, fills a tree
TreeNode* levelOrderCreateTree(vector<string>& arr); // used in make_trees to pass 1 value to pass head
void printCurrentLevel(TreeNode* root, int level);// Prints current level of tree
int height(TreeNode* node); // Compute the "height" of a tree - number of levels
void sort_by_name(vector <Product> &prods); // sort an array by name
void output_arr(vector <Product> prods); // print array
void one_num_tree(Product pr); // if a tree has only 1 value
void printLevelOrder(TreeNode* root); // function to print in level order
void make_trees(vector<Product>prods, int am_prods); // create and fill all trees
int check_same(vector<Product>prods, Product good); // check if object is already in a list
int find_total(vector<Product>prods, string good); // count total for the product

#endif //INC_6LAB_HEADER_H