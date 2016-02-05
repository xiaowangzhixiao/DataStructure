#include <iostream>
#include "BinaryTree.h"

using namespace std;

BiTptr BinaryTree::create1(){
	BiTptr root=NULL;
	char a;
	cin>>a;
	if (a >= 'A' && a <= 'Z')
	{
		root = new BinaryTree;
		(*root).data = a;
		cin>>a;
		if (a=='(')
		{
			(*root).lc=create1();
		}else{
			(*root).lc = NULL;
			(*root).rc = NULL;
			return root;
		}
		cin>>a;
		(*root).rc=create1();
	}else if (a == '#')
	{
		return root;
	}
	return root;
}

void BinaryTree::print(BiTptr root,int n){
	if(root){
		print((*root).rc,n+1);
		for (int i = 0; i < n; ++i)
		{
			cout<<' ';
		}
		cout<<(*root).data<<endl;
		print((*root).lc,n+1);
	}
	
}

int main(int argc, char const *argv[])
{
	BiTptr root;
	root=(*root).create1();
	
	(*root).print(root,0);
	return 0;
}