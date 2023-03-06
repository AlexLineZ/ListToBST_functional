#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(INT_MIN), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

int findMid(int left, int right) {
    return ((left + right) % 2 != 0) ? ((left + right) / 2 + 1) : ((left + right) / 2);
}

TreeNode* buildTree(int left, int right, vector<int> v) {
    return left > right ? new TreeNode() : new TreeNode(v[findMid(left, right)], buildTree(left, findMid(left, right) - 1, v), buildTree(findMid(left, right) + 1, right, v));
}

vector <int> inputList() {
    vector <int> v;
    fstream input("input.txt");
    copy(istream_iterator<int>(input), istream_iterator<int>(), back_inserter(v));
    return v;
}

int getChildren(TreeNode* root);

int printTree(TreeNode* root) {

    (root == nullptr) ?
        []() {
        return NULL;
    }() :
        [root] {
        root->val == INT_MIN ? cout << "null" << " " : cout << root->val << " ";
        return getChildren(root);
    }();
    return NULL;
}

int getChildren(TreeNode* root) {
    return printTree(root->left) + printTree(root->right);
}

int main()
{
    printTree(buildTree(0, inputList().size() - 1, inputList()));
}
