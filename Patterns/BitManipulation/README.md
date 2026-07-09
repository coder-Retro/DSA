# 💻 Bit Manipulation Pattern

> **"Techniques to manipulate data at the individual bit level for maximum performance and memory efficiency."**

Bit manipulation is the process of applying logical operations to the smallest unit of data in a computer—the bit. Because these operations map directly to CPU instructions, they are exceptionally fast and memory-efficient.

Mastering bit manipulation is a hallmark of high-performance programming, systems architecture, and low-level optimization.

---

# 📖 Prerequisites

Before studying this pattern, you should understand:

* **Binary numbering system** (Base 2)
* **Two's Complement** representation
* Basic **logical operators** (`AND`, `OR`, `NOT`, `XOR`)
* Integer data types and sizes

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

* Represent integers in binary format.
* Perform bitwise logical and shift operations.
* Use bitmasks to set, clear, and toggle specific bits.
* Apply bitwise tricks to optimize arithmetic and state management.
* Solve competitive programming problems involving bitsets or bit-level logic.

---

# 🧠 The Core Idea

Bit manipulation revolves around the **Bitmask**—a sequence of bits used to target specific positions within a number.

### 1️⃣ Logical Operators
Using `&`, `|`, `^`, and `~` to compare or transform bits.

### 2️⃣ Shift Operators
Using `<<` and `>>` to move bit patterns, effectively performing rapid multiplication or division by powers of 2.

---

# 🔍 How to Recognize This Pattern

Bit manipulation is useful when you see:

* Constraints involving powers of 2 (e.g., $2^n$).
* Needs for extreme speed or low memory usage.
* Problems involving "sets" of boolean flags.
* Operations like toggling, finding parity, or reversing bits.
* Binary representation puzzles.

**Common keywords include:**
* Bitwise
* Mask
* Toggle
* Set/Clear bit
* Power of 2
* XOR/AND/OR

---

# 📂 Directory Structure

```text
BitManipulation/
├── BitManipulation.cpp
└── README.md
