# 📘 Doubly Linked List — Easy Guide
> Based on Seymour Lipschutz's *Data Structures* | CSE 2101

---

## 🧠 What Is a Doubly Linked List?

A **doubly linked list** (also called a *two-way list*) is like a regular linked list, but each node has **two pointers** instead of one:

- One pointer looks **forward** (to the next node)
- One pointer looks **backward** (to the previous node)

Think of it like a **train**: each carriage is connected to the one in front AND the one behind.

---

## 🗂️ How Each Node Is Stored

Every node holds three things:

| Field      | What it stores                        |
|------------|---------------------------------------|
| `INFO[K]`  | The actual **data** of node K         |
| `FORW[K]`  | The **index of the next** node        |
| `BACK[K]`  | The **index of the previous** node    |

> **K** is just the position/index of a node in the array.

---

## 🔗 Types of Doubly Linked Lists

### 1. Basic Two-Way List

```
NULL ← [A] ↔ [B] ↔ [C] → NULL
       ↑                    ↑
     FIRST                LAST
```

- `FIRST` = points to the **first node**
- `LAST` = points to the **last node**
- `FORW[LAST] = NULL` → the last node has no "next"
- `BACK[FIRST] = NULL` → the first node has no "previous"

---

### 2. Two-Way Circular Header List

```
    ┌──────────────────────────────┐
    ↓                              ↑
[HEADER/START] ↔ [A] ↔ [B] ↔ [C]
```

- A special **header node** (called `START`) is added at the beginning
- `FORW[START]` points to the **first real node** (A)
- `BACK[START]` points to the **last real node** (C)
- The list is **circular** — no NULL pointers anywhere inside
- This makes coding easier because you never have to worry about "is this the end?"

---

### 3. Free List (AVAIL)

- When nodes are deleted, they don't just disappear
- They go into a **free list** managed by `AVAIL`
- This free list uses only `FORW` (one-way) to chain free nodes together
- When you need a new node, you take it from `AVAIL`

---

## 🔁 3.1 Traversal — Walking Through the List

Traversal means **visiting every node**, one by one.

---

### ➡️ Forward Traversal (Basic List)

Start from the **first node**, move forward using `FORW`.

```
Step 1: PTR ← FIRST              (start at the beginning)
Step 2: While PTR ≠ NULL:        (keep going until the end)
          a. Process INFO[PTR]   (do something with this node's data)
          b. PTR ← FORW[PTR]    (move to the next node)
Step 3: Exit
```

> **Example:** If the list is A → B → C, you visit A, then B, then C.

---

### ⬅️ Backward Traversal (Basic List)

Start from the **last node**, move backward using `BACK`.

```
Step 1: PTR ← LAST               (start at the end)
Step 2: While PTR ≠ NULL:        (keep going until the beginning)
          a. Process INFO[PTR]   (do something with this node's data)
          b. PTR ← BACK[PTR]    (move to the previous node)
Step 3: Exit
```

> **Example:** If the list is A → B → C, you visit C, then B, then A.

---

### 🔄 Circular Header List Traversal

For the header-based list, use `START` as the boundary instead of NULL.

| Direction | Start at          | Stop when       |
|-----------|-------------------|-----------------|
| Forward   | `FORW[START]`     | `PTR = START`   |
| Backward  | `BACK[START]`     | `PTR = START`   |

> The loop stops when you come back around to the header node.

---

## ❌ 3.2 Deleting a Node (Circular Header List)

**Goal:** Remove a node at position `LOC` from the list.

**Algorithm name:** `DELTWL(INFO, FORW, BACK, START, AVAIL, LOC)`

### What happens visually

Before deletion:
```
... ↔ [BACK[LOC]] ↔ [LOC] ↔ [FORW[LOC]] ↔ ...
```

After deletion:
```
... ↔ [BACK[LOC]] ↔ [FORW[LOC]] ↔ ...
             (LOC is skipped and removed)
```

### Steps

```
Step 1: Adjust the neighbors to skip over LOC:
          a. FORW[BACK[LOC]] ← FORW[LOC]
             (the node BEFORE LOC now points forward to the node AFTER LOC)
          b. BACK[FORW[LOC]] ← BACK[LOC]
             (the node AFTER LOC now points backward to the node BEFORE LOC)

Step 2: Return LOC to the free list:
          a. FORW[LOC] ← AVAIL   (LOC's forward pointer now points to old AVAIL)
          b. AVAIL ← LOC         (AVAIL now starts at LOC — it's free again)

Step 3: Exit
```

### 💡 Key Insight

- Step 1 **disconnects** the node from its neighbors (2 pointer changes)
- Step 2 **recycles** the node by sending it back to the free list (2 pointer changes)
- Total: only **4 pointer changes** needed!

> **For a basic list (no header):** If you delete the first or last node, you also need to update `FIRST` or `LAST` — but the logic is very similar.

---

## ➕ 3.3 Inserting a Node Between Two Known Nodes

**Goal:** Insert a new node with data `ITEM` between two known adjacent nodes `LOCA` and `LOCB`.

**Algorithm name:** `INSTWL(INFO, FORW, BACK, START, AVAIL, LOCA, LOCB, ITEM)`

### Before insertion

```
... ↔ [LOCA] ↔ [LOCB] ↔ ...
```

### After insertion

```
... ↔ [LOCA] ↔ [NEW] ↔ [LOCB] ↔ ...
```

### Precondition

`FORW[LOCA] = LOCB` and `BACK[LOCB] = LOCA`
(The two nodes must actually be adjacent)

### Steps

```
Step 1: Check for overflow (no space left):
          If AVAIL = NULL → print "OVERFLOW" and Exit

Step 2: Get a new node from the free list:
          a. NEW ← AVAIL           (take the first free node)
          b. AVAIL ← FORW[AVAIL]  (free list now starts at the next free node)
          c. INFO[NEW] ← ITEM      (store the data in the new node)

Step 3: Connect NEW into the list (4 pointer changes):
          a. FORW[LOCA] ← NEW      (LOCA now points forward to NEW)
          b. FORW[NEW]  ← LOCB     (NEW now points forward to LOCB)
          c. BACK[LOCB] ← NEW      (LOCB now points backward to NEW)
          d. BACK[NEW]  ← LOCA     (NEW now points backward to LOCA)

Step 4: Exit
```

### 💡 Key Insight — The 4 Pointer Rule

Think of it like inserting a person into a line. You need to update:
1. The person behind them → points to the new person
2. The new person → points forward to the one ahead
3. The person ahead → points back to the new person
4. The new person → points back to the one behind

### ⚠️ Special Cases (Basic List Without Header)

| Situation                  | What to do extra             |
|----------------------------|------------------------------|
| Inserting at the beginning | `LOCA = NULL` → update `FIRST` |
| Inserting at the end       | `LOCB = NULL` → update `LAST`  |

---

## 🔍 3.4 Searching in a Doubly Linked List

Searching means finding **where** a particular value `ITEM` is in the list.

The big advantage of a doubly linked list: you can search from **either end**!

---

### ➡️ Forward Search (Unsorted List)

Start from the beginning and walk forward.

```
Step 1: PTR ← FIRST
Step 2: While PTR ≠ NULL AND INFO[PTR] ≠ ITEM:
          PTR ← FORW[PTR]     (move forward)
Step 3: If PTR = NULL → LOC ← NULL    (item NOT found)
        Else          → LOC ← PTR     (item found at LOC)
Step 4: Exit
```

---

### ⬅️ Backward Search (e.g., Sorted List, Large Items Near End)

Start from the end and walk backward.

```
Step 1: PTR ← LAST
Step 2: While PTR ≠ NULL AND INFO[PTR] ≠ ITEM:
          PTR ← BACK[PTR]     (move backward)
Step 3: If PTR = NULL → LOC ← NULL    (item NOT found)
        Else          → LOC ← PTR     (item found at LOC)
Step 4: Exit
```

---

### 💡 When to Use Each Direction?

| Situation                            | Use           |
|--------------------------------------|---------------|
| Unsorted list, item could be anywhere | Forward search |
| Sorted list, item is likely near end  | Backward search |
| You have a hint about where it is     | Start from the closest end |

> This is the big advantage over singly linked lists — you have flexibility!

---

## 🧩 Quick Summary Table

| Operation    | Key Steps                                  | Pointer Changes |
|--------------|--------------------------------------------|-----------------|
| Traversal    | Follow FORW or BACK until NULL/START       | 0               |
| Deletion     | Bypass node → return to free list          | 4               |
| Insertion    | Get from free list → link into position    | 4               |
| Search       | Walk forward or backward, compare INFO     | 0               |

---

## 🧾 Glossary

| Term    | Meaning                                               |
|---------|-------------------------------------------------------|
| `PTR`   | A pointer variable that "points to" the current node  |
| `AVAIL` | Head of the free list (available/unused nodes)        |
| `NULL`  | Means "nothing" — no next or previous node exists     |
| `LOC`   | The location (index) of a specific node               |
| `NEW`   | A freshly allocated node from the free list           |
| `INFO`  | The data stored inside a node                         |
| `FORW`  | Forward pointer (→ next node)                         |
| `BACK`  | Backward pointer (← previous node)                   |

---

*Course: CSE 2101 — Data Structures | Based on Seymour Lipschutz's Data Structures*
