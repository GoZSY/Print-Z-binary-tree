/*
按照层序遍历，添加一个计数，在奇数层反向存储,使用队列
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        queue<TreeNode*> Node;
        if (pRoot == NULL)
            return ret;
        int CountLevel = 0;
        Node.push(pRoot);
        while (!Node.empty())
        {
            int Index = 0;
            int Len = Node.size();
            vector<int> tmp;
            while (Index++ < Len)
            {
                TreeNode *pNode = Node.front();
                Node.pop();
                tmp.push_back(pNode->val);
                if (pNode->left != NULL)
                    Node.push(pNode->left);
                if (pNode->right != NULL)
                    Node.push(pNode->right);
            }
            if (CountLevel % 2 == 0)
            {
                ret.push_back(tmp);
                CountLevel++;
            }
            else
            {
                vector<int> tmp1;
                vector<int>::reverse_iterator it = tmp.rbegin();
                for (; it != tmp.rend(); it++)
                {
                    tmp1.push_back(*it);
                }
                ret.push_back(tmp1);
                CountLevel++;
            }
        }
        return ret;
    }
 
};
