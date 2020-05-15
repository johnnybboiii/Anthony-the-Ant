/* Name: John Li
   Date: 11/20/2019
   Description: libraries and global constants
*/
#include "headers.h"

int main()
{
	int currentColumn = 0; //current column being attacked
	int armySize = 0; //Anthony's army size
	int rowSelect = 10; //row selected by user
	int **row = new int*[SIZE]; //creating 2D dynamic array
	for (int i = 0; i < SIZE; ++i) {
		row[i] = new int[SIZE];
	}

	//outputting bascic information
	IntroDetails();
	cout << endl;

	//outputting game field
	InitializeMatrix(row, armySize);
	OutputField(row, currentColumn, rowSelect);
	cout << "Now let's begin...Anthony's army is " << armySize << " strong!" << endl;
	cout << endl;
	currentColumn += 1;

	//results of selected row
	while ((currentColumn < SIZE) && (armySize > 0)) {
		for (int i = 0; i < SIZE; ++i) {
			bool status;
			bool loss;
			cout << "Enter row position in column " << static_cast<char>('A' + currentColumn) << " to strike: ";
			cin >> rowSelect;
			while ((rowSelect < 0) || (rowSelect > 9)) {
				cout << "Error. Row selected is out of range. Please enter a valid row number: ";
				cin >> rowSelect;
			}
			cout << endl;
			status = CheckRowStatus(rowSelect, currentColumn, armySize, row);

			//loss
			if (armySize <= 0) {
				cout << "Sorry, but Anthony's army has been defeated before taking over all ant colonies." << endl;
				cout << endl;
				loss = true;
				OutputField(row, currentColumn, rowSelect, status, loss);
				break;
			}

			//still alive
			if (status) {
				OutputField(row, currentColumn, rowSelect, status);
				break;
			}
			else {
				OutputField(row, currentColumn, rowSelect);
			}
		}
		currentColumn += 1;
	}

	//success
	if (armySize > 0) {
		cout << "Congratulations! Anthony has taken over all ant colonies with " << armySize << " remaining!" << endl;
	}

	return 0;
}