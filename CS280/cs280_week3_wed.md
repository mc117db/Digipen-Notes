# Week 3 - CS280 (Wednesday)
## Topic: Performance
---
## Binary Search
- Psuedo Code for Binary Search
```
function binary_search(A, n, T):
    L := 0
    R := n − 1
    while L <= R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else if A[m] > T:
            R := m - 1
        else:
            return m
    return unsuccessful
```
- For each comparision, the search space gets smaller by half
- The execution time calculation can be represented by (n+1)/2.
  - This can also be representated by logbase2(N)
    - Where N is the number of elements.
## Common Growth Rates
- Constant time elementary operations **0(1)**
  - one arithmetic operation
  - one assignment
  - one test (eg x== 0)
  - one read
  - one write of a primitive type..
- Estimating the Growth Rate
  - Sequences
    ```
    void voi()
    {
      int a; // C1
      int b; // C2
      int c; // C3
    }

    // Function voi have a time complexity = total amount of statements (3)
    ```
  - Conditionals
    - if = O(N)
    - Else = O(N^2)
  - Function Calls
  - Loops (most important)
    ```
    void Op(int steps){
      for (int i = 0; i < steps; i++){
        // a single operation
      }
    }
    ```
    - Case 1 - Op(1);
      - The number of times the single statement is executed is 1 there its O(1)
    - Case 2 - Op(5);
      - The number of times the single statement is executed is 5. It is still O(1)
        - This is because the number of executions required is constant to the data size. 5 = 5
    - Case 3
    ```
    for (int i = 0; i < 5; i++)
    {
      Op(1);
    }
    ```
    - The number of times the single statement is executed is still O(1) as its being executed 5 times.
    - Case 4
    ```
    void Case4(void){
      Op(N);
      Op(500);
    }
    ```
    - Op(N) -> O(N)
    - Op(500) -> O(1)
    - The dominant term in this scenario is O(N), even though there is O(N) in this execution, we only care about the worst case where N is the larger than 500.
    - Therefore the Big O for Case 4 is O(N)
    - Case 5
    ```
    void Case5(void){
      for (int i = 0; i < N; i++)
      {
        Op(1);
      }
      Op(N);
    }
    ```
    - T(N) = N x C1 + N x C2 = N(C1+C2)
    - Remember, We only care about the N value in this scenario
    - Therefore the time complexity is O(N)
    - Case 6
    ```
    void Case6(void)
    {
      Op(N*N);
      for (int i = 0; i < N; i++)
      {
        Op(5);
      }
      Op(1000)l
    }
    ```
    - T(n) = (N^2 X C1) + (N x C2) + C3
    - The Big O is N^2 as it is the most dominant term.
    - Case7
    ```
    void Case7(void){
      for(int i = 0; i < 5; i++)
      {
        Op(N);
      }
    }
    ```
    - T(N) = 5 x C1 x N
    - Again the most dominant term is N therefore it is O(N)
    - Case8
    ```
    void Case8(void){
      for (int i = 0; i < N; i++){
        Op(N);
      }
    }
    ```
    - T(N) = C1(NxN) = N^2
    - Therefore the Big O is N^2
    - Case9
    ```
    void Case9(void){
      for(int i = 0; i < 10; i++)
      {
        for (int j=0; j < N; j++)
        {
          Op(N);
        }
      }
    }
    ```
    - T(N) = C1 X 10 x N x N = 10C1(N^2)
    - The most dominant term is N^2 therefore Big O is N^2
    - Case10
    ```
    void Case10(void){
      for(int i = 0; i < N; i++)
      {
        for (int j=0; j < N; j++)
        {
          Op(N);
        }
      }
    }
    ```
    - T(N) = C1 X N x N x N = C1N^3
    - The most dominant term is N^3 therefore Big O is N^3
    - Case11
    ```
    void Case11(void){
      if (/*conditional*/){
        Op(N);
      }
      else{
        Op(500);
      }
    }
    ```
    - Result 1 = T(N) = C1 X N
    - Result 2 = T(N) = C1 X 500
    - The most dominant term is N still so its O(N)