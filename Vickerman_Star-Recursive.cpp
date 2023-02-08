#include <iostream>
using namespace std;

void recursiveStars(int);


int main() {
	int userStars = -1;

	while (userStars <= -1) {
		cout << "Enter a number of stars to be displayed: ";
		cin >> userStars;
	}

	recursiveStars(userStars);

	return 0;
}

void recursiveStars(int input) {
	int bottom = input;
	int top = input;
	
	

	if (input == 0) {
	}
	else {
		while (bottom > 0) {
			cout << "*";
			bottom--;
		}
		if (input != 0) {
			cout << endl;
		}
		recursiveStars(input - 1);
	}
	while (bottom < top) {
		cout << "*";
		bottom++;
	}
	if (bottom != 0) {
		cout << endl;
	}


}


/*Enter a number of stars to be displayed : 10
*********
********
*******
******
*****
****
***
**
*
*
*
**
***
****
*****
******
*******
********
*********
*/