/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include<stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
   int index1, index2, counter;
     if( len <=0 || Arr== NULL) //ERROR CASES
		return -1;
	else
         for (index1 = 0; index1<len; index1++)
	  {
		for (index2 = index1 + 1; index2<len;)
		{
			if (Arr[index1] == Arr[index2])//if Duplicate element found
			{   len--;
				for (counter = index2; counter<len; counter++)
				{
					Arr[counter] = Arr[counter + 1];//backshifting elements after duplicate element found
				}
			}
			else 
			      index2++;
		  }
	   }
		return index1;
	 }
	
