// ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <conio.h>
#include <time.h>

using namespace std;

typedef double* pDouble;

typedef struct {
    double x, y;
} TPoint;


const int MAX_SIZE = 560;

/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, int A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

int ConsoleInputArrayPoints(int sizeMax, TPoint A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "].x "; cin >> A[i].x;
        cout << " Array[ " << i << "].y "; cin >> A[i].y;
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, int A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();

        A[i] = r1;
        if (r2 % 2 == 0)
            A[i] = -A[i];

        cout << A[i] << "   ";
    }
    return size;
}

int RndInputArrayPoint(int sizeMax, TPoint A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1, r2, r3,r4,r5, r6;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        r3 = rand();
        r4 = rand();
        r5 = rand();
        r6 = rand();

        A[i].x = r1 / (1.0 + r2);
        if (r3 % 2 == 0)
            A[i].x = -A[i].x;

        A[i].y = r4 / (1.0 + r5);
        if (r6 % 2 == 0)
            A[i].x = -A[i].x;
    }
    return size;
}


int ConsoleInputDynamicArrayNew(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double>& A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return;
}


/*
*  WriteArrayTextFile
*
*/

void WriteArrayTextFile(int n, int* arr)
{
    char fileName[200];
    cout << "Input Filename:\n";
    cin >> fileName;

    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
void WriteArrayConsole(int n, int* arr)
{
    cout << "Array:\n";
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "]" << ":" << arr[i] << "\n";
    }
}
void WriteArrayConsole(int n, TPoint* arr)
{
    cout << "Array:\n";
    for (int i = 0; i < n; i++) {
        cout << "[" << i + 1 << "].x" << ":" << arr[i].x << "\n";
        cout << "[" << i + 1 << "].y" << ":" << arr[i].y << "\n";
    }
}

/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, int* arr)
{ 
    char fileName[200];
    cout << "Input Filename:\n";
    cin >> fileName;

    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
    return size;
}

void WriteArrayBinFile(int n, TPoint* arr)
{
    char fileName[200];
    cout << "Input Filename:\n";
    cin >> fileName;

    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(TPoint);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, TPoint* arr)
{
    char fileName[200];
    cout << "Input Filename:\n";
    cin >> fileName;

    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(TPoint));
    bfin.close();
    // ssdhs
    return size;
}

int InputArray(int sizeMax, int arr[]) {
    char ch;
    int i, arrLen;

    cout << "\n  Select Input method:   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File \n";
    do {
        ch = _getch();
    } while (ch != '1' && ch != '2' && ch != '3');

    switch (ch) {
    case '1':
        cout << "    1.  Console all \n";
        arrLen = ConsoleInputArray(MAX_SIZE, arr);
        break;
    case '2':
        cout << "    2.  Console - size, array - random \n";
        arrLen = RndInputArray(MAX_SIZE, arr);
        break;
    case '3':
        cout << "    3.  File \n";
        arrLen = ReadArrayTextFile(MAX_SIZE, arr);
        break;
    }

    return arrLen;
}

void OutputArray(int arrLen, int arr[]) {
    char ch;

    cout << "\n  Select Output method:   \n";
    cout << "    1.  Console \n";
    cout << "    2.  File \n";
    cout << "    3.  Console & File \n";

    do {
        ch = _getch();
    } while (ch != '1' && ch != '2' && ch != '3');

    switch (ch) {
    case '1':
        WriteArrayConsole(arrLen, arr);
        break;
    case '2':
        WriteArrayTextFile(arrLen, arr);
        break;
    case '3':
        WriteArrayConsole(arrLen, arr);
        WriteArrayTextFile(arrLen, arr);
        break;
    }
}

void Task1() {
    int i, arrLen;
    int arr[MAX_SIZE];

    arrLen = InputArray(MAX_SIZE, arr);

    for (i = 0; i < arrLen; i++) {
        if (i < arrLen / 2) {
            arr[i] = arr[i] * 2;
        }
        else {
            arr[i] = arr[i] * 3;
        }
    }

    OutputArray(arrLen, arr);
}
void Task2() {
    int i, arrLen;
    int arr[MAX_SIZE];
    int indV;
    int indexResult;
    int min = 10000010;

    arrLen = InputArray(MAX_SIZE, arr);


    for (i = 0; i < arrLen; i++) {
        if (arr[i] < 0) {
            indV = i;
            break;
        }
    }

    for (i = indV; i < arrLen; i++) {
        if ((arr[i] < min) && (arr[i] > 0) &&
            (arr[i] % 2 == 0)) {
            min = arr[i];
        }
    }

    for (i = arrLen; i > 0; i--) {
        if (min == arr[i]) {
            indexResult = i;
            break;
        }
    }
    cout << "\n  Hомер останнього мінімального елемента серед парних додатних елементів, що лежать правіше першого від’ємного елемента :   \n";
    cout << indexResult << "\n";

    OutputArray(arrLen, arr);
}

int InputArrayPoints(int sizeMax, TPoint arr[]) {
    char ch;
    int i, arrLen;

    cout << "\n  Select Input method:   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File \n";
    do {
        ch = _getch();
    } while (ch != '1' && ch != '2' && ch != '3');

    switch (ch) {
    case '1':
        cout << "    1.  Console all \n";
        arrLen = ConsoleInputArrayPoints(MAX_SIZE, arr);
        break;
    case '2':
        cout << "    2.  Console - size, array - random \n";
        arrLen = RndInputArrayPoint(MAX_SIZE, arr);
        WriteArrayConsole(arrLen, arr);
        break;
    case '3':
        cout << "    3.  File \n";
        arrLen = ReadArrayBinFile(MAX_SIZE, arr);
        WriteArrayConsole(arrLen, arr);
        break;
    }

    return arrLen;
}

void OutputArrayPoint(int arrLen, TPoint arr[]) {
    char ch;

    cout << "\n  Select Output method:   \n";
    cout << "    1.  Console \n";
    cout << "    2.  File \n";
    cout << "    3.  Console & File \n";

    do {
        ch = _getch();
    } while (ch != '1' && ch != '2' && ch != '3');

    switch (ch) {
    case '1':
        WriteArrayConsole(arrLen, arr);
        break;
    case '2':
        WriteArrayBinFile(arrLen, arr);
        break;
    case '3':
        WriteArrayConsole(arrLen, arr);
        WriteArrayBinFile(arrLen, arr);
        break;
    }
}

void Task3() {
    int N;
    TPoint A, B, C;
    TPoint Points[MAX_SIZE];
    double PL1, PL2, PL3, PL;
    double Nx, Ny;
    int i, j;
    int inside = 0;

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

    N = InputArrayPoints(MAX_SIZE, Points);

    PL = abs(((A.x * B.y + B.x * C.y + C.x * A.y) - (A.y * B.x + B.y * C.x + C.y * A.x)) / 2);

    for (i = 0; i < N; i++) {
        PL1 = abs(((Points[i].x * B.y + B.x * C.y + C.x * Points[i].y) - (Points[i].y * B.x + B.y * C.x + C.y * Points[i].x)) / 2);
        PL2 = abs(((A.x * Points[i].y + Points[i].x * C.y + C.x * A.y) - (A.y * Points[i].x + Points[i].y * C.x + C.y * A.x)) / 2);
        PL3 = abs(((A.x * B.y + B.x * Points[i].y + Points[i].x * A.y) - (A.y * B.x + B.y * Points[i].x + Points[i].y * A.x)) / 2);


        if (PL == PL1 + PL2 + PL3) {
            inside++;
        }
    }
    cout << "There are " << inside << " points inside triangle.\t";
    OutputArrayPoint(N, Points);

}

void SelectTask() {
    char ch;

    do {
        cout << "\n  Select Task:   \n";
        cout << "    1.  Task 1 \n";
        cout << "    2.  Task 2 \n";
        cout << "    3.  Task 3 \n";
        cout << "    4.  Exit \n";

        ch = _getch();
        switch (ch) {
        case '1': Task1(); break;
        case '2': Task2(); break;
        case '3': Task3(); break;
        }
    } while (ch != '4');
}


int main()
{

    SelectTask();

    return 1;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
