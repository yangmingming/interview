#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *CreateTree(std::vector<int> &vec){
    if(vec.empty()){
        return nullptr;
    }

    std::queue<TreeNode *> q;
        TreeNode *head = new TreeNode(vec[0]);
    q.push(head);

    int i = 1;
    while(i < vec.size()){
        TreeNode *node = q.front();q.pop();

        if(vec[i] != 0){
            node->left = new TreeNode(vec[i]);
            q.push(node->left);
        }
        i++;

        if(vec[i] != 0){
            node->right= new TreeNode(vec[i]);
            q.push(node->right);
        }
        i++;
    }

    return head;
}

void PreOrder(TreeNode *head){
    if(head == nullptr){
        return;
    }
    std::cout << head->val << ",";
    PreOrder(head->left);
    PreOrder(head->right);
}

void InOrder(TreeNode *head){
    if(head == nullptr){
        return;
    }
    InOrder(head->left);
    std::cout << head->val << ",";
    InOrder(head->right);
}

void PostOrder(TreeNode *head){
    if(head == nullptr){
        return;
    }
    PostOrder(head->left);
    PostOrder(head->right);
    std::cout << head->val << ",";
}

// 通过栈模拟递归实现前序遍历
void PreOrder2(TreeNode *root){
    std::stack<TreeNode *> s;

    while(!s.empty() || root != nullptr){
        // 添加左节点
        while(root != nullptr){
            std::cout << root->val << ","; 	// 根
            s.push(root);
            root = root->left;			// 根
        }

        if(!s.empty()){
            TreeNode *node = s.top();s.pop();

            root = node ->right;		// 右
        }
    }
}

// 通过栈模拟递归实现中序遍历
void InOrder2(TreeNode *root){
    std::stack<TreeNode *> s;

    while(!s.empty() || root != nullptr){
        // 添加左节点
        while(root != nullptr){
            s.push(root);
            root = root->left;			// 左
        }

        if(!s.empty()){
            TreeNode *node = s.top();s.pop();
            std::cout << node->val << ",";	// 根

            root = node ->right;		// 右
        }
    }
}

void PostOrder2(TreeNode *head){
    std::stack<TreeNode *> s;

    TreeNode *pre = nullptr;
    while(head != nullptr || !s.empty()){
        while(head != nullptr){
            s.push(head);
            head = head->left;			// 左
        }

        if(!s.empty()){
            auto node = s.top(); s.pop();

            if(pre != node->right && node->right != nullptr){
		s.push(node);			// 重新入栈
                head = node->right;		// 右
            }else{
                std::cout << node->val << ",";	// 根
		pre = node;
		head = nullptr;			// 从栈中获取下一个节点
            }
        }
    }

    if(head == nullptr){
        return;
    }
    PostOrder(head->left);
    PostOrder(head->right);
    std::cout << head->val << ",";
}

void LevelOrder(TreeNode *head){
    if(head == nullptr){
        return;
    }

    std::queue<TreeNode *> q;
    q.push(head);
    while(!q.empty()){
        auto node = q.front();q.pop();
	std::cout << node->val << ",";

	// 注意添加的是当前节点的左右节点
        if(node->left != nullptr){
            q.push(node->left);
        }

        if(node->right != nullptr){
            q.push(node->right);
        }
    }
}

/* 参考资料
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/solution/qing-song-ji-yi-er-cha-shu-de-qian-zhong-6vu5/ [前中后非递归统一写法]
 */
int main(){
    //std::vector<int> vec{5, 1, 4, 0, 0, 3, 6};
    std::vector<int> vec{5, 1, 4, 0, 2, 3, 6};
    //std::vector<int> vec{1,2,3,0,4,5,6,7,0};
    TreeNode *head = CreateTree(vec);

    std::cout <<"递归实现先序遍历/中序遍历/后续遍历" << std::endl;

    // 先序遍历
    PreOrder(head);
    std::cout << std::endl;

    // 中序遍历
    InOrder(head);
    std::cout << std::endl;

    // 后续遍历
    PostOrder(head);
    std::cout << std::endl;

    std::cout <<"层序遍历" << std::endl;
    // 层序遍历
    LevelOrder(head);
    std::cout << std::endl;

    std::cout <<"迭代实现先序遍历/中序遍历/后续遍历" << std::endl;

    PreOrder2(head);
    std::cout << std::endl;

    InOrder2(head);
    std::cout << std::endl;

    PostOrder2(head);
    std::cout << std::endl;

    return 0;
}
