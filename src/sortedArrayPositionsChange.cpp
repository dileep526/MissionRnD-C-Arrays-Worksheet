/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 2)//ERROR CASES i.e, Invalid inputs
		return NULL;
	int counter1, counter2, temp=0,pos1=0,pos2=0;
	for (int counter1 = len - 1; counter1 > 0; counter1--)//finding	the misplaced elements from the last
	{
		if (Arr[counter1] < Arr[counter1 - 1])//if found 
		{
			pos1 = counter1;
			counter2 = counter1 - 1;
			while (counter2 >= 0 && Arr[pos1] < Arr[counter2])// finding second element
			{
				pos2 = counter2;
				counter2--;
			}
			  //swapping the positions
			temp = Arr[pos1];
			Arr[pos1] = Arr[pos2];
			Arr[pos2] = temp;
break;
		}
	}
return Arr;
}