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

void preorderTraversal2(TreeNode* cur, vector<int>& vec) {//ǰ�����
    if (cur == NULL) return;
    vec.push_back(cur->val);    // ��
    preorderTraversal2(cur->left, vec);  // ��
    preorderTraversal2(cur->right, vec); // ��
}

//�ݹ��������
void inorderTraversal12(TreeNode* cur, vector<int>& vec) {//�������
    if (cur == NULL) return;
    inorderTraversal12(cur->left, vec);  // ��
    vec.push_back(cur->val);    // ��
    inorderTraversal12(cur->right, vec); // ��
}

void postorderTraversal2(TreeNode* cur, vector<int>& vec) {//�������
    if (cur == NULL) return;
    postorderTraversal2(cur->left, vec);  // ��
    postorderTraversal2(cur->right, vec); // ��
    vec.push_back(cur->val);    // ��
}

//�ǵݹ��������
vector<int> preorderTraversal1(TreeNode* root) {//ǰ�����
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();                       // ��
        st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);           // �ң��սڵ㲻��ջ��
        if (node->left) st.push(node->left);             // �󣨿սڵ㲻��ջ��
    }
    return result;
}

vector<int> inorderTraversal1(TreeNode* root) {//�������
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) { // ָ�������ʽڵ㣬���ʵ���ײ�
            st.push(cur); // �����ʵĽڵ�Ž�ջ
            cur = cur->left;                // ��
        }
        else {
            cur = st.top(); // ��ջ�ﵯ�������ݣ�����Ҫ��������ݣ��Ž�result����������ݣ�
            st.pop();
            result.push_back(cur->val);     // ��
            cur = cur->right;               // ��
        }
    }
    return result;
}

vector<int> postorderTraversal1(TreeNode* root) {//�������
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left) st.push(node->left); // �����ǰ������������һ����ջ˳�� ���սڵ㲻��ջ��
        if (node->right) st.push(node->right); // �սڵ㲻��ջ
    }
    reverse(result.begin(), result.end()); // �������ת֮����������е�˳����
    return result;
}

//�������
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        // ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()����Ϊque.size�ǲ��ϱ仯��
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

//�������
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if (root->val > val) root->left = insertIntoBST(root->left, val);
    if (root->val < val) root->right = insertIntoBST(root->right, val);
    return root;
}


//ɾ������
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) { printf("δ�ҵ�ɾ���Ľڵ㣡\n"); return root; }  // ��һ�������û�ҵ�ɾ���Ľڵ㣬�������սڵ�ֱ�ӷ�����
    if (root->val == key) {
        // �ڶ�����������Һ��Ӷ�Ϊ�գ�Ҷ�ӽڵ㣩��ֱ��ɾ���ڵ㣬 ����NULLΪ���ڵ�
        if (root->left == nullptr && root->right == nullptr) {
            ///! �ڴ��ͷ�
            delete root;
            printf("ɾ���ɹ���\n");
            return nullptr;
        }
        // �����������������Ϊ�գ��Һ��Ӳ�Ϊ�գ�ɾ���ڵ㣬�Һ��Ӳ�λ �������Һ���Ϊ���ڵ�
        else if (root->left == nullptr) {
            auto retNode = root->right;
            ///! �ڴ��ͷ�
            delete root;
            printf("ɾ���ɹ���\n");
            return retNode;
        }
        // ��������������Һ���Ϊ�գ����Ӳ�Ϊ�գ�ɾ���ڵ㣬���Ӳ�λ����������Ϊ���ڵ�
        else if (root->right == nullptr) {
            auto retNode = root->left;
            ///! �ڴ��ͷ�
            delete root;
            printf("ɾ���ɹ���\n");
            return retNode;
        }
        // ��������������Һ��ӽڵ㶼��Ϊ�գ���ɾ���ڵ���������ŵ�ɾ���ڵ����������������ڵ�����ӵ�λ��
        // ������ɾ���ڵ��Һ���Ϊ�µĸ��ڵ㡣
        else {
            TreeNode* cur = root->right; // ��������������Ľڵ�
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            cur->left = root->left; // ��Ҫɾ���Ľڵ㣨root������������cur�����ӵ�λ��
            TreeNode* tmp = root;   // ��root�ڵ㱣��һ�£�������ɾ��
            root = root->right;     // ���ؾ�root���Һ�����Ϊ��root
            delete tmp;
            printf("ɾ���ɹ���\n");// �ͷŽڵ��ڴ棨���ﲻдҲ���ԣ���C++����ֶ��ͷ�һ�°ɣ�
            return root;
        }
    }
    if (root->val > key) root->left = deleteNode(root->left, key);
    if (root->val < key) root->right = deleteNode(root->right, key);
    return root;
}

//����ƽ�������
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

//����
TreeNode* find(TreeNode* root, int key)
{
    if (root == NULL) return NULL;
    if (key < root->val) return find(root->left, key);
    else if (key > root->val) return find(root->right, key);
    else return root;
}