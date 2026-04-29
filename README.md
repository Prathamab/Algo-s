# lab1:


1. Power of xⁿ using Binary Exponentiation (Recursive)
Aim

To efficiently compute x raised to the power n using divide and conquer approach.

Algorithm
int fastPower(int base, int exponent) {
    if(exponent == 0)
        return 1;

    int halfValue = fastPower(base, exponent / 2);

    if(exponent % 2 == 0)
        return halfValue * halfValue;
    else
        return base * halfValue * halfValue;
}

Time Complexity

At each step exponent becomes exponent / 2

Total recursive calls ≈ log₂(n)

Time Complexity: O(log n)
Space Complexity: O(log n) (due to recursion stack)

Use Case

Cryptography algorithms like RSA

Competitive programming modular exponentiation

Large power calculations efficiently

2. String Permutations
Aim

To generate all possible permutations of characters of a string and analyze execution time.

Algorithm
void generatePermutation(string &str, int left, int right) {
    if(left == right) {
        return;
    }

    for(int pos = left; pos <= right; pos++) {
        swap(str[left], str[pos]);
        generatePermutation(str, left + 1, right);
        swap(str[left], str[pos]);   // Backtracking
    }
}

Time Complexity

Time: O(n × n!)
Space: O(n)

Use Case

Password generation

Anagram problems

Brute force search

3. Horner’s Rule (Polynomial Evaluation)
Aim

To evaluate polynomial efficiently using recursive Horner’s method.

Algorithm
long long hornerEvaluate(vector<int> &coef, int valueX, int index) {

    if(index == coef.size() - 1)
        return coef[index];

    return coef[index] + valueX * hornerEvaluate(coef, valueX, index + 1);
}

Time Complexity

Time: O(n)
Space: O(n) recursive, O(1) iterative

Use Case

Polynomial calculation

Compiler optimization

Numerical methods

4. Tower of Hanoi
Aim

To solve Tower of Hanoi using recursion and measure execution time.

Algorithm
void solveHanoi(int disks, char source, char helper, char destination) {

    if(disks == 0)
        return;

    solveHanoi(disks - 1, source, destination, helper);
    solveHanoi(disks - 1, helper, source, destination);
}

Time Complexity

Time: O(2ⁿ)
Space: O(n)

Use Case

Recursion understanding

Divide and conquer concept

5. Bubble Sort and Selection Sort
Aim

To sort arrays and analyze execution time of simple sorting algorithms.

Bubble Sort Algorithm
void bubbleSorting(vector<int> &arrData) {
    int size = arrData.size();

    for(int pass = 0; pass < size - 1; pass++) {
        for(int pos = 0; pos < size - pass - 1; pos++) {
            if(arrData[pos] > arrData[pos + 1])
                swap(arrData[pos], arrData[pos + 1]);
        }
    }
}

Selection Sort Algorithm
void selectionSorting(vector<int> &arrData) {
    int size = arrData.size();

    for(int step = 0; step < size - 1; step++) {
        int minIndex = step;

        for(int check = step + 1; check < size; check++) {
            if(arrData[check] < arrData[minIndex])
                minIndex = check;
        }

        swap(arrData[step], arrData[minIndex]);
    }
}

Time Complexity

Bubble Sort: O(n²)
Selection Sort: O(n²)

Use Case

Learning sorting basics

Small dataset sorting

6. Missing Number using Bitwise Idea
Aim

To detect missing number in sequence using bitwise logic.

Algorithm
int detectMissing(int arrValues[], int length) {

    for(int i = 0; i < length - 1; i++) {

        if((arrValues[i] & 1) == (arrValues[i+1] & 1)) {
            return (arrValues[i] + arrValues[i+1]) / 2;
        }
    }

    return -1;
}

Time Complexity

Time: O(n)
Space: O(1)

Use Case

Bitwise programming

Sequence analysis

7. findTips (Velocity Reduction Recursion)
Aim

To calculate number of tips until velocity becomes less than 1.

Algorithm
int countTips(double velocity) {

    if(velocity < 1.0)
        return 0;

    return 1 + countTips(velocity - 0.425 * velocity);
}

Time Complexity

Time: O(v)
Space: O(v) recursion stack

Use Case

Recursion depth understanding

Simulation problems

8. Truth Table Generation
Aim

To generate boolean truth table combinations using recursion.

Algorithm
void generateTruthTable(int index, int total) {

    if(index > total)
        return;

    arr[index] = true;
    generateTruthTable(index + 1, total);

    arr[index] = false;
    generateTruthTable(index + 1, total);
}

Time Complexity

Time: O(2ⁿ)
Space: O(n)

Use Case

Digital logic

Boolean algebra

Circuit design

9. Linear Search
Aim

To search element sequentially in array and analyze execution time.

Algorithm
void sequentialSearch(int arrData[], int size) {

    int key = rand();

    for(int pos = 0; pos < size; pos++) {
        if(arrData[pos] == key)
            break;
    }
}

Time Complexity

Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)

Space Complexity: O(1)

Use Case

Small datasets

Unsorted arrays

2nd
## lab 2:

# Binary Search
 Aim
To search an element in a sorted array using Binary Search.
 Theory
Binary Search works only on a sorted array. It checks the middle element first.
If the element is found, search stops.
If the element is smaller, search moves to the left side.
If bigger, search moves to the right side.
This reduces the number of comparisons.

 Algorithm
1.Take number of elements
2.Enter sorted array
3.Enter element to search
4.Find middle element
5.If middle element matches, stop
6.If smaller, search left side
7.If bigger, search right side
8.Repeat until found or search ends

Input
1.Number of elements
2.Sorted array elements
3.Element to search

Output

Position of element if found
Message if element is not found
Time Taken
Less because half array is removed every step

Time Complexity
O(log n)

Conclusion
Binary Search is faster than linear search for sorted data.

 ## Insertion Sort
 
 Aim
To sort elements using Insertion Sort.
#Theory
Insertion Sort works like arranging playing cards in hand.
It takes one element at a time and places it in the correct position.
The left part remains sorted and new elements are inserted properly.

Algorithm


Take number of elements

1. Enter array elements
2. Start from second element
3. Compare with previous elements
4. Shift bigger elements to the right
5. Insert current element in correct place
6. Repeat until all elements are sorted


Input
1.Number of elements
2.Array elements

Output
Sorted array

Time Taken
Good for small number of elements

Time Complexity
O(n²)

Conclusion
Insertion Sort is simple and useful for small datasets.

3rd
# lab: 3

Analysis of Merge Sort and Quick Sort
Overview
This repository contains the implementation and analysis of two important sorting algorithms:

Merge Sort
Quick Sort (Left element as pivot)

Both algorithms were implemented in C++ to calculate their execution time for different input sizes.
The obtained results were then used in Python to plot graphs showing the relationship between input size and execution time.

Algorithms Implemented

Merge Sort
Uses the divide and conquer technique
Recursively divides the array into halves
Merges sorted subarrays to produce the final sorted array

Time Complexity:
Best / Average / Worst: O(n log n)

Quick Sort
Uses leftmost element as pivot
Partitions the array around the pivot
Recursively sorts the subarrays

Time Complexity:

Best / Average: O(n log n)
Worst: O(n²) (already sorted input)

Time Measurement

Execution time was calculated in C++ using the clock() function
Input sizes ranged from 1000 to 10000
Average time per element (in microseconds) was computed
For small input sizes, execution time appears as 0 due to clock resolution limits

Graph Plotting Using Python

The output time values obtained from C++ programs were stored in Python arrays
Matplotlib was used to plot graphs

Graphs plotted:

Input Size vs Average Time (Merge Sort)
Input Size vs Average Time (Quick Sort)
These graphs help visualize and verify the theoretical time complexities of the algorithms.

Technologies Used

C++ – Algorithm implementation and time calculation
Python – Graph plotting
Matplotlib – Visualization library
GitHub – Version control and project hosting

4th

# lab 4: Kth Smallest Element Using Partition Algorithm (Quickselect)

1. Description

    This program finds the Kth smallest element in an unsorted array using the Partition Algorithm (based on Quick Sort).
    
    The approach used is called Quickselect Algorithm, which works similarly to Quick Sort but only processes the part of the array that contains the required element.

2. Algorithm Used

    Uses Partition function
    
    Selects first element as pivot
    
    Places pivot in its correct sorted position
    
    Recursively searches only the required side of the array
    
    This improves efficiency compared to fully sorting the array.

3. How It Works

    Choose the first element as pivot.
    
    Rearrange elements:
    
    Smaller elements → left side
    
    Larger elements → right side
    
    Get pivot index.
    
    Compare pivot index with k.
    
    If equal → element found.
    
    If greater → search left subarray.
    
    If smaller → search right subarray.

4. Code Features

    Uses recursion
    
    Implements partition logic manually
    
    Does not sort full array
    
    Time Complexity:
    
    Average Case: O(n)
    
    Worst Case: O(n²)

   5th
   ## lab 5:
   
  # Convex Hull (Brute Force)
Aim

To find convex hull points using brute force method.

Theory

Convex Hull is the smallest boundary covering all points.

Algorithm
1.Take all points.
2.Check if a point lies inside any triangle.
3.If yes, it is not extreme.
4.Remaining points form convex hull.

Input
1.Number of points
2.Coordinates

Output
Convex hull points

Time Complexity

O(n⁴)

Conclusion

Brute force checks all possibilities but works slowly for large input.

## (Greedy Method Comparison)
Aim

To compare greedy methods for solving knapsack problem.

Theory

Items have profit and weight. We try different greedy methods like profit, weight, and ratio to get best result.

Algorithm
1.Take items and capacity.
2.Sort by profit
3.Sort by weight
4.Sort by ratio
5.Compare total profit
6.Select best method

Input
Number of items
Profit and weight
Capacity

Output
Selected items
Total profit
Best method
Time Complexity

O(n log n)

Conclusion

Greedy methods help compare different selection strategies.

6th

 # lab 6 :
 
# Dijkstra’s Algorithm

Aim

To find the shortest distance from source node to all other nodes.

Theory

Dijkstra’s Algorithm finds shortest path in weighted graph where weights are positive.

Algorithm

1.Choose source node.
2.Mark source distance as 0.
3.Find nearest unvisited node.
4.Update distances.
5.Repeat until all nodes are visited.

Input
Number of nodes
Edges with weights
Source node

Output
Shortest distance from source to all nodes

Time Complexity

O(n²)

Conclusion

Dijkstra gives shortest path efficiently for positive weights.

# Prim’s Algorithm
Aim

To find Minimum Spanning Tree using Prim’s Algorithm.

Theory

Minimum Spanning Tree connects all vertices with minimum total cost and no cycles.

Algorithm
1.Start from one vertex.
2.Find minimum cost edge.
3.Add new vertex.
4.Repeat until all vertices are connected.

Input
Number of vertices
Cost matrix

Output
MST edges
Total minimum cost
Time Complexity

O(n²)

Conclusion

Prim’s Algorithm builds MST by selecting minimum edges step by step.

7th

# lab 7 : Kruskal’s Algorithm

Aim

To find Minimum Spanning Tree using Kruskal’s Algorithm.

Theory

Kruskal’s Algorithm selects smallest edges first while avoiding cycles.

Algorithm
1.Sort all edges by weight.
2.Pick smallest edge.
3.Check cycle.
4.Add edge if no cycle.
5.Repeat until MST is complete.

Input
Number of vertices
Number of edges
Edge details

Output
MST edges
Total minimum cost

Time Complexity

O(E log E)

Conclusion

Kruskal gives MST by choosing smallest safe edges.



8th

# Lab-08: Rod Cutting Problem (Dynamic Programming)

## Aim

To implement the Rod Cutting problem using Dynamic Programming and visualize the maximum profit using a graph in Python.

## Theory

The Rod Cutting problem is a classic Dynamic Programming problem where the goal is to determine the maximum profit obtainable by cutting a rod of length n into smaller pieces and selling them. The idea is to try all possible cuts and choose the one that gives the maximum profit. Dynamic Programming is used to store intermediate results and avoid recomputation.

## Algorithm

1. Initialize a DP array to store maximum profit for each length
2. For each rod length i, try all possible cuts j
3. Compute maximum value using price[j] + dp[i - j - 1]
4. Store the maximum value in dp[i]
5. Repeat until the full length is evaluated

## Input

Rod length (n) and an array of prices where price[i] represents the value of a rod of length (i + 1).

## Output

Maximum obtainable profit for the given rod length.

## Graph Visualization

A Python program is used to plot a graph with rod length on the x-axis and maximum profit on the y-axis. This helps in understanding how profit increases with length using Dynamic Programming.

## Time Complexity

O(n^2)

## Conclusion

The Rod Cutting problem demonstrates the effectiveness of Dynamic Programming in optimization problems. It ensures maximum profit by considering all possible cuts and visualizing the result using a graph improves understanding.

9th

# Lab-09:Multistage Graph

Aim

To find the shortest path in a multistage graph using Dynamic Programming.

Theory

A multistage graph has vertices divided into stages. We move only forward stage by stage.

Algorithm
1. Start from destination.
2. Move backward.
3. Find minimum cost for each node.
4. Store best path.
5.Print shortest path.

Input
Number of stages
Graph edges and weights

Output
Shortest path
Minimum cost

Time Complexity

O(n²)

Conclusion

Dynamic Programming helps find shortest path efficiently.

10th

# Lab-10:Matrix Chain Multiplication

Aim

To find the minimum number of multiplications needed to multiply matrices.

Theory

Different orders of matrix multiplication give different costs. Matrix Chain Multiplication finds the best order with minimum operations.

Algorithm
1. Take matrix dimensions.
2. Store cost as 0 for single matrix.
3. Try all possible splitting points.
4. Find multiplication cost.
5. Store minimum value.
   
Input
Number of matrices
Dimensions of matrices

Output
Minimum number of multiplications

Time Complexity

O(n³)

Conclusion

Best multiplication order reduces total operations.



# Lab-11:Travelling Salesperson Problem (Dynamic Programming)
Aim

To find the minimum cost path that visits all cities exactly once and returns to the starting city using Dynamic Programming.

Theory

Travelling Salesperson Problem (TSP) is used to find the shortest possible route that visits every city exactly once and returns to the starting point. Dynamic Programming helps reduce repeated calculations.

Algorithm
1. Start from the first city.
2. Mark visited cities using mask.
3. Try all unvisited cities one by one.
4. Calculate cost for each path.
5. Store minimum cost.
6. Return the smallest total cost.
 
Input
Number of cities
Distance matrix
Output
Minimum travelling cost
Time Taken

Less for small inputs

Time Complexity

O(n² × 2ⁿ)

Conclusion

Dynamic Programming makes TSP faster by avoiding repeated calculations.

# Lab-12:N-Queen Problem (Backtracking)

Aim

To place N queens on a chessboard so that no two queens attack each other.

Theory

Queens attack in row, column, and diagonal directions. Backtracking tries all safe positions and returns when wrong placement happens.

Algorithm
1. Start from first row.
2. Try every column.
3. Check if safe.
4. Place queen if safe.
5. Move to next row.
6. If fail, go back and try again.
   
Input
Number of queens
Output
Valid arrangement of queens
Time Complexity

O(N!)

Conclusion

Backtracking helps solve problems by trying and undoing steps.




