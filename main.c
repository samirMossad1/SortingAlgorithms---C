

#include <stdio.h>
#include "sortingAlgorithms.h"
#include "std_types.h"


void inputIntArray(sint32*,uint16);
void printIntArray(sint32*,uint16);
void swapTwoElements(sint32*,sint32*);
sint32* getIndexReference(sint32*,uint16);
uint8 compareTwoElements(sint32*,sint32*);
uint8 heapCompare(sint32*,sint32*);
void copyArray(sint32*,sint32*,uint16);


int main(void)
{
	uint8 returnValue = FALSE;
	sint32 array[10],arrayCopy[10];

	inputIntArray(array,10);

	/*Testing Selection Sort*/
	copyArray(arrayCopy,array,10);
	returnValue = selectionSort(arrayCopy,10,getIndexReference,swapTwoElements,compareTwoElements);
	if (returnValue == TRUE)
	{
		returnValue = FALSE;
		printf("Selection Sort	: ");
		printIntArray(arrayCopy,10);
	}
	printf("\n");


	/*Testing Bubble Sort*/
	copyArray(arrayCopy,array,10);
	returnValue = bubbleSort(arrayCopy,10,getIndexReference,swapTwoElements,compareTwoElements);
	if (returnValue == TRUE)
	{
		returnValue = FALSE;
		printf("Bubble Sort	: ");
		printIntArray(arrayCopy,10);
	}
	printf("\n");


	/*Testing Insertion Sort*/
	copyArray(arrayCopy,array,10);
	returnValue = insertionSort(arrayCopy,10,getIndexReference,swapTwoElements,heapCompare);
	if (returnValue == TRUE)
	{
		returnValue = FALSE;
		printf("Insertion Sort	: ");
		printIntArray(arrayCopy,10);
	}
	printf("\n");


	/*Testing Quick Sort*/
	copyArray(arrayCopy,array,10);
	returnValue = quickSort(arrayCopy,10,getIndexReference,swapTwoElements,compareTwoElements);
	if (returnValue == TRUE)
	{
		returnValue = FALSE;
		printf("Quick Sort	: ");
		printIntArray(arrayCopy,10);
	}
	printf("\n");


	/*Testing Heap Sort*/
	copyArray(arrayCopy,array,10);
	returnValue = heapSort(arrayCopy,10,getIndexReference,swapTwoElements,heapCompare);
	if (returnValue == TRUE)
	{
		returnValue = FALSE;
		printf("Heap Sort	: ");
		printIntArray(arrayCopy,10);
	}
	printf("\n");


	return 0;
}


void inputIntArray(sint32* array , uint16 arrayLength)
{
	uint16 counter;
	for (counter = 0 ; counter < arrayLength ; counter ++)
	{
		scanf("%d",&array[counter]);
	}
}

void printIntArray(sint32* array , uint16 arrayLength)
{
	uint16 counter;
	for (counter = 0 ; counter < arrayLength ; counter ++)
	{
		printf("%d\t",array[counter]);
	}
}



void swapTwoElements(sint32* ptrFirstElement , sint32* ptrSecondElement)
{
	sint32 swapTempValue = *ptrFirstElement;
	*ptrFirstElement = *ptrSecondElement;
	*ptrSecondElement = swapTempValue;

}


uint8 compareTwoElements(sint32* ptrFirstElement , sint32* ptrSecondElement)
{
	sint32 returnElement = FALSE;

	if( *ptrFirstElement < *ptrSecondElement)
		returnElement = TRUE;

	return returnElement;

}


uint8 heapCompare(sint32* ptrFirstElement , sint32* ptrSecondElement)
{
	sint32 returnElement = FALSE;

	if( *ptrFirstElement > *ptrSecondElement)
		returnElement = TRUE;

	return returnElement;

}

sint32* getIndexReference(sint32* genericList , uint16 index)
{
	return &genericList[index];
}




void copyArray(sint32* arrayCopy,sint32* array,uint16 arrayLength)
{
	uint16 counter;
	for (counter = 0 ; counter < arrayLength ; counter ++)
		arrayCopy [counter] = array [counter];
}




