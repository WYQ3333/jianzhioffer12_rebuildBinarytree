#include<iostream>

using namespace std;

struct BinaryTreeNode{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

BinaryTreeNode* Construct(int *preorder, int *inorder, int length){
	if (preorder == nullptr || inorder == nullptr || length < 0){
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
	int *startInorder, int *endInorder){
	int rootvalue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->value = rootvalue;
	root->left = root->right = nullptr;

	if (startPreorder == endPreorder){
		if (startInorder == endInorder
			&&*startPreorder==*startInorder){
			return root;
		}
		else{
			throw std::exception("Inbalid input");
		}
	}
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootvalue){
		++rootInorder;
	}
	if (rootInorder == endInorder&&*rootInorder != rootvalue){
		throw std::exception("Invalid input");
	}
	int leftlength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftlength;
	if (leftlength > 0){
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd,
			startInorder, rootInorder - 1);
	}
	if (leftlength < endPreorder - startPreorder){
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1,
			endInorder);
	}
	return root;
}

