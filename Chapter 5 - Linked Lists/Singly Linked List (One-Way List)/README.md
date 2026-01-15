# Singly Linked List (One-Way List)
A comprehensive guide to singly linked list operations and algorithms based on Seymour Lipschutz's Data Structures textbook.

## Table of Contents

1. [Traversing a Singly Linked List](#11-traversing-a-singly-linked-list)
2. [Searching in an Unsorted Singly Linked List](#12-searching-in-an-unsorted-singly-linked-list)
3. [Searching in a Sorted Singly Linked List](#13-searching-in-a-sorted-singly-linked-list)
4. [Inserting as the First Node](#14-inserting-as-the-first-node-unsorted-list)
5. [Inserting After a Given Location](#15-inserting-after-a-given-location)
6. [Finding the Node Before Insertion Position](#16-finding-the-node-just-before-insertion-position-in-a-sorted-list)
7. [Inserting into a Sorted Singly Linked List](#17-inserting-into-a-sorted-singly-linked-list)
8. [Deleting a Node](#18-deleting-a-node-when-its-location-and-its-predecessor-are-known)
9. [Finding Node and Its Predecessor](#19-finding-node-containing-item-and-its-predecessor)
10. [Deleting the First Occurrence of ITEM](#110-deleting-the-first-occurrence-of-item)
11. [Deleting the Last Node](#111-deleting-the-last-node-of-a-singly-linked-list)

---

## 1.1 Traversing a Singly Linked List

**Algorithm: TRAVERSE(INFO, LINK, START)**

**Goal:** Apply some operation PROCESS to every element, in order.

```
1. Set PTR ← START.  (Initialize pointer.)

2. Repeat Steps 3 and 4 while PTR ≠ NULL.

3.   Apply PROCESS to INFO[PTR].

4.   Set PTR ← LINK[PTR].  (Move to next node.)

5. Exit.
```

---

## 1.2 Searching in an Unsorted Singly Linked List

**Algorithm:  SEARCH(INFO, LINK, START, ITEM, LOC)**

**Goal:** Find location LOC of first node where INFO[LOC] = ITEM; set LOC ← NULL if not found.

```
1. Set PTR ← START.

2. Repeat Step 3 while PTR ≠ NULL.

3.   If ITEM = INFO[PTR] then
       a. Set LOC ← PTR, and
       b. Exit.
     Else
       c. Set PTR ← LINK[PTR]. (Move to next node.)
     End of If.

4. Set LOC ← NULL. (Search unsuccessful.)

5. Exit.
```

---

## 1.3 Searching in a Sorted Singly Linked List

**Algorithm: SEARCH_SORTED(INFO, LINK, START, ITEM, LOC)**

List is sorted in nondecreasing order by INFO.

```
1. Set PTR ← START. 

2. Repeat Step 3 while PTR ≠ NULL.

3.   If ITEM > INFO[PTR] then
       a. Set PTR ← LINK[PTR]. (Continue forward.)
     Else if ITEM = INFO[PTR] then
       b. Set LOC ← PTR, and Exit.  (Found.)
     Else
       c. Set LOC ← NULL, and Exit. (ITEM is smaller than current; cannot appear later.)
     End of If.

4. Set LOC ← NULL. (Reached end; not found.)

5. Exit.
```

---

## 1.4 Inserting as the First Node (Unsorted List)

**Algorithm: INSFIRST(INFO, LINK, START, AVAIL, ITEM)**

**Goal:** Insert new node with data ITEM at the beginning of the list. 

```
1. Overflow? If AVAIL = NULL then
     a. Write OVERFLOW, and
     b. Exit.

2. Remove first node from free list: 
     a. Set NEW ← AVAIL.
     b. Set AVAIL ← LINK[AVAIL].

3. Set INFO[NEW] ← ITEM. (Copy data.)

4. Set LINK[NEW] ← START. (New node points to old first node.)

5. Set START ← NEW. (New node becomes first.)

6. Exit.
```

---

## 1.5 Inserting After a Given Location

**Algorithm: INSLOC(INFO, LINK, START, AVAIL, LOC, ITEM)**

**Goal:** Insert ITEM so that it follows node at location LOC.  If LOC = NULL, insert as first node (same as INSFIRST).

```
1. Overflow? If AVAIL = NULL then
     a. Write OVERFLOW, and
     b. Exit.

2. Remove first node from free list: 
     a. Set NEW ← AVAIL.
     b. Set AVAIL ← LINK[AVAIL].

3. Set INFO[NEW] ← ITEM. (Copy data.)

4. If LOC = NULL then (Insert as first node)
     a. Set LINK[NEW] ← START.
     b. Set START ← NEW.
   Else (Insert after node LOC)
     c. Set LINK[NEW] ← LINK[LOC].
     d. Set LINK[LOC] ← NEW.
   End of If. 

5. Exit.
```

---

## 1.6 Finding the Node Just Before Insertion Position in a Sorted List

**Procedure: FINDA(INFO, LINK, START, ITEM, LOC)**

**Goal:** For a sorted list, find LOC = location of last node whose INFO[LOC] < ITEM. If ITEM must go at the beginning, set LOC ← NULL. 

```
1. List empty? If START = NULL then
     a.  Set LOC ← NULL, and Return.

2. Special case (insert before the first node)?
   If ITEM ≤ INFO[START] then
     a.  Set LOC ← NULL, and Return.

3. Set SAVE ← START and PTR ← LINK[START]. (Initialize pointers.)

4. Repeat Steps 5 and 6 while PTR ≠ NULL. 

5.   If ITEM ≤ INFO[PTR] then
       a. Set LOC ← SAVE, and Return. (Found preceding node.)
     End of If.

6.   Set SAVE ← PTR and PTR ← LINK[PTR]. (Advance both.)

7. Set LOC ← SAVE. (ITEM greater than all existing; insert after last node.)

8. Return.
```

---

## 1.7 Inserting into a Sorted Singly Linked List

**Algorithm: INSERT_SORTED(INFO, LINK, START, AVAIL, ITEM)**

**Goal:** Insert ITEM so that the list remains sorted.

```
1. Call FINDA(INFO, LINK, START, ITEM, LOC) to find the node preceding the insertion position.

2. Call INSLOC(INFO, LINK, START, AVAIL, LOC, ITEM) to insert after LOC 
   (or at beginning if LOC = NULL).

3. Exit.
```

---

## 1.8 Deleting a Node When Its Location and Its Predecessor Are Known

**Algorithm: DEL(INFO, LINK, START, AVAIL, LOC, LOCP)**

- **LOC** = node to delete.
- **LOCP** = node preceding LOC, or NULL if LOC is first node.

```
1. If LOCP = NULL then (delete first node)
     a. Set START ← LINK[START]. (First node removed.)
   Else (delete a node in the middle or end)
     b. Set LINK[LOCP] ← LINK[LOC]. (Bypass node LOC.)
   End of If.

2. Return node to free list:
     a.  Set LINK[LOC] ← AVAIL.
     b. Set AVAIL ← LOC.

3. Exit. 
```

---

## 1.9 Finding Node Containing ITEM and Its Predecessor

**Procedure: FINDB(INFO, LINK, START, ITEM, LOC, LOCP)**

**Goal:** Find the first node LOC with INFO[LOC] = ITEM and its predecessor LOCP.  If ITEM is in first node, set LOCP ← NULL.  If not found, LOC ← NULL.

```
1. List empty? If START = NULL then
     a. Set LOC ← NULL and LOCP ← NULL, and Return.

2. ITEM in first node? If INFO[START] = ITEM then
     a. Set LOC ← START and LOCP ← NULL, and Return.

3. Set SAVE ← START and PTR ← LINK[START]. (Initialize pointers.)

4. Repeat Steps 5 and 6 while PTR ≠ NULL.

5.   If INFO[PTR] = ITEM then
       a. Set LOC ← PTR and LOCP ← SAVE, and Return.
     End of If.

6.   Set SAVE ← PTR and PTR ← LINK[PTR]. (Advance.)

7. Set LOC ← NULL. (Search unsuccessful.)

8. Return.
```

---

## 1.10 Deleting the First Occurrence of ITEM

**Algorithm: DELETE(INFO, LINK, START, AVAIL, ITEM)**

**Goal:** Delete first node whose info equals ITEM. 

```
1. Call FINDB(INFO, LINK, START, ITEM, LOC, LOCP).

2. If LOC = NULL then
     a.  Write ITEM not in list, and Exit.

3. If LOCP = NULL then (delete first node)
     a. Set START ← LINK[START]. 
   Else (delete middle or last node)
     b. Set LINK[LOCP] ← LINK[LOC]. 
   End of If.

4. Return deleted node to free list: 
     a. Set LINK[LOC] ← AVAIL. 
     b. Set AVAIL ← LOC.

5. Exit.
```

---

## 1.11 Deleting the Last Node of a Singly Linked List

**Algorithm: DELLAST(INFO, LINK, START, AVAIL)**

*(Variant often asked in problems.)*

```
1. List empty? If START = NULL then
     a. Write UNDERFLOW, and Exit. 

2. List has one element? If LINK[START] = NULL then
     a. Set PTR ← START.
     b. Set START ← NULL. (List becomes empty.)
     c. Set LINK[PTR] ← AVAIL and AVAIL ← PTR.
     d. Exit.

3. Set PTR ← START and SAVE ← NULL. (Initialize.)

4. Repeat while LINK[PTR] ≠ NULL.
     a. Set SAVE ← PTR.
     b. Set PTR ← LINK[PTR].
   (After loop, PTR is last node, SAVE is second‑last.)

5. Set LINK[SAVE] ← NULL. (Remove last node from list.)

6. Set LINK[PTR] ← AVAIL and AVAIL ← PTR. (Return to free list.)

7. Exit.
```

---
