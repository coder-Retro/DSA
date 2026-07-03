# 🔍 Search Algorithms

> **"Searching is the process of locating a specific element within a collection of data."**

Searching is one of the most fundamental operations in computer science. Whether you're looking for a username in a database, a word in a dictionary, or a file on your computer, you're using a search algorithm.

This chapter introduces two of the most important searching techniques:

* **Linear Search** – Simple and works on any collection.
* **Binary Search** – Extremely fast but requires sorted data.

Understanding **when** to use each algorithm is just as important as understanding **how** they work.

---

# 📖 Prerequisites

Before studying this chapter, you should understand:

* Arrays
* Loops
* Functions
* Conditional Statements
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand how searching algorithms work.
* Compare Linear Search and Binary Search.
* Choose the appropriate search algorithm for different scenarios.
* Analyze time and space complexity.
* Avoid common implementation mistakes.

---

# 📂 Directory Structure

```text
Search/
├── LinearSearch.cpp
├── BinarySearch.cpp
└── README.md
```

---

# 📄 Files in this Chapter

## 🔹 `LinearSearch.cpp`

Introduces the simplest searching algorithm.

### Concepts Covered

* Sequential traversal
* Element comparison
* Searching unsorted arrays
* Early termination

---

## 🔹 `BinarySearch.cpp`

Introduces one of the fastest searching algorithms.

### Concepts Covered

* Divide and Conquer
* Midpoint calculation
* Searching sorted arrays
* Reducing search space

---

# 🧠 Choosing the Right Search Algorithm

```text
                 Need to Search?
                       │
                       ▼
          Is the data sorted?
              │             │
             Yes            No
              │              │
              ▼              ▼
      Binary Search     Linear Search
```

If your data isn't sorted and you only need to search once, **Linear Search** is usually the simplest solution.

If your data is sorted—or can be sorted once and searched many times—**Binary Search** is almost always the better choice.

---

# 🔍 Linear Search

Linear Search checks every element one by one until the target is found or the collection ends.

### Advantages

* Works on sorted and unsorted data.
* Very easy to implement.
* No preprocessing required.

### Disadvantages

* Slow for large datasets.
* May examine every element.

### Complexity

| Case    | Time |
| ------- | ---- |
| Best    | O(1) |
| Average | O(n) |
| Worst   | O(n) |

---

# ⚡ Binary Search

Binary Search repeatedly divides the search space into two halves.

Instead of checking every element, it eliminates half of the remaining data after each comparison.

### Requirements

✔ Data **must be sorted**.

### Advantages

* Extremely fast.
* Excellent for large datasets.

### Disadvantages

* Requires sorted input.
* Slightly more complex to implement.

### Complexity

| Case    | Time     |
| ------- | -------- |
| Best    | O(1)     |
| Average | O(log n) |
| Worst   | O(log n) |

---

# 📊 Linear Search vs Binary Search

| Feature                     | Linear Search | Binary Search |
| --------------------------- | ------------- | ------------- |
| Sorted Data Required        | ❌             | ✅             |
| Worst-Case Time             | O(n)          | O(log n)      |
| Best-Case Time              | O(1)          | O(1)          |
| Easy to Implement           | ⭐⭐⭐⭐⭐         | ⭐⭐⭐           |
| Suitable for Small Datasets | ✅             | ✅             |
| Suitable for Large Datasets | ❌             | ✅             |

---

# 🌍 Real-World Applications

### Linear Search

* Small datasets
* Unsorted collections
* Simple lookup operations

### Binary Search

* Dictionary lookup
* Database indexing
* Search engines
* Library catalogs
* Version control systems
* Large sorted datasets

---

# ⚠️ Common Mistakes

## Linear Search

* Forgetting to stop after finding the target.
* Searching beyond array bounds.

---

## Binary Search

* Applying Binary Search to unsorted data.
* Incorrect midpoint calculation.
* Off-by-one errors.
* Incorrectly updating `low` and `high`.

A safer midpoint calculation is:

```cpp
mid = low + (high - low) / 2;
```

This avoids potential integer overflow in very large datasets.

---

# 🎯 Suggested Practice

Try solving these problems after completing this chapter:

### Linear Search

* Find First Occurrence
* Find Last Occurrence
* Count Frequency
* Search in an Unsorted Array

### Binary Search

* Search Insert Position
* First Bad Version
* Guess Number Higher or Lower
* Find Peak Element
* Search in Rotated Sorted Array
* Square Root using Binary Search

---

# 📝 Key Takeaways

* Linear Search works on **any** dataset but scales poorly.
* Binary Search is significantly faster but requires **sorted data**.
* Choosing the correct algorithm depends on the characteristics of the input.
* Understanding algorithm selection is just as important as implementation.

---

# 🔗 Continue Learning

⬅️ Previous: **Algorithms**

➡️ Next: **Sorting Algorithms**

🏠 Back to: **Algorithms**

🏠 Repository Home
