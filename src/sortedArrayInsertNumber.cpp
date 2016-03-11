/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>


int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL || len < 0)//ERROR CASES
	{
		return NULL;
	}
	Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));//reallocating the Arr with len+1 size as insering only one element
	/* 
	METHOD-I
	int temp,index = 0;
	Arr[len] = num;
	while (Arr[index]<Arr[len] )
	{
	index++;
	}
	while (Arr[index]>Arr[len])
	{
	temp = Arr[len];
	Arr[len] = Arr[index];
	Arr[index] = temp;
	index++;
	}*/

	//METHOD -II
	int counter=len,pos=0,index=0;
	if (Arr[0]>num)//if it is to be inserted at 0th index
		pos= 0;
    if (Arr[len - 1]<num)
		pos= len;//if it is to be inserted at last index
	
	for (index = 1; index < len; index++)//if it is to be inserted at middle indexes
	     {
			if (Arr[index - 1]<num && Arr[index]>num)
				pos=index;
		}
    while (counter > pos)//shifting indexes for insertion at middle indexes and starting index from the last index 
		//i.e shifting to the right from last index
	{
		Arr[counter] = Arr[counter - 1];
		counter--;
	}
	Arr[pos] = num;//inserting at the indexes at the found positions, 
	//but if it is to be inserted at last it doesn't go for shifting (i.e above while loop)
	return Arr;
}