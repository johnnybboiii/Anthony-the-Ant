/* Name: John Li 
   Date: 11/20/2019
   Description: libraries and global constants
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;

const int SIZE = 10;

void IntroDetails();
void PersonalInfo();
void InitializeMatrix(int** row, int& armySize);
void OutputField(int** row, int currentColumn, int rowSelect, bool status = false, bool loss = false);
bool CheckRowStatus(int rowSelect,int currentColumn,int& armySize,int** row);