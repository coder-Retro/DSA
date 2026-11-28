# 🗃️ Implementing a Hash Map (Separate Chaining)

> **"A hash map turns a key into an array index, so finding a value takes one jump instead of a search."**

A **Hash Map** stores **key → value** pairs and answers three questions very quickly: *insert this pair*, *is this key present?*, and *remove this key*. Instead of scanning every element, it runs the key through a **hash function** that computes the **bucket** (array slot) where the pair must live.

This chapter builds a `HashMap<T>` from scratch using **separate chaining**:

- The map is a **fixed-size array of buckets**.
- Every bucket is a small **singly linked list** holding all the pairs that hashed to that slot.
- Keys are `int`, values are of any type `T`.
- Duplicate keys are not allowed.

---

# 📖 Prerequisites

Before studying this implementation, you should understand:

- Arrays and Dynamic Memory (`new[]` / `delete[]`)
- Linked Lists
- Templates (Generic Programming)
- The Modulo Operator (`%`)
- References
- Time Complexity (Big-O)

---

# 🎯 Learning Objectives

After completing this chapter, you should be able to:

- Explain what a **hash function** does and why it maps keys to buckets.
- Explain what a **collision** is and how **separate chaining** resolves it.
- Implement `insert`, `erase`, `contains`, and `operator[]` on top of an array of linked lists.
- Return a **reference** from `operator[]` so that `map[key] = value` works.
- Explain why `operator[]` creates an entry when the key is missing.
- Analyze the **average** and **worst-case** cost of each operation.
- Understand the role of the **load factor** and why this map degrades when it fills up.
- Recognize the limitations of a fixed-capacity table.

---

# 📂 Directory Structure

```text
8.HashMap/
├── hashmap.h
├── main.cpp
└── README.md
```

| File         | Purpose                                                                 |
| ------------ | ----------------------------------------------------------------------- |
| `hashmap.h`  | The `LinkedList<T>` bucket class and the `HashMap<T>` class             |
| `main.cpp`   | Driver that exercises every operation and prints the table after each   |
| `README.md`  | This document                                                           |

`LinkedList<T>` lives inside `hashmap.h` so this folder is self-contained. It is a small keyed singly linked list written just for the buckets.

---

# 🧠 The Core Idea

An array gives O(1) access, but only if you know the **index**. A hash map creates that index from the key.

```text
key ──► hash(key) ──► bucket index ──► search only that bucket
```

With a capacity of 10, the map looks like this after inserting four pairs:

```text
index   bucket (a linked list)
  0     []
  1     (1001:Shanks)
  2     []
  ...
  5     (3005:Luffy) ──► (3015:Kaido)
  ...
  9     (3019:Brook)
```

To find key `3015`, the map computes its bucket (`5`) and walks only that one short list. The other buckets are never touched.

---

# 🔢 The Hash Function

```cpp
size_t hash(int _key) const { return _key%cap; }
```

The key is divided by the capacity and the **remainder** is the bucket index. The remainder is always in `[0, cap)`, so it is always a valid array index.

| Key    | Calculation | Bucket |
| ------ | :---------: | :----: |
| `1001` | `1001 % 10` |   1    |
| `3015` | `3015 % 10` |   5    |
| `3005` | `3005 % 10` |   5    |
| `3019` | `3019 % 10` |   9    |

Notice that `3015` and `3005` land in the **same** bucket. That is a collision.

> 💡 **Why is the default capacity `11`?** A **prime** capacity spreads keys more evenly. With a capacity of 10, any set of keys that all end in the same digit (`5, 15, 25, ...`) piles into one bucket. With 11, the same keys scatter. `main.cpp` uses `10` on purpose so that `3015` and `3005` collide.

> ⚠️ **Negative keys:** `_key` is an `int` but `cap` is a `size_t`, so the key is converted to an unsigned number *before* the `%`. The result is still a valid index, but it is not the mathematical remainder. With a capacity of 10, key `-5` lands in bucket `1`, not bucket `5`. The map stays correct, because every operation uses the same function.

---

# 💥 Collisions and Separate Chaining

Two different keys can hash to the same bucket, because there are far more possible keys than buckets. A **collision** is unavoidable, so the map needs a plan for it.

**Separate chaining** keeps a list in each bucket, so colliding keys simply share a list:

```text
insert(3015, "Kaido")   bucket 5:  (3015:Kaido)
insert(3005, "Luffy")   bucket 5:  (3005:Luffy) ──► (3015:Kaido)
```

- **Insert** adds the new node at the **front** of the list (O(1) once the duplicate check is done).
- **Lookup / erase** hash the key, then walk that bucket's list comparing **keys**.

Comparing keys inside the bucket is required. The bucket index only says *where to look*, not that the key is there.

---

# ⚙️ Supported Operations

| Operation               | Description                                                                 |
| ----------------------- | --------------------------------------------------------------------------- |
| `HashMap(cap = 11)`     | Create a map with `cap` empty buckets                                       |
| `insert(key, value)`    | Add a pair. Returns `false` and changes nothing if the key already exists   |
| `erase(key)`            | Remove a pair. Returns `false` if the key is missing                        |
| `contains(key)`         | Whether the key is present                                                  |
| `operator[](key)`       | Returns a **reference** to the value. Creates an empty entry if missing     |
| `clear()`               | Remove every pair. The capacity stays the same                              |
| `size()`                | Number of pairs stored                                                      |
| `empty()`               | Whether the map has no pairs                                                |
| `buckets()`             | Number of buckets (the capacity)                                            |
| `printMap()`            | Print every bucket and its chain                                            |

Two behaviors worth remembering:

- `insert` **never overwrites**. To change an existing value, assign through `operator[]`.
- `operator[]` **modifies the map**. Reading a missing key creates it, just like `std::map` and `std::unordered_map`. Use `contains` first when you only want to check.

### The bucket class

`HashMap` delegates the work inside a bucket to `LinkedList<T>`:

| Operation              | Description                                                         |
| ---------------------- | ------------------------------------------------------------------- |
| `push(key, value)`     | Insert at the front. Returns `false` if the key is already there    |
| `pop(key)`             | Remove the node with this key. Returns `false` if not found         |
| `contains(key)`        | Whether a node has this key                                         |
| `updateValue(key)`     | Return a reference to that node's value                             |
| `headInfo()`           | Return the front `(key, value)`. Throws `std::underflow_error` if empty |
| `clear()`              | Remove every node                                                   |
| `size()` / `empty()`   | Number of nodes / whether there are none                            |
| `printList()`          | Print the chain as `[(key:value),...]`                              |

---

# 🏗️ The Implementation

`hashmap.h`, part 1: the bucket (`LinkedList<T>`):

```cpp
#pragma once
#include<iostream>
#include<stdexcept>
#include<utility>
#include<string>

template<typename T>
class LinkedList {
    struct Node {
        int key;
        T data;
        Node* next;
        Node(int _key,T _data,Node* _next): key(_key), data(_data), next(_next) {}
    };
    Node* head; // Points to Front Node of list
    size_t len;
public:
    LinkedList(): head(nullptr), len(0) {}

    bool push(int _key,T _data) {
        if(contains(_key)) return false;
        head=new Node(_key,_data,head);
        len++;
        return true;
    }
    bool pop(int _key) {
        if(empty()) return false;
        Node dummy(-1,T(),head);
        Node* prev=&dummy;
        while(prev->next && prev->next->key != _key) prev=prev->next;
        if(prev->next) {
            Node* target=prev->next;
            prev->next=target->next;
            if(target==head) head=head->next;
            delete target;
            len--;
            return true;
        }
        return false;
    }
    T& updateValue(int _key) {
        Node* curr=head;
        while(curr && curr->key!=_key) curr=curr->next;
        return curr->data;
    }
    bool contains(int _key) const {
        Node* curr=head;
        while(curr) {
            if(curr->key==_key) return true;
            curr=curr->next;
        }
        return false;
    }
    std::pair<int,T> headInfo() {
        if(empty()) throw std::underflow_error("List is empty!\n");
        return {head->key,head->data};
    }
    void clear() { while(head) pop(head->key); }
    size_t size() const { return len; }
    bool empty() const { return !len; }
    void printList() {
        std::cout<<"[";
        Node* curr=head;
        while(curr) {
            std::cout<<"("<<curr->key<<":"<<curr->data<<")";
            if(curr->next) std::cout<<",";
            curr=curr->next;
        }
        std::cout<<"]\n";
    }

    ~LinkedList() { clear(); }
};
```

`hashmap.h`, part 2: the map itself (`HashMap<T>`):

```cpp
template<typename T>
class HashMap {
private:
    size_t cap;
    size_t len;
    LinkedList<T>* table;
    size_t hash(int _key) const { return _key%cap; }
public:
    HashMap(size_t cap=11): cap(cap), len(0), table(new LinkedList<T>[cap]) {}
    T& operator[](int _key) {
        size_t bucket=hash(_key);
        if(table[bucket].push(_key,"")) len++;
        return table[bucket].updateValue(_key);
    }

    bool insert(int _key,T _data) {
        size_t bucket=hash(_key);
        bool inserted=table[bucket].push(_key,_data);
        if(inserted) len++;
        return inserted;
    }
    bool erase(int _key) {
        size_t bucket=hash(_key);
        bool erased=table[bucket].pop(_key);
        if(erased) len--;
        return erased;
    }
    bool contains(int _key) {
        size_t bucket=hash(_key);
        return table[bucket].contains(_key);
    }

    void clear() {
        for(int i=0;i<(int)cap;i++) table[i].clear();
        len=0;
    }
    size_t buckets() const { return cap; }
    size_t size() const { return len; }
    size_t empty() const { return !len; }
    void printMap() {
        std::cout<<"HashMap: [\n";
        for(int i=0;i<(int)cap;i++) {
            std::cout<<"    "<<i<<": ";
            table[i].printList();
        }
        std::cout<<"]\n";
    }

    ~HashMap() { delete[] table; }
};
```

**Requirements on `T`:** default-constructible (the `Node` dummy uses `T()`), copy-constructible, and printable with `operator<<` if you call `printList` or `printMap`. Because member functions of a template are only compiled when used, `printMap` costs nothing for types you never print.

---

# 🔍 How It Works

### `LinkedList::push`

```cpp
bool push(int _key,T _data) {
    if(contains(_key)) return false;
    head=new Node(_key,_data,head);
    len++;
    return true;
}
```

The duplicate check scans the whole bucket first. Only then is a new node created and linked in **front** of the old head. This is why the newest key is always printed first in a chain.

### `LinkedList::pop` (the dummy node)

```cpp
Node dummy(-1,T(),head);
Node* prev=&dummy;
while(prev->next && prev->next->key != _key) prev=prev->next;
```

`prev` stops on the node **before** the target, so the target can be unlinked with `prev->next=target->next`. A temporary `dummy` node placed in front of `head` means the head needs no special case while searching. The line `if(target==head) head=head->next;` then fixes `head` when the removed node was the first one.

`dummy` lives on the stack and is never `delete`d. `T()` gives it a harmless default value of any type.

### `HashMap::insert` and `erase`

```cpp
bool insert(int _key,T _data) {
    size_t bucket=hash(_key);
    bool inserted=table[bucket].push(_key,_data);
    if(inserted) len++;
    return inserted;
}
```

Hash the key, hand the work to that bucket, and update `len` **only if** the bucket reports success. `erase` follows the same shape with `pop` and `len--`.

### `HashMap::operator[]`

```cpp
T& operator[](int _key) {
    size_t bucket=hash(_key);
    if(table[bucket].push(_key,"")) len++;
    return table[bucket].updateValue(_key);
}
```

1. `push` tries to insert the key with an empty value. If the key already exists it does nothing and returns `false`.
2. `len` grows only when a **new** entry was created.
3. `updateValue` returns a reference to the node's value, so `map[k] = v` and `map[k] += s` write straight into the map.

Because the empty value is written as `""`, this operator compiles only when `T` can be built from a string literal, such as `std::string`. See the exercises for the fix.

### Destruction

`~HashMap` runs `delete[] table`, which calls `~LinkedList` on every bucket. Each one runs `clear()`, which frees every node. Use `delete[]` (not `delete`) because `table` was created with `new[]`.

---

# 🧪 Example Usage

`main.cpp` walks through every operation and prints the whole table after each step. A capacity of `10` is used so that `3015` and `3005` collide in bucket 5.

```cpp
HashMap<string> hp(10);

hp.insert(3015,"Kaido");
hp.insert(3005,"Luffy");
hp.insert(1001,"Shanks");
hp.insert(3015,"Zoro");     // false: key 3015 already exists
hp.printMap();

hp.erase(3015);
hp[3005]="Sanji";           // update an existing key
hp[3019]="Brook";           // create a new key
hp[3019]+=" Chopper";       // modify through the reference
string blank=hp[4444];      // a missing key is created with an empty value
hp.printMap();
```

After the inserts, `printMap()` shows the collision (empty buckets omitted here):

```text
size: 3
HashMap: [
    1: [(1001:Shanks)]
    5: [(3005:Luffy),(3015:Kaido)]
]
```

After the erase and the `operator[]` calls:

```text
size: 4
HashMap: [
    1: [(1001:Shanks)]
    4: [(4444:)]
    5: [(3005:Sanji)]
    9: [(3019:Brook Chopper)]
]
```

Things to notice:

- The duplicate `insert(3015, "Zoro")` returned `false` and left `"Kaido"` untouched.
- In bucket 5 the newest key (`3005`) is listed **first**.
- Reading `hp[4444]` **added** an entry, so `size` went from 3 to 4 (`3005`, `1001`, `3019`, and `4444`; `3015` had been erased).

---

# ⚡ Complexity Analysis

Let `n` be the number of stored pairs and `cap` the number of buckets. The **load factor** is `α = n / cap`, the average chain length.

| Operation                         | Average        | Worst case |
| --------------------------------- | :------------: | :--------: |
| `insert`                          | O(1 + α)       | O(n)       |
| `erase`                           | O(1 + α)       | O(n)       |
| `contains`                        | O(1 + α)       | O(n)       |
| `operator[]`                      | O(1 + α)       | O(n)       |
| `clear`, `printMap`               | O(cap + n)     | O(cap + n) |
| `size`, `empty`, `buckets`        | O(1)           | O(1)       |

The **worst case** happens when every key lands in one bucket, so the map degenerates into a single linked list.

**Space complexity:** O(cap + n), the bucket array plus one node per pair.

> ⚠️ **Fixed capacity:** this map never grows. If `cap` stays at 11 and `n` reaches 1,000,000, every chain holds about 90,000 nodes and every operation takes O(n / cap), which is effectively linear. Real hash maps (like `std::unordered_map`) **rehash** into a larger table when `α` crosses a threshold, which keeps operations O(1) on average. Implementing that is the best next step.

---

# 🌍 Real-World Applications

Hash maps are one of the most used data structures in practice:

- Dictionaries and Symbol Tables (compilers, interpreters)
- Caches (LRU Cache, memoization)
- Counting Frequencies (word counts, anagram checks)
- Database Indexes
- Detecting Duplicates
- Two Sum and other "have I seen this before?" interview problems
- Routers and Network Lookup Tables
- Sets (a hash map with no values)

---

# ⚠️ Common Implementation Mistakes

When implementing a hash map, beginners often:

- **Forget the template argument:** `new LinkedList[cap]` does not compile. It must be `new LinkedList<T>[cap]`.
- **Hard-code a type inside a template:** `Node dummy(-1,-1,head);` fails for `std::string`. Use `T()`.
- **Skip the duplicate check**, which stores the same key twice and corrupts `size()`.
- **Forget `len++` in `operator[]`** when it creates a new entry, so `size()` is too small.
- **Update `len` before knowing the bucket succeeded.** Only change it when `push` or `pop` returns `true`.
- **Use `delete` instead of `delete[]`** on an array created with `new[]`.
- **Use `[]` to check for a key.** It silently inserts the key. Use `contains` instead.
- **Pick a capacity of `0`.** The hash function would compute `_key % 0`, which is undefined behavior.
- **Copy a `HashMap`.** The compiler-generated copy duplicates the `table` *pointer*, so two maps share one array and both free it. See the exercises.
- **Compare only the bucket index** and forget to compare keys inside the bucket.
- **Assume order.** A hash map has no meaningful order. Do not expect keys back in the order you inserted them.

Testing boundary conditions (empty map, one key, many keys in one bucket, erasing the head, middle and tail of a chain, negative keys) is essential for a reliable implementation.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- Fix `operator[]` for any `T` by replacing `""` with `T()`
- Change `HashMap::empty()` to return `bool` instead of `size_t`
- A **copy constructor**, **copy assignment**, and **destructor** (the Rule of Three), or **move** versions (the Rule of Five)
- **Rehashing:** when `α` passes a threshold such as `0.75`, allocate a larger table and re-insert every pair
- A `const` lookup (`at` or `find`) that does **not** create missing keys and throws `std::out_of_range`
- A `get` that returns a pointer or `std::optional<T>`
- Generic keys using `template<typename K, typename V>` and `std::hash<K>`
- An iterator so you can write `for(auto& [key,value] : map)`
- A guard against a capacity of `0`
- A `HashSet` built on the same buckets
- **Open addressing** (linear probing) as an alternative to chaining
- Compare this map's speed against `std::unordered_map`
- Two Sum, Longest Substring Without Repeating Characters, and Group Anagrams using your own map

---

# 📝 Key Takeaways

- A hash map **computes** the bucket for a key instead of searching for it.
- A **hash function** maps many possible keys onto few buckets, so **collisions** are unavoidable.
- **Separate chaining** resolves collisions by keeping a linked list in each bucket.
- The bucket index only says where to look. You must still **compare keys** inside the bucket.
- Average operations cost **O(1 + α)**, and the worst case is **O(n)** when everything collides.
- A **fixed** capacity makes `α` grow with `n`, so a real hash map **rehashes** as it fills.
- `operator[]` returns a **reference** and **creates** a missing entry, so it is a poor way to test for a key.
- `insert` does not overwrite, while assignment through `operator[]` does.
- The class owns heap memory with `new[]`, so copying it safely needs the **Rule of Three**.

---

# 🔗 Related Implementations

⬅️ **Heap** — Another structure stored in contiguous memory, built for fast access to one special element.

⬅️ **Linked List** — The bucket chains in this chapter are singly linked lists.

➡️ **Graph** — Uses hash sets internally to store each node's neighbors, so it builds directly on this idea.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home