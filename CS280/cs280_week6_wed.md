# Week 6 - CS280 (Wednesday)
## Topic: Abstract Data Types
---
## Quicksort Analysis/Revision
- Quicksort uses the following
  - Pivot
    - Pivot can be any index of the array.
  - Left Indicator
    - Starts off at the leftmost index of the range
  - Swap Indicator
    - Starts off as Left Indicator - 1 (S=L-1)

![Quicksort](https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif)
```
Step 1 − Choose the highest index value has pivot
Step 2 − Take two variables to point left and right of the list excluding pivot
Step 3 − left points to the low index
Step 4 − right points to the high
Step 5 − while value at left is less than pivot move right
Step 6 − while value at right is greater than pivot move left
Step 7 − if both step 5 and step 6 does not match swap left and right
Step 8 − if left ≥ right, the point where they met is new pivot
```
- Code implementation for Quick sort (one way)
  - Note there are different implementation of the same algorithm
```
function partitionFunc(left, right, pivot)
   leftPointer = left
   rightPointer = right - 1

   while True do
      while A[++leftPointer] < pivot do
         //do-nothing            
      end while
		
      while rightPointer > 0 && A[--rightPointer] > pivot do
         //do-nothing         
      end while
		
      if leftPointer >= rightPointer
         break
      else                
         swap leftPointer,rightPointer
      end if
		
   end while 
	
   swap leftPointer,right
   return leftPointer
	
end function
```
- And the actual code itself, note that it is recursive.
```
procedure quickSort(left, right)

   if right-left <= 0
      return
   else     
      pivot = A[right]
      partition = partitionFunc(left, right, pivot)
      quickSort(left,partition-1)
      quickSort(partition+1,right)    
   end if		
   
end procedure
```
## Abstract Data Types
- Queue

