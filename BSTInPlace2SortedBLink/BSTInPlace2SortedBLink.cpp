#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
		Node(int v)
		{
			mV = v;
			left = right = 0;
		}
	int mV;
	Node* left;
	Node* right;
	};

class BST
{
	Node* root;

public:
	BST()
	{
		root = NULL;
	}

	void Init(vector<int>& inputA)
	{
		for(int i = 0; i< inputA.size(); i++)
		{
			insert(&root, inputA[i]);
		}
	}

	void insert(Node** iRoot, int Value)
	{
		if(*iRoot == NULL)
		{
			*iRoot = new Node(Value);
		}
		else
		{
			if((*iRoot)->mV > Value)
			{
				insert(&((*iRoot)->left), Value);
			}
			else
			{
				insert(&((*iRoot)->right), Value);
			}
		}
	}

	Node* GetRoot()
	{
		return root;
	}
};

void TranslateBST2SortedBLink(Node* iRoot, Node** oppBegin, Node** oppEnd)
{
	Node* lLeftBegin = NULL;
	Node* lLeftEnd = NULL;
	if(iRoot->left)
	{
		TranslateBST2SortedBLink(iRoot->left, &lLeftBegin, &lLeftEnd);
		iRoot->left = lLeftEnd;
		lLeftEnd->right = iRoot;
	}
	else
	{
		lLeftBegin = lLeftEnd = iRoot;
	}
	

	Node* lRightBegin = NULL;
	Node* lRightEnd = NULL;
	if(iRoot->right)
	{
		TranslateBST2SortedBLink(iRoot->right, &lRightBegin, &lRightEnd);
		iRoot->right = lRightBegin;
		lRightBegin->left = iRoot;
	}
	else
	{
		lRightBegin = lRightEnd = iRoot;
	}


	*oppBegin = lLeftBegin;
	*oppEnd= lRightEnd;
}

void PrintBLink(Node* iStart, Node* iEnd)
{
	while(iStart != iEnd)
	{
		cout << iStart->mV << ' ';
		iStart = iStart->right;
	}

	cout << iStart->mV << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> inputV;
	for(int i = 0; i< n; i++)
		inputV.push_back(i);

	random_shuffle(inputV.begin(), inputV.end());

	BST mB;
	mB.Init(inputV);

	Node* lRoot = mB.GetRoot();

	Node* lBegin = NULL;
	Node* lEnd = NULL;
	TranslateBST2SortedBLink(lRoot, &lBegin, &lEnd);

	PrintBLink(lBegin, lEnd);
	

	int a;
	cin >> a;
	return 0;
}