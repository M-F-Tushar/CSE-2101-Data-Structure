# CSE 2101 — Data Structure Final Examination 2023

**Chandpur Science and Technology University**
**Department of Computer Science and Engineering**
**B.Sc. Engineering 2nd Year 1st Semester Final Examination, 2023**
**Course Code: CSE 2101 | Course Title: Data Structure**
**Time: 03 Hours | Full Marks: 210**

---

# SECTION – A (Marks: 105)

*(Answer any three (03) questions from this section in Script A)*

---

## Question 1

---

### 1(a) Define data structure. Give some examples of linear and non-linear data structure. [06]

**Definition:**
A **data structure** is a systematic way of organizing, storing, and managing data in a computer so that it can be accessed and modified efficiently.

**Linear Data Structures** — Elements are arranged in a sequential order, one after another:

| Structure | Example |
|---|---|
| Array | `[10, 20, 30, 40]` |
| Linked List | `10 → 20 → 30 → NULL` |
| Stack | Push/Pop from top |
| Queue | Enqueue at rear, Dequeue from front |

**Non-Linear Data Structures** — Elements are arranged in a hierarchical or network manner:

| Structure | Example |
|---|---|
| Tree | File system folder hierarchy |
| Graph | City road network |
| Heap | Priority queue |

---

### 1(b) Briefly describe the notions of (i) the complexity of an algorithm, and (ii) the space-time trade-off of algorithm. [08]

#### (i) Complexity of an Algorithm

The **complexity** of an algorithm is a function `f(n)` that measures the amount of **time** or **space** required by the algorithm relative to the **size of the input `n`**.

- **Time Complexity** — How many steps/operations the algorithm performs.
- **Space Complexity** — How much memory the algorithm uses.

We express complexity using **Big-O notation**:

| Notation | Name | Example |
|---|---|---|
| O(1) | Constant | Accessing array element |
| O(log n) | Logarithmic | Binary Search |
| O(n) | Linear | Linear Search |
| O(n²) | Quadratic | Bubble Sort |

**Example:** Linear Search on n = 10,000 elements → worst case O(n) = 10,000 comparisons.

#### (ii) Space-Time Trade-off

The **space-time trade-off** is the idea that you can often **save time by using more memory**, or **save memory by using more time**. There is usually an inverse relationship between the two.

**Example:**
> A file is sorted by Social Security Number (SSN). Searching by **Name** is slow (O(n) linear scan).

**Solution 1 (Save Time, Use More Space):**
Keep two complete sorted copies — one sorted by SSN, one by Name. Searching is fast O(log n) in both, but storage doubles.

**Solution 2 (Save Space, Use More Time):**
Keep only one file sorted by SSN. Use a small index (auxiliary array) sorted by Name with pointers to the main file. Less space, slightly more steps.

---

### 1(c) Suppose a data set S contains n elements. (i) Compare the running time T₁ of the linear search algorithm with the running time T₂ of the binary search algorithm when n = 10000. (ii) Discuss searching for a given item in S when S is sorted as a linked list. [12]

#### (i) Linear Search T₁ vs Binary Search T₂ when n = 10,000

**Linear Search:**
- Checks elements one-by-one from start to end.
- Average comparisons = n/2 = 10,000 / 2 = **5,000**
- Worst case = n = **10,000** comparisons
- Complexity: **O(n)**

**Binary Search:**
- Divides the search range in half each step.
- Max comparisons = ⌈log₂(n)⌉ = ⌈log₂(10,000)⌉ = ⌈13.28⌉ = **14**
- Complexity: **O(log₂ n)**

**Comparison Table:**

| Algorithm | Best Case | Average Case | Worst Case |
|---|---|---|---|
| Linear Search T₁ | 1 | 5,000 | 10,000 |
| Binary Search T₂ | 1 | ~7 | 14 |

> **Conclusion:** Binary search is **714 times faster** on average for n = 10,000. However, binary search **requires the data to be sorted**.

#### (ii) Searching in S when S is sorted as a linked list

Even though the linked list is sorted, **binary search CANNOT be used** because:

- Binary search requires **direct (random) access** to the middle element: `A[mid]`
- In a linked list, to reach the middle node, you must **traverse from the beginning** — there is no index-based access.

Therefore, we are **forced to use linear search**:

```
Procedure: SRCHSL(INFO, LINK, START, ITEM, LOC)
1. Set PTR := START
2. Repeat while PTR ≠ NULL:
     If ITEM = INFO[PTR]: Set LOC := PTR, Exit  [Found]
     Else if ITEM < INFO[PTR]: Set LOC := NULL, Exit  [Not here]
     Else: PTR := LINK[PTR]  [Move forward]
3. Set LOC := NULL
4. Exit
```

**Advantage over unsorted list:** We can stop early if `ITEM < INFO[PTR]`, since all remaining elements will be larger. But worst case is still **O(n)**.

---

### 1(d) Write a procedure FIND(DATA, N, LOC1, LOC2) which finds the location LOC1 of the largest element and the location LOC2 of the second largest element in an array DATA with n ≥ 1 elements. [09]

**Idea:** Traverse the array once. Track the position of the **largest** (LOC1) and **second largest** (LOC2) elements.

**Pseudocode:**

```
Procedure: FIND(DATA, N, LOC1, LOC2)
──────────────────────────────────────
1. Set LOC1 := 1  [Assume first element is largest]
   Set LOC2 := NULL  [No second largest yet]

2. Repeat for K := 2 to N:

     If DATA[K] > DATA[LOC1], then:
         LOC2 := LOC1        [Old largest becomes second]
         LOC1 := K           [K is the new largest]

     Else If DATA[K] > DATA[LOC2] OR LOC2 = NULL, then:
         If DATA[K] ≠ DATA[LOC1], then:
             LOC2 := K       [K is the new second largest]

   [End of loop]

3. Return (LOC1, LOC2)
```

**Step-by-step Example:**
DATA = [12, 35, 28, 35, 7, 42, 15], N = 7

| K | DATA[K] | LOC1 (largest) | LOC2 (2nd largest) | Action |
|---|---|---|---|---|
| Start | — | 1 (val=12) | NULL | Initialize |
| 2 | 35 | 2 (val=35) | 1 (val=12) | 35 > 12, update |
| 3 | 28 | 2 (val=35) | 3 (val=28) | 28 < 35 but 28 > 12 |
| 4 | 35 | 2 (val=35) | 3 (val=28) | 35 = 35, skip |
| 5 | 7 | 2 (val=35) | 3 (val=28) | 7 < 28, no change |
| 6 | 42 | 6 (val=42) | 2 (val=35) | 42 > 35, update |
| 7 | 15 | 6 (val=42) | 2 (val=35) | 15 < 35, no change |

**Result:** LOC1 = 6 (value = 42), LOC2 = 2 (value = 35) ✓

---

## Question 2

---

### 2(a) You have learned that singly linked lists are trees. Are circularly linked lists also trees? Why or why not? [05]

**Answer: No, circularly linked lists are NOT trees.**

**Reasons:**

1. **A tree must be acyclic** (no cycles). In a circular linked list, the last node points back to the first node, creating a **cycle**. Trees cannot have cycles.

2. **A singly linked list can be considered a degenerate tree** (every node has exactly one child, except the last which has none). But this only works because it has no cycle and has a clear root (START).

3. **Circular linked list violates the tree property**: In a tree, each node has exactly one parent (except the root). In a circular linked list, the last node points to the first node, making the first node appear to have a "parent" (the last node), which creates a circular dependency — breaking the tree structure.

**Diagram:**

```
Circular List: HEAD → A → B → C → (back to HEAD)  ← CYCLE exists = NOT a tree

Singly Linked: START → A → B → C → NULL  ← No cycle = Can be a tree
```

---

### 2(b) "Stacks are used in processing of data when certain steps of processing must be postponed until other conditions are fulfilled" – Explain with an example. [08]

**Statement Meaning:**
Stacks are useful when some processing steps **cannot be completed immediately** and must wait until a certain condition is met. The **LIFO (Last-In, First-Out)** property of stacks allows us to resume the most recently postponed task first.

**Example — Function Call Stack:**

Consider calling functions in this order:
```
Main() calls Function_A()
Function_A() calls Function_B()
Function_B() calls Function_C()
```

The system uses a stack to remember **where to return** after each function:

| Step | Action | Stack (top→bottom) |
|---|---|---|
| 1 | Main starts, calls A | [Return to Main] |
| 2 | A starts, calls B | [Return to A, Return to Main] |
| 3 | B starts, calls C | [Return to B, Return to A, Return to Main] |
| 4 | C finishes | Pop → Return to B. Stack: [Return to A, Return to Main] |
| 5 | B finishes | Pop → Return to A. Stack: [Return to Main] |
| 6 | A finishes | Pop → Return to Main. Stack: [] |

**Another Example — Postfix Expression Evaluation:**
Expression: `5 6 2 + * 12 4 / -`

When we see `*`, we cannot evaluate it yet — we must **postpone** it until both operands are ready. The stack holds intermediate results until the operator can be applied.

> **Key Insight:** Each item pushed represents a "postponed decision." When conditions are met (operator arrives), we pop and process.

---

### 2(c) Write a procedure to translate the binary search and insertion algorithm into a subprogram BINARY(ARRAY, LB, UB, ITEM, LOC) which finds either the location LOC where ITEM appears in ARRAY or the location LOC where ITEM should be inserted into ARRAY. [12]

**Purpose:** Search a sorted ARRAY for ITEM. Return the index where ITEM is found (if present), or the index where ITEM should be **inserted** (if not present).

**Pseudocode:**

```
Procedure: BINARY(ARRAY, LB, UB, ITEM, LOC)
─────────────────────────────────────────────
ARRAY = Sorted array
LB    = Lower Bound (start index)
UB    = Upper Bound (end index)
ITEM  = Element to search for
LOC   = Location where ITEM is found or should be inserted

1. Set BEG := LB
   Set END := UB

2. Repeat while BEG <= END:

     Set MID := (BEG + END) / 2

     If ARRAY[MID] = ITEM, then:
         Set LOC := MID    [FOUND at MID]
         Return

     Else If ITEM < ARRAY[MID], then:
         Set END := MID - 1    [Search left half]

     Else:
         Set BEG := MID + 1    [Search right half]

   [End of loop]

3. [NOT FOUND — LOC is the insertion position]
   Set LOC := BEG

4. Return
```

**Step-by-step Example:**

ARRAY = [10, 20, 30, 40, 50, 60], LB=0, UB=5

**Search for ITEM = 40 (Found):**

| Step | BEG | END | MID | ARRAY[MID] | Comparison | Action |
|---|---|---|---|---|---|---|
| 1 | 0 | 5 | 2 | 30 | 40 > 30 | BEG = 3 |
| 2 | 3 | 5 | 4 | 50 | 40 < 50 | END = 3 |
| 3 | 3 | 3 | 3 | 40 | 40 = 40 | LOC = 3, Found! |

**Search for ITEM = 35 (Not Found — insertion position):**

| Step | BEG | END | MID | ARRAY[MID] | Comparison | Action |
|---|---|---|---|---|---|---|
| 1 | 0 | 5 | 2 | 30 | 35 > 30 | BEG = 3 |
| 2 | 3 | 5 | 4 | 50 | 35 < 50 | END = 3 |
| 3 | 3 | 3 | 3 | 40 | 35 < 40 | END = 2 |
| 4 | BEG(3) > END(2) | — | Loop ends | — | — | LOC = BEG = 3 → Insert at 3 |

> **35 should be inserted at index 3** (between 30 and 40). ✓

---

### 2(d) Write a function that will merge two linked lists of integer, assuming that they are sorted in ascending order. The merged list should itself be sorted in ascending order. [10]

**Idea:** Compare the heads of both lists. Take the smaller node and append it to the merged list. Repeat until both lists are exhausted.

**Pseudocode:**

```
Function: MERGE_LISTS(LIST1, LIST2)
─────────────────────────────────────
LIST1 = First sorted linked list (head pointer)
LIST2 = Second sorted linked list (head pointer)
Returns: Head of merged sorted list

1. Create a DUMMY node to serve as the head of the result list.
   Set CURR := DUMMY  [CURR is the tail of the result so far]

2. Set P := LIST1
   Set Q := LIST2

3. Repeat while P ≠ NULL and Q ≠ NULL:

     If INFO[P] <= INFO[Q], then:
         Set LINK[CURR] := P
         Set P := LINK[P]

     Else:
         Set LINK[CURR] := Q
         Set Q := LINK[Q]

     Set CURR := LINK[CURR]  [Advance tail]

   [End of loop]

4. [Attach remaining nodes]
   If P ≠ NULL, then: Set LINK[CURR] := P
   Else: Set LINK[CURR] := Q

5. Return LINK[DUMMY]  [Head of merged list]
```

**Step-by-step Example:**

LIST1: 1 → 3 → 5 → NULL
LIST2: 2 → 4 → 6 → NULL

| Step | P | Q | Smaller | Result List So Far |
|---|---|---|---|---|
| 1 | 1 | 2 | 1 | 1 → |
| 2 | 3 | 2 | 2 | 1 → 2 → |
| 3 | 3 | 4 | 3 | 1 → 2 → 3 → |
| 4 | 5 | 4 | 4 | 1 → 2 → 3 → 4 → |
| 5 | 5 | 6 | 5 | 1 → 2 → 3 → 4 → 5 → |
| 6 | NULL | 6 | P = NULL, attach Q | 1 → 2 → 3 → 4 → 5 → 6 → NULL |

**Merged List:** 1 → 2 → 3 → 4 → 5 → 6 → NULL ✓

---

## Question 3

---

### 3(a) Use Merge sort to find the largest integer on 38, 27, 43, 3, 9, 82, 10. Show your work step-by-step and also draw the recursion tree. [11]

**Array:** [38, 27, 43, 3, 9, 82, 10]

#### STEP 1 — DIVIDE PHASE (Splitting)

```
Level 0:  [38, 27, 43, 3, 9, 82, 10]
              /              \
Level 1: [38, 27, 43]     [3, 9, 82, 10]
           /    \            /         \
Level 2: [38] [27, 43]   [3, 9]     [82, 10]
               /   \      /  \        /    \
Level 3:      [27] [43] [3]  [9]    [82]  [10]
```

Each single element is already sorted.

#### STEP 2 — MERGE PHASE (Combining)

**Merge [27] and [43]:**
- 27 < 43 → [27, 43] ✓

**Merge [38] and [27, 43]:**
- Compare 38 vs 27 → take 27
- Compare 38 vs 43 → take 38
- Remaining: 43
- Result: **[27, 38, 43]** ✓

**Merge [3] and [9]:**
- 3 < 9 → [3, 9] ✓

**Merge [82] and [10]:**
- 10 < 82 → [10, 82] ✓

**Merge [3, 9] and [10, 82]:**
- 3 < 10 → take 3
- 9 < 10 → take 9
- Remaining: [10, 82]
- Result: **[3, 9, 10, 82]** ✓

**Final Merge [27, 38, 43] and [3, 9, 10, 82]:**

| Compare | Take | Result So Far |
|---|---|---|
| 27 vs 3 | 3 | [3] |
| 27 vs 9 | 9 | [3, 9] |
| 27 vs 10 | 10 | [3, 9, 10] |
| 27 vs 27 | 27 | [3, 9, 10, 27] |
| 38 vs 38 | 38 | [3, 9, 10, 27, 38] |
| 43 vs 43 | 43 | [3, 9, 10, 27, 38, 43] |
| Remaining: [82] | 82 | [3, 9, 10, 27, 38, 43, 82] |

**Final Sorted Array:** [3, 9, 10, 27, 38, 43, 82]

**Largest Integer = 82**

#### Recursion Tree

```
mergeSort([38, 27, 43, 3, 9, 82, 10])
├── mergeSort([38, 27, 43])
│   ├── mergeSort([38])          → [38]
│   └── mergeSort([27, 43])
│       ├── mergeSort([27])      → [27]
│       └── mergeSort([43])      → [43]
│       └── MERGE([27],[43])     → [27, 43]
│   └── MERGE([38],[27,43])      → [27, 38, 43]
│
└── mergeSort([3, 9, 82, 10])
    ├── mergeSort([3, 9])
    │   ├── mergeSort([3])       → [3]
    │   └── mergeSort([9])       → [9]
    │   └── MERGE([3],[9])       → [3, 9]
    └── mergeSort([82, 10])
        ├── mergeSort([82])      → [82]
        └── mergeSort([10])      → [10]
        └── MERGE([82],[10])     → [10, 82]
    └── MERGE([3,9],[10,82])     → [3, 9, 10, 82]
│
└── MERGE([27,38,43],[3,9,10,82]) → [3, 9, 10, 27, 38, 43, 82]
```

---

### 3(b) "Is bubble sort is divide and conquer type"? Explain your answer if you say 'yes' or give a counter example if you say 'no'. [08]

**Answer: NO. Bubble sort is NOT a divide and conquer algorithm.**

**What is Divide and Conquer?**
An algorithm is "divide and conquer" if it:
1. **Divides** the problem into smaller sub-problems
2. **Conquers** each sub-problem independently (usually recursively)
3. **Combines** the solutions

**Why Bubble Sort is NOT Divide and Conquer:**

Bubble sort works by **repeatedly comparing adjacent elements** and swapping them if they are in the wrong order. It does NOT divide the array into sub-problems.

**Counter Example:**

Array: [5, 3, 1, 4, 2]

**Bubble Sort Pass 1:**
- Compare 5 and 3 → swap → [3, 5, 1, 4, 2]
- Compare 5 and 1 → swap → [3, 1, 5, 4, 2]
- Compare 5 and 4 → swap → [3, 1, 4, 5, 2]
- Compare 5 and 2 → swap → [3, 1, 4, 2, 5]

At no point does bubble sort split the array into two independent halves and solve them separately. It processes the **entire array** in each pass.

**Comparison:**

| Property | Divide & Conquer (Merge Sort) | Bubble Sort |
|---|---|---|
| Splits array? | Yes, into halves | No |
| Recursive? | Yes | No (iterative) |
| Independent sub-problems? | Yes | No |
| Complexity | O(n log n) | O(n²) |

**Bubble sort belongs to the "Exchange Sort" category** — it sorts by exchanging neighboring elements until the list is ordered.

---

### 3(c) Consider a singly linked list of the form shown in following figure, where F is a pointer to the first element in the linked list and L is a pointer to the last element in the list. Write the functions/procedures separately to perform the following operations – (i) Delete the last element of the list. (ii) Delete the first element of the list. (iii) Add an element after the last element of the list. (iv) Add an element before the first element of the list. [16]

**List Structure:** `F → [Node1] → [Node2] → ... → [NodeN] → NULL`, where L points to NodeN.

#### (i) Delete the Last Element

```
Procedure: DELETE_LAST(F, L)
──────────────────────────────
1. If F = NULL, then:
       Print "UNDERFLOW — List is empty"
       Return

2. If F = L, then:       [Only one node]
       Set F := NULL
       Set L := NULL
       Return

3. [Traverse to the second-to-last node]
   Set PTR := F
   Repeat while LINK[PTR] ≠ L:
       Set PTR := LINK[PTR]

4. Set LINK[PTR] := NULL   [Cut off the last node]
5. Set L := PTR            [Update L to new last node]
6. Return
```

**Example:** F → 10 → 20 → 30 → NULL (L = 30)
After delete last: F → 10 → 20 → NULL (L = 20) ✓

#### (ii) Delete the First Element

```
Procedure: DELETE_FIRST(F, L)
───────────────────────────────
1. If F = NULL, then:
       Print "UNDERFLOW — List is empty"
       Return

2. Set TEMP := F
   Set F := LINK[F]     [Move F to second node]

3. If F = NULL, then:   [List had only one node]
       Set L := NULL

4. Free TEMP (optional memory release)
5. Return
```

**Example:** F → 10 → 20 → 30 → NULL (L = 30)
After delete first: F → 20 → 30 → NULL (L = 30) ✓

#### (iii) Add an Element After the Last Element of the List

```
Procedure: ADD_AFTER_LAST(F, L, ITEM)
───────────────────────────────────────
1. Create a new node NEW
   Set INFO[NEW] := ITEM
   Set LINK[NEW] := NULL

2. If F = NULL, then:    [List is empty]
       Set F := NEW
       Set L := NEW
       Return

3. Set LINK[L] := NEW    [Link last node to NEW]
4. Set L := NEW          [Update L to new last node]
5. Return
```

**Example:** F → 10 → 20 → 30 → NULL (L = 30), ITEM = 40
After: F → 10 → 20 → 30 → 40 → NULL (L = 40) ✓

#### (iv) Add an Element Before the First Element of the List

```
Procedure: ADD_BEFORE_FIRST(F, L, ITEM)
─────────────────────────────────────────
1. Create a new node NEW
   Set INFO[NEW] := ITEM

2. If F = NULL, then:    [List is empty]
       Set LINK[NEW] := NULL
       Set F := NEW
       Set L := NEW
       Return

3. Set LINK[NEW] := F    [NEW points to old first node]
4. Set F := NEW          [Update F to NEW]
5. Return
```

**Example:** F → 10 → 20 → 30 → NULL (L = 30), ITEM = 5
After: F → 5 → 10 → 20 → 30 → NULL (L = 30) ✓

---

## Question 4

---

### 4(a) Explain how Stack is used in Depth-First Search (DFS). [05]

**DFS uses a Stack** to implement its "explore as deep as possible, then backtrack" strategy.

**How it works:**

1. **Push** the starting vertex onto the stack. Mark it as visited.
2. **Pop** a vertex from the stack. Visit it.
3. **Push** all unvisited neighbors of that vertex onto the stack. Mark them as visited.
4. Repeat steps 2–3 until the stack is empty.

**Why Stack?** Because DFS explores depth-first — it goes as deep as possible before backtracking. The stack's **LIFO (Last-In, First-Out)** property ensures we always continue from the most recently discovered vertex.

**Example:** Graph: A–B, A–C, B–D, C–E

| Step | Stack (top→bottom) | Visited | Action |
|---|---|---|---|
| Start | [A] | {A} | Push A |
| 1 | [C, B] | {A, B, C} | Pop A, Push B and C |
| 2 | [E, C] | {A, B, C, E} | Pop B, Push D... Continue |
| ... | ... | ... | Continue until stack empty |

**DFS Algorithm using Stack:**

```
1. Initialize all nodes STATUS = 1 (Ready)
2. Push starting node, set STATUS = 2 (Waiting)
3. While STACK is not empty:
     Pop node N, process it, STATUS[N] = 3 (Processed)
     For each neighbor M of N where STATUS[M] = 1:
         Push M, STATUS[M] = 2
4. Exit
```

---

### 4(b) Consider the following infix expression: (3 + 5) * (6 – 4) / 2. (i) Convert to Postfix Notation. (ii) Evaluate using a Stack. [10]

#### (i) Convert Infix to Postfix Notation

**Rules:**
- Operands → directly to output
- `(` → push onto stack
- `)` → pop and output until `(`
- Operator → pop operators of equal/higher precedence, then push

**Operator Precedence:** `*` and `/` have higher precedence than `+` and `-`. `*` and `/` have the same level (left-to-right).

**Conversion Trace:**

| Symbol | Action | Stack (top→bottom) | Output |
|---|---|---|---|
| `(` | Push | `(` | |
| `3` | Output | `(` | `3` |
| `+` | Push | `+ (` | `3` |
| `5` | Output | `+ (` | `3 5` |
| `)` | Pop until `(` | (empty) | `3 5 +` |
| `*` | Push | `*` | `3 5 +` |
| `(` | Push | `( *` | `3 5 +` |
| `6` | Output | `( *` | `3 5 + 6` |
| `-` | Push | `- ( *` | `3 5 + 6` |
| `4` | Output | `- ( *` | `3 5 + 6 4` |
| `)` | Pop until `(` | `*` | `3 5 + 6 4 -` |
| `/` | Same level as `*`, pop `*` then push `/` | `/` | `3 5 + 6 4 - *` |
| `2` | Output | `/` | `3 5 + 6 4 - * 2` |
| End | Pop all | (empty) | `3 5 + 6 4 - * 2 /` |

**Postfix Result:** `3 5 + 6 4 - * 2 /`

#### (ii) Evaluate Postfix `3 5 + 6 4 - * 2 /` using a Stack

| Symbol | Action | Stack (top→bottom) |
|---|---|---|
| `3` | Push 3 | `3` |
| `5` | Push 5 | `5, 3` |
| `+` | Pop 5 and 3, compute 3+5=8, Push 8 | `8` |
| `6` | Push 6 | `6, 8` |
| `4` | Push 4 | `4, 6, 8` |
| `-` | Pop 4 and 6, compute 6-4=2, Push 2 | `2, 8` |
| `*` | Pop 2 and 8, compute 8×2=16, Push 16 | `16` |
| `2` | Push 2 | `2, 16` |
| `/` | Pop 2 and 16, compute 16÷2=8, Push 8 | `8` |

**Final Answer = 8** ✓

Verification: (3+5) × (6-4) / 2 = 8 × 2 / 2 = 16 / 2 = **8** ✓

---

### 4(c) A stack is implemented using an array of size 5. Perform the following operations step by step: — Push(10), Push(20), Push(30), Push(40), Push(50) — Pop() — Push(60) — Pop(), Pop() — Push(70), Push(80). Show the stack contents after each operation. [10]

**Stack:** Array of size 5 (indices 0–4), TOP starts at –1 (empty).

| Operation | TOP Before | TOP After | Stack Contents | Notes |
|---|---|---|---|---|
| **Push(10)** | –1 | 0 | `[10, _, _, _, _]` | |
| **Push(20)** | 0 | 1 | `[10, 20, _, _, _]` | |
| **Push(30)** | 1 | 2 | `[10, 20, 30, _, _]` | |
| **Push(40)** | 2 | 3 | `[10, 20, 30, 40, _]` | |
| **Push(50)** | 3 | 4 | `[10, 20, 30, 40, 50]` | Stack FULL (TOP = MAX−1) |
| **Pop()** | 4 | 3 | `[10, 20, 30, 40, _]` | Returns **50** |
| **Push(60)** | 3 | 4 | `[10, 20, 30, 40, 60]` | |
| **Pop()** | 4 | 3 | `[10, 20, 30, 40, _]` | Returns **60** |
| **Pop()** | 3 | 2 | `[10, 20, 30, _, _]` | Returns **40** |
| **Push(70)** | 2 | 3 | `[10, 20, 30, 70, _]` | |
| **Push(80)** | 3 | 4 | `[10, 20, 30, 70, 80]` | Final state |

**Final Stack (bottom → top):** `10 | 20 | 30 | 70 | 80` (TOP = 4)

---

### 4(d) A queue is represented using a linked list with Front and Rear pointers. Perform the following operations: — Enqueue(5), Enqueue(10), Enqueue(15), Enqueue(20) — Dequeue() — Enqueue(25) — Dequeue(), Dequeue(). Draw the queue structure after each step and update the front and rear pointers accordingly. [10]

**Initial State:** Queue is empty. FRONT = NULL, REAR = NULL.

**Enqueue(5):**
```
[5] → NULL
FRONT → 5,  REAR → 5
```

**Enqueue(10):**
```
[5] → [10] → NULL
FRONT → 5,  REAR → 10
```

**Enqueue(15):**
```
[5] → [10] → [15] → NULL
FRONT → 5,  REAR → 15
```

**Enqueue(20):**
```
[5] → [10] → [15] → [20] → NULL
FRONT → 5,  REAR → 20
```

**Dequeue():** Removes 5 (FRONT node)
```
[10] → [15] → [20] → NULL
FRONT → 10,  REAR → 20
```
Returns: **5**

**Enqueue(25):**
```
[10] → [15] → [20] → [25] → NULL
FRONT → 10,  REAR → 25
```

**Dequeue():** Removes 10
```
[15] → [20] → [25] → NULL
FRONT → 15,  REAR → 25
```
Returns: **10**

**Dequeue():** Removes 15
```
[20] → [25] → NULL
FRONT → 20,  REAR → 25
```
Returns: **15**

**Final Queue State:** `[20] → [25] → NULL`, FRONT → 20, REAR → 25

---

# SECTION – B (Marks: 105)

*(Answer any three (03) questions from this section in Script B)*

---

## Question 5

---

### 5(a) Explain the different types of binary tree traversals: Pre-order, In-order, Post-order. [05]

Given a binary tree, three standard traversal methods visit all nodes in different orders:

**Example Tree:**
```
        A
       / \
      B   C
     / \
    D   E
```

#### 1. Pre-order (NLR — Node, Left, Right)

Visit the **node first**, then traverse left subtree, then right subtree.

```
Algorithm: PREORDER(ROOT)
1. If ROOT = NULL: Return
2. Process INFO[ROOT]          ← Visit node FIRST
3. Call PREORDER(LEFT[ROOT])
4. Call PREORDER(RIGHT[ROOT])
```

**Result for example:** A → B → D → E → C

#### 2. In-order (LNR — Left, Node, Right)

Traverse left subtree first, then visit **node**, then right subtree.

```
Algorithm: INORDER(ROOT)
1. If ROOT = NULL: Return
2. Call INORDER(LEFT[ROOT])
3. Process INFO[ROOT]          ← Visit node IN MIDDLE
4. Call INORDER(RIGHT[ROOT])
```

**Result for example:** D → B → E → A → C

> **Important:** Inorder traversal of a **BST** produces elements in **sorted order**.

#### 3. Post-order (LRN — Left, Right, Node)

Traverse left subtree, then right subtree, then visit **node last**.

```
Algorithm: POSTORDER(ROOT)
1. If ROOT = NULL: Return
2. Call POSTORDER(LEFT[ROOT])
3. Call POSTORDER(RIGHT[ROOT])
4. Process INFO[ROOT]          ← Visit node LAST
```

**Result for example:** D → E → B → C → A

#### Summary Table

| Traversal | Order | Use Case |
|---|---|---|
| Pre-order | Node → Left → Right | Copy tree, Prefix notation |
| In-order | Left → Node → Right | Sorted output from BST |
| Post-order | Left → Right → Node | Delete tree, Postfix notation |

---

### 5(b) Consider the inorder and postorder traversals of a binary tree and perform the following operations: Inorder: 8, 4, 2, 5, 1, 6, 3, 9, 10, 7 | Postorder: 8, 4, 5, 2, 6, 10, 9, 7, 3, 1. (i) Construct the binary tree from above tree traversals. (ii) Determine the depth and height of the tree. [10]

**Key Rule:** The **last element** of Postorder is always the **root**.

**Step 1:** Root = **1** (last in Postorder)
Find **1** in Inorder at index 4 (0-indexed).
- **Left subtree** inorder: `[8, 4, 2, 5]` (4 elements)
- **Right subtree** inorder: `[6, 3, 9, 10, 7]` (5 elements)
- **Left subtree** postorder: first 4 = `[8, 4, 5, 2]`
- **Right subtree** postorder: next 5 = `[6, 10, 9, 7, 3]`

**Step 2 — Build Left Subtree:**
Root = **2** (last of `[8, 4, 5, 2]`)
Find **2** in `[8, 4, 2, 5]` at index 2.
- Left of 2: `[8, 4]` → Postorder: `[8, 4]`
- Right of 2: `[5]` → Postorder: `[5]`

Root of `[8, 4]` = **4** (last element)
Find **4** in `[8, 4]` at index 1.
- Left of 4: `[8]` → single node = **8**
- Right of 4: empty → NULL

Right of 2 = single node **5**

**Left subtree of 1:**
```
      2
     / \
    4   5
   /
  8
```

**Step 3 — Build Right Subtree:**
Root = **3** (last of `[6, 10, 9, 7, 3]`)
Find **3** in `[6, 3, 9, 10, 7]` at index 1.
- Left of 3: `[6]` → single node = **6**
- Right of 3: `[9, 10, 7]` → Postorder: `[10, 9, 7]`

Root of right = **7** (last of `[10, 9, 7]`)
Find **7** in `[9, 10, 7]` at index 2.
- Left of 7: `[9, 10]` → Postorder: `[10, 9]`
- Right of 7: empty → NULL

Root of `[9, 10]` = **9** (last of `[10, 9]`)
Find **9** in `[9, 10]` at index 0.
- Left of 9: empty → NULL
- Right of 9: `[10]` → single node = **10**

**Right subtree of 1:**
```
      3
     / \
    6   7
       /
      9
       \
        10
```

**Complete Binary Tree:**

```
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
        /         /
       8          9
                   \
                    10
```

**Verification:**
- Inorder (L→N→R): 8, 4, 2, 5, 1, 6, 3, 9, 10, 7 ✓
- Postorder (L→R→N): 8, 4, 5, 2, 6, 10, 9, 7, 3, 1 ✓

#### (ii) Depth and Height of the Tree

| Term | Definition |
|---|---|
| **Depth of a node** | Number of edges from root to that node |
| **Height of the tree** | Maximum depth of any leaf node |

**Level assignments:**
- Level 0: Node 1
- Level 1: Nodes 2, 3
- Level 2: Nodes 4, 5, 6, 7
- Level 3: Nodes 8, 9
- Level 4: Node 10

**Height = 4** (longest path: 1 → 3 → 7 → 9 → 10)
**Depth of the tree = 4**

---

### 5(c) A database system uses a Binary Search Tree (BST) to store and index records by unique keys. Consider the following list of keys: [50, 30, 70, 20, 40, 60, 80]. (i) Construct a Binary Search Tree (BST) from the list. (ii) Search for a record with key 40. (iii) Insert 75 and draw the updated BST. (iv) Delete node 40 from the updated BST and show the updated BST. [20]

#### (i) Construct the BST

**Insertion Order:** 50, 30, 70, 20, 40, 60, 80

| Key | Comparison | Position |
|---|---|---|
| **50** | First node | Root |
| **30** | 30 < 50 → left | Left of 50 |
| **70** | 70 > 50 → right | Right of 50 |
| **20** | 20 < 50 → left; 20 < 30 → left | Left of 30 |
| **40** | 40 < 50 → left; 40 > 30 → right | Right of 30 |
| **60** | 60 > 50 → right; 60 < 70 → left | Left of 70 |
| **80** | 80 > 50 → right; 80 > 70 → right | Right of 70 |

**Constructed BST:**

```
          50
        /    \
      30       70
     /  \     /  \
   20   40   60   80
```

#### (ii) Search for key 40

Start at root, compare 40 with each node:

| Step | Node | Comparison | Direction |
|---|---|---|---|
| 1 | 50 | 40 < 50 | Go LEFT |
| 2 | 30 | 40 > 30 | Go RIGHT |
| 3 | 40 | 40 = 40 | **FOUND!** |

**Key 40 found in 3 comparisons!**

#### (iii) Insert 75 — Updated BST

Path for 75: 75 > 50 → right; 75 > 70 → right; 75 < 80 → **left of 80**

```
          50
        /    \
      30       70
     /  \     /  \
   20   40   60   80
                  /
                 75
```

#### (iv) Delete node 40 — Updated BST

**Node 40 is a LEAF node** (no children). Simply remove it.

```
          50
        /    \
      30       70
     /        /  \
   20         60   80
                   /
                  75
```

---

## Question 6

---

### 6(a) Define hashing and hash function. Discuss at least three hash function techniques with example(s). What is meant by hash collision? [12]

**Hashing:**
Hashing is a technique for **storing and retrieving data** from a table using a special formula (hash function) that converts a key value directly into an address (index) of a hash table. Average time complexity: **O(1)**.

**Hash Function:**
A hash function `h(key)` maps a key value to an index in the hash table:
```
h(key) = address in hash table
```
The **same hash function** must be used for both storing and retrieving.

#### Three Hash Function Techniques

**Technique 1: Division Method (Most Common)**

```
h(key) = key mod m
```
Where m = size of hash table.

**Example:** m = 10, keys = {13, 4, 12, 9, 24}

| Key | Calculation | Hash Address |
|---|---|---|
| 13 | 13 mod 10 | 3 |
| 4 | 4 mod 10 | 4 |
| 12 | 12 mod 10 | 2 |
| 9 | 9 mod 10 | 9 |
| 24 | 24 mod 10 | **4** ← Collision! |

**Technique 2: Mid-Square Method**

Steps:
1. Convert key to binary
2. Square the binary number
3. Extract the **middle k bits** as the hash address

**Example:** key = 89 (binary = 1011001)
- Squared: 1011001 × 1011001 = 1111011110001
- k = 3, middle 3 bits = **111** = 7 (decimal)
- Hash address = **7**

**Technique 3: Folding Method**

Steps:
1. Split key into equal parts
2. Add all parts together

**Example:** key = 324112, parts of 2 digits each:
- Parts: 32, 41, 12
- Sum: 32 + 41 + 12 = **85**
- Hash address = **85**

**Hash Collision:**

A **hash collision** occurs when **two different keys** produce the **same hash address**.

```
h(105) = 105 mod 100 = 5
h(205) = 205 mod 100 = 5  ← COLLISION! Both map to index 5
```

**Collisions are unavoidable** because the key space is much larger than the hash table size. They are resolved using techniques like **Linear Probing, Chaining**, etc.

---

### 6(b) Construct a Max-heap H from the list 34, 30, 40, 22, 50, 2, 55, 77, 55, now (i) insert another item 70 into the constructed heap, and (ii) then delete the number 22 for re-heaping it. What the correct steps in both cases. Explain. [15]

**Max-Heap Property:** Parent ≥ Children. Stored in 1-indexed array. For node at position i: Left child = 2i, Right child = 2i+1, Parent = ⌊i/2⌋.

**Build Max-Heap by inserting one by one:**

| Insert | Array State | Swap Needed? |
|---|---|---|
| 34 | [34] | No |
| 30 | [34, 30] | 30 < 34 at parent → No swap |
| 40 | [34, 30, 40] | 40 > 34 (parent at 1) → Swap → **[40, 30, 34]** |
| 22 | [40, 30, 34, 22] | 22 < 30 (parent at 2) → No swap |
| 50 | [40, 30, 34, 22, 50] | 50 > 30 → Swap → [40, 50, 34, 22, 30]; 50 > 40 → Swap → **[50, 40, 34, 22, 30]** |
| 2 | [50, 40, 34, 22, 30, 2] | 2 < 34 (parent at 3) → No swap |
| 55 | [50, 40, 34, 22, 30, 2, 55] | 55 > 34 → Swap → [50, 40, 55, 22, 30, 2, 34]; 55 > 50 → Swap → **[55, 40, 50, 22, 30, 2, 34]** |
| 77 | [55, 40, 50, 22, 30, 2, 34, 77] | 77 > 22 → Swap; 77 > 40 → Swap; 77 > 55 → Swap → **[77, 55, 50, 40, 30, 2, 34, 22]** |
| 55 | [77, 55, 50, 40, 30, 2, 34, 22, 55] | 55 > 40 → Swap → [77, 55, 50, 55, 30, 2, 34, 22, 40]; 55 = 55 → No swap |

**Final Max-Heap H:**

```
Array: [77, 55, 50, 55, 30, 2, 34, 22, 40]
Index:  [1,  2,  3,  4,  5, 6,  7,  8,  9]
```

```
              77
            /    \
          55      50
         /  \    /  \
        55   30  2   34
       /  \
      22   40
```

#### (i) Insert 70 into the Heap

1. Add 70 at position 10 (end of array):
   `[77, 55, 50, 55, 30, 2, 34, 22, 40, 70]`

2. Bubble up: Parent of 10 = position 5 = value **30**
   - 70 > 30 → Swap: `[77, 55, 50, 55, 70, 2, 34, 22, 40, 30]`

3. Parent of 5 = position 2 = value **55**
   - 70 > 55 → Swap: `[77, 70, 50, 55, 55, 2, 34, 22, 40, 30]`

4. Parent of 2 = position 1 = value **77**
   - 70 < 77 → STOP ✓

**Heap after inserting 70:**

```
Array: [77, 70, 50, 55, 55, 2, 34, 22, 40, 30]
```

```
              77
            /    \
          70      50
         /  \    /  \
        55   55  2   34
       /  \   \
      22  40   30
```

#### (ii) Delete node 22

Current heap: `[77, 70, 50, 55, 55, 2, 34, 22, 40, 30]`

22 is at position 8.

**Re-heaping steps:**
1. Replace 22 with the **last element** (30). Remove last element.
   New array: `[77, 70, 50, 55, 55, 2, 34, 30, 40]` (n = 9)

2. 30 is now at position 8. Check against parent at position 4 = **55**
   - 30 < 55 → No upward swap needed.

3. Children of position 8: 2×8=16 and 17 (both > n=9) → No children → No downward swap needed.

**Heap after deleting 22:**

```
Array: [77, 70, 50, 55, 55, 2, 34, 30, 40]
```

```
              77
            /    \
          70      50
         /  \    /  \
        55   55  2   34
       /  \
      30   40
```

---

### 6(c) Using Warshall's algorithm, find the path matrix of the following graph. [08]

*(Graph with vertices X, Y, W, Z with directed edges)*

**Graph vertices:** X, Y, W, Z

**Directed edges from graph:** Y → X, Y → W, W → X, W → Z, Z → W

**Step 1: Build Adjacency Matrix P₀**

Using order: X=1, Y=2, W=3, Z=4

|   | X | Y | W | Z |
|---|---|---|---|---|
| **X** | 0 | 0 | 0 | 0 |
| **Y** | 1 | 0 | 1 | 0 |
| **W** | 1 | 0 | 0 | 1 |
| **Z** | 0 | 0 | 1 | 0 |

**Step 2: Apply Warshall's Algorithm**

**Rule:** `P_k[i,j] = P_{k-1}[i,j] OR (P_{k-1}[i,k] AND P_{k-1}[k,j])`

**P₁ — Using X as intermediate:**
Row X = [0, 0, 0, 0] (X has no outgoing edges) → **No changes. P₁ = P₀**

**P₂ — Using Y as intermediate:**
Column Y = [0, 0, 0, 0] (nobody points to Y) → **No changes. P₂ = P₁**

**P₃ — Using W as intermediate:**
New paths discovered:
- `P₃[Y,Z]` = 0 OR (1 AND 1) = **1** ← NEW
- `P₃[Z,X]` = 0 OR (1 AND 1) = **1** ← NEW
- `P₃[Z,Z]` = 0 OR (1 AND 1) = **1** ← NEW

**P₃:**

|   | X | Y | W | Z |
|---|---|---|---|---|
| **X** | 0 | 0 | 0 | 0 |
| **Y** | 1 | 0 | 1 | **1** |
| **W** | 1 | 0 | 0 | 1 |
| **Z** | **1** | 0 | 1 | **1** |

**P₄ — Using Z as intermediate:**

New paths discovered:
- `P₄[W,W]` = 0 OR (1 AND 1) = **1** ← NEW (W reaches itself via Z)

**P₄ = Final Path Matrix P:**

|   | X | Y | W | Z |
|---|---|---|---|---|
| **X** | 0 | 0 | 0 | 0 |
| **Y** | 1 | 0 | 1 | 1 |
| **W** | 1 | 0 | **1** | 1 |
| **Z** | 1 | 0 | 1 | 1 |

**Interpretation:**
- X cannot reach any node (no outgoing edges)
- Y can reach X, W, Z
- W can reach X, W (itself via Z cycle), Z
- Z can reach X, W, Z (itself)
- No one can reach Y

---

## Question 7

---

### 7(a) Define the terms, (i) directed graph, (ii) complete graph, and (iii) connected graph. Discuss the steps needed to follow to insert a node into a graph. Explain with example. [12]

**Definition 1 — Directed Graph (Digraph):**
A **directed graph** is a graph where each edge has a specific **direction**, represented by an arrow. Edge (u, v) means there is a path **FROM u TO v** only (not necessarily from v to u).

**Example:**
```
A → B → C
↑         |
└─────────┘
```
Vertices: {A, B, C}, Edges: {(A,B), (B,C), (C,A)}

**Definition 2 — Complete Graph:**
A **complete graph** with n vertices is one where **every vertex is directly connected to every other vertex**. Each pair of vertices has exactly one edge.

- For undirected graph with n vertices: number of edges = **n(n-1)/2**
- For n = 4: 4×3/2 = **6 edges**

```
     A
    /|\
   / | \
  B--+--D
   \ | /
    \|/
     C
```

**Definition 3 — Connected Graph:**
A graph is **connected** if there exists a **path between every pair of vertices**. No vertex is isolated or unreachable from others.

**Example:**
```
A — B — C
    |
    D
```
All vertices A, B, C, D are reachable from each other → Connected.

**Steps to Insert a Node into a Graph:**

Suppose we want to insert a new node **V** into graph G.

**Step 1:** Create a new node V and add it to the vertex list.
```
NODE[NEW] := V
NEXT[NEW] := START
START := NEW
ADJ[NEW] := NULL
```

**Step 2:** For each edge connecting V to existing vertex W, insert the edge.
```
For each neighbor W of V:
    (i)  Find location of W in NODE list (LOCW)
    (ii) Create a new edge record:
         DEST[edge] := LOCW
         LINK[edge] := ADJ[NEW]
         ADJ[NEW]  := edge
```

**Step 3:** If the graph is undirected, also add edges from W to V.

**Example:** Add node E to graph with A, B, C, D, with edges (E, B) and (E, C):

```
Before:
A — B — C — D

After inserting E:
A — B — C — D
    |   |
    E───┘
```

---

### 7(b) You find yourself in a maze, looking for exit. Which graph traversal techniques would you choose depth-first or breadth-first? Why? Apply your choice in the following graph (Consider your position except D, H, and K because they are for exit). [10]

**Choice: Depth-First Search (DFS)**

**Reason:**
- In a maze, we want to **follow one path as far as possible** until we reach the exit or a dead end, then backtrack.
- This is exactly what DFS does — it goes deep first using a stack.
- BFS would explore all paths level-by-level, using more memory.
- DFS is more **memory efficient** in a maze (only remembers current path, not all frontiers).
- DFS naturally implements **backtracking**.

**Graph structure (exits are D, H, K):**
```
        C       A
       / \     / \
      E   \   B   G
     / \   \ /     \
    D   I   B   F
         \   \ /
          H   J
           \ /
            K
```

**Apply DFS starting from any non-exit node (e.g., C), exits = {D, H, K}:**

| Step | Visit | Action |
|---|---|---|
| Start | C | Visit C, push neighbors |
| 1 | E | Visit E, push neighbors |
| 2 | D | **EXIT FOUND at D!** 🎉 |

**Path to exit D:** C → E → D ✓

**DFS Trace:**
```
Start at C
  Visit C → go to E
  Visit E → go to D (EXIT!)
  FOUND EXIT at D!
```

DFS is ideal here because it dives deep immediately and finds the first available exit quickly, just like a person navigating a maze by following one path until hitting a dead end or exit.

---

### 7(c) What is an in-place sorting? Write an in-place sorting algorithm. Analyse the worst case and the best case time-complexities of the algorithm. [13]

**Definition:**
An **in-place sorting** algorithm sorts an array **without using any additional (extra) memory array**. It rearranges elements within the original array using only a **constant O(1) extra space** (a few variables like a temp or counter).

**Examples of in-place sorts:** Selection Sort, Insertion Sort, Bubble Sort, Quick Sort.
**NOT in-place:** Merge Sort (requires O(n) extra array).

**In-Place Sorting Algorithm: Selection Sort**

```
Algorithm: SELECTION_SORT(A, N)
────────────────────────────────
A = Array to sort
N = Number of elements

1. Repeat for i := 0 to N-2:

     (a) Set small_index := i

     (b) Repeat for j := i+1 to N-1:
             If A[j] < A[small_index], then:
                 Set small_index := j
         [End of inner loop]

     (c) [Swap A[i] with A[small_index]]
         Set TEMP := A[i]
         Set A[i] := A[small_index]
         Set A[small_index] := TEMP

   [End of outer loop]

2. Output sorted array A
```

**Why it is in-place:** Only uses a constant amount of extra space (`TEMP`, `small_index`, loop counters `i`, `j`) — **O(1) extra space**.

**Step-by-Step Example:**

Array: `[64, 25, 12, 22, 11]`

| Pass i | Array State | Minimum Found | After Swap |
|---|---|---|---|
| i=0 | [**64**, 25, 12, 22, 11] | 11 at index 4 | [**11**, 25, 12, 22, 64] |
| i=1 | [11, **25**, 12, 22, 64] | 12 at index 2 | [11, **12**, 25, 22, 64] |
| i=2 | [11, 12, **25**, 22, 64] | 22 at index 3 | [11, 12, **22**, 25, 64] |
| i=3 | [11, 12, 22, **25**, 64] | 25 at index 3 | [11, 12, 22, **25**, 64] |

**Sorted:** `[11, 12, 22, 25, 64]` ✓

**Time Complexity Analysis:**

**Worst Case:**
The algorithm always scans all remaining elements regardless of input:
- Pass 1: (N-1) comparisons
- Pass 2: (N-2) comparisons
- ...
- Pass (N-1): 1 comparison
- Total = N(N-1)/2

**T_worst(n) = N(N-1)/2 = O(n²)**

Worst case occurs when the array is in reverse order (e.g., `[5, 4, 3, 2, 1]`).

**Best Case:**
Selection sort **always performs the same number of comparisons** regardless of initial order. Even if the array is already sorted, it still scans all remaining elements.

**T_best(n) = N(N-1)/2 = O(n²)**

> **Best case = Worst case = O(n²)** for Selection Sort.
> **Note:** If using **Insertion Sort** (also in-place), the best case improves to **O(n)** (when array is already sorted, inner while loop never executes).

**Comparison of In-Place Sorting Algorithms:**

| Algorithm | Best Case | Worst Case | Extra Space |
|---|---|---|---|
| Selection Sort | O(n²) | O(n²) | O(1) |
| Insertion Sort | **O(n)** | O(n²) | O(1) |
| Bubble Sort | O(n) | O(n²) | O(1) |
| Quick Sort | O(n log n) | O(n²) | O(log n) stack |

---

## Question 8

---

### 8(a) Define Spanning Tree, and Minimum Spanning Tree (MST). [08]

**Spanning Tree:**
A **spanning tree** of a connected graph G is a subgraph that:
1. **Includes all vertices** of G
2. **Is a tree** (connected, no cycles)
3. Contains exactly **V-1 edges** (where V = number of vertices)

A graph with n vertices can have multiple spanning trees. Each spanning tree has exactly n-1 edges.

**Minimum Spanning Tree (MST):**
A **Minimum Spanning Tree** is a spanning tree where the **total sum of edge weights is minimized**.

```
Total weight of MST = sum of weights of all edges in the spanning tree
```

**Properties:**
- MST has exactly **n-1 edges** for n vertices
- MST has **no cycles**
- MST **minimizes total connection cost**
- A graph may have **multiple MSTs** with the same minimum weight

**Application:** Cable network installation, circuit design, network routing — connecting all points at minimum cost.

---

### 8(b) A company wants to install network cables between offices A, B, C, D, and E. The following table shows the cost between offices. (i) Represent this problem as a graph. (ii) Find the MST using Kruskal's Algorithm. (iii) What is the minimum cost of connecting all offices? [12]

#### (i) Graph Representation

**Vertices:** A, B, C, D, E

**Edges with costs:**

| Office Pair | Cost |
|---|---|
| A – B | 5 |
| A – C | 3 |
| B – C | 4 |
| B – D | 6 |
| C – D | 2 |
| C – E | 7 |
| D – E | 8 |

#### (ii) Find MST using Kruskal's Algorithm

**Kruskal's Algorithm Steps:**
1. Sort all edges by weight (ascending)
2. Add each edge to MST if it doesn't create a cycle
3. Stop when MST has V-1 = 4 edges

**Sorted Edges:**

| Edge | Weight |
|---|---|
| C–D | 2 |
| A–C | 3 |
| B–C | 4 |
| A–B | 5 |
| B–D | 6 |
| C–E | 7 |
| D–E | 8 |

**Building MST:**

| Step | Edge | Weight | Cycle? | Action | MST Edges |
|---|---|---|---|---|---|
| 1 | **C–D** | 2 | No | ✅ Add | {C–D} |
| 2 | **A–C** | 3 | No | ✅ Add | {C–D, A–C} |
| 3 | **B–C** | 4 | No | ✅ Add | {C–D, A–C, B–C} |
| 4 | A–B | 5 | Yes (A–C–B) | ❌ Skip | — |
| 5 | B–D | 6 | Yes (B–C–D) | ❌ Skip | — |
| 6 | **C–E** | 7 | No | ✅ Add | {C–D, A–C, B–C, C–E} |

**MST has 4 edges (V-1 = 5-1 = 4) → DONE!**

**MST Diagram:**

```
    A
    |
   (3)
    |
    C-----(2)-----D
   / \
 (4) (7)
 /     \
B       E
```

**MST Edges:** C–D (2), A–C (3), B–C (4), C–E (7)

#### (iii) Minimum Cost

```
Minimum Cost = 2 + 3 + 4 + 7 = 16
```

**The minimum cost to connect all offices is 16 units.**

---

## 8(c) Run depth first search (DFS) on the following graph starting from vertex **A** and show discovery and finishing times for each vertex as well as edge types. Decompose the graph into strongly connected components (SCCs). **[15]**

### Answer

Assume that adjacent vertices are visited in **alphabetical order**.

---

### 1. Directed edges of the graph

The graph contains the following directed edges:

* `A → B`
* `A → C`
* `A → F`
* `B → E`
* `E → F`
* `F → B`
* `E → G`
* `F → G`
* `E → H`
* `C → D`
* `D → A`
* `D → H`
* `H → G`

---

### 2. DFS traversal starting from `A`

Starting DFS from vertex `A`, the traversal order is:

```text
A → B → E → F → G → H → C → D
```

---

### 3. Discovery and finishing times

Let discovery time be denoted by `d[v]` and finishing time by `f[v]`.

| Vertex | Discovery Time `d` | Finishing Time `f` |
| ------ | ------------------ | ------------------ |
| A      | 1                  | 16                 |
| B      | 2                  | 11                 |
| E      | 3                  | 10                 |
| F      | 4                  | 7                  |
| G      | 5                  | 6                  |
| H      | 8                  | 9                  |
| C      | 12                 | 15                 |
| D      | 13                 | 14                 |

---

### 4. Edge classification

#### Tree edges

These are the edges through which a new vertex is first discovered:

* `A → B`
* `B → E`
* `E → F`
* `F → G`
* `E → H`
* `A → C`
* `C → D`

#### Back edges

These connect a vertex to one of its ancestors in the DFS tree:

* `F → B`
* `D → A`

#### Forward edges

These connect a vertex to one of its descendants, but are not tree edges:

* `E → G`
* `A → F`

#### Cross edges

These connect vertices belonging to different DFS branches:

* `H → G`
* `D → H`

---

### 5. Strongly Connected Components (SCCs)

The graph can be decomposed into the following SCCs:

* `{A, C, D}`
* `{B, E, F}`
* `{H}`
* `{G}`

---

### 6. Final result

Therefore,

* **DFS traversal:** `A → B → E → F → G → H → C → D`
* **Discovery/finishing times:**

  * `A(1,16)`
  * `B(2,11)`
  * `E(3,10)`
  * `F(4,7)`
  * `G(5,6)`
  * `H(8,9)`
  * `C(12,15)`
  * `D(13,14)`
* **SCCs:** `{A,C,D}`, `{B,E,F}`, `{H}`, `{G}`

> **Note:** If a different adjacent-vertex visiting order is used, the DFS order and times may change, but the SCCs remain the same.

---

> **Note:** All answers are based on the course textbook *Data Structures with C* by Seymour Lipschutz (Schaum's Outlines). For graph-based questions (Warshall's, DFS-SCC), edge interpretations are based on the best available reading of the exam paper.
