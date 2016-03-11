/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
struct student temp;
int i=0, index=0,temp1=0,maxscoreindex=0;
struct student ** topKStudents(struct student *students, int len, int K) {

	if (students == NULL || len == 0 || K <= 0)//ERROR CASES i.e, Invalid inputs
		return NULL;
	if (K == 1){// if only one top student is asked
		
		for (index= 0; index < len; index++){
			if (students[index].score>temp1){
				temp1= students[index].score;
				maxscoreindex = index;
			}
		}
		struct student **topKstudents = (struct student**)calloc(K, sizeof(struct student));
		topKstudents[0] = &students[maxscoreindex];
		return topKstudents;
	}
	else{
		struct student **topKstudents = (struct student**)calloc(K, sizeof(struct student));
		int index1 = 0, index2=0;
		for (index1 = 0; index1 < len - 1; index1++){
			for (index2 = index1; index2 < len; index2++){
				if (students[index1].score < students[index2].score){
					temp = students[index1];
					students[index1] = students[index2];
					students[index2] = temp;
				}
			}
		}

		for (i = 0; i < K; i++)
			topKstudents[i] = &students[i];

		return topKstudents;
	}
}