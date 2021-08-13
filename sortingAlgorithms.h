
#ifndef SORTINGALGORITHMS_H_
#define SORTINGALGORITHMS_H_


#include "std_types.h"


/* ------------------------------------------------------------
 *Function-Name:
 *
 *Description: This function performs selection sort algorithm
 *
 *Inputs:
 *		sint32* 		==> pointer to signed 32 bit element ( generic list to be sorted)
 *		uint16  		==> generic list length
 *		getIndexRef     ==> pointer to function to get the reference of an element using its index.
 *		swapFunction 	==> pointer to function to state how can you swap 2 elements.
 *		compareFunction ==> pointer to function to state how can you compare between 2 elements.
 *
 *Returns: TRUE if success / FALSE if it fails
 *
 *--------------------------------------------------------------*/
uint8 selectionSort(sint32*,uint16,sint32*(*)(sint32*,uint16),void(*)(sint32*,sint32*),uint8 (*)(sint32*,sint32*));


/* ------------------------------------------------------------
 *Function-Name:
 *
 *Description: This function performs bubble sort algorithm
 *
 *Inputs:
 *		sint32* 		==> pointer to signed 32 bit element ( generic list to be sorted)
 *		uint16  		==> generic list length
 *		getIndexRef     ==> pointer to function to get the reference of an element using its index.
 *		swapFunction 	==> pointer to function to state how can you swap 2 elements.
 *		compareFunction ==> pointer to function to state how can you compare between 2 elements.
 *
 *Returns: TRUE if success / FALSE if it fails
 *
 *--------------------------------------------------------------*/
uint8 bubbleSort(sint32*,uint16,sint32*(*)(sint32*,uint16),void(*)(sint32*,sint32*),uint8 (*)(sint32*,sint32*));




/* ------------------------------------------------------------
 *Function-Name:
 *
 *Description: This function performs insertion sort algorithm
 *
 *Inputs:
 *		sint32* 		==> pointer to signed 32 bit element ( generic list to be sorted)
 *		uint16  		==> generic list length
 *		getIndexRef     ==> pointer to function to get the reference of an element using its index.
 *		swapFunction 	==> pointer to function to state how can you swap 2 elements.
 *		compareFunction ==> pointer to function to state how can you compare between 2 elements.
 *
 *Returns: TRUE if success / FALSE if it fails
 *
 *--------------------------------------------------------------*/
uint8 insertionSort(sint32*,uint16,sint32*(*)(sint32*,uint16),void(*)(sint32*,sint32*),uint8 (*)(sint32*,sint32*));



/* ------------------------------------------------------------
 *Function-Name:
 *
 *Description: This function performs quick sort algorithm
 *
 *Inputs:
 *		sint32* 		==> pointer to signed 32 bit element ( generic list to be sorted)
 *		uint16  		==> generic list length
 *		getIndexRef     ==> pointer to function to get the reference of an element using its index.
 *		swapFunction 	==> pointer to function to state how can you swap 2 elements.
 *		compareFunction ==> pointer to function to state how can you compare between 2 elements.
 *
 *Returns: TRUE if success / FALSE if it fails
 *
 *--------------------------------------------------------------*/
uint8 quickSort(sint32*,uint16,sint32*(*)(sint32*,uint16),void(*)(sint32*,sint32*),uint8 (*)(sint32*,sint32*));



/* ------------------------------------------------------------
 *Function-Name:
 *
 *Description: This function performs merge sort algorithm
 *
 *Inputs:
 *		sint32* 		==> pointer to signed 32 bit element ( generic list to be sorted)
 *		uint16  		==> generic list length
 *		sint32* 		==> sorted array pass by reference ( merge sort requires O(n) space )
 *		getIndexRef     ==> pointer to function to get the reference of an element using its index.
 *		swapFunction 	==> pointer to function to state how can you swap 2 elements.
 *		compareFunction ==> pointer to function to state how can you compare between 2 elements.
 *
 *Returns: TRUE if success / FALSE if it fails
 *
 *--------------------------------------------------------------*/
uint8 mergeSort(sint32*,uint16,sint32*,sint32*(*)(sint32*,uint16),uint8(*)(sint32*,sint32*));



/* ------------------------------------------------------------
 *Function-Name:
 *
 *Description: This function performs heap sort algorithm
 *
 *Inputs:
 *		sint32* 		==> pointer to signed 32 bit element ( generic list to be sorted)
 *		uint16  		==> generic list length
 *		getIndexRef     ==> pointer to function to get the reference of an element using its index.
 *		swapFunction 	==> pointer to function to state how can you swap 2 elements.
 *		compareFunction ==> pointer to function to state how can you compare between 2 elements.
 *
 *Returns: TRUE if success / FALSE if it fails
 *
 *--------------------------------------------------------------*/
uint8 heapSort(sint32*,uint16,sint32*(*)(sint32*,uint16),void(*)(sint32*,sint32*),uint8 (*)(sint32*,sint32*));



#endif /* SORTINGALGORITHMS_H_ */
