#pragma once
#include <cstddef>
#include <vector>
#include<stack>
#include<queue>
#include<iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal2(TreeNode* cur, vector<int>& vec) {//前序遍历
    if (cur == NULL) return;
    vec.push_back(cur->val);    // 中
    preorderTraversal2(cur->left, vec);  // 左
    preorderTraversal2(cur->right, vec); // 右
}

//递归三序遍历
void inorderTraversal12(TreeNode* cur, vector<int>& vec) {//中序遍历
    if (cur == NULL) return;
    inorderTraversal12(cur->left, vec);  // 左
    vec.push_back(cur->val);    // 中
    inorderTraversal12(cur->right, vec); // 右
}

void postorderTraversal2(TreeNode* cur, vector<int>& vec) {//后序遍历
    if (cur == NULL) return;
    postorderTraversal2(cur->left, vec);  // 左
    postorderTraversal2(cur->right, vec); // 右
    vec.push_back(cur->val);    // 中
}

//非递归三序遍历
vector<int> preorderTraversal1(TreeNode* root) {//前序遍历
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();                       // 中
        st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);           // 右（空节点不入栈）
        if (node->left) st.push(node->left);             // 左（空节点不入栈）
    }
    return result;
}

vector<int> inorderTraversal1(TreeNode* root) {//中序遍历
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) { // 指针来访问节点，访问到最底层
            st.push(cur); // 将访问的节点放进栈
            cur = cur->left;                // 左
        }
        else {
            cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            st.pop();
            result.push_back(cur->val);     // 中
            cur = cur->right;               // 右
        }
    }
    return result;
}

vector<int> postorderTraversal1(TreeNode* root) {//后序遍历
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
        if (node->right) st.push(node->right); // 空节点不入栈
    }
    reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
    return result;
}

//层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

//插入操作
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if (root->val > val) root->left = insertIntoBST(root->left, val);
    if (root->val < val) root->right = insertIntoBST(root->right, val);
    return root;
}


//删除操作
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) { printf("未找到删除的节点！\n"); return root; }  // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
    if (root->val == key) {
        // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
        if (root->left == nullptr && root->right == nullptr) {
            ///! 内存释放
            delete root;
            printf("删除成功！\n");
            return nullptr;
        }
        // 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
        else if (root->left == nullptr) {
            auto retNode = root->right;
            ///! 内存释放
            delete root;
            printf("删除成功！\n");
            return retNode;
        }
        // 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
        else if (root->right == nullptr) {
            auto retNode = root->left;
            ///! 内存释放
            delete root;
            printf("删除成功！\n");
            return retNode;
        }
        // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
        // 并返回删除节点右孩子为新的根节点。
        else {
            TreeNode* cur = root->right; // 找右子树最左面的节点
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
            TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
            root = root->right;     // 返回旧root的右孩子作为新root
            delete tmp;
            printf("删除成功！\n");// 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
            return root;
        }
    }
    if (root->val > key) root->left = deleteNode(root->left, key);
    if (root->val < key) root->right = deleteNode(root->right, key);
    return root;
}

//构建平衡二叉树
TreeNode* traversal(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + ((right - left) / 2);
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = traversal(nums, left, mid - 1);
    root->right = traversal(nums, mid + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = traversal(nums, 0, nums.size() - 1);
    return root;
}

//查找
TreeNode* find(TreeNode* root, int key)
{
    if (root == NULL) return NULL;
    if (key < root->val) return find(root->left, key);
    else if (key > root->val) return find(root->right, key);
    else return root;
}