#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#include "sort.h"
#define min(x, y) ((x) < (y) ? (x) : (y))

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

void iterative_mergesort (long int *a, long int n) {
  int N = n;
  long int* aux = (long int*)malloc(n * sizeof(long int));
  int sz, lo;
  for (sz = 1; sz < N; sz = sz+sz) {
    for (lo = 0; lo < N - sz; lo += sz+sz) {
      merge1(a, lo, lo+sz-1, min(lo+sz+sz-1, N-1), aux); } } 
  free(aux);
}

