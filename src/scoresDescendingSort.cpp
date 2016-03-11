/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len < 1)//ERROR CASES i.e, Invalid inputs
		return NULL;

	int counter1= 0, counter2 = 0;
		struct student temp;
	for (counter1 = 0; counter1 < len - 1; counter1++){//sorting in descending order
		for (counter2 = counter1 + 1; counter2 < len; counter2++){
			if (students[counter1].score < students[counter2].score)
			{
				temp = students[counter1];
				students[counter1] = students[counter2];
				students[counter2] = temp;
			}
		}
	}
}