<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=gradient&text=Sort&fontSize=70&fontColor=FFFFFF&animation=fadeIn&fontAlignY=35&desc=Quadratic%20Time%20%7C%20Logarithmic%20Time%20%7C%20Linear%20Time&descSize=35&descColor=FFFFFF&descAlignY=65" width="100%"/>

# 🔄 Sorting Algorithms

> **"Sorting is the process of arranging data in a specific order to improve efficiency and simplify processing."**

Sorting is one of the most fundamental operations in computer science. Efficient sorting improves searching, data organization, duplicate detection, and countless other algorithms.

This chapter introduces some of the most commonly taught sorting algorithms, progressing from beginner-friendly techniques to more advanced divide-and-conquer approaches, and finishing with two non-comparison techniques that sort without comparing elements.

---

# 📖 Prerequisites

Before studying sorting algorithms, you should understand:

* Arrays
* Loops
* Functions
* Swapping Elements
* Frequency Counting (recommended for Counting Sort)
* Recursion (recommended for Merge Sort)
* Queues (recommended for Radix Sort)
* Digit Extraction using `/` and `%` (recommended for Radix Sort)
* Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Understand why sorting is important.
* Compare different sorting algorithms.
* Analyze time and space complexity.
* Recognize when each sorting algorithm is appropriate.
* Understand the concepts of **stability** and **in-place sorting**.
* Explain how non-comparison sorting (Counting Sort and Radix Sort) differs from comparison sorting.

---

# 📂 Directory Structure

```text
2.Sort/
├── BubbleSort.cpp
├── CountingSort.cpp
├── ExchangeSort.cpp
├── HeapSort.cpp
├── InsertionSort.cpp
├── MergeSort.cpp
├── RadixSort.cpp
├── SelectionSort.cpp
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

## 🔹 CountingSort.cpp

Sorts values from a small fixed range by counting how often each one appears, instead of comparing elements.

Concepts Covered:

* Frequency array (26 lowercase letters)
* Index mapping (`c - 'a'`)
* Non-comparison sorting
* Rewriting the array from counts
* Linear time sorting

---

## 🔹 ExchangeSort.cpp

Illustrates sorting by exchanging out-of-order elements.

Concepts Covered:

* Pairwise comparisons
* Element swapping
* Basic sorting logic

---

## 🔹 HeapSort.cpp

Uses a max heap for holding values then extracts top and fills.

Concepts Covered:

* Iterative heapify
* Large extraction
* UnStable sorting

---

## 🔹 InsertionSort.cpp

Builds a sorted portion of the array one element at a time.

Concepts Covered:

* Incremental sorting
* Element shifting
* Efficient handling of nearly sorted arrays

---

## 🔹 MergeSort.cpp

Introduces the Divide and Conquer paradigm.

Concepts Covered:

* Recursive division
* Merging sorted halves
* Stable sorting
* Efficient large-scale sorting

---

## 🔹 RadixSort.cpp

Sorts integers digit by digit using one queue per digit value, instead of comparing elements.

Concepts Covered:

* Non-comparison sorting
* Digit extraction (`num/hasher%10`)
* Bucket distribution using queues
* Stable sorting (FIFO buckets)
* Negative numbers using 19 buckets

---

## 🔹 SelectionSort.cpp

Demonstrates selecting the smallest element during each iteration.

Concepts Covered:

* Minimum element selection
* Swapping strategy
* Reduced number of swaps

---

# 🔢 Counting Sort: Sorting Without Comparing

Apart from Radix Sort (covered below), every other algorithm in this chapter works by **comparing** elements. Counting Sort never compares two elements. Instead, it counts how many times each value appears and then rewrites the array in order.

This works because the values come from a small, fixed range. `CountingSort.cpp` sorts lowercase letters, so there are only 26 possible values.

### How It Works

1. Create a count array with one slot per possible value (26 slots for `'a'` to `'z'`).
2. Walk through the input once and add 1 to the slot of every element (`freq[c-'a']++`).
3. Walk through the count array from `'a'` to `'z'`, writing each letter back into the original array as many times as it was counted.

```cpp
int freq[26]={0};
for(char c:chars) freq[c-'a']++;
for(int i=0,j=0;i<26;i++)
    while(freq[i]--) chars[j++]='a'+i;
```

### Example

```text
Input:   d b a d c a

Counts:  a=2  b=1  c=1  d=2

Output:  a a b c d d
```

### Why It Is Fast

Counting Sort runs in **O(n)** time and **O(1)** space here: one pass over the input, one pass over the 26 count slots, and a count array whose size never changes.

More generally, its cost is **O(n + k)** time and **O(k)** space, where `k` is the size of the value range. When `k` is small and fixed, it beats the O(n log n) limit that applies to every comparison-based sort. When `k` is huge compared to `n`, the count array becomes wasteful.

### Limitations

* Only works when every value falls inside a small, known range.
* Cannot directly sort arbitrary data such as long strings, floating-point numbers, or very large integers.
* This version rewrites values from the counts, so it cannot carry extra data along with each value.

---

# 🔟 Radix Sort: Sorting Digit by Digit

Counting Sort needs a small value range. Radix Sort removes that restriction by sorting the numbers **one digit at a time**, so every pass only ever sees 10 possible digit values (0 to 9), no matter how large the numbers are.

`RadixSort.cpp` uses the **LSD (Least Significant Digit)** approach: sort by the ones digit, then the tens digit, then the hundreds digit, and so on. Every pass must be **stable**, otherwise the order built by the earlier digits would be destroyed.

### How It Works

1. Find how many digits the largest absolute value has (`maxDigs`).
2. For each digit position (`hasher` = 1, 10, 100, ...):
   * **Distribute:** push every number into the queue that matches its digit (`num/hasher%10`).
   * **Collect:** empty the queues from the lowest bucket to the highest, writing the numbers back into the array.
3. After `maxDigs` passes the array is sorted.

```cpp
int dig=(num/hasher%10+9);
table[dig].push(num);
```

Queues are FIFO, so numbers with the same digit come out in the order they went in. That is what keeps every pass stable.

### Example

```text
Input:        170  45  75  90  802  24  2  66

Ones pass:    0: 170 90 | 2: 802 2 | 4: 24 | 5: 45 75 | 6: 66
Collected:    170  90  802  2  24  45  75  66

Tens pass:    0: 802 2 | 2: 24 | 4: 45 | 6: 66 | 7: 170 75 | 9: 90
Collected:    802  2  24  45  66  170  75  90

Hundreds:     0: 2 24 45 66 75 90 | 1: 170 | 8: 802
Output:       2  24  45  66  75  90  170  802
```

### Negative Numbers

In C++, `%` keeps the sign of the left operand, so a digit of a negative number is negative (`-53/1%10` is `-3`). A digit therefore lies in `[-9, 9]`, which is **19** possible values, not 10.

Adding 9 shifts those values to indices `0` to `18`. Collecting from index 0 upward then visits the digits from -9 to +9, which is exactly numeric order. This is why `table` holds 19 queues.

```text
digit -9  ->  index 0
digit  0  ->  index 9
digit +9  ->  index 18
```

### Why It Is Fast

Radix Sort runs in **O(d·n)** time, where `d` is the number of digits in the largest absolute value: each pass is one O(n) sweep, and there are `d` passes. It uses **O(n)** extra space, because the queues hold every element during a pass.

For 32-bit integers `d` is at most 10, so the cost is effectively linear and is not bound by the O(n log n) limit of comparison sorts. When the numbers have far more digits than `log n`, a comparison sort can win.

### Limitations

* Sorts integers (or data that can be split into digit-like keys). It cannot directly sort floating-point numbers.
* Not in-place: it needs O(n) extra memory.
* One very large value forces `maxDigs` passes over the whole array.
* Extracting decimal digits with `/` and `%` is slower than bit operations. Production implementations usually work in base 256 with shifts and masks.

---

# 🧠 How to Choose a Sorting Algorithm

```text
                    Need to Sort?
                          │
                          ▼
            Values in a small fixed range?
             │                           │
            Yes                         No
             │                           │
             ▼                           ▼
       Counting Sort              Small Dataset?
                                   │          │
                                  Yes         No
                                   │          │
                                   ▼          ▼
                               Insertion  Need Stability?
                                 Sort        │       │
                                            Yes      No
                                             │       │
                                             ▼       ▼
                                       Merge Sort  Heap Sort
```

> **Note:** In this repository, **Merge Sort** is the most efficient *comparison-based* algorithm covered for large, general-purpose datasets. **Counting Sort** is faster still (O(n)), but only when the values fall inside a small, fixed range. **Radix Sort** extends that idea to larger integers, including negatives, by sorting one digit at a time in O(d·n).

---

# 📊 Sorting Algorithm Comparison

| Algorithm      |    Best    |   Average  |    Worst   | Space | Stable | In-Place |
| -------------- | :--------: | :--------: | :--------: | :---: | :----: | :------: |
| Bubble Sort    |    O(n)    |    O(n²)   |    O(n²)   |  O(1) |    ✅   |     ✅    |
| Selection Sort |    O(n²)   |    O(n²)   |    O(n²)   |  O(1) |    ❌   |     ✅    |
| Insertion Sort |    O(n)    |    O(n²)   |    O(n²)   |  O(1) |    ✅   |     ✅    |
| Exchange Sort  |    O(n²)   |    O(n²)   |    O(n²)   |  O(1) |    ❌   |     ✅    |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) |  O(n) |    ✅   |     ❌    |
| Counting Sort  |    O(n)    |    O(n)    |    O(n)    |  O(1) |    ❌   |     ✅    |
| Radix Sort     |   O(d·n)   |   O(d·n)   |   O(d·n)   |  O(n) |    ✅   |     ❌    |

> **Note:** Counting Sort's general cost is O(n + k) time and O(k) space, where `k` is the size of the value range. In `CountingSort.cpp` the range is fixed at 26 letters, so `k` is a constant and the costs simplify to O(n) and O(1).

> **Note:** In Radix Sort, `d` is the number of digits in the largest absolute value. For 32-bit integers `d` is at most 10, so the cost is effectively linear.

---

# 📚 Stable vs Unstable Sorting

A sorting algorithm is **stable** if equal elements retain their original relative order after sorting.

### Stable Algorithms

* Bubble Sort
* Insertion Sort
* Merge Sort
* Radix Sort (FIFO queues keep each pass stable)

### Unstable Algorithms

* Selection Sort
* Exchange Sort
* Counting Sort (the frequency-count version used here)

Counting Sort can be made stable by using prefix sums and an output array, but the version in this repository rewrites values from counts, so it makes no promise about the order of equal records. For plain characters this makes no visible difference, because equal characters are identical.

Radix Sort depends on stability: every digit pass must keep the order produced by the previous pass, which is why it uses FIFO queues as buckets.

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
* Counting Sort (only a fixed 26-slot count array)

---

### Out-of-Place

Requires additional memory.

Examples:

* Merge Sort
* Radix Sort (the queues hold all `n` elements during each pass)

The extra memory allows Merge Sort to achieve significantly better performance on larger datasets, and lets Radix Sort hold elements in buckets between passes.

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

### Counting Sort

* Sorting characters inside strings (for example, building anagram keys)
* Data with a small fixed range, such as ages, grades, or digits
* Frequency analysis
* As the stable per-digit pass inside many Radix Sort implementations

### Radix Sort

* Large sets of integers with a bounded number of digits (IDs, phone numbers, timestamps)
* Fixed-width numeric keys
* Sorting by several keys, from the least significant key to the most significant

---

# ⚠️ Common Mistakes

When implementing sorting algorithms, beginners often:

* Forget loop boundaries.
* Swap incorrect indices.
* Assume every algorithm is stable.
* Ignore additional memory requirements.
* Miscalculate recursive base cases in Merge Sort.
* Use Counting Sort when the value range is huge or unknown.
* Forget to subtract the base offset (`c - 'a'`) when mapping a value to a count index.
* Pass values outside the expected range (such as uppercase letters or digits), which index outside the count array and cause undefined behavior.
* Forget that `%` keeps the sign in C++, so a negative number gives a negative digit and a negative bucket index in Radix Sort. Shift by 9 and use 19 buckets.
* Let `hasher` overflow `int` on 10-digit values. Use `long long`.
* Collect Radix Sort buckets out of order, or use a non-FIFO container, which breaks stability.

Always test your implementation using:

* Empty arrays
* Single-element arrays
* Already sorted arrays
* Reverse sorted arrays
* Arrays with duplicate values
* Values at both ends of the range (for Counting Sort, `'a'` and `'z'`)
* Negative numbers and mixed digit counts (for Radix Sort, for example `-200, -33, 2, 102`)

---

# 🎯 Suggested Practice

After completing this chapter, try implementing:

* Merge Two Sorted Arrays
* Sort Colors
* Relative Sort Array
* Sort Characters by Frequency
* Kth Largest Element
* Merge Intervals
* Height Checker

These problems reinforce sorting concepts and frequently appear in coding interviews.

---

# 📝 Key Takeaways

* Different sorting algorithms excel in different situations.
* Merge Sort offers the best asymptotic performance among the **comparison-based** algorithms in this section.
* Counting Sort avoids comparisons entirely and sorts in O(n), but only when values fall in a small, fixed range.
* Radix Sort extends the non-comparison idea to large integers, sorting one digit at a time with stable passes in O(d·n).
* Stability and memory usage are important considerations alongside time complexity.
* Understanding trade-offs is more valuable than memorizing implementations.

---

# 🔗 Continue Learning

⬅️ Previous: **Search Algorithms**

➡️ Next: **Calculative Algorithms**

🏠 Back to: **Algorithms**

🏠 Repository Home