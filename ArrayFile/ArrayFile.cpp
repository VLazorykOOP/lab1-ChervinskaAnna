
/* Варіант 11 
Завдання 1: Задано одновимірний масив А розміру N. Першу половину елементів масиву 
помножити на 2, а другу - на 3.
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;

typedef struct {
	int length;
	int data[200];
} TArray;


void saveArrayToFile(TArray arr) {
	char filename[200];
	char answer;
	cout << "Bazhaete zberigti?" << endl;
	cin >> answer;
	if (answer == 'N' or answer == 'n')
		return;

	cout << "FileName?" << endl;
	cin >> filename;

	cout << filename << endl;


	ofstream outfile;
	remove(filename);
	outfile.open(filename);

	for (int i = 0; i < arr.length; i++) {
		outfile << " " << arr.data[i];
	}

	outfile.close();
}


TArray readFromFile() {
	char filename[200];
	TArray result;
	result.length = 0;

	cout << "Enter filename" << endl;
	cin >> filename;

	ifstream inFile;
	inFile.open(filename);

	if (inFile.is_open())
	{
		for (int i = 0; i < 200; i++)
		{
			inFile >> result.data[i];
			result.length++;
			cout << result.data[i] << " ";

			if (inFile.eof())
				break;
		}

		inFile.close(); // CLose input file
	}

	return result;
}



int main() {
    int i;
	TArray arr;
	arr = readFromFile();
	if (arr.length == 0)
	{
		cout << "File is not found!!!11" << endl;

		cout << "Vedite Length" << endl;
		cin >> arr.length;

		for (i = 0; i < arr.length; i++) {

			cout << "[" << i + 1 << "]" << ":";
			cin >> arr.data[i];
		}

		saveArrayToFile(arr);
	}


    for (i = 0; i < arr.length; i++) {
        if (i < arr.length / 2) {
			arr.data[i] = arr.data[i] * 2;
        }
        else {
			arr.data[i] = arr.data[i] * 3;
        }
    }

	cout << "Res\n";
	for (i = 0; i < arr.length; i++) {
		cout << arr.data[i] << " ";
	}

	saveArrayToFile(arr);

    cout << endl;

    _getch();
    return 0;
}




 /*Завдання 2: Знайти номер останнього мінімального елемента серед парних додатних
елементів, що лежать правіше першого від’ємного елемента

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {
	int i, N;
	int indV;
	int min = 10000010;

	cout << "Vedite N" << endl;
	cin >> N;

	int massive_A[100];

	for (i = 0; i < N; i++) {

		cout << "[" << i + 1 << "]" << ":";
		cin >> massive_A[i];
	}

	for (i = 0; i < N; i++) {
		if (massive_A[i] < 0) {
			indV = i;
			break;
		}
	}

	for (i = indV; i < N; i++) {
		if ((massive_A[i] < min) && (massive_A[i] > 0) &&
			(massive_A[i] % 2 == 0)) {
			min = massive_A[i];
		}
	}

	for (i = N; i > 0; i--) {
	 if (min == massive_A[i]){
	  cout << i;
	  break;
	 }
	}

	getch();
	return 0;
}*/


/*Завдання 3: На площині задано множину точок з координатами 
 , , , ,..., , ,
n n
x y x y x y 1 1 2 2 n  200
і координати вершин трикутника 
  a a A x , y ,   b b B x , y ,   c c C x , y
. Розробити програму, яка 
обчислює кількість точок заданої множини, що належать 
ABC */

/*#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace winrt;
using namespace Windows::Foundation;
using namespace std;
typedef struct {
	double x, y;
} TPoint;

int main()
{
	int N;
	TPoint A, B, C;
	TPoint Points[200];
	double PL1, PL2, PL3, PL;
	double Nx, Ny;
	int i, j;
	int inside=0;

	cout << "Enter number points" << endl;
	cin >> N;


	cout << "Enter Ax" << endl;
	cin >> A.x;

	cout << "Enter Ay" << endl;
	cin >> A.y;

	cout << "Enter Bx" << endl;
	cin >> B.x;

	cout << "Enter By" << endl;
	cin >> B.y;

	cout << "Enter Cx" << endl;
	cin >> C.x;

	cout << "Enter Cy" << endl;
	cin >> C.y;

	for (i = 0; i < N; i++) {
		printf("Enter Point[%d].X: ", i);
		cin >> Points[i].x;

		printf("Enter Point[%d].Y: ", i);
		cin >> Points[i].y;
	}

	PL = abs(((A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x)) / 2);

	for (i = 0; i < N; i++) {
		PL1 = abs(((Points[i].x * B.y + B.x * C.y + C.x * Points[i].y) - (Points[i].y * B.x + B.y * C.x + C.y * Points[i].x)) / 2);
		PL2 = abs(((A.x * Points[i].y + Points[i].x * C.y + C.x * A.y) - (A.y * Points[i].x + Points[i].y * C.x + C.y * A.x)) / 2);
		PL3 = abs(((A.x * B.y + B.x * Points[i].y + Points[i].x * A.y) - (A.y * B.x + B.y * Points[i].x + Points[i].y * A.x)) / 2);


		if (PL == PL1 + PL2 + PL3) {
			inside++;
		}
	}
	cout << "RES" << endl << inside;

	getch();
	return 0;
}
*/

