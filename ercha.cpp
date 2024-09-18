#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;

class Tree
{
public:
	Tree() :root(nullptr)
	{
	}
	struct Node
	{
		Node(int date = int())
			: date(date)
			, left(nullptr)
			, right(nullptr)
		{}

		int date;
		Node*left;
		Node*right;
	};
	Node *root;
	void insert(int val)
	{
		root=insert(root, val);
	}
	void remove(int val)
	{
		if (root == nullptr)
		{
			throw "is empty";
		}
		remove(root, val);
	}
	bool find(int val)
	{
		if (root == nullptr)
		{
			throw"is empty";
		}
		Node*fuck = find(root, val);
		if (fuck != nullptr)
		{
			return true;
		}
		else
			return false;
	}
	int num()
	{
		return num(root);
	}
	int level()
	{
		return level(root);
	}
	void levelf()
	{
		levelf(root);
		cout << endl;
	}
private:
	Node* insert(Node*root, int val)
	{
		if (root == nullptr)
		{
			return new Node(val);
		}
		if (root->date == val)
		{
			return root;
		}
		else if (root->date > val)
		{
			root->left = insert(root->left, val);
		}
		else
		{
			root->right = insert(root->right, val);
		}
		return root;
	}
	Node*remove(Node*root, int val)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		else if (root->date == val)
		{
			if (root->right != nullptr&&root->left != nullptr)
			{
				Node*p = root->left;
				while (p->right != nullptr)
				{
					p = p->right;
				}
				root->date = p->date;
				root->left = remove(root->left, p->date);
			}
			else {
				if (root->right != nullptr)
				{
					Node*right = root->right;
					delete root;
					return right;
				}
				else if (root->left != nullptr)
				{
					Node*left = root->left;
					delete left;
					return left;
				}
				else {
					return nullptr;
				}

			}
		}
		else {
			if (root->date > val)
			{
				root->left = remove(root->left, val);
			}
			else
			{
				root->right = remove(root->right, val);
			}
		}
		return root;
	}
	Node*find(Node*root, int val)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->date == val)
		{
			return root;
		}
		else if (root->date > val)
		{
			find(root->left, val);
		}
		else {
			find(root->right, val);
		}
	}
	int level(Node*root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max(level(root->left), level(root->right)) + 1;
	}
	int num(Node*root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = num(root->left) ;
		int right = num(root->right);
		return left + right + 1;
	}
	void levelf(Node*root)
	{
		if (root == nullptr)
		{
			return;
		}
		levelf(root->left);
		cout << root->date << " ";
		levelf(root->right);
	}
};

int main()
{
	int arr[] = { 2,3,9,1,7,4,10,18,13,15 };
	Tree t;
	for (auto f : arr)
	{
		t.insert(f);
	}
	t.levelf();
	t.remove(4);
	t.levelf();
	cout << t.num() << " " << t.level() << endl;
}
