#include <iostream>
#include <stdlib.h>
using namespace std;


struct Сonstruction {
	Сonstruction* midline;
	Сonstruction* left;
	Сonstruction* right;
	int value;
};

Сonstruction* MakeElements(int N) {
	if (N == 0) {
		return NULL;
	}
	Сonstruction* p;
	p = new Сonstruction;
	Сonstruction* p0 = p-> midline = new Сonstruction;
	p0->value = rand();
	N--;
	if (N == 0) {
		p->left = p->right = NULL;
	}
	Сonstruction* p1 = p->left = new Сonstruction;
	Сonstruction* p2 = p->right = new Сonstruction;
	p1->right = p2;
	p2->left = p1;
	p1->value = rand();
	p2->value = rand();
	p1->left = p2->right = MakeElements(N-2);
	return p;
}

int main()
{
	Сonstruction* root = MakeElements(3);
	cout << root->midline->value << endl;
	cout << root->left->value << endl;
	cout << root->right->value << endl;
	return 0;
}
