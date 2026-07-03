# 🧮 Calculative Algorithms

> **"Some algorithms don't organize data—they compute, optimize, and solve mathematical problems efficiently."**

Not every algorithm is designed to search or sort. Many algorithms are created to solve specific computational problems using mathematical insights or optimization techniques.

This chapter introduces two classic examples:

* **Euclidean Algorithm** – Efficiently computes the Greatest Common Divisor (GCD) of two integers.
* **Kadane's Algorithm** – Finds the maximum sum contiguous subarray in linear time.

Although these algorithms solve very different problems, they share a common goal: achieving efficient solutions through clever reasoning rather than brute force.

---

# 📖 Prerequisites

Before studying this chapter, you should understand:

* Variables
* Loops
* Functions
* Arrays
* Modulus Operator (`%`)
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand mathematical optimization algorithms.
* Compute the Greatest Common Divisor efficiently.
* Solve maximum subarray problems using Kadane's Algorithm.
* Recognize optimization problems where brute force is unnecessary.
* Analyze algorithmic efficiency.

---

# 📂 Directory Structure

```text
Calculative/
├── Euclidean.cpp
├── Kadanes.cpp
└── README.md
```

---

# 📄 Files in this Chapter

## 🔹 Euclidean.cpp

Implements the **Euclidean Algorithm**, one of the oldest known algorithms still widely used today.

### Concepts Covered

* Greatest Common Divisor (GCD)
* Modulus operation
* Mathematical recursion/iteration
* Number theory fundamentals

---

## 🔹 Kadanes.cpp

Implements **Kadane's Algorithm**, a classic dynamic programming technique for finding the maximum sum contiguous subarray.

### Concepts Covered

* Running sum
* Greedy optimization
* Dynamic Programming intuition
* Maximum Subarray Problem

---

# 🧠 Algorithm Selection

```text
Need to Solve?

        │
        ▼
Is it about numbers?
        │
       Yes
        │
        ▼
Need Greatest Common Divisor?
        │
      Yes ─────────► Euclidean Algorithm
        │
       No
        │
        ▼
Maximum Sum Subarray?
        │
      Yes ─────────► Kadane's Algorithm
```

---

# 📊 Complexity Comparison

| Algorithm           |        Time       | Space |
| ------------------- | :---------------: | :---: |
| Euclidean Algorithm | O(log(min(a, b))) |  O(1) |
| Kadane's Algorithm  |        O(n)       |  O(1) |

Both algorithms demonstrate how mathematical insight can dramatically outperform naive approaches.

---

# 🌍 Real-World Applications

## Euclidean Algorithm

Used in:

* Fraction simplification
* Cryptography
* Number theory
* Modular arithmetic
* RSA encryption foundations

---

## Kadane's Algorithm

Used in:

* Financial profit analysis
* Signal processing
* Performance analytics
* Data science
* Stock market trend analysis

---

# ⚠️ Common Mistakes

### Euclidean Algorithm

* Forgetting that GCD is always non-negative.
* Mishandling zero as input.
* Incorrect modulus operations.

---

### Kadane's Algorithm

* Initializing the maximum sum incorrectly.
* Failing to handle arrays containing only negative values.
* Confusing contiguous subarrays with arbitrary subsets.

Always test edge cases such as:

* Empty arrays (if applicable)
* Single-element arrays
* All-negative arrays
* Large integer values

---

# 🎯 Suggested Practice

After completing this chapter, try implementing:

### Euclidean Algorithm

* Least Common Multiple (LCM)
* Extended Euclidean Algorithm
* Modular Inverse

### Kadane's Algorithm

* Maximum Circular Subarray
* Maximum Product Subarray
* Maximum Sum Rectangle
* Best Time to Buy and Sell Stock

These problems extend the concepts introduced in this chapter and are common in technical interviews.

---

# 📝 Key Takeaways

* Not all algorithms are designed for searching or sorting.
* The Euclidean Algorithm efficiently computes the GCD using repeated division.
* Kadane's Algorithm finds the maximum sum contiguous subarray in linear time.
* Mathematical insight often leads to elegant and highly efficient solutions.

---

# 🔗 Continue Learning

⬅️ Previous: **Sorting Algorithms**

➡️ Next: **Data Structures**

🏠 Back to: **Algorithms**

🏠 Repository Home
