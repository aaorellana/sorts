#include <math.h>
#include <limits.h>
#include <stdio.h>
#include "Sorts.h"

void insertionSort(int *array, int size);

void bubbleSort(int *array, int size);

void selectionSort(int *array, int size);

//merge sort recursive call, divides the problem into sub problems
void mergeSort(int *array, int begining, int end);

//combines all the sub arrays into the original
void merge(int *array, int begining, int middle, int end);

void quickSort(int *array, int p, int r);

void swap(int *array, int i, int j);
//help from Introduction to Algorithms third edition

void insertionSort(int *array, int size)
{
	int i;
	int j;
	int temp;

	for(i = 0; i <= size; i++)
	{
		j = i;
		//inserts the value in the correct index and shifts the elements to the right
		while((j > 0) && (array[j - 1] > array[j]))
		{	//swaps the elements
			swap(array, j - 1, j);
			j = j - 1;
		}
	}
	
}

//help from http://en.wikipedia.org/wiki/Bubble_sort
void bubbleSort(int *array, int size)
{
	int i;
	int temp;
	int swapped;
	
	//loops until no elements have been swapped
	while(swapped != 0)
	{
		swapped = 0;
		for(i = 1; i < size; i++)
		{
			if(array[i - 1] > array[i])
			{	//swaps the elements
				swap(array, i, i - 1);
				swapped = 1;
			}
		}
	}
	
}

void selectionSort(int *array, int size)
{
	int i;
	int j;
	int min;
	int temp;
	
	for(j = 0; j < size - 1; j++)
	{
		min = j;
		//looks for the smallest value
		for(i = j + 1; i < size; i++)
		{
			if(array[i] < array[min])
			{
				min = i;
			}
		}
		if(min != j)
		{	//swaps the elements
			swap(array, min, j);
		}
		
	}
	
}

//splits the array into sub arrays to sort them
void mergeSort(int *Array, int begining, int end)
{
	int middle;
	if(begining < end)
	{
		middle = floor((begining + end) / 2);
		mergeSort(Array, begining, middle);
		mergeSort(Array, middle + 1, end);
		merge(Array, begining, middle, end);
	}
}

//combines the elements into the original array in sorted order
void merge(int *Array, int begining, int middle, int end)
{
	int i;
	int j;
	int k;
	int n1 = middle - begining + 1;
	int n2 = end - middle;
	int leftArray[n1 + 1];
	int rightArray[n2 + 1];
	//stores the left part of the array into a new array
	for(i = 1; i <= n1; i++)
	{
		leftArray[i] = Array[begining + i - 1];
	}
	//stores the right part of the array into a new array
	for(j = 1; j <= n2; j++)
	{
		rightArray[j] = Array[middle + j];
	}

	leftArray[n1 + 1] = INT_MAX;
	rightArray[n2 + 1] = INT_MAX;
	i = 1;
	j = 1;
	//puts the elements in sorted order into the original array
	for(k = begining; k <= end; k++)
	{
		if(leftArray[i] <= rightArray[j])
		{
			Array[k] = leftArray[i];
			i = i + 1;
		}
		else
		{
			Array[k] = rightArray[j];
			j = j + 1;
		}
	}
	
	
}

//divides the problem into sub problems
void quickSort(int *array, int p, int r)
{
	int q;
	if(p < r)
	{
		q = partition(array, p, r);
		quickSort(array, p, q - 1);
		quickSort(array, q + 1, r);
	}
}

//creates partition
int partition(int *array, int p, int r)
{
	int i;
	int x;
	int j;
	int temp;
	
	x = array[r];
	i = p - 1;
	
	for(j = p; j < r; j++)
	{
		if(array[j] <= x)
		{
			i = i + 1;
			//swaps the elements
			swap(array, i, j);
			
		}
	}
	//swaps the elements
	swap(array, i + 1, r);
	
	return i + 1;
}

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
	
}
