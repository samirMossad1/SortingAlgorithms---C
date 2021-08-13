
#include "sortingAlgorithms.h"


static void insertElement(sint32*,uint16,sint32,sint32*(*)(sint32*,uint16),uint8 (*)(sint32*,sint32*));
static void merge(sint32*,uint16,sint32*,uint16,sint32*,sint32*(*)(sint32*,uint16),uint8 (*)(sint32*,sint32*));
static void heapify(sint32*,uint16,uint16,sint32*(*)(sint32*,uint16),void(*)(sint32*,sint32*),uint8 (*)(sint32*,sint32*));


uint8 selectionSort(sint32* genericList , uint16 genericListLength , sint32* (*getIndexRef)(sint32*,uint16),
					void(*swapFunction)(sint32*,sint32*) , uint8 (*compareFunction)(sint32*,sint32*))
{
	uint16 outerCounter,innerCounter,valueIndex;

	/*Sort the whole list*/
	for (outerCounter = 0 ; outerCounter < (genericListLength-1) ; outerCounter ++)
	{
		/*Set the selected item to be the local minimum/maximum value*/
		valueIndex = outerCounter;

		/*Iterate to find the absolute minimum/maximum value if exists*/
		for (innerCounter = (outerCounter+1) ; innerCounter < genericListLength ; innerCounter ++)
		{
			/*Abstract compare function*/
			if(	compareFunction( getIndexRef(genericList,innerCounter) ,	getIndexRef(genericList,valueIndex) ) )
			{
				valueIndex = innerCounter;
			}

		}

		/*Swap the selected local minimum/maximum value with the absolute minimum value*/
		if(valueIndex != outerCounter)
		{
			/*Abstract swap function*/
			swapFunction ( getIndexRef(genericList,valueIndex) , getIndexRef(genericList,outerCounter) );
		}
	}

	return TRUE;
}


uint8 bubbleSort(sint32* genericList , uint16 genericListLength , sint32* (*getIndexRef)(sint32*,uint16),
				void(*swapFunction)(sint32*,sint32*) , uint8 (*compareFunction)(sint32*,sint32*))
{
	uint8 swapFlag;
	uint16 outerCounter,innerCounter;
	sint32 *firstValueRef,*secondValueRef;

	/*Iterate over all the array*/
	for (outerCounter = 0 ; outerCounter < (genericListLength-1) ; outerCounter ++)
		{
			swapFlag = FALSE;

			/*Iterate over all elements in each iteration == > O(n**2)*/
			for (innerCounter = 0 ; innerCounter < (genericListLength-1) ; innerCounter ++)
			{

					firstValueRef  =  getIndexRef(genericList,innerCounter+1);
					secondValueRef =  getIndexRef(genericList,innerCounter);

					/*Abstract compare function*/
					if ( compareFunction( firstValueRef , secondValueRef )  )
					{

						/*Abstract swap function*/
						swapFunction ( firstValueRef , secondValueRef );

						/*Optimization swap flag*/
						swapFlag = TRUE;
					}
			}

			/*Check if the array is now sorted or already sorted ==> O(n)*/
			if ( swapFlag == FALSE )
				break;

		}

	return TRUE;
}

void insertElement(sint32* array, uint16 arrayLength, sint32 element,
				   sint32*(*getIndexRef)(sint32*,uint16), uint8 (*compareFunction)(sint32*,sint32*))
{
	uint16 counter;
	sint32 *counterElementRef, *nextCounterElementRef;

	for(counter = (arrayLength-1) ; counter >= 0 ; counter --)
	{
		counterElementRef = getIndexRef(array,counter);

		if ( compareFunction(&element,counterElementRef) )
		{
			break;
		}
		else
		{
			nextCounterElementRef = getIndexRef(array,counter+1);

			*nextCounterElementRef = *counterElementRef;
			*counterElementRef = element;

		}

		if (counter == 0)
			break;

	}

}

uint8 insertionSort(sint32* genericList, uint16 genericListLength, sint32*(*getIndexRef)(sint32*,uint16),
					void(*swapFunction)(sint32*,sint32*) , uint8 (*compareFunction)(sint32*,sint32*))
{

	uint16 counter,sortedLength = 1;

	/*Divide the list into two lists (sorted (element 0) and unsorted (1===>last element) inclusive)*/
	/*iterate over the unsorted list*/
	for (counter = 1 ; counter < genericListLength ; counter++)
	{
		/*Insert the unsorted selected item in the sorted part of the list with the provided insertion function*/
		insertElement(genericList,sortedLength,*getIndexRef(genericList,counter),getIndexRef,compareFunction);

		/*Increment the size of the sorted list by 1*/
		sortedLength++;
	}

	return TRUE;
}



uint8 quickSort(sint32* genericList , uint16 genericListLength , sint32* (*getIndexRef)(sint32*,uint16),
				void(*swapFunction)(sint32*,sint32*) , uint8 (*compareFunction)(sint32*,sint32*))
{

	sint32 pivotElementIndex = 0 , comparedElementIndex = genericListLength - 1, *pivotElementRef,*comparedElementRef;

	/*Base condition to stop recursion*/
	if (genericListLength == 1 || genericListLength == 0)
		return TRUE;

	/*Sort the pivot element*/
	while( pivotElementIndex != comparedElementIndex )
		{
		  	   pivotElementRef	   =  getIndexRef(genericList,pivotElementIndex);
		  	   comparedElementRef  =  getIndexRef(genericList,comparedElementIndex);

		  	 if (*pivotElementRef < *comparedElementRef)
		  	 	{

		  	 		if ( pivotElementIndex < comparedElementIndex)
		  	 		{
		  	 			/*Decrement second pointer, change element to be compared with*/
		  	 			comparedElementIndex --;
		  	 		}
		  	 		else
		  	 		{
		  	 			/*Swap pivot with the compared element*/
		  	 			swapFunction(pivotElementRef,comparedElementRef);

		  	 			/*Decrement pivot Index*/
		  	 			pivotElementIndex --;

		  	 			/*Swap pivot and compared indexes*/
		  	 			swapFunction(&pivotElementIndex,&comparedElementIndex);
		  	 		}

		  	 	}
		  	 	else
		  	 	{
		  	 		if ( pivotElementIndex < comparedElementIndex)
		  	 		{
		  	 			/*Swap pivot with the compared element*/
		  	 			swapFunction(pivotElementRef,comparedElementRef);

		  	 			/*Increment pivot index*/
		  	 			pivotElementIndex ++;

		  	 			/*Swap pivot and compared indexes*/
		  	 			swapFunction(&pivotElementIndex,&comparedElementIndex);

		  	 		}
		  	 		else
		  	 		{
		  	 			/*Increment compared index*/
		  	 			comparedElementIndex ++;
		  	 		}
		  	 	}

		}

		   /*Sort The left unsorted list*/
	return quickSort(getIndexRef(genericList,0),pivotElementIndex,getIndexRef,swapFunction,compareFunction) &&
		   /*Sort The right unsorted list*/
		   quickSort(getIndexRef(genericList,pivotElementIndex+1),(genericListLength-1)-pivotElementIndex,getIndexRef,swapFunction,compareFunction);


}



uint8 mergeSort(sint32* array, uint16 arrayLength, sint32* mergedArray,
				sint32* (*getIndexRef)(sint32*,uint16), uint8 (*compareFunction)(sint32*,sint32*))
{


	uint16 leftArrayLen = arrayLength/2 , secondArrayLen = arrayLength - arrayLength/2;

	if ( arrayLength == 1 || arrayLength == 0)
		return TRUE;

	mergeSort(array,leftArrayLen,mergedArray,getIndexRef,compareFunction);
	mergeSort(&array[leftArrayLen],secondArrayLen,mergedArray,getIndexRef,compareFunction);
	merge(array,leftArrayLen,&array[leftArrayLen],secondArrayLen,mergedArray,getIndexRef,compareFunction);


	return TRUE;
}




static void merge(sint32* firstGenericList, uint16 firstGenericListLen, sint32* secondGenericList, uint16 secondGenericListLen, sint32* mergedGenericList,
		   sint32* (*getIndexRef)(sint32*,uint16), uint8 (*compareFunction)(sint32*,sint32*))
{
	uint16 firstGenericListRef = 0, secondGenericListRef = 0 , mergedGenericListRef = 0 ;
	sint32 *firstElementPtr, *secondElementPtr, *mergedElementPtr;

	/*Iterate over both lists till the maxlength of any of them*/
	while( firstGenericListRef != firstGenericListLen && secondGenericListRef != secondGenericListLen)
	{
		/*Get all the required elements pointers*/
		firstElementPtr  = getIndexRef(firstGenericList,firstGenericListRef);
		secondElementPtr = getIndexRef(secondGenericList,secondGenericListRef);
		mergedElementPtr = getIndexRef(mergedGenericList,mergedGenericListRef);

		/*Compare between the first and second element*/
		if( compareFunction(firstElementPtr, secondElementPtr) )
		{
			/*Swap the referenced first element to the merged list*/
			*mergedElementPtr = *firstElementPtr;
			/*Increment the reference of the first element to get the next first from the same first list*/
			firstGenericListRef ++;
		}
		else
		{
			/*Swap the referenced second element to the merged list*/
			*mergedElementPtr = *secondElementPtr;
			/*Increment the reference of the second element to get the next second from the same second list*/
			secondGenericListRef ++;
		}

		/*Increment the place to be swapped to*/
		mergedGenericListRef ++;
	}


	/*Check if there any elements left in the first list*/
	if(firstGenericListRef != firstGenericListLen)
	{
		/*swap all the left elements to the merged list*/
		while( firstGenericListRef != firstGenericListLen )
		{
			firstElementPtr  = getIndexRef(firstGenericList,firstGenericListRef);
			mergedElementPtr = getIndexRef(mergedGenericList,mergedGenericListRef);

			*mergedElementPtr = *firstElementPtr;
			firstGenericListRef ++;
			mergedGenericListRef ++;
		}

	}
	else
	{
		/*Check if there any elements left in the second list*/

		/*swap all the left elements to the merged list*/
		while( secondGenericListRef != secondGenericListLen )
		{
			secondElementPtr = getIndexRef(secondGenericList,secondGenericListRef);
			mergedElementPtr = getIndexRef(mergedGenericList,mergedGenericListRef);

			*mergedElementPtr = *secondElementPtr;
			secondGenericListRef ++;
			mergedGenericListRef ++;
		}

	}


}



static void heapify(sint32*genericList, uint16 listlength, uint16 rootNodeIndex, sint32* (*getIndexRef)(sint32*,uint16),
		void(*swapFunction)(sint32*,sint32*), uint8 (*compareFunction)(sint32*,sint32*))
{

	uint16 rootIndex = rootNodeIndex,
		   leftChildIndex = (2*rootIndex) + 1,
		   rightChidIndex = (2*rootIndex) + 2;

	/*Compare root element with the left child*/
	if(leftChildIndex < listlength)
	{
		if( compareFunction(getIndexRef(genericList, leftChildIndex), getIndexRef(genericList, rootIndex)) )
		{
			/*Swap left to the root*/
			rootIndex = leftChildIndex;
		}
	}


	/*Compare root element with the right child*/
	if(rightChidIndex < listlength)
	{
		if( compareFunction(getIndexRef(genericList, rightChidIndex), getIndexRef(genericList, rootIndex))  )
		{
			/*Swap right to the root*/
			rootIndex = rightChidIndex;
		}
	}

	/*Base Condition*/
	/*Check if there the left or right child are smalled than the root, so it has changed*/
	if(rootIndex != rootNodeIndex)
	{
		/*Swap root(smallest from root,left and right) with the given root*/
		swapFunction(getIndexRef(genericList, rootNodeIndex), getIndexRef(genericList, rootIndex));

		/*Heapify starting from the swapped previous root element to reflect all the changes to the new subtree*/
		heapify(genericList,listlength,rootIndex,getIndexRef,swapFunction,compareFunction);
	}

}

uint8 heapSort(sint32* genericList, uint16 listLength, sint32* (*getIndexRef)(sint32*,uint16),
			   void(*swapFunction)(sint32*,sint32*), uint8 (*compareFunction)(sint32*,sint32*))
{

	uint16 lastNonLeafNodeIndex,index;

	/*Build the heap data structure*/
	lastNonLeafNodeIndex = listLength/2 - 1;

	/*Start heapifying starting from that last non leaf node and up to the root*/
	for(index = lastNonLeafNodeIndex ; (index >=0 && index < listLength); index--)
	{
		heapify(genericList,listLength,index,getIndexRef,swapFunction,compareFunction);
	}

	/*Sort each element (Heapify each element as it becomes the new root)*/
	for(index = listLength-1 ; (index >=0 && index < listLength) ; index--)
	{
		/*Swap the first sorted element to the last of the list (beginning of previous sorted list)*/
		/*Last unsorted element (most right) was chosen to keep the heap data structure (complete binary tree)*/
		swapFunction(getIndexRef(genericList,0), getIndexRef(genericList,index));

		/*Adjust list to neglect all swapped sorted elements and reheapify from the first element always*/
		/*It will be compared with the right and left children, the right/left path will be decided accordingly after comparison*/
		heapify( genericList, index, 0, getIndexRef, swapFunction, compareFunction);

	}

	return TRUE;
}
