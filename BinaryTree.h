class BinaryTree
{
private:
	char data;
	BinaryTree *lc, *rc;
public:
	BinaryTree *create1();
	void print(BinaryTree *r,int n);
};

typedef BinaryTree* BiTptr;