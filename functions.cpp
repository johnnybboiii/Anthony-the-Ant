/* Name: John Li
   Date: 11/20/2019
   Description: function definitions
*/

#include "headers.h"

//outputting game info
void IntroDetails() {
	cout << "                       Welcome to Anthony's Battle" << endl;
	cout << endl;
	cout << "        ----------------------------------------------------------" << endl;
	cout << "        Anthony the ant has decided that he wants to take over all" << endl;
	cout << "        the adjacent ant colonies with his army of ants from colo-" << endl;
	cout << "        ny 'A'. To do this, Anthony's army will attempt to capture" << endl;
	cout << "        ants from columns 'B' through 'J', with at least 1 ant re-" << endl;
	cout << "        maining when the column 'J' ant colony is found. Each col-" << endl;
	cout << "        umn's ant colony is identified with a 0 in one of the rows" << endl;
	cout << "        for that column, while patrols are represented by integers" << endl;
	cout << "        between 1 and 10 for the number of ants in that particular" << endl;
	cout << "        patrol. On the way to column 'J' if Anthony's army encoun-" << endl;
	cout << "        ters a patrol, the number in the patrol is subtracted from" << endl;
	cout << "        Anthony's army total. Once his army finds the colony, how-" << endl;
	cout << "        ever, any patrols not confronted will be added to his army" << endl;
	cout << "        total. If Anthony makes really good decisions, then he can" << endl;
	cout << "        take over all of the adjacent ant colonies; otherwise, his" << endl;
	cout << "        army will be defeated!                                    " << endl;
	cout << "        ----------------------------------------------------------" << endl;
}

//initializing board
void InitializeMatrix(int** row, int& armySize) {
	srand(time(NULL));
	cout << " Initializing Board..." << endl;
	cout << endl;

	//generating patrols
	for (int i = 0; i < SIZE; ++i) {
		for (int h = 0; h < SIZE; ++h) {
			row[i][h] = (rand() % 9) + 1;
		}
	}

	//declaring any colonies
	for (int i = 1; i < SIZE; ++i) {
		int randomRow;
		randomRow = rand() % SIZE;
		row[randomRow][i] = 0;
	}

	//finding Anthony's army size
	for (int i = 0; i < SIZE; ++i) {
		armySize += row[0][i];
	}
}

//outputting field
void OutputField(int** row, int currentColumn, int rowSelect, bool status, bool loss) {

	//displaying field
	cout << "   A  B  C  D  E  F  G  H  I  J " << endl;
	cout << " +-------------------------------+" << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << i << "|";

		//when player loses
		if (loss) {
			for (int h = 0; h < SIZE; ++h) {
				if (row[i][h] == 11) {
					cout << " XX";
				}
				else {
					printf(" %02d", row[i][h]);
				}
			}
			cout << " |" << endl;
		}
		else {
			//displaying values of array
			if (currentColumn == 0) {
				for (int h = 0; h < SIZE; ++h) {
					if (h == 0) {
						printf(" %02d", row[i][h]);
					}
					else {
						cout << " **";
					}
				}
				cout << " |" << endl;
			}
			else {
				for (int h = 0; h < SIZE; ++h) {
					if (h == 0) {
						printf(" %02d", row[i][h]);
						continue;
					}
					if (row[i][h] == 11) {
						cout << " XX";
					}
					else if (status && (currentColumn == h)) {
						printf(" %02d", row[i][h]);
					}
					else if (currentColumn > h) {
						printf(" %02d", row[i][h]);
					}
					else {
						cout << " **";
					}

				}
				cout << " |" << endl;
			}
		}
	}
	cout << " +-------------------------------+" << endl;
	cout << endl;
}

//checking status of the row
bool CheckRowStatus(int rowSelect, int currentColumn, int& armySize, int** row) {
	int capturedNum = 0;

	//checking if row chosen is colony
	if (row[rowSelect][currentColumn] == 0) {
		for (int i = 0; i < SIZE; ++i) {
			if (row[i][currentColumn] != 11) {
				capturedNum += row[i][currentColumn];
			}
		}
		armySize += capturedNum;
		cout << "Anthony's army found any colony in column " << static_cast<char>('A' + currentColumn) << ", captured " << capturedNum << " ants." << endl;
		cout << endl;
		return true;
	}

	//checking if row chosen has already been removed
	else if (row[rowSelect][currentColumn] == 11) {
		cout << "Ant patrol at this location has already been removed." << endl;
		cout << endl;
		return false;
	}

	//if there is patrol at row
	else {
		armySize -= row[rowSelect][currentColumn];
		row[rowSelect][currentColumn] = 11;
		cout << "Anthony's army suffered casualties and has " << armySize << " ants remaining." << endl;
		cout << endl;
		return false;
	}
}
