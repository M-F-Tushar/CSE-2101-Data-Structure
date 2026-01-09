# Circular Linked List (Circular Header List)

A comprehensive guide to circular header list operations and algorithms based on Seymour Lipschutz's Data Structures textbook.

## Overview

The chapter's main "circular" structure is a **circular header list**: 

- **START** points to the header node. 
- For a circular header list, the list is empty if `LINK[START] = START`.
- The last real node points back to the header node (START).

These algorithms are directly for circular header lists, which are the standard textbook model. 

## Table of Contents

1. [Traversing a Circular Header List](#21-traversing-a-circular-header-list)
2. [Searching in a Circular Header List](#22-searching-in-a-circular-header-list)
3. [Finding Node with ITEM and Its Predecessor](#23-finding-node-with-item-and-its-predecessor-header-circular)
4. [Deleting a Node with Given ITEM](#24-deleting-a-node-with-given-item-header-circular)
5. [Deleting the Last Node](#25-deleting-the-last-node-from-a-circular-header-list)

---

## 2.1 Traversing a Circular Header List

**Algorithm:  TRAVERSE_HEADER(INFO, LINK, START)**

**Goal:** Apply PROCESS to each ordinary node once.

```
1. Set PTR ← LINK[START]. (First ordinary node.)

2. Repeat Steps 3 and 4 while PTR ≠ START.  (Stop when header reached again.)

3.   Apply PROCESS to INFO[PTR].

4.   Set PTR ← LINK[PTR]. (Next node.)

5. Exit.
```

---

## 2.2 Searching in a Circular Header List

**Algorithm: SEARCH_HEADER(INFO, LINK, START, ITEM, LOC)**

**Goal:** Find location LOC where INFO[LOC] = ITEM, or LOC ← NULL.

```
1. Set PTR ← LINK[START]. (First real node.)

2. Repeat while INFO[PTR] ≠ ITEM and PTR ≠ START.
     a. Set PTR ← LINK[PTR]. (Advance.)

3.  If INFO[PTR] = ITEM then
     a. Set LOC ← PTR.
   Else
     b. Set LOC ← NULL.
   End of If.

4. Exit. 
```

---

## 2.3 Finding Node with ITEM and Its Predecessor (Header Circular)

**Procedure: FINDB_HEADER(INFO, LINK, START, ITEM, LOC, LOCP)**

**Goal:** In a circular header list, find first node LOC with INFO[LOC] = ITEM and its predecessor LOCP. If not found, set LOC ← NULL.

```
1. Set SAVE ← START and PTR ← LINK[START]. (Initialize pointers.)

2. Repeat while INFO[PTR] ≠ ITEM and PTR ≠ START.
     a. Set SAVE ← PTR.
     b. Set PTR ← LINK[PTR].
   (When loop stops, either found ITEM or returned to header.)

3. If INFO[PTR] = ITEM then
     a. Set LOC ← PTR and LOCP ← SAVE.
   Else
     b. Set LOC ← NULL and LOCP ← SAVE.
   End of If. 

4. Exit.
```

---

## 2.4 Deleting a Node with Given ITEM (Header Circular)

**Algorithm: DELETE_HEADER(INFO, LINK, START, AVAIL, ITEM)**

**Goal:** In a circular header list, delete first node whose INFO = ITEM. 

```
1. Call FINDB_HEADER(INFO, LINK, START, ITEM, LOC, LOCP).

2. If LOC = NULL then
     a. Write ITEM not in list, and Exit.

3. Set LINK[LOCP] ← LINK[LOC]. (Bypass LOC.)

4. Return node to free list:
     a. Set LINK[LOC] ← AVAIL. 
     b. Set AVAIL ← LOC.

5. Exit.
```

---

## 2.5 Deleting the Last Node from a Circular Header List

**Algorithm: DELLAST_HEADER(INFO, LINK, START, AVAIL)**

**Goal:** Delete last ordinary node of a circular header list.

```
1. List empty? If LINK[START] = START then
     a. Write UNDERFLOW, and Exit.

2. Set PTR ← LINK[START] and SAVE ← START. (Initialize.)

3. Repeat while LINK[PTR] ≠ START. (Traverse until last node.)
     a. Set SAVE ← PTR.
     b. Set PTR ← LINK[PTR].

4. Set LINK[SAVE] ← LINK[PTR]. (Remove last node; now LINK[SAVE] = START.)

5. Set LINK[PTR] ← AVAIL and AVAIL ← PTR. (Return to free list.)

6. Exit.
```

---

## Note on Circular Singly List Without Header Node

If you need a circular singly list **without header node** for class, the logic is the same as above but with: 

- **START** pointing to first data node
- **End of list** detected by `PTR = START` again

The book explicitly notes that as a variation. 

---
