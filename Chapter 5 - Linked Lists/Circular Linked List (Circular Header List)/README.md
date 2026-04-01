# 📘 Circular Linked List — Easy Guide
> Based on Seymour Lipschutz's *Data Structures* | CSE 2101

---

## 🧠 What Is a Circular Header List?

A **circular header list** is a special type of linked list with two key features:

### 1. It Has a Header Node
- The very first node is a **dummy/header node** — it holds no real data
- It just acts as a **fixed starting point** so your code always has somewhere to begin
- `START` always points to this header node

### 2. It Is Circular
- Instead of the last node pointing to `NULL`, it points **back to the header node**
- This means the list forms a **complete circle** — no dead ends!

### What It Looks Like

```
START
  ↓
[HEADER] → [Node A] → [Node B] → [Node C] ─┐
   ↑                                         |
   └─────────────────────────────────────────┘
         (last node loops back to HEADER)
```

---

## ❓ How Do You Know If the List Is Empty?

Since there's no NULL pointer, we use this rule:

> **If `LINK[START] = START` → the list is empty**

Why? Because if the header's LINK points back to itself, there are no real nodes in between.

```
Empty list:
START
  ↓
[HEADER] ──┐
   ↑        |
   └────────┘
   (points to itself)
```

---

## 🔁 2.1 Traversal — Visiting Every Node

**Goal:** Go through every real node in the list, one by one, and do something with each.

### The Algorithm

```
Step 1: PTR ← LINK[START]        (skip the header, start at the first REAL node)
Step 2: While PTR ≠ START:       (keep going until we loop back to the header)
          a. Process INFO[PTR]   (do something with the current node's data)
          b. PTR ← LINK[PTR]    (move to the next node)
Step 3: Exit
```

### 💡 How It Works — Step by Step

Imagine the list: `HEADER → A → B → C → (back to HEADER)`

| Step | PTR     | Action                    |
|------|---------|---------------------------|
| 1    | A       | Start at first real node  |
| 2    | A       | Process A, move to B      |
| 3    | B       | Process B, move to C      |
| 4    | C       | Process C, move to HEADER |
| 5    | HEADER  | PTR = START → **STOP**    |

> We stop as soon as we hit the header again — that means we've gone through the whole circle.

---

## 🔍 2.2 Searching — Finding a Value in the List

**Goal:** Find the location `LOC` of the node whose data equals `ITEM`. If not found, return `LOC = NULL`.

### The Algorithm

```
Step 1: PTR ← LINK[START]                         (start at the first real node)
Step 2: While INFO[PTR] ≠ ITEM and PTR ≠ START:   (keep going if not found yet and not back at header)
          PTR ← LINK[PTR]                          (move forward)
Step 3: If INFO[PTR] = ITEM:
            LOC ← PTR                              (FOUND! record the position)
        Else:
            LOC ← NULL                             (NOT found)
Step 4: Exit
```

### 💡 Two Ways the Loop Ends

The `while` loop in Step 2 stops for one of two reasons:

| Reason                  | Meaning                        |
|-------------------------|--------------------------------|
| `INFO[PTR] = ITEM`      | ✅ Found the node we want       |
| `PTR = START`           | ❌ Went all the way around, not found |

> After the loop, we just check which reason caused it to stop.

---

## 🔎 2.3 Finding a Node AND Its Predecessor

**Goal:** Find the node containing `ITEM` (`LOC`) **and** the node just before it (`LOCP`).

> **Why do we need the predecessor?**
> To delete a node, you need to update the pointer of the node *before* it. So you always need to know who comes just before your target.

### The Algorithm

```
Step 1: SAVE ← START                               (SAVE tracks the previous node, starts at header)
        PTR ← LINK[START]                          (PTR tracks the current node)

Step 2: While INFO[PTR] ≠ ITEM and PTR ≠ START:
          a. SAVE ← PTR                            (remember current as "previous")
          b. PTR ← LINK[PTR]                       (advance to next)

Step 3: If INFO[PTR] = ITEM:
            LOC  ← PTR                             (found it here)
            LOCP ← SAVE                            (its predecessor is SAVE)
        Else:
            LOC  ← NULL                            (not found)
            LOCP ← SAVE                            (SAVE still holds last visited)

Step 4: Exit
```

### 💡 How SAVE and PTR Move Together

Think of them as two people walking the list — one step apart:

```
Initially:
SAVE = HEADER,  PTR = A

After step 1:
SAVE = A,  PTR = B

After step 2:
SAVE = B,  PTR = C     ← if C has ITEM, then LOC=C, LOCP=B
```

> SAVE is always **one step behind** PTR. That's how we always know the predecessor.

---

## ❌ 2.4 Deleting a Node with a Given Value

**Goal:** Delete the first node in the list whose data equals `ITEM`.

**Algorithm name:** `DELETE_HEADER(INFO, LINK, START, AVAIL, ITEM)`

### The Algorithm

```
Step 1: Call FINDB_HEADER(...)         (find LOC and LOCP using algorithm 2.3)

Step 2: If LOC = NULL:
            Print "ITEM not in list"   (nothing to delete)
            Exit

Step 3: LINK[LOCP] ← LINK[LOC]        (make the predecessor skip over LOC)

Step 4: Return the deleted node to the free list:
            a. LINK[LOC] ← AVAIL      (LOC's pointer now points to old free list)
            b. AVAIL ← LOC            (free list now starts at LOC)

Step 5: Exit
```

### 💡 What Happens to the Pointers

**Before deletion** (deleting node B):
```
[HEADER] → [A] → [B] → [C] → ...
              LOCP  LOC
```

**After Step 3** (`LINK[A] ← LINK[B]`, i.e., A now points to C):
```
[HEADER] → [A] → [C] → ...
                  (B is now bypassed)
```

**After Step 4** (B sent to free list):
```
AVAIL → [B] → (old AVAIL) → ...
```

> The deleted node is **recycled**, not thrown away. It goes to the free list for future use.

---

## 🗑️ 2.5 Deleting the Last Node

**Goal:** Remove the very last node in the circular header list.

**Algorithm name:** `DELLAST_HEADER(INFO, LINK, START, AVAIL)`

### The Algorithm

```
Step 1: If LINK[START] = START:        (list is empty!)
            Print "UNDERFLOW"
            Exit

Step 2: PTR ← LINK[START]             (PTR = first real node)
        SAVE ← START                  (SAVE = header, our "one step behind" tracker)

Step 3: While LINK[PTR] ≠ START:      (keep going until PTR is the LAST node)
            a. SAVE ← PTR             (move SAVE forward)
            b. PTR ← LINK[PTR]       (move PTR forward)

Step 4: LINK[SAVE] ← LINK[PTR]        (SAVE now points where PTR pointed, which is START)

Step 5: LINK[PTR] ← AVAIL             (recycle the deleted node)
        AVAIL ← PTR

Step 6: Exit
```

### 💡 How to Find the Last Node

The last node is the one whose `LINK` points back to `START` (the header). So we walk the list until we find that node.

```
Walk the list step by step:

Start:
SAVE = HEADER,  PTR = A

LINK[A] ≠ START? Yes → SAVE = A, PTR = B
LINK[B] ≠ START? Yes → SAVE = B, PTR = C
LINK[C] = START? YES → STOP!   PTR = C (last node), SAVE = B (its predecessor)
```

**After Step 4** (`LINK[B] ← LINK[C]`, which equals `START`):
```
[HEADER] → [A] → [B] ─┐
   ↑                    |
   └────────────────────┘
         (C is removed, B is now last)
```

### ⚠️ What Is "UNDERFLOW"?

Underflow means you tried to **delete from an empty list**. Always check for this first!

---

## 📝 Variation: Circular List Without a Header Node

Some textbooks or problems use a circular list **without** a header node:

| Feature               | With Header               | Without Header              |
|-----------------------|---------------------------|-----------------------------|
| `START` points to...  | Header (dummy) node       | First real data node        |
| Empty list condition  | `LINK[START] = START`     | `START = NULL`              |
| Loop termination      | `PTR = START`             | `PTR = START` (same logic!) |

> The core logic is almost identical — just no dummy node at the front.

---

## 🧩 Quick Summary of All Algorithms

| Algorithm         | Goal                                        | Key Idea                              |
|-------------------|---------------------------------------------|---------------------------------------|
| **Traversal**     | Visit all nodes                             | Loop until `PTR = START` again        |
| **Search**        | Find a node by value                        | Loop until match or `PTR = START`     |
| **Find + Predecessor** | Locate a node and its previous node   | Use two pointers: SAVE + PTR          |
| **Delete by Value** | Remove the node containing ITEM           | Find it, bypass it, recycle it        |
| **Delete Last**   | Remove the final node                       | Walk to last node, then bypass it     |

---

## 🧾 Glossary

| Term      | Meaning                                                       |
|-----------|---------------------------------------------------------------|
| `START`   | Always points to the header node                              |
| `PTR`     | A pointer that moves through the list node by node            |
| `SAVE`    | Tracks the **previous** node (one step behind PTR)            |
| `LOC`     | The **location** of the node we're looking for                |
| `LOCP`    | The **predecessor** (node just before LOC)                    |
| `AVAIL`   | Head of the free list (pool of reusable empty nodes)          |
| `INFO[K]` | The **data** stored in node K                                 |
| `LINK[K]` | The **pointer** from node K to the next node                  |
| OVERFLOW  | No free nodes left — can't insert                             |
| UNDERFLOW | List is empty — can't delete                                  |

---

*Course: CSE 2101 — Data Structures | Based on Seymour Lipschutz's Data Structures*
