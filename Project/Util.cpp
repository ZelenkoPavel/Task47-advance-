#include <iostream>

using namespace std;


void logic(int** matrix, int vertical, int horizontal) {
	for (int i = 0; i < vertical; i++){
		*(*(matrix + i) + 3) = 0;
		*(*(matrix + i) + 4) = 0;
		for (int j = 0; j < horizontal - 2; j++)
		{
			*(*(matrix + i) + 3) += *(*(matrix + i) + j);
		}
		for (int k = 0; k < horizontal - 2; k++)
		{
			*(*(matrix + i) + 4) += (7 - k) * *(*(matrix + i) + k);
		}
	}
}

bool checking_the_filling(int* matrix, int horizontal) {
	for (int j = 0; j < horizontal - 2; j++) {
		if (*(matrix + j) < 0) {
			return true;
		}
	}

	return false;
}

void user_init(int** matrix, string* country_name, int vertical, int horizontal) {

	cout << "Input the number of gold, silver and bronze medals in one line:"
		<< endl;
	for (int i = 0; i < vertical; i++) {
		do {
			cout << *(country_name + i) << ": ";
			for (int j = 0; j < horizontal - 2; j++) {
				cin >> *(*(matrix + i) + j);
			}
		} while (checking_the_filling(*(matrix + i), horizontal));
	}
}
