// Movie Statistics
// This program gathers statistical data about the number of movies college students see in a month.

#include <iostream>
#include <iomanip>
using namespace std;

void sort(int *, int);
int getMode(int *, int);

int main() {
	int NUM_STUDENTS, sum=0;
	int *NUM_MOVIES;
	int mode;
	double average, median;

	cout << "Please enter how many students were surveyed: \n";
	cin >> NUM_STUDENTS;
	while (NUM_STUDENTS < 0) {
		cout << "The number of students cannot be negative. Please enter the valid number: \n";
		cin >> NUM_STUDENTS;
	}

	NUM_MOVIES = new int[NUM_STUDENTS];

	cout << "Please enter the number of movies each student has seen: \n";
	for (int count = 0; count < NUM_STUDENTS; count++) {
		cout << "Student " << count + 1 << ": ";
		cin >> *(NUM_MOVIES + count);
		while (*(NUM_MOVIES + count) < 0) {
			cout << "The number of movies cannot be negative. Please enter the valid number: \n";
			cin >> *(NUM_MOVIES + count);
		}
	}

	// calculate average
	for (int count = 0; count < NUM_STUDENTS; count++) {
		sum += *(NUM_MOVIES + count);
		average = double(sum) / NUM_STUDENTS;
	}	
	cout << "The average of the values: " << average << endl;

	sort(NUM_MOVIES, NUM_STUDENTS);

	// find median
	if (NUM_STUDENTS % 2 != 0)
		median = *(NUM_MOVIES + (NUM_STUDENTS - 1) / 2);
	else
		median = double(*(NUM_MOVIES + NUM_STUDENTS / 2) + *(NUM_MOVIES + (NUM_STUDENTS / 2 - 1))) / 2;
	
	cout << "The median of the values: " << median << endl;
	
	mode = getMode(NUM_MOVIES, NUM_STUDENTS);	

	system("PAUSE");
}
// sorting in ascending order
void sort(int *array, int size)
{
	int count, MIN_INDEX, MIN_VALUE;

	for (int count = 0; count < (size - 1); count++)
	{
		MIN_INDEX = count;
		MIN_VALUE = *(array + count);
		for (int i = count + 1; i < size; i++)
		{
			if (*(array + i) < MIN_VALUE)
			{
				MIN_VALUE = *(array + i);
				MIN_INDEX = i;
			}
		}
		*(array + MIN_INDEX) = *(array + count);
		*(array + count) = MIN_VALUE;
	}
}
// find mode
int getMode(int *array, int size) {
	int counter = 1;
	int max = 1;
	int NUM_REPEATING_VALUE = 0;
	int *mode;

	for (int i = 0; i < size; i++) {
		if (*(array + i) == *(array + i + 1)) {
			counter++;
			if (counter > max)
				max = counter;
		}
		else counter = 1;
	}
	for (int i = 0; i < size; i++) {
		if (*(array + i) == *(array + i + max - 1))
			NUM_REPEATING_VALUE++;
	}
	mode = new int[NUM_REPEATING_VALUE];

	for (int count = 0; count < NUM_REPEATING_VALUE; count++) {
		for (int i = 0; i < size; i++) {
			if (*(array + i) == *(array + i + max - 1))
			{
				*(mode + count) = *(array + i);
				count++;
			}
		}
	}
	if (size > 1 && max*NUM_REPEATING_VALUE == size || NUM_REPEATING_VALUE==0)
		cout << "A mode doesn't exist. \n";
	else {
		cout << "Mode of the values: ";
		for (int count = 0; count < NUM_REPEATING_VALUE; count++) 
		cout << *(mode+count) << " ";
	}
	cout << endl;

	return 0;
}