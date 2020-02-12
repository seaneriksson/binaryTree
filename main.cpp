#include <iostream>
using namespace std;

typedef int ItemType;

struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

class Tree
{
public:
	Tree();
	void PutItem(ItemType item);
	void Print()const;

private:
	TreeNode* root;

};

void Insert(TreeNode*& tree, ItemType item);
void PrintTree(TreeNode* tree);


int main()
{
	Tree newTree;

	for (int n = 0; n < 12; n++)
	{
    	newTree.PutItem(n);
	}

	newTree.Print();

	return 0;
}

Tree::Tree()
{
	root = NULL;
}


void Tree::PutItem(ItemType item)
{
	Insert(root, item);
}

void Tree::Print()const
{
	PrintTree(root);
}

void Insert(TreeNode*& tree, ItemType item)
{
	if (tree == NULL)
	{
    	tree = new TreeNode;
    	tree->right = NULL;
    	tree->left = NULL;
    	tree->info = item;
	}

	else if (item < tree->info)
    	Insert(tree->left, item);
	else
    	Insert(tree->right, item);

}

void PrintTree(TreeNode* tree)
{
	if (tree != NULL)
	{
    	PrintTree(tree->left);
    	cout << tree->info << endl;
    	PrintTree(tree->right);
	}
}




