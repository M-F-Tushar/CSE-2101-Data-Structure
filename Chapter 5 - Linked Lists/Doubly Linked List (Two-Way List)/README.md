# Doubly Linked List (Two-Way List)

A comprehensive guide to doubly linked list operations and algorithms based on Seymour Lipschutz's Data Structures textbook.

## Overview

The chapter's "two‑way list" is exactly a **doubly linked list**. 

### Representation

- **INFO[K]** = data
- **FORW[K]** = index of next node
- **BACK[K]** = index of previous node

### Basic Two-Way List

- **FIRST** = first node
- **LAST** = last node
- `FORW[LAST] = NULL`
- `BACK[FIRST] = NULL`

### Two-Way Circular Header List

- **START** points to header
- `FORW[START]` and `BACK[START]` point to ends
- No null pointers inside the list

### Free List

- **AVAIL** = free list, maintained as a one‑way list via FORW

## Table of Contents

1. [Traversing a Doubly Linked List](#31-traversing-a-doubly-linked-list)
2. [Deleting a Node with Known Location](#32-deleting-a-node-with-known-location-two-way-circular-header)
3. [Inserting a Node Between Two Known Nodes](#33-inserting-a-node-between-two-known-nodes-two-way-circular-header)
4. [Searching in a Doubly Linked List](#34-searching-in-a-doubly-linked-list)

---

## 3.1 Traversing a Doubly Linked List

*(Using forward pointers is same as singly traversal; backward is symmetric. )*

### Forward Traversal (Ordinary Two-Way List)

```
1. Set PTR ← FIRST.

2. Repeat while PTR ≠ NULL. 
     a. Apply PROCESS to INFO[PTR].
     b.  Set PTR ← FORW[PTR].

3. Exit.
```

### Backward Traversal

```
1. Set PTR ← LAST.

2. Repeat while PTR ≠ NULL.
     a. Apply PROCESS to INFO[PTR]. 
     b. Set PTR ← BACK[PTR].

3. Exit.
```

### For Two-Way Circular Header List

**Forward:**
- `PTR ← FORW[START]`
- Stop when `PTR = START`

**Backward:**
- `PTR ← BACK[START]`
- Stop when `PTR = START`

---

## 3.2 Deleting a Node with Known Location (Two-Way Circular Header)

This is the core deletion algorithm for a doubly linked list, using both FORW and BACK.

**Algorithm: DELTWL(INFO, FORW, BACK, START, AVAIL, LOC)**

**Goal:** Delete node LOC from a two‑way circular header list.

```
1. Adjust neighbors to bypass LOC: 
     a. Set FORW[BACK[LOC]] ← FORW[LOC].
     b. Set BACK[FORW[LOC]] ← BACK[LOC].

2. Return node to free list:
     a. Set FORW[LOC] ← AVAIL. 
     b. Set AVAIL ← LOC.

3. Exit.
```

### Note

For an ordinary doubly linked list (no header, with FIRST/LAST), you must also update FIRST or LAST when deleting at ends, but pointer adjustments are similar. 

---

## 3.3 Inserting a Node Between Two Known Nodes (Two-Way Circular Header)

**Algorithm: INSTWL(INFO, FORW, BACK, START, AVAIL, LOCA, LOCB, ITEM)**

- **LOCA** and **LOCB** are adjacent nodes with `FORW[LOCA] = LOCB` and `BACK[LOCB] = LOCA`
- Insert new node **NEW** between LOCA and LOCB

```
1. Overflow? If AVAIL = NULL then
     a. Write OVERFLOW, and Exit.

2. Get new node and copy data:
     a. Set NEW ← AVAIL.
     b. Set AVAIL ← FORW[AVAIL].
     c.  Set INFO[NEW] ← ITEM.

3. Insert node into list (update 4 pointers):
     a. Set FORW[LOCA] ← NEW.
     b. Set FORW[NEW] ← LOCB.
     c. Set BACK[LOCB] ← NEW.
     d. Set BACK[NEW] ← LOCA.

4. Exit. 
```

### For Lists Without Header Nodes

- If inserting at beginning, LOCA may be NULL; then adjust **FIRST**
- If inserting at end, LOCB may be NULL; then adjust **LAST**

---

## 3.4 Searching in a Doubly Linked List

Same idea as singly, but you can search either forward from FIRST or backward from LAST, depending on where you expect the item to be.

### Forward Search (Unsorted)

```
1. Set PTR ← FIRST.

2. Repeat while PTR ≠ NULL and INFO[PTR] ≠ ITEM.
     a. Set PTR ← FORW[PTR].

3. If PTR = NULL then LOC ← NULL, else LOC ← PTR. 

4. Exit.
```

### Backward Search 

*(Example for sorted, large items near end)*

```
1. Set PTR ← LAST.

2. Repeat while PTR ≠ NULL and INFO[PTR] ≠ ITEM. 
     a. Set PTR ← BACK[PTR]. 

3. If PTR = NULL then LOC ← NULL, else LOC ← PTR.

4. Exit.
```

---


---

**Course:** CSE 2101 - Data Structures  
**Based on:** Seymour Lipschutz's Data Structures textbook
