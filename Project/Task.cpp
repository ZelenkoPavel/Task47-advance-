#include <iostream>

using namespace std;

void user_init(int** matrix, string* country_name, int vertical, int horizontal);
void logic(int** matrix, int vertical, int horizontal);


void processing_the_results_of_sports_competitions(int** matrix,
	string* country_name, int vertical, int horizontal);
string output_as_a_string(int** matrix,
	string* country_name, int vertical, int horizontal);

int main() {
	int vertical = 8;
	const int horizontal = 5;
	string* country_name = new string[vertical]
	{"Austria", "Germany", "Norway", "Russia", "Finland", "China", "USA", "Belarus"};
	int** matrix = new int*[vertical];
	for (int i = 0; i < vertical; i++) {
		*(matrix + i) = new int[horizontal];
	}

	user_init(matrix, country_name, vertical, horizontal);

	logic(matrix, vertical, horizontal);

	processing_the_results_of_sports_competitions(matrix, country_name,
		vertical, horizontal);

	cout << output_as_a_string(matrix, country_name, vertical, horizontal) << endl;

	for (int i = 0; i < vertical; i++) {
		delete[] *(matrix + i);
	}
	delete[] matrix;

	return 0;
}