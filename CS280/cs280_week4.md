# Week 4 - CS280 (Monday)
## Topic: Introduction to Sorting Algorithms
---
## Benefits of Sorting Algorithm
- Sorted output helps in faster search.
# Four attributes of Sorting Algorithms
## Stable or Unstable.
- If you give an input with some elements and there is duplicate elements, after sorting the array; if the duplicate elements preserve their order than that means its stable. If the duplicate elements change position then its unstable.
  - Stable algorithm maintains the relative orders of keys.
  - The advantage of this is that stable algorithm allows sorting based on multiple criterias and having the other sort criteria take advantage of the already sorted parts. 
## Adaptive or Non-adaptive
  - Such algorithm can take advantage of sorted parts in the input array.
    - Can be either space, time taken or correctness.
## Loop invariant
  - A loop invariant is a condition [among program variables] that is necessarily true immediately before and immediately after each iteration of a loop.
    - Helps prove the correct-ness of an algorithm
## In-place or Out-of-place
```
int temp = a[i];
a[i] = a[j];
a[j] = temp;
```
  - Whether the algorithm uses temporary variables or not.
  - In-place algorithm uses only few additional memory for its execution.
    - Strictly in-place means no additional memory is used.
  - Out of place uses a relatively large amount of additional memory for its execution.
## Sorting Algorithm Visualization
![sorting algo](https://i.imgur.com/fq0A8hx.gif)
## Bubble-sort
```
begin BubbleSort(list)

   for all elements of list
      if list[i] > list[i+1]
         swap(list[i], list[i+1])
      end if
   end for
   
   return list
   
end BubbleSort
```
Big-oh of Bubble sort is O(N^2)
- Can we make it even better?
```
for (int i = 0; i < (N-1) ; i++)
{
  for(int j = 0; j < (N-i-1); j++)
  {
    if (a[j] > a[j+1])
    swap(a[j],a[j+1])
  }
}
```
- This improved algorthim is better in the following ways.
  - Stable
    - Duplicate element orders are preserved since the algorthim will skip over them
- However this algorithm isnt adaptive
  - Still doing comparisions with latter elements that are already sorted.
  - Adding a swap check will help, if the algorithm goes reaches the array end wihout doing a swap then break out.
    - That way, we don't need to reach the end to finish but can break out early if the latter elements are already sorted.
```
for (int i = 0; i < (N-1) ; i++)
{
  bool swap_check = false;
  for(int j = 0; j < (N-i-1); j++)
  {
    if (a[j] > a[j+1]){
      swap_check = true;
      swap(a[j],a[j+1]);
    }
    if (swap_check == false) break;
  }
}
```
## Selection Sort
```
repeat (numOfElements - 1) times
  set the first unsorted element as the minimum
  for each of the unsorted elements
    if element < currentMinimum
      set element as new minimum
  swap minimum with first unsorted position
```
- The Big O for Selection sort is N^2 since it iterates through the input set N times for every elements (where N is the number of elements).
```
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(arr[min_idx], arr[i]); 
    } 
} 
```
- Characteristics of Selection Sort
  - Stable
  - Inplace
  - Not Adaptive
  - Loop invariant
## Insertion Sort
```
i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while
```
- The Big O of insertion sort is N^2
```
void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 
```
- Characteristics of Insertion Sort
  - Stable
  - Inplace
  - Adaptive
  - Loop invariant
## Merge Sort
```
function merge_sort(list m)
    // Base case. A list of zero or one elements is sorted, by definition.
    if length of m ≤ 1 then
        return m

    // Recursive case. First, divide the list into equal-sized sublists
    // consisting of the first half and second half of the list.
    // This assumes lists start at index 0.
    var left := empty list
    var right := empty list
    for each x with index i in m do
        if i < (length of m)/2 then
            add x to left
        else
            add x to right

    // Recursively sort both sublists.
    left := merge_sort(left)
    right := merge_sort(right)

    // Then merge the now-sorted sublists.
    return merge(left, right)
```
![Merge-sort](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)
- Merge Sort is a divide and conquer algorithm which divides the problem into smaller, easily managable parts.
- The Big O for Merge Sort is O(n log(n))
```
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 6
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
```
- Computing Complexity of Merge Sort
  - as a math function, it can be represented as the following
  - f(1) (No sort), or f(n/2) + f(n/2) + merge function
  - merge copies over the elements so its time complexity is n
  - f(n/2) + f(n/2) + n = 2f(n/2) + n
- Characteristics of Merge Sort
  - Stable
    - Maintains relative order of keys
  - Out of place
    - Extra arrays need to be created to store the subsets.
  - Not Adaptive
    - Doesn't make use of sorted elements
  - Loop invariant