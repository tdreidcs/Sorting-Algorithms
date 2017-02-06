#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <assert.h>
#include "sort.h"

void merge1 (long int*a, int lo, int mid, int hi, long int *aux) {
  int i = lo, j = mid + 1;
  int k;
  for (k = lo; k <= hi; k++) {
    aux[k] = a[k]; }
  for (k = lo; k <= hi; k++) {
    if (i > mid) {a[k] = aux[j++];}
    else if (j > hi) {a[k] = aux[i++];}
    else if (aux[j] < aux[i]) {a[k] = aux[j++];}
    else { a[k] = aux[i++]; } } }

void first_sort (long int *a, int lo, int hi, long int *aux) {
  if (hi <= lo) {return; }
  if (hi - lo + 1<= 42) {
    insertion_sort (a+lo, *a+hi-lo+1); }
  int mid = lo + (hi - lo)/2;
  first_sort(a, lo, mid, aux);
  first_sort(a, mid+1, hi, aux);
  merge1(a, lo, mid, hi, aux); }
 
void insertion_sort_duplicate (long int *a, long int n) {
  if (n <= 0) { /* Watch out for tricks! */
    return;
  }
  long int i, j;
  for (i = 1; i < n; i++) {
    for (j = i; (j > 0) && (a[j] < a[j-1]); j--) {
      long int tmp = a[j]; a[j] = a[j-1]; a[j-1] = tmp;
    }
  }
}

void recursive_mergesort (long int *a, long int n) {
  long int* aux = (long int*)malloc(n * sizeof(long int));
  first_sort(a, 0, n-1, aux);
  free(aux); }


