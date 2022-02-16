 /*Є 3 двовимірні масиви A, B, C. Кількість рядків і стовпців вводить користувач з клавіатури для кожного з них.Реалізуйте:
■■Створіть одновимірний масив, який містить загальні  +
значення для A, B, C;
■■Створіть одновимірний масив, який містить унікальні+-
значення для A, B, C;
■■Створіть одновимірний масив, який містить загальні  +
значення для A і C;
■■Створіть одновимірний масив, який містить від'ємні +
значення для A, B, C без повторень.*/

#include <iostream>
#include<Windows.h>
#include<ctime>
using namespace std;
void divisionArr(int** Array, int n, int m);//ф-н виділення дин.ам'яті
void inputArr(int** Array, int n, int m);//ф-н заповнення масиву рандомними числами
void printArr(int** Array, int n, int m);//ф-н виводу двохвимірних масивів
void printNewArr(int* Arr, int &n);//ф-н виводу одовимірних масивів
void Common_Arays_ABC(int** A, int stringA, int columsA, int** B, int stringB, int columsB, int** C, int stringC, int columsC, int* CommonABC, int& size123);//ф-н яка заповнення одновимірного масиву загальними значенями для А,В,С
void Different_Arays_ABC(int** A, int stringA, int columsA, int** B, int stringB, int columsB, int** C, int stringC, int columsC, int* DifferentABC, int& sizenew2);//ф-н яка заповнення одновимірного масиву унікальними значенями для А,В,С
void Common_Array_AC(int** A, int stringA, int columsA, int** C, int stringC, int columsC, int* CommonAC, int& sizenew2);//ф-н яка заповнення одновимірного масиву загальними значенями для А,В,С
void Negative(int** A, int stringA, int columsA, int** B, int stringB, int columsB, int** C, int stringC, int columsC, int* NegativeABC, int& sizenew);//ф-н яка заповнює одновимірний масив негативними значенями для А,В,С

void arr_uniq(int* C, int& NM);//ф-н видалення двохвимірних масивів

void deleteArr(int** Array, int n, int m);//ф-н видалення масиву
int main()
{ 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int stringA = 0,stringB = 0,stringC = 0;//кількість рядків в масивах ABC
	int columsA = 0, columsB = 0, columsC = 0;//кількість колонок в масивах ABC
	int** A = nullptr;
	cout << "Введіть кількість рядків і колонок масиву А :";
	cin >> stringA >> columsA;	
	A= new int* [stringA];

	int** B = nullptr;
	cout << "Введіть кількість рядків і колонок масиву B :";
	cin >> stringB >> columsB;
	B = new int* [stringB];

	int** C = nullptr;
	cout << "Введіть кількість рядків і колонок масиву C :";
	cin >> stringC >> columsC;
	C = new int* [stringC];
	
	int size1 = stringA * columsA;//взнаємо
	int size2 = stringB * columsB;//розмір
	int size3 = stringC * columsC;//двовимірних масивів

	int size123 = size1 + size2 + size3;            //для зручності записую розмір трьох масиві в одну зміну
	int sizenew = size123;
	int sizenew2 = size123;
	int size213 = size123;	
	int size12 = size1 + size3; //для зручності записую розмір першого і третього масивів 

	int* CommonABC = new int[size123];            //масив ,який містить загальні значення  для A, B, C
	int* DifferentABC = new int[sizenew2];        //масив, який містить унікальні	значення для  A, B, C
	int* DifferentC = new int[size213];
	int* CommonAC = new int[size12];            //масив, який містить загальні значення для A і C
	int* NegativeABC = new int[sizenew];       //масив, який містить від'ємні значення для A, B, C без повторень

	divisionArr( A, stringA, columsA);
	inputArr(A, stringA, columsA);
	cout << "\t\tЕлементи першого масиву" << endl;
	printArr(A, stringA, columsA);

	divisionArr(B, stringB, columsB);
	inputArr(B, stringB, columsB);
	cout << "\t\tЕлементи другого масиву" << endl;
	printArr(B, stringB, columsB);

	divisionArr(C, stringC, columsC);
	inputArr(C, stringC, columsC);
	cout << "\t\tЕлементи третього масиву" << endl;
	printArr(C, stringC, columsC);

	Common_Arays_ABC(A, stringA, columsA, B, stringB, columsB, C, stringC, columsC, CommonABC, size123);
	cout << "\n\n\tмасив загальних значень АВС\n";
	arr_uniq(CommonABC, size123);
	printNewArr(CommonABC,size123); //ф-н виводу одовимірних масивів

	Common_Array_AC(A,stringA,columsA,C,stringC,columsC,CommonAC,size12);
	cout << "\n\n\tмасив загальих значень АС\n";
	arr_uniq(CommonAC, size12);
	printNewArr(CommonAC, size12); //ф-н виводу одовимірних масивів

	Negative(A, stringA,columsA, B, stringB, columsB, C,stringC,columsC,NegativeABC, sizenew);
	cout << "\n\n\n\tмасив негативних значень АВС\n";
	arr_uniq(NegativeABC, sizenew);
	printNewArr(NegativeABC, sizenew); //ф-н виводу одовимірних масивів	

	 Different_Arays_ABC(A,stringA,columsA,B,stringB,columsB,C,stringC,columsC,DifferentABC,sizenew2);	//ф-н яка заповнення одновимірного масиву унікальними значенями для А,В,С
	cout << "\n\n\n\t\tмасив унікальних значень АВС\n";
	arr_uniq(DifferentABC, sizenew2);
	printNewArr(DifferentABC, sizenew2); //ф-н виводу одовимірних масивів

	deleteArr(A, stringA, columsA);//видалення
	deleteArr(B, stringB, columsB);
	deleteArr(C, stringC, columsC);
	delete[]A;
	delete[]B;
	delete[]C;
	delete[]CommonABC;
	delete[]CommonAC;
	delete[]DifferentABC;	
	delete[]NegativeABC;//всіх масивів
}
void divisionArr(int** Array, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		Array[i] = new int[m];
	}

}
void inputArr(int** Array, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Array[i][j] = rand() % 40-10;
		}
	}
}
void printArr(int** Array, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout <<Array[i][j] << "\t";
		}
		cout << endl;
	}
}
void printNewArr(int* Arr, int& n) {
		for (int i = 0; i < n; i++)
		{
			cout << Arr[i] << "\t";
		}			
}

void arr_uniq(int* C, int& NM)//функція видалення повторюваних елементів в кінцевому масиві 
{
	for (int i = 0; i < NM; i++)
	{
		for (int j = 0; j < NM; j++)
		{
			if (i != j)//перевірка чи ми не порівнюємо значення масиву під одним індексом 
			{
				if (C[i] == C[j])//перевірка чи знайшлись подібні едементи 
				{
					swap(C[NM - 1], C[j]);//стираємо подібний елемент
					NM--;//зменшуємо розмір масиву оскільки видалили повторюваний елемент
				}
			}
		}
	}
}
void Common_Arays_ABC(int** A, int stringA, int columsA, int** B, int stringB, int columsB,  int** C, int stringC, int columsC, int* CommonABC , int& size123) {
	int size = 0;//зміна для створення нового розміру масиву 
	for (int i = 0; i < stringA; i++)
	{
		for (int j = 0; j <columsA; j++)
		{
			for (int k = 0; k < stringB; k++)
			{
				for (int l = 0; l < columsB; l++)
				{
					for (int n = 0; n < stringC; n++)
					{
						for (int m = 0; m < columsC; m++)
						{
							if (A[i][j]==B[k][l] and A[i][j] == C[n][m]) {
								CommonABC[size] = A[i][j];
								size++;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < stringB; i++)
	{
		for (int j = 0; j < columsB; j++)
		{
			for (int k = 0; k < stringA; k++)
			{
				for (int l = 0; l < columsA; l++)
				{
					for (int n = 0; n < stringC; n++)
					{
						for (int m = 0; m < columsC; m++)
						{
							if (B[i][j] == A[k][l] and B[i][j] == C[n][m]) {
								CommonABC[size] = B[i][j];
								size++;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < stringC; i++)
	{
		for (int j = 0; j < columsC; j++)
		{
			for (int k = 0; k < stringA; k++)
			{
				for (int l = 0; l < columsA; l++)
				{
					for (int n = 0; n < stringB; n++)
					{
						for (int m = 0; m < columsB; m++)
						{
							if (C[i][j] == A[k][l] and C[i][j] == B[n][m]) {
								CommonABC[size] = C[i][j];
								size++;
							}
						}
					}
				}
			}
		}
	}
	size123 = size;
}
void Different_Arays_ABC(int** A, int stringA, int columsA, int** B, int stringB,int columsB, int** C, int stringC, int columsC, int* DifferentABC, int& sizenew2) {//працює трішки не коректно не записує унікальні значення масиву А
	
	int size = 0;//зміна для створення нового розміру масиву 
	for (int i = 0; i < stringA; i++)
	{
		for (int j = 0; j < columsA; j++)
		{
			for (int k = 0; k < stringB; k++)
			{
				for (int l = 0; l < columsB; l++)
				{
					for (int t = 0; t < stringC; t++)
					{
						for (int f = 0; t < stringC; t++)
						{
							if ((A[i][j] == B[k][l])and(A[i][j]==C[t][f])){
								break;
							}
							else if ((k == stringB - 1) and (l == columsB - 1)and (t == stringC - 1) and (f == columsC - 1)) {
								DifferentABC[size] = A[i][j];
								size++;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < stringB; i++)
	{
		for (int j = 0; j < columsB; j++)
		{
			for (int k = 0; k < stringA; k++)
			{
				for (int l = 0; l < columsA; l++)
				{
					for (int t = 0; t < stringC; t++)
					{
						for (int f = 0; f < columsC; f++)
						{
							if ((B[i][j] == A[k][l])and (B[i][j] == C[t][f]) ) {
								break;
							}
							else if ((k == stringA - 1) and (l == columsA - 1) and (t == stringC - 1) and (f == columsC - 1)) {
								DifferentABC[size] = B[i][j];
								size++;
							}
						}
					}
				}
			}
		}
	}	
	for (int i = 0; i < stringC; i++)
	{
		for (int j = 0; j < columsC; j++)
		{
			for (int k = 0; k < stringA; k++)
			{
				for (int l = 0; l < columsA; l++)
				{
					for (int t = 0; t < stringB; t++)
					{
						for (int f = 0; f < columsB; f++)
						{
							if ((C[i][j] == A[k][l]) and (C[i][j] == B[t][f])) {
								break;
							}
							else if ((k == stringA - 1) and (l == columsA - 1) and (t == stringB - 1) and (f == columsB- 1)) {
								DifferentABC[size] = C[i][j];
								size++;
							}
						}
					}
				}
			}
		}
	}
	
	sizenew2 = size;	
}
void Common_Array_AC(int** A, int stringA, int columsA, int** C, int stringC, int columsC, int* CommonAC, int& sizenew2) {
	int size = 0;
	for (int i = 0; i < stringA; i++)
	{
		for (int j = 0; j < columsA; j++)
		{
			for (int k = 0; k < stringC; k++)
			{
				for (int f = 0; f < columsC; f++)
				{
					if (A[i][j] == C[k][f]) { 
						CommonAC[size++] = A[i][j]; }//присвоюємо загальні елементи масивів А і С новому масиву

				}
			}
		}
	}
	sizenew2 = size;
}
void Negative(int** A, int stringA, int columsA, int** B, int stringB, int columsB, int** C, int stringC, int columsC, int* NegativeABC, int& sizenew){
	int size = 0;
	for (int i = 0; i < stringA; i++)
	{
		for (int j = 0; j < columsA; j++)
		{
			if (A[i][j] < 0) {
				NegativeABC[size++] = A[i][j]; }//присвоюємо негативні елементи новому масиву
		}

	}
	for (int i = 0; i < stringB; i++)
	{
		for (int j = 0; j < columsB; j++)
		{
			if (B[i][j] < 0) {
				NegativeABC[size++] = B[i][j]; }//присвоюємо негативні елементи новому масиву

		}

	}
	for (int i = 0; i < stringC; i++)
	{
		for (int j = 0; j < columsC; j++)
		{
			if (C[i][j] < 0){
				NegativeABC[size++] = C[i][j];}//присвоюємо негативні елементи новому масиву
		}

	}
	sizenew = size;//присвоюємо size розміру нового масиву
}
void deleteArr(int** Array, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		delete[]Array[i];
	}
}




