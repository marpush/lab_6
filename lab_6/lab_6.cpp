#include <iostream>
#include <stdlib.h>
#define RIGHT_BORDER 100
#define LEFT_BORDER 0
using namespace std;

struct Сonstruction {
	Сonstruction* middle;
	Сonstruction* left;
	Сonstruction* right;
	int value;
};

Сonstruction* MakeElements(int N) {
	if (N == 0) {
		return NULL;
	}
	Сonstruction* middle = new Сonstruction;
	middle->value = 1;
	N--;
	middle->middle = NULL;
	if (N == 0) {
		middle->left = NULL;
		middle->right = NULL;
	} else {
		Сonstruction* left = middle->left = new Сonstruction;
		left->value = 2;		
		left->left = NULL;
		left->right = NULL;
		N--;
		if (N == 0) {
			left->middle = NULL;
			middle->right = NULL;
		} else {
			Сonstruction* right = middle->right = new Сonstruction;
			right->value = 3;
			right->left = NULL;
			right->right = NULL;
			N--;
			if (N == 0) {
				right->middle = NULL;
			} else {
				left->middle = right->middle = MakeElements(N);
			}
		}
	}
	return middle;
}

int ScanNumberInRange(const int left_border, const int right_border);
void Show(Сonstruction* root);
void FreeMemory(Сonstruction* middle);

int main()
{
	cout << "Enter the number of elements in the structure:\n ";
	const int count_elements = ScanNumberInRange(LEFT_BORDER, RIGHT_BORDER);
	Сonstruction* root = MakeElements(count_elements);
	Show(root);
	FreeMemory(root);
	return 0;
}

void Show(Сonstruction* middle)
{
	if (middle != NULL) {
			cout << "          " << middle->value << endl;
		
		if (middle->left != NULL) {
			Сonstruction* left = middle->left;
			cout << "     " << left->value;
		}
		if (middle->right != NULL) {
			Сonstruction* right = middle->right;
			cout << "         " << right->value << endl;
			if (right->middle != NULL) {
				Show(right->middle);
			}				
		}		
	}
}

void FreeMemory(Сonstruction* middle){
	if (middle != NULL) {		
		if (middle->left != NULL) {
			if (middle->right != NULL) {
				Сonstruction* right = middle->right;
				if (right->middle != NULL) {
					FreeMemory(right->middle);
				}
				delete middle->right;
			}
			delete middle->left;
		}
		delete middle;
	}	
}

int ScanNumberInRange(const int left_border, const int right_border)
{
	while (true) {
		cout << "Enter a border less than " << right_border << " greater or equally than " << left_border << endl;
		int number = 0;
		cin >> number;

		if (cin.fail()) {
			cout << "Entered is not a number.\n";
			cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else {
			if ((number >= left_border) && (number < right_border)) {
				return number;
			}
			else {
				if (number < left_border) {
					cout << "The entered number is less " << left_border << endl;
					cin.clear();
				}
				if (number >= right_border) {
					cout << "The entered number is greater than or equal to " << right_border << endl;
					cin.clear();
				}
			}
		}
	}
}
