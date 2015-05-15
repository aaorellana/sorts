#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Sorts.h"

int average(int *array1, int size, int code);

int main(int argc, char *argv[])
{   
	FILE *fp;
	char *func = argv[1];
	char *filename = argv[3];
	int i = 0;
	int num;
	int size = strtol(argv[2], NULL, 10);
	int array1[size];
	clock_t start_t, end_t;
	double time;

	fp = fopen(filename, "r");

	while(fscanf(fp, "%d", &num) > 0)
	{
		array1[i] = num;
		i++;
	}

    fclose(fp);


	//calls the function and gives it the parameters
    switch(func[0])
    {
    	case 'i': time = average(array1, size, 1);
    		break;
    	case 's': time = average(array1, size, 2);
    		break;
    	case 'b': time = average(array1, size, 3);
    		break;
    	case 'm': time = average(array1, size, 4);
    		break;
    	case 'q': time = average(array1, size, 5);
    		break;
    	default: puts("command not found");
    	
    }
    
    printf("%f", time);

	return 0;
}

int average(int *array1, int size, int code)
{
	int array2[size];
	int array3[size];
	int array4[size];
	int array5[size];
	int array6[size];
	int array7[size];
	int array8[size];
	int array9[size];
	int array10[size];
	int i;
	double time = 0;
	clock_t start_t, end_t;
	
	//copies array1 to the rest of the arrays
	for(i = 0; i <= size; i++)
	{
		array2[i] = array1[i];
		array3[i] = array1[i];
		array4[i] = array1[i];
		array5[i] = array1[i];
		array6[i] = array1[i];
		array7[i] = array1[i];
		array8[i] = array1[i];
		array9[i] = array1[i];
	}

	switch(code)
	{
		case 1: start_t = clock();
				insertionSort(array1, size);	
				insertionSort(array2, size);	
				insertionSort(array3, size);
				insertionSort(array4, size);	
				insertionSort(array5, size);	
				insertionSort(array6, size);	
				insertionSort(array7, size);	
				insertionSort(array8, size);	
				insertionSort(array9, size);	
				insertionSort(array10, size);	
				end_t = clock();
				time = (double)(end_t - start_t);
			break;
		case 2: start_t = clock();
				selectionSort(array1, size);	
				selectionSort(array2, size);	
				selectionSort(array3, size);	
				selectionSort(array4, size);	
				selectionSort(array5, size);	
				selectionSort(array6, size);	
				selectionSort(array7, size);	
				selectionSort(array8, size);	
				selectionSort(array9, size);	
				selectionSort(array10, size);	
				end_t = clock();
				time = (double)(end_t - start_t);
			break;
		case 3: start_t = clock();
				bubbleSort(array1, size);	
				bubbleSort(array2, size);	
				bubbleSort(array3, size);	
				bubbleSort(array4, size);	
				bubbleSort(array5, size);	
				bubbleSort(array6, size);	
				bubbleSort(array7, size);	
				bubbleSort(array8, size);	
				bubbleSort(array9, size);	
				bubbleSort(array10, size);	
				end_t = clock();
				time = (double)(end_t - start_t);
			break;
		case 4: start_t = clock();
				mergeSort(array1, 0, size);	
				mergeSort(array2, 0, size);	
				mergeSort(array3, 0, size);	
				mergeSort(array4, 0, size);	
				mergeSort(array5, 0, size);	
				mergeSort(array6, 0, size);	
				mergeSort(array7, 0, size);	
				mergeSort(array8, 0, size);	
				mergeSort(array9, 0, size);	
				mergeSort(array10, 0, size);	
				end_t = clock();
				time = (double)(end_t - start_t);
			break;
		case 5: start_t = clock();
				quickSort(array1, 0, size);	
				quickSort(array2, 0, size);	
				quickSort(array3, 0, size);	
				quickSort(array4, 0, size);	
				quickSort(array5, 0, size);	
				quickSort(array6, 0, size);	
				quickSort(array7, 0, size);	
				quickSort(array8, 0, size);	
				quickSort(array9, 0, size);	
				quickSort(array10, 0, size);	
				end_t = clock();
				time = (double)(end_t - start_t);
			break;
		default: puts("command not found");
	}

	return time / 10;
}