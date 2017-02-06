#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <assert.h>

#include "sort.h"

/***************************************************************
 * Insertion sort
 */

void insertion_sort (long int *a, long int n) {
  if (n <= 0) { /* Watch out for tricks! */
    return;
  }

  for (long int i = 1; i < n; i++) {
    for (long int j = i; (j > 0) && (a[j] < a[j-1]); j--) {
      long int tmp = a[j]; a[j] = a[j-1]; a[j-1] = tmp;
    }
  }
}

int is_sorted (long int *a, long int n)
{
  for (long int i = 0; i < n-1; i++) {
    if (a[i] > a[i+1]) {
      return 0;
    }
  }
  return 1;
}

int are_identical (long int *a, long int *b, long int n)
{
  long int sum = 0;
  for (int k = 0; k < n; k++) {
    sum += abs(a[k] - b[k]);
  }
  return (!sum);
}

void recursive_mergesort (long int *a, long int n) {
  if (n <= 0) {
    return;
  }
  
  if (n <= 42){
    insertion_sort(a,n);
  }
  
  else {
  	long int* list = (long int*)malloc(n * sizeof(long int));
  	for (int i = 0; i < n; i++) {
  		list[i] = a[i];
  	}
    long int l = list[0];
    long int r = list[n-1];
    
    if (l < r)
    {
      int m = l + (r-l)/2;
      int index;
      for (int j = 0;j < n; j++) {
      	if (m == list[j]) {
      		index = j;
      	}
      }
      long int first[index];
      for (int x = 0; x < index; x++) {
      	first[x] = list[x];
      }
      
      long int second[n - index];
      for (int y = index; y < n; y++) {
      	second[y] = list[y];
      }
      recursive_mergesort(first,m);
      recursive_mergesort(second,n - index);
       int n1 = m - l + 1;
	  int n2 = r - m;
	  int L[n1], R[n2];
	  for (int i=0;i<n1;i++) {
	    L[i] = a[l+i];
	    }
	  for (int j=0;j<n2;j++) {
	    R[j] = a[m+1+j];
	    }
	  int i,j,k;
	  
	  i = 0;
	  j = 0;
	  k = 1;
	  while (i < n1 && j < n2){
	    if (L[i] <= R[j])
	    {
	      a[k] = L[i];
	      i++;
	    }
	    else {
	      a[k] = R[j];
	      j++;
	    }
	    k++;
	  }
	  while (i < n1) {
	    a[k] = L[i];
	    i++;
	    k++;
	  }
	  while (j < n2) {
	    a[k] = R[j];
	    j++;
	    k++;
	  }
	}
	      
    }
    
  }


void quicksort (long int *a, long int n) {
	int l = 0;
	if (l < n) {
	//divide & conquer
		int pivot, i, j, z, size;
		size = sizeof(a);
		pivot = a[l];
		i = l; j = size + 1;
		while (1) {
			while (a[i] <= pivot && i <= size) {
				i++; }
			while (a[j] > pivot) {
				j--; }
			if ( i >= j ) break;
			int temp = a[i]; a[i] = a[j]; a[j] = temp; }
		int temp = a[l]; a[l] = a[j]; a[j] = temp;
		quicksort(a, j-1); 
		l = j + 1;
		if (l < n) {
	//divide & conquer #2
		int pivot, i, j, z, size;
		size = sizeof(a);
		pivot = a[l];
		i = l; j = size + 1;
		while (1) {
			while (a[i] <= pivot && i <= size) {
				i++; }
			while (a[j] > pivot) {
				j--; }
			if ( i >= j ) break;
			int temp = a[i]; a[i] = a[j]; a[j] = temp; }
		temp = a[l]; a[l] = a[j]; a[j] = temp; } } }

int main() {
return 0; }

			


