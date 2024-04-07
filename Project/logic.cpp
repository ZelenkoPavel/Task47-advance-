#include <iostream>
#include <string>

using namespace std;

void selection_of_places(int** matrix, string* country_name,
	int index1, int index2, int horizontal) {
	string str_t = *(country_name + index1);
	*(country_name + index1) = *(country_name + index2);
	*(country_name + index2) = str_t;

	for (int i = 0; i < horizontal; i++){
		int t = *(*(matrix + index1) + i);
		*(*(matrix + index1) + i) = *(*(matrix + index2) + i);
		*(*(matrix + index2) + i) = t;
	}
}

void processing_the_results_of_sports_competitions(int** matrix,
	string* country_name, int vertical, int horizontal) {

	bool flag = true;

	while (flag) {
		flag = false;

		for (int i = 0; i < vertical; i++) {
			for (int j = i + 1; j < vertical; j++) {
				if (*(*(matrix + i) + horizontal - 1)
					< *(*(matrix + j) + horizontal - 1)) {
					selection_of_places(matrix, country_name, i, j, horizontal);
				}
			}
		}
	}
}

string output_as_a_string(int** matrix,
	string* country_name, int vertical, int horizontal) {
	string result = "-------------------------------------------------------------------\n";
	result += "Team     Gold  Silver  Bronze  Total  Points\n";
	for (int i = 0; i < vertical; i++) {
		result += to_string(i + 1) + " " + *(country_name + i);
		result += "    ";
		for (int j = 0; j < horizontal; j++) {
			result += to_string(*(*(matrix + i) + j)) + "      ";
		}
		result += "\n";
	}

	return result;
}
