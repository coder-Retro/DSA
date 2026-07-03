# 🔄 Sorting Algorithms

> **"Sorting is the process of arranging data in a specific order to improve efficiency and simplify processing."**

Sorting is one of the most fundamental operations in computer science. Efficient sorting improves searching, data organization, duplicate detection, and countless other algorithms.

This chapter introduces some of the most commonly taught sorting algorithms, progressing from beginner-friendly techniques to more advanced divide-and-conquer approaches.

---

# 📖 Prerequisites

Before studying sorting algorithms, you should understand:

* Arrays
* Loops
* Functions
* Swapping Elements
* Recursion (recommended for Merge Sort)
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand why sorting is important.
* Compare different sorting algorithms.
* Analyze time and space complexity.
* Recognize when each sorting algorithm is appropriate.
* Understand the concepts of **stability** and **in-place sorting**.

---

# 📂 Directory Structure

```text
Sort/
├── BubbleSort.cpp
├── SelectionSort.cpp
├── InsertionSort.cpp
├── ExchangeSort.cpp
├── MergeSort.cpp
└── README.md
```

---

# 📄 Files in this Chapter

## 🔹 BubbleSort.cpp

Introduces one of the simplest sorting algorithms.

Concepts Covered:

* Adjacent swaps
* Multiple passes
* Early termination optimization

---

## 🔹 SelectionSort.cpp

Demonstrates selecting the smallest element during each iteration.

Concepts Covered:

* Minimum element selection
* Swapping strategy
* Reduced number of swaps

---

## 🔹 InsertionSort.cpp

Builds a sorted portion of the array one element at a time.

Concepts Covered:

* Incremental sorting
* Element shifting
* Efficient handling of nearly sorted arrays

---

## 🔹 ExchangeSort.cpp

Illustrates sorting by exchanging out-of-order elements.

Concepts Covered:

* Pairwise comparisons
* Element swapping
* Basic sorting logic

---

## 🔹 MergeSort.cpp

Introduces the Divide and Conquer paradigm.

Concepts Covered:

* Recursive division
* Merging sorted halves
* Stable sorting
* Efficient large-scale sorting

---

# 🧠 How to Choose a Sorting Algorithm

```text
Need to Sort?
       │
       ▼
Small Dataset?
   │         │
 Yes        No
 │           │
 ▼           ▼
Insertion   Need Stability?
Sort           │       │
               Yes     No
               │        │
               ▼        ▼
          Merge Sort  Merge Sort*
```

> **Note:** In this repository, **Merge Sort** is the most efficient algorithm covered for large datasets.

---

# 📊 Sorting Algorithm Comparison

| Algorithm      |    Best    |   Average  |    Worst   | Space | Stable | In-Place |
| -------------- | :--------: | :--------: | :--------: | :---: | :----: | :------: |
| Bubble Sort    |    O(n)    |    O(n²)   |    O(n²)   |  O(1) |    ✅   |     ✅    |
| Selection Sort |    O(n²)   |    O(n²)   |    O(n²)   |  O(1) |    ❌   |     ✅    |
| Insertion Sort |    O(n)    |    O(n²)   |    O(n²)   |  O(1) |    ✅   |     ✅    |
| Exchange Sort  |    O(n²)   |    O(n²)   |    O(n²)   |  O(1) |    ❌   |     ✅    |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) |  O(n) |    ✅   |     ❌    |

---

# 📚 Stable vs Unstable Sorting

A sorting algorithm is **stable** if equal elements retain their original relative order after sorting.

### Stable Algorithms

* Bubble Sort
* Insertion Sort
* Merge Sort

### Unstable Algorithms

* Selection Sort
* Exchange Sort

Stability becomes important when sorting records using multiple keys.

---

# 💾 In-Place vs Out-of-Place

### In-Place

Uses little or no additional memory.

Examples:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Exchange Sort

---

### Out-of-Place

Requires additional memory.

Example:

* Merge Sort

The extra memory allows Merge Sort to achieve significantly better performance on larger datasets.

---

# 🌍 Real-World Applications

### Bubble Sort

* Educational purposes
* Demonstrating sorting concepts

### Selection Sort

* Situations where minimizing swaps is important

### Insertion Sort

* Small datasets
* Nearly sorted arrays

### Merge Sort

* Large datasets
* External sorting
* Stable sorting requirements
* Divide and Conquer algorithms

---

# ⚠️ Common Mistakes

When implementing sorting algorithms, beginners often:

* Forget loop boundaries.
* Swap incorrect indices.
* Assume every algorithm is stable.
* Ignore additional memory requirements.
* Miscalculate recursive base cases in Merge Sort.

Always test your implementation using:

* Empty arrays
* Single-element arrays
* Already sorted arrays
* Reverse sorted arrays
* Arrays with duplicate values

---

# 🎯 Suggested Practice

After completing this chapter, try implementing:

* Merge Two Sorted Arrays
* Sort Colors
* Relative Sort Array
* Sort Characters by Frequency
* Kth Largest Element
* Merge Intervals

These problems reinforce sorting concepts and frequently appear in coding interviews.

---

# 📝 Key Takeaways

* Different sorting algorithms excel in different situations.
* Merge Sort offers the best asymptotic performance among the algorithms in this section.
* Stability and memory usage are important considerations alongside time complexity.
* Understanding trade-offs is more valuable than memorizing implementations.

---

# 🔗 Continue Learning

⬅️ Previous: **Search Algorithms**

➡️ Next: **Calculative Algorithms**

🏠 Back to: **Algorithms**

🏠 Repository Home
