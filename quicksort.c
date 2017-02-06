#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#include "sort.h"

int partition(long int *a, int lo, int hi) {
  int i = lo, j = hi + 1;
  int v = a[lo];
  while (1) {
    while (a[++i] < v) {
      if (i == hi) {
	break; } }
    while (v < a[--j]) {
      if (j == lo) {
	break; } }
    if (i >= j ) {
      break; }
    int temp = a[i]; a[i] = a[j]; a[j] = temp; }
  int temp = a[lo]; a[lo] = a[j]; a[j] = temp; 
  return j; }

void second_sort (long int *a, int lo, int hi) {
  if (hi <= lo) {return; }
  int j = partition(a, lo, hi);
  second_sort(a, lo, j-1);
  second_sort(a, j+1, hi); }
  
void quicksort (long int *a, long int n) {
  second_sort(a, 0, n -1); }
 
