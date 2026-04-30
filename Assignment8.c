/* ================================================================
   PROGRAM 1 — Bubble Sort
   (shows array after each pass, counts comparisons & swaps)
   === START ===
================================================================ */
 
#include <stdio.h>
 
void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    int comparisons = 0, swaps = 0;
 
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swaps++;
                swapped = 1;
            }
        }
        printf("After pass %d: ", i + 1);
        print(a, n);
        if (!swapped) break;   /* already sorted */
    }
 
    printf("\nSorted array: ");
    print(a, n);
    printf("Total Comparisons: %d\n", comparisons);
    printf("Total Swaps      : %d\n", swaps);
 
    return 0;
}
 
 
/* ================================================================
   PROGRAM 2 — Selection Sort
   (shows array after each pass, counts comparisons & swaps)
   === START ===
================================================================ */
#include <stdio.h>
 
void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    int comparisons = 0, swaps = 0;
 
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int t = a[i]; a[i] = a[min]; a[min] = t;
            swaps++;
        }
        printf("After pass %d: ", i + 1);
        print(a, n);
    }
 
    printf("\nSorted array: ");
    print(a, n);
    printf("Total Comparisons: %d\n", comparisons);
    printf("Total Swaps      : %d\n", swaps);
 
    return 0;
}
 
 
/* ================================================================
   PROGRAM 3 — Insertion Sort
   (shows array after inserting each element)
   === START ===
================================================================ */
#include <stdio.h>
 
void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printf("After inserting element %d: ", key);
        print(a, n);
    }
 
    printf("\nSorted array: ");
    print(a, n);
 
    return 0;
} 
 
/* ================================================================
   PROGRAM 4 — Merge Sort (Recursive)
   (clearly shows divide and merge steps)
   === START ===
================================================================ */
#include <stdio.h>
 
void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
 
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];
 
    printf("Merging: [");
    for (int i = 0; i < n1; i++) printf("%d ", L[i]);
    printf("] and [");
    for (int i = 0; i < n2; i++) printf("%d ", R[i]);
    printf("]\n");
 
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}
 
void mergesort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        printf("Dividing: left half [%d..%d], right half [%d..%d]\n", l, m, m+1, r);
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    printf("\n--- Merge Sort Steps ---\n");
    mergesort(a, 0, n - 1);
 
    printf("\nSorted array: ");
    print(a, n);
 
    return 0;
} 
 
/* ================================================================
   PROGRAM 5 — Quick Sort (Recursive, last element as pivot)
   === START ===
================================================================ */
#include <stdio.h>
 
void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
 
int partition(int a[], int l, int r) {
    int pivot = a[r], i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i + 1]; a[i + 1] = a[r]; a[r] = t;
    printf("Pivot=%d placed at index %d: ", pivot, i + 1);
    print(a, r - l + 2);   /* show current subarray context */
    return i + 1;
}
 
void quicksort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    printf("\n--- Quick Sort Steps ---\n");
    quicksort(a, 0, n - 1);
 
    printf("\nSorted array: ");
    print(a, n);
 
    return 0;
} 
 
/* ================================================================
   PROGRAM 6 — Linear Search (finds ALL occurrences)
   === START ===
================================================================ */
#include <stdio.h>
 
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
 
    int found = 0;
    printf("\nSearching for %d...\n", key);
 
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element %d found at index %d (position %d)\n", key, i, i + 1);
            found++;
        }
    }
 
    if (!found)
        printf("Element %d not found in the array.\n", key);
    else
        printf("\nTotal occurrences of %d: %d\n", key, found);
 
    return 0;
} 
 
/* ================================================================
   PROGRAM 7 — Binary Search (Recursive)
   Input must be a SORTED array
   === START ===
================================================================ */
#include <stdio.h>
 
int binary_search(int a[], int l, int r, int key) {
    if (l > r) return -1;
 
    int mid = (l + r) / 2;
    printf("Checking index %d (value %d)...\n", mid, a[mid]);
 
    if (a[mid] == key) return mid;
    if (a[mid] > key)  return binary_search(a, l, mid - 1, key);
    else               return binary_search(a, mid + 1, r, key);
}
 
int main() {
    int n;
    printf("Enter number of elements (sorted array): ");
    scanf("%d", &n);
 
    int a[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
 
    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);
 
    printf("\nSearching for %d...\n", key);
    int result = binary_search(a, 0, n - 1, key);
 
    if (result == -1)
        printf("Element %d not found.\n", key);
    else
        printf("Element %d found at index %d (position %d)\n", key, result, result + 1);
 
    return 0;
}
