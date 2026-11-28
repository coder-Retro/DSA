# 🗃️ Implementing a Hash Map (Separate Chaining)

> **"A hash map turns a key into an array index, so finding a value takes one jump instead of a search."**

A **Hash Map** stores **key → value** pairs and answers three questions very quickly: *insert this pair*, *is this key present?*, and *remove this key*. Instead of scanning every element, it runs the key through a **hash function** that computes the **bucket** (array slot) where the pair must live.

This chapter builds a `HashMap<T>` from scratch using **separate chaining**:

- The map is an **array of buckets** that **doubles in size** (a **rehash**) whenever it gets too full.
- Every bucket is a small **singly linked list** holding all the pairs that hashed to that slot.
- Keys are `int`, values are of any type `T`.
- Duplicate keys are not allowed.
- A map can be **copied** safely: the copy gets its own nodes, so changing one map never affects the other.

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
- Define the **load factor** and explain why long chains make a map slow.
- Implement **rehashing**: allocate a bigger table and move every pair into its new bucket.
- Explain why a rehash must recompute every bucket, and why inserts are still **amortized O(1)**.
- Recognize that a rehash invalidates references returned earlier by `operator[]`.
- Explain why a class that owns heap memory needs a **copy constructor** and **copy assignment** (the Rule of Three), and write them as a **deep copy**.
- Mark every method that only reads the map as `const`.

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
| `main.cpp`   | Driver that exercises every operation, including automatic rehashing, and prints the table after each   |
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

The bucket also depends on `cap`. When the capacity changes, the same key can map to a different bucket (`4 % 4 = 0`, but `4 % 8 = 4`), which is why a rehash has to recompute the bucket of every pair.

> 💡 **Why is the default capacity `11`?** A **prime** capacity spreads keys more evenly. With a capacity of 10, any set of keys that all end in the same digit (`5, 15, 25, ...`) piles into one bucket. With 11, the same keys scatter. `main.cpp` uses `10` on purpose so that `3015` and `3005` collide. Rehashing doubles the capacity (`11 → 22 → 44`), so it stops being prime after the first growth. Some real implementations keep the capacity prime, while others use powers of two together with a hash function that mixes the bits. Plain `%` with doubling is fine for learning.

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

# 📈 Load Factor and Rehashing

Chaining is fast only while the chains are **short**. The **load factor** measures how full the table is:

```text
α = n / cap        (pairs stored ÷ number of buckets)
```

`α` is the **average chain length**. With a fixed number of buckets, `α` grows without limit as pairs are added, and every operation slows toward O(n). The cure is to **rehash**: when the table gets too full, allocate a **bigger** one and move every pair into it.

This map checks before it adds a key. If the new size would pass **75%** of the buckets, it rehashes first:

```cpp
if(len+1>cap*0.75) rehash();
```

Both `insert` and `operator[]` run this check, so after any insertion `α` stays at or below `0.75`. `erase` and `clear` never shrink the table.

### Why every pair has to move

The bucket is `key % cap`, and `cap` has just doubled. A pair cannot stay where it is, because `contains` will now look in a different bucket. Every pair is taken out of the old table and **re-inserted** using the new capacity.

### What growth looks like

Starting from 4 buckets and inserting keys `1` to `8` (the output comes from `main.cpp`):

```text
start: size: 0, buckets: 4
insert 1 (Luffy): size: 1, buckets: 4
insert 2 (Kaido): size: 2, buckets: 4
insert 3 (Shanks): size: 3, buckets: 4
insert 4 (Zoro): size: 4, buckets: 8   <-- rehash: 4 -> 8
insert 5 (Sanji): size: 5, buckets: 8
insert 6 (Brook): size: 6, buckets: 8
insert 7 (Chopper): size: 7, buckets: 16   <-- rehash: 8 -> 16
insert 8 (Robin): size: 8, buckets: 16
```

The first rehash fires on the **4th** insert, because adding a 4th pair would make `4 > 0.75 × 4 = 3`. The second fires on the 7th (`7 > 0.75 × 8 = 6`). Each time the capacity **doubles**.

> 💡 `rehash()` is **private**. Callers never invoke it, they only see its effect through `buckets()`. If you know roughly how many pairs you will store, start with a larger capacity (about `n / 0.75`) and the map never needs to rehash while loading them.

---

# ⚙️ Supported Operations

| Operation               | Description                                                                 |
| ----------------------- | --------------------------------------------------------------------------- |
| `HashMap(cap = 11)`     | Create a map with `cap` empty buckets (the starting capacity). A `cap` of `0` becomes `11` |
| `HashMap(other)`        | **Copy constructor**: a deep copy with its own buckets and nodes            |
| `operator=(other)`      | **Copy assignment**: replaces this map with a deep copy of `other`          |
| `insert(key, value)`    | Add a pair. Returns `false` and keeps the old value if the key already exists |
| `erase(key)`            | Remove a pair. Returns `false` if the key is missing                        |
| `contains(key)`         | Whether the key is present                                                  |
| `operator[](key)`       | Returns a **reference** to the value. Creates a default-valued (`T()`) entry if missing |
| `clear()`               | Remove every pair. The capacity does **not** shrink back                    |
| `size()`                | Number of pairs stored                                                      |
| `empty()`               | Whether the map has no pairs                                                |
| `buckets()`             | Current number of buckets. Grows after a rehash                             |
| `printMap()`            | Print every bucket and its chain                                            |

A few behaviors worth remembering:

- `insert` **never overwrites**. To change an existing value, assign through `operator[]`.
- `operator[]` **modifies the map**. Reading a missing key creates it, just like `std::map` and `std::unordered_map`. Use `contains` first when you only want to check.
- `insert` and `operator[]` may **rehash** before they add a key. `operator[]` rehashes only when it is really creating a new key, while `insert` checks the load first, so a duplicate `insert` can still trigger a needless rehash. `rehash()` itself is private.
- `contains`, `size`, `empty`, `buckets` and `printMap` are `const`, so they work on a `const HashMap&`. `operator[]` is not, because it can create entries.

### The bucket class

`HashMap` delegates the work inside a bucket to `LinkedList<T>`:

| Operation              | Description                                                         |
| ---------------------- | ------------------------------------------------------------------- |
| copy constructor / `operator=` | Deep copy of the chain, keeping the original order          |
| `push(key, value)`     | Insert at the front. Returns `false` if the key is already there    |
| `pop(key)`             | Remove the node with this key. Returns `false` if not found         |
| `contains(key)`        | Whether a node has this key                                         |
| `updateValue(key)`     | Return a reference to that node's value                             |
| `headInfo()`           | Return the front `(key, value)`. Throws `std::underflow_error` if empty. `const` |
| `clear()`              | Remove every node                                                   |
| `size()` / `empty()`   | Number of nodes / whether there are none                            |
| `printList()`          | Print the chain as `[(key:value),...]`. `const`                     |

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
    void copy(const LinkedList& other) {
        Node* tail=nullptr; // Local tail keeps the original order
        Node* copier=other.head;
        while(copier) {
            Node* newNode=new Node(copier->key,copier->data,nullptr);
            if(!tail) head=newNode;
            else tail->next=newNode;
            tail=newNode;
            len++;
            copier=copier->next;
        }
    }
public:
    LinkedList(): head(nullptr), len(0) {}
    LinkedList(const LinkedList& other): head(nullptr), len(0) {
        copy(other);
    }
    LinkedList& operator=(const LinkedList& other) {
        if(this!=&other) {
            clear();
            copy(other);
        }
        return *this;
    }

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
    std::pair<int,T> headInfo() const {
        if(empty()) throw std::underflow_error("List is empty!\n");
        return {head->key,head->data};
    }
    void clear() { while(head) pop(head->key); }
    size_t size() const { return len; }
    bool empty() const { return !len; }
    void printList() const {
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
    void rehash() {
        size_t old_cap=cap;
        cap*=2;
        LinkedList<T>* newTable=new LinkedList<T>[cap];
        for(int i=0;i<(int)old_cap;i++) {
            LinkedList<T>& curr=table[i];
            while(!curr.empty()) {
                auto [key,data]=curr.headInfo();
                size_t bucket=hash(key);
                newTable[bucket].push(key,data);
                curr.pop(key);
            }
        }
        delete[] table;
        table=newTable;
    }
    void copy(const HashMap& other) {
        cap=other.cap;
        len=other.len;
        table=new LinkedList<T>[cap];
        for(size_t i=0;i<cap;i++) table[i]=other.table[i];
    }
public:
    HashMap(size_t _cap=11): cap(_cap?_cap:11), len(0), table(new LinkedList<T>[cap]) {}
    HashMap(const HashMap& other): cap(0), len(0), table(nullptr) {
        copy(other);
    }
    HashMap& operator=(const HashMap& other) {
        if(this!=&other) {
            delete[] table;
            copy(other);
        }
        return *this;
    }
    T& operator[](int _key) {
        size_t bucket=hash(_key);
        if(!table[bucket].contains(_key)) {
            if(len+1>cap*0.75) { rehash(); bucket=hash(_key); }
            table[bucket].push(_key,T());
            len++;
        }
        return table[bucket].updateValue(_key);
    }

    bool insert(int _key,T _data) {
        if(len+1>cap*0.75) rehash();
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
    bool contains(int _key) const {
        size_t bucket=hash(_key);
        return table[bucket].contains(_key);
    }

    void clear() {
        for(int i=0;i<(int)cap;i++) table[i].clear();
        len=0;
    }
    size_t buckets() const { return cap; }
    size_t size() const { return len; }
    bool empty() const { return !len; }
    void printMap() const {
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

**Requirements on `T`:** default-constructible (the `Node` dummy and `operator[]` both use `T()`), copy-constructible, and printable with `operator<<` if you call `printList` or `printMap`. Because member functions of a template are only compiled when used, `printMap` costs nothing for types you never print.

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
    if(len+1>cap*0.75) rehash();
    size_t bucket=hash(_key);
    bool inserted=table[bucket].push(_key,_data);
    if(inserted) len++;
    return inserted;
}
```

First make room if the map is too full. Then hash the key (**after** the possible rehash, because `cap` may have changed), hand the work to that bucket, and update `len` **only if** the bucket reports success. `erase` follows the same shape with `pop` and `len--`. It never rehashes, since removing a pair only makes the map emptier.

### `HashMap::operator[]`

```cpp
T& operator[](int _key) {
    size_t bucket=hash(_key);
    if(!table[bucket].contains(_key)) {
        if(len+1>cap*0.75) { rehash(); bucket=hash(_key); }
        table[bucket].push(_key,T());
        len++;
    }
    return table[bucket].updateValue(_key);
}
```

1. Hash the key and look in that bucket. If the key is **already there**, skip straight to step 4: nothing is created, `len` does not change, and no rehash happens.
2. If the key is **new**, check the load limit. `operator[]` can create entries, so it needs the same check as `insert`. After a `rehash`, `cap` has changed, so the bucket must be **recomputed**. The old index belongs to the old table.
3. `push` inserts the key with `T()`, the default value of the type (`""` for `std::string`, `0` for `int`), and `len` grows by one.
4. `updateValue` returns a reference to the node's value, so `map[k] = v` and `map[k] += s` write straight into the map.

Using `T()` instead of a string literal means `operator[]` works for **any** default-constructible `T`, so `HashMap<int> counts; counts[7]+=2;` compiles and starts from `0`.

### `HashMap::rehash`

```cpp
void rehash() {
    size_t old_cap=cap;
    cap*=2;
    LinkedList<T>* newTable=new LinkedList<T>[cap];
    for(int i=0;i<(int)old_cap;i++) {
        LinkedList<T>& curr=table[i];
        while(!curr.empty()) {
            auto [key,data]=curr.headInfo();
            size_t bucket=hash(key);
            newTable[bucket].push(key,data);
            curr.pop(key);
        }
    }
    delete[] table;
    table=newTable;
}
```

1. Remember the old capacity and **double `cap` first**. From this line on, `hash` uses the new capacity.
2. Allocate a bigger array of empty lists.
3. Visit every old bucket. While it still has pairs, read the front pair with `headInfo()`, compute its bucket with the **new** `cap`, `push` it into `newTable[bucket]`, and `pop` it from the old bucket.
4. `delete[] table` frees the old array (every old list is empty by now), and `table` points at the new one.

Points worth noticing:

- `LinkedList<T>& curr=table[i];` is a **reference**. A bucket is a list *object*, not a pointer, and a by-value copy would share nodes with the original.
- `len` is **not** changed. The number of pairs is the same before and after.
- The pair goes to `newTable[bucket]`, not `newTable[i]`. The old index is meaningless in the new table.
- Pairs are **copied** into new nodes and the old nodes are deleted. A reference you obtained earlier from `operator[]` therefore dangles after a rehash:

```cpp
string& r=hp[1];
hp.insert(...);   // may rehash
r="x";            // r points to a deleted node
```

### Copying (the Rule of Three)

`HashMap` owns heap memory (`table`), so it defines a **destructor**, a **copy constructor** and a **copy assignment**. Without the last two, the compiler copies only the `table` *pointer*: two maps would share one array and both would `delete[]` it.

```cpp
void copy(const HashMap& other) {
    cap=other.cap;
    len=other.len;
    table=new LinkedList<T>[cap];
    for(size_t i=0;i<cap;i++) table[i]=other.table[i];
}
HashMap(const HashMap& other): cap(0), len(0), table(nullptr) {
    copy(other);
}
HashMap& operator=(const HashMap& other) {
    if(this!=&other) {
        delete[] table;
        copy(other);
    }
    return *this;
}
```

- A private `copy` helper does the real work, and both public functions call it.
- The copy constructor starts from an empty state, then calls `copy`.
- `operator=` first guards against **self-assignment** (`a = a`), which would otherwise `delete[]` the very table it is about to copy from. It then frees the old table and calls `copy`. The other map may have a different `cap`, so the whole table is reallocated.
- `table[i]=other.table[i]` uses `LinkedList::operator=`, which is why the bucket class needs its own copy support. Its `copy` helper builds new nodes with a local `tail` pointer, so each chain keeps the **same order** as the original and no duplicate check is needed.

```cpp
HashMap<string> a(10);
a.insert(3015,"Kaido");
a.insert(3005,"Luffy");

HashMap<string> b=a;        // copy constructor
b[3005]="Sanji";            // change the copy only
b.insert(1001,"Shanks");    // add to the copy only
```

```text
a: 2 pairs, a[3005] = Luffy
b: 3 pairs, b[3005] = Sanji
```

`a` is untouched, because `b` owns its own nodes.

> 💡 This version clears the old data **before** copying. If `new` threw halfway through `copy`, the target would be left half-built. The **copy-and-swap** idiom (copy into a temporary, then swap) avoids that. For a learning implementation, clear-then-copy is simpler to read.

### Destruction

`~HashMap` runs `delete[] table`, which calls `~LinkedList` on every bucket. Each one runs `clear()`, which frees every node. Use `delete[]` (not `delete`) because `table` was created with `new[]`.

---

# 🧪 Example Usage

`main.cpp` walks through every operation and prints the whole table after each step. A capacity of `10` is used so that `3015` and `3005` collide in bucket 5. It finishes with two rehash demos, shown after this example.

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

### Watching a rehash

The end of `main.cpp` inserts the eight names into a map that starts with only 4 buckets, and prints `buckets()` after every insert:

```cpp
HashMap<string> crew(4);
for(int i = 0; i < 8; i++) {
    size_t before = crew.buckets();
    crew.insert(i + 1, names[i]);
    // print size and buckets, and flag the insert if buckets() changed
}
```

```text
start: size: 0, buckets: 4
insert 1 (Luffy): size: 1, buckets: 4
insert 2 (Kaido): size: 2, buckets: 4
insert 3 (Shanks): size: 3, buckets: 4
insert 4 (Zoro): size: 4, buckets: 8   <-- rehash: 4 -> 8
insert 5 (Sanji): size: 5, buckets: 8
insert 6 (Brook): size: 6, buckets: 8
insert 7 (Chopper): size: 7, buckets: 16   <-- rehash: 8 -> 16
insert 8 (Robin): size: 8, buckets: 16
```

A last check confirms that nothing was lost: `all keys still found after rehash: true, crew[5] = Sanji, size: 8`.

The same growth happens through `operator[]`. Starting from 2 buckets and assigning six entries:

```text
start: buckets: 2
bounty[100]: size: 1, buckets: 2
bounty[200]: size: 2, buckets: 4   <-- rehash: 2 -> 4
bounty[300]: size: 3, buckets: 4
bounty[400]: size: 4, buckets: 8   <-- rehash: 4 -> 8
bounty[500]: size: 5, buckets: 8
bounty[600]: size: 6, buckets: 8
```

---

# ⚡ Complexity Analysis

Let `n` be the number of stored pairs and `cap` the number of buckets. The **load factor** is `α = n / cap`, the average chain length. Rehashing keeps `α` at or below `0.75`, so chains stay short.

| Operation                         | Average          | Worst case   |
| --------------------------------- | :--------------: | :----------: |
| `insert`, `operator[]`            | O(1) amortized   | O(n²)        |
| `erase`, `contains`               | O(1)             | O(n)         |
| `rehash` (private)                | O(cap + n)       | O(cap + n²)  |
| `clear`, `printMap`               | O(cap + n)       | O(cap + n)   |
| copy constructor, `operator=`     | O(cap + n)       | O(cap + n)   |
| `size`, `empty`, `buckets`        | O(1)             | O(1)         |

**Why amortized O(1)?** A single insert that triggers a rehash costs O(n), but the capacity **doubles**, so the next rehash is a long way off: after a rehash at capacity `c`, roughly `0.75c` more inserts must happen before the next one. Spread over those inserts, the O(c) cost of a rehash adds only O(1) to each.

**Why the worst case is bad:** it happens when every key lands in one bucket (for example, keys that are all multiples of a large power of two), so the map degenerates into a single linked list. A lookup then walks `n` nodes, and a rehash is even worse, because each `push` scans the growing chain for duplicates, giving O(n²).

**Space complexity:** O(cap + n), the bucket array plus one node per pair. While a rehash runs, the old and new bucket arrays exist at the same time. Because `erase` and `clear` never shrink the table, `cap` stays as large as the map ever needed.

> 💡 **Rehash spikes:** one unlucky insert pays for the whole rehash. A single `insert` can be much slower than its neighbors even though the average cost is O(1). Real-time code often avoids this by reserving capacity up front.

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
- **Hard-code a type inside a template:** `Node dummy(-1,-1,head);` fails for `std::string`, and `push(_key,"")` in `operator[]` fails for `int`. Use `T()`.
- **Skip the duplicate check**, which stores the same key twice and corrupts `size()`.
- **Forget `len++` in `operator[]`** when it creates a new entry, so `size()` is too small.
- **Update `len` before knowing the bucket succeeded.** Only change it when `push` or `pop` returns `true`.
- **Re-insert into the old index during a rehash.** Writing `newTable[i]` instead of `newTable[hash(key)]` leaves every pair in its old bucket, so `contains` looks in the wrong place and misses keys.
- **Double `cap` too late.** The new capacity must be set *before* re-hashing, or `hash` still uses the old size.
- **Write a broken loop condition.** `for(int i=0;(int)old_cap;i++)` has no comparison, never stops, and runs off the end of the array. It must be `i<(int)old_cap`.
- **Treat a bucket as a pointer.** `LinkedList<T>* curr=table[i];` does not compile, because `table[i]` is a list object. Use `LinkedList<T>& curr=table[i];`.
- **Change `len` inside `rehash`.** The number of pairs is the same afterwards.
- **Compute the bucket before the rehash check** in `insert`, or forget to **recompute it after** a `rehash` in `operator[]`. The index belongs to the old table, which `rehash` has just deleted.
- **Keep a reference across an insert.** A rehash deletes the old nodes, so a `T&` from `operator[]` can dangle.
- **Never call `rehash` from `operator[]`.** It creates entries too, so a map filled through `[]` would never grow.
- **Use `delete` instead of `delete[]`** on an array created with `new[]`.
- **Use `[]` to check for a key.** It silently inserts the key. Use `contains` instead.
- **Allow a capacity of `0`.** The hash function would compute `_key % 0`, which is undefined behavior, and doubling `0` gives `0` again, so rehashing cannot rescue it. The constructor replaces `0` with `11`.
- **Give a constructor parameter the same name as a member.** With `HashMap(size_t cap): cap(cap?cap:11), table(new LinkedList<T>[cap])`, the `cap` inside `new[]` is the **parameter**, not the fixed member, so `HashMap(0)` allocated zero buckets while the member said `11`, a heap buffer overflow. Naming the parameter `_cap` removes the ambiguity.
- **Forget the copy constructor and copy assignment.** The compiler-generated copy duplicates the `table` *pointer*, so two maps share one array and both free it (a use-after-free). The same goes for `LinkedList`, whose copy would share every node.
- **Skip the self-assignment check** in `operator=`. `a = a` would `delete[]` the table and then copy from the freed memory.
- **Forget `const`** on methods that only read. A `const HashMap&` can then not call `contains` or `printMap`, and a `const` method can only call other `const` methods, so `LinkedList::printList` has to be `const` before `HashMap::printMap` can be.
- **Compare only the bucket index** and forget to compare keys inside the bucket.
- **Assume order.** A hash map has no meaningful order. Do not expect keys back in the order you inserted them.

Testing boundary conditions (empty map, one key, many keys in one bucket, erasing the head, middle and tail of a chain, negative keys) is essential for a reliable implementation.

---

# 🎯 Suggested Exercises

After completing this implementation, try adding:

- A **move constructor** and **move assignment** (the Rule of Five). Right now `std::move(map)` falls back to a full copy
- Rewrite `operator=` with **copy-and-swap** so that a failed allocation leaves the target unchanged
- Rehash **only when a new key is really being added** in `insert` too. `operator[]` already does this, but a duplicate `insert` can still trigger a needless rehash
- Make the **maximum load factor** a constructor parameter instead of the fixed `0.75`
- Rehash by **relinking the existing nodes** instead of copying them, so references stay valid
- **Shrink** the table when `erase` leaves it mostly empty
- A `reserve(n)` function that sizes the table up front so no rehash happens while loading `n` pairs
- Keep the capacity **prime** after each growth (for example, the next prime above `2 * cap`)
- A `const` lookup (`at` or `find`) that does **not** create missing keys and throws `std::out_of_range`
- A `get` that returns a pointer or `std::optional<T>`
- Generic keys using `template<typename K, typename V>` and `std::hash<K>`
- An iterator so you can write `for(auto& [key,value] : map)`
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
- The **load factor** `α = n / cap` is the average chain length. Lookups cost **O(1 + α)**, and the worst case is **O(n)** when everything collides.
- **Rehashing** doubles the table whenever `α` would pass `0.75`, which keeps chains short as the map grows.
- A rehash must recompute every key's bucket, because the bucket depends on `cap`.
- Doubling makes inserts **amortized O(1)**, even though a single rehash costs O(n).
- A rehash re-creates the nodes, so references from earlier `operator[]` calls become dangling.
- `operator[]` returns a **reference** and **creates** a missing entry, so it is a poor way to test for a key.
- `insert` does not overwrite, while assignment through `operator[]` does.
- The class owns heap memory with `new[]`, so it defines the **Rule of Three** (destructor, copy constructor, copy assignment) to make every copy a **deep copy**.
- Methods that only read the map are marked `const`, so they can be used on a `const HashMap&`.

---

# 🔗 Related Implementations

⬅️ **Heap** — Another structure stored in contiguous memory, built for fast access to one special element.

⬅️ **Linked List** — The bucket chains in this chapter are singly linked lists.

➡️ **Graph** — Uses hash sets internally to store each node's neighbors, so it builds directly on this idea.

🏠 Back to: **Data Structure Implementations**

🏠 Repository Home