// OSU ACM Sample Data Structure Problems
// Link to slides:
//      https://docs.google.com/presentation/d/1Q921WdsK-Z7KmuKAIgLPL_CnKnc31SQ6HpLW2pLMcOk/edit?usp=sharing

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* next;
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) { };
};

// Linked list problem
int problem(vector<int>& arr, int k) {
    Node* head = new Node;
    Node* it = head;
    for (int i = 0; i < arr.size(); i++) {
	it->next = new Node;
	it = it->next;
	it->val = arr[i];
    }
    it->next = head->next;
    it = it->next;

    while (it->next != it) {
	for (int i = 0; i < k-2; i++)
	    it = it->next;
	Node* t = it->next->next;
	delete [] it->next;
	it->next = t;
    }
    return it->val;
}

// Stack problem
string removeDuplicates(string S) {
    stack<char> s;
    for (int i = 0; i < S.size(); i++) {
	if (!s.empty() && s.top() == S[i])
	    s.pop();
	else
	    s.push(S[i]);
    }
    string r;
    while (!s.empty()) {
	r += s.top();
	s.pop();
    }
    reverse(r.begin(), r.end());
    return r;
}

// Hashmap problem
int getPairs(vector<int>& arr, int target) {
    unordered_map<int, int> m;
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res += m[target - arr[i]];
        m[arr[i]]++;
    } 
    return res;
}


vector<int> bfs(TreeNode* root) {
    vector<int> r;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* t = q.front();
        r.push_back(t->val);
        q.pop();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = {1, 2, 3, 4, 5};
    int k = 3;
    cout << "Linked list: Answer should be 4" << endl;
    cout << "Your answer: " << problem(input, k) << endl;

    string x = "aaabbccad";
    cout << "Stack: Answer should be \"d\"" << endl;
    cout << "Your answer: " << removeDuplicates(x) << endl;

    vector<int> input2 = {1, 2, 5, 13, 2};
    int target = 3;
    cout << "Hashmap: Answer should be 2" << endl;
    cout << "Your answer: " << getPairs(input2, target) << endl;

    TreeNode* root = new TreeNode(20, 
                            new TreeNode(12,
                                new TreeNode(8,
                                    new TreeNode(2, NULL, NULL),
                                    new TreeNode(9, NULL, NULL)),
                                new TreeNode(18, NULL, NULL)),
                            new TreeNode(32, 
                                new TreeNode(23, NULL, NULL),
                                new TreeNode(45, NULL, NULL)));
    cout << "Tree: Answer should be: 20 12 32 8 18 23 45 2 9" << endl;
    cout << "Your answer: ";
    vector<int> r = bfs(root);
    for (int i = 0; i < r.size(); i++) cout << r[i] << " ";
    cout << endl;

    return 0;
}
