# CSE 2101 – Data Structure: Complete Answer Guide
**Chandpur Science and Technology University**
**B.Sc. Engineering 2nd Year 1st Semester Final Examination, 2024**

---

# SECTION – A (Marks: 105)
> Answer any **three (03)** questions from this section in **Script A**

---

## Question 1

### (a) Define data structure. How does data structure differ from elementary data type? [06]

**Data Structure:**
A data structure is a way of organizing, storing, and managing data in a computer so that it can be accessed and modified efficiently.

*Examples:* Array, Linked List, Stack, Queue, Tree, Graph.

**Elementary Data Type:**
An elementary (or primitive) data type is a basic type directly supported by the programming language.

*Examples:* `int`, `float`, `char`, `bool`.

**Differences:**

| Feature | Elementary Data Type | Data Structure |
|---|---|---|
| Definition | A single, simple value | A collection/organization of values |
| Example | `int x = 5;` | `int arr[10];` or linked list |
| Operations | +, -, *, / etc. | Insert, delete, search, traverse |
| Complexity | Simple | Can be complex |
| Memory | Fixed size | Variable or fixed |
| Purpose | Store one value | Store and organize multiple values |

---

### (b) Which data structure would you use to program tic-tac-toe game? How would you determine a winning configuration? [09]

**Data Structure: 2D Array (Matrix)**

Use a **3×3 two-dimensional array** to represent the tic-tac-toe board.

```
board[3][3]

After some moves (X=1, O=2, Empty=0):
[1][2][1]
[0][1][2]
[2][0][1]
```

**Representation:**
- `board[i][j] = 0` → Empty cell
- `board[i][j] = 1` → Player X
- `board[i][j] = 2` → Player O

**Determining a Winning Configuration:**

A player wins if they have **3 same marks** in:

1. **Any Row:** Check `board[i][0] == board[i][1] == board[i][2]` for i = 0,1,2
2. **Any Column:** Check `board[0][j] == board[1][j] == board[2][j]` for j = 0,1,2
3. **Main Diagonal:** Check `board[0][0] == board[1][1] == board[2][2]`
4. **Anti-Diagonal:** Check `board[0][2] == board[1][1] == board[2][0]`

**Algorithm:**
```
CHECK_WIN(board, player):
  FOR i = 0 to 2:
    IF board[i][0] == player AND board[i][1] == player AND board[i][2] == player:
      RETURN TRUE
  FOR j = 0 to 2:
    IF board[0][j] == player AND board[1][j] == player AND board[2][j] == player:
      RETURN TRUE
  IF board[0][0] == player AND board[1][1] == player AND board[2][2] == player:
    RETURN TRUE
  IF board[0][2] == player AND board[1][1] == player AND board[2][0] == player:
    RETURN TRUE
  RETURN FALSE
```

---

### (c) There are two linear arrays. Find the number of elements of the first array which are divisible by the first element of the second array. Write an algorithm. [10]

**Idea:**
- Let Array A = first array with `n` elements
- Let Array B = second array; use `B[0]` (first element) as the divisor
- Count how many elements in A are divisible by `B[0]`

**Algorithm:**
```
COUNT_DIVISIBLE(A, n, B):
  divisor = B[0]
  count = 0
  FOR i = 0 to n-1:
    IF A[i] mod divisor == 0:
      count = count + 1
  RETURN count
```

**Example:**
- A = [4, 7, 10, 15, 20, 3], B = [5, 8, 2] → B[0] = 5
- Elements divisible by 5: 10, 15, 20 → **count = 3**

**Step-by-step trace:**

| i | A[i] | A[i] mod 5 | Divisible? | count |
|---|------|------------|------------|-------|
| 0 | 4    | 4          | No         | 0     |
| 1 | 7    | 2          | No         | 0     |
| 2 | 10   | 0          | Yes        | 1     |
| 3 | 15   | 0          | Yes        | 2     |
| 4 | 20   | 0          | Yes        | 3     |
| 5 | 3    | 3          | No         | 3     |

**Time Complexity:** O(n)

---

### (d) Prove that the time complexity for enqueue and dequeue operations in a circular queue is O(1) with amortized analysis. [10]

**Circular Queue Basics:**

A circular queue uses a fixed-size array with two pointers:
- `FRONT` → points to the front element
- `REAR` → points to the last element
- Uses modulo arithmetic: `(index + 1) mod MAX`

**Enqueue Operation:**
```
ENQUEUE(Q, item):
  IF (REAR + 1) mod MAX == FRONT:
    PRINT "Queue Full"
    RETURN
  REAR = (REAR + 1) mod MAX
  Q[REAR] = item
```

**Dequeue Operation:**
```
DEQUEUE(Q):
  IF FRONT == REAR:
    PRINT "Queue Empty"
    RETURN
  FRONT = (FRONT + 1) mod MAX
  RETURN Q[FRONT]
```

**Why O(1)?**

Both operations perform a **fixed, constant number of steps** regardless of how many elements are in the queue:
1. One arithmetic calculation: `(REAR+1) mod MAX`
2. One comparison (overflow/underflow check)
3. One assignment

No loops. No searching. No shifting of elements.

**Amortized Analysis:**

Consider n enqueue + n dequeue operations.
- Total work = n + n = 2n steps
- Amortized cost per operation = 2n / 2n = **O(1)**

> **Conclusion:** Only pointer manipulation and modulo arithmetic (constant-time operations) are used, so both enqueue and dequeue are O(1).

---

## Question 2

### (a) You have learned that singly linked lists are trees. Are circularly linked lists also trees? Why or why not? [06]

**Answer: NO — Circular linked lists are NOT trees.**

A **tree** must satisfy:
1. Exactly **one root** node (no parent)
2. Every other node has **exactly one parent**
3. **No cycles**

A **circularly linked list** violates property 3 — the last node points back to the first node, forming a cycle. Trees cannot have cycles.

```
Singly linked:  START → A → B → C → NULL   (no cycle → can be a tree)
Circular:       HEAD  → A → B → C → HEAD   (cycle exists → NOT a tree)
```

---

### (b) Compare doubly linked lists and circular linked lists in terms of: i) Memory usage, ii) Insertion/deletion at both ends, iii) Traversal complexity [12]

#### i) Memory Usage

| | Doubly Linked List | Circular Linked List (singly) |
|---|---|---|
| Pointers per node | 2 (next + prev) | 1 (next only) |
| NULL pointers | Head.prev = NULL, Tail.next = NULL | None |

**Winner:** Singly Circular uses less memory per node.

#### ii) Insertion/Deletion at Both Ends

**Doubly Linked List (with head and tail pointers):**
- Insert/Delete at front: O(1)
- Insert/Delete at end: O(1) — uses `tail.prev`

**Singly Circular Linked List (head pointer only):**
- Insert/Delete at front: O(1)
- Insert/Delete at end: O(n) — must traverse to last node unless a tail pointer is maintained

**Winner:** Doubly Linked List is better for end operations.

#### iii) Traversal Complexity

| | Doubly Linked List | Singly Circular Linked List |
|---|---|---|
| Forward traversal | O(n) | O(n) |
| Backward traversal | O(n) — use prev pointer | Not possible |
| Risk of infinite loop | No | Yes — must stop at head |

**Winner:** Doubly Linked List for bidirectional traversal. Circular is useful for round-robin type tasks.

---

### (c) Delete the node containing 20 from the doubly linked list: NULL ← [10] ⇌ [20] ⇌ [30] → NULL [17]

**Initial State:**
```
NULL ← [10] ⇌ [20] ⇌ [30] → NULL
```
- Node A: `NULL | 10 | →20`
- Node B: `←10  | 20 | →30`   ← node to delete
- Node C: `←20  | 30 | NULL`

**Step 1:** Identify `DEL = Node B`, `DEL.PREV = Node A`, `DEL.NEXT = Node C`

**Step 2:** Update NEXT pointer of previous node:
- `DEL.PREV.NEXT = DEL.NEXT` → Node A now points forward to Node C

```
Node A: NULL | 10 | →30
```

**Step 3:** Update PREV pointer of next node:
- `DEL.NEXT.PREV = DEL.PREV` → Node C now points backward to Node A

```
Node C: ←10 | 30 | NULL
```

**Step 4:** Isolate deleted node (cleanup):
- `DEL.NEXT = NULL`, `DEL.PREV = NULL`, free memory

**Final State:**
```
NULL ← [10] ⇌ [30] → NULL
```

**Algorithm:**
```
DELETE_NODE(DEL):
  IF DEL.PREV != NULL:
    DEL.PREV.NEXT = DEL.NEXT
  ELSE:
    HEAD = DEL.NEXT

  IF DEL.NEXT != NULL:
    DEL.NEXT.PREV = DEL.PREV
  ELSE:
    TAIL = DEL.PREV

  FREE(DEL)
```

---

## Question 3

### (a) "Is bubble sort divide and conquer type?" Explain your answer. [08]

**Answer: NO — Bubble Sort is NOT a divide and conquer algorithm.**

**What is Divide and Conquer?**
1. **Divide** – Break the problem into smaller subproblems
2. **Conquer** – Solve each subproblem recursively
3. **Combine** – Merge the solutions

*True divide and conquer sorts:* Merge Sort, Quick Sort.

**How Bubble Sort Works:**
Bubble Sort repeatedly **compares adjacent elements** and **swaps** them if out of order — pass by pass until the array is sorted.

**Why it is NOT Divide and Conquer:**
1. Does **not divide** the array into subproblems
2. Does **not solve subproblems independently**
3. Works on the **entire array in each pass**
4. No combining step

**Counter Example:**
- Merge Sort: divides → sorts each half → merges ✓ (D&C)
- Bubble Sort: compares adjacent pairs again and again ✗ (Not D&C)

**Conclusion:** Bubble Sort is an **iterative comparison-based** algorithm classified under **"Exchange Sort"**, not divide and conquer.

---

### (b) Explain how Stack is used in Depth-First Search (DFS). [08]

**DFS Overview:**
Depth-First Search explores a graph by going as deep as possible before backtracking.

**Role of Stack in DFS:**
The stack tracks the path from the start node. When a dead end is reached, we backtrack by popping from the stack.

**Algorithm (Iterative DFS using Stack):**
```
DFS(graph, start):
  CREATE empty stack S
  CREATE visited[] array, all FALSE
  PUSH start onto S
  MARK start as visited
  WHILE S is not empty:
    current = POP from S
    PRINT current
    FOR each neighbor v of current:
      IF v is not visited:
        MARK v as visited
        PUSH v onto S
```

**Example:**
Graph: 1–2, 1–3, 2–4, 3–4

```
Stack: [1] → Pop 1, push 2,3 → Stack: [2,3]
Pop 3, push 4       → Stack: [2,4]
Pop 4, no unvisited → Stack: [2]
Pop 2, 4 already visited → Stack: []
DFS Order: 1, 3, 4, 2
```

**Key Points:**
- Stack = LIFO → naturally goes deep before backtracking
- Recursive DFS uses the **call stack** implicitly
- Iterative DFS uses an **explicit stack**

---

### (c) Write a function that will merge two Linked Lists of integers, sorted in ascending order. The merged list should also be sorted. [09]

**Idea:** Compare heads of both lists, pick the smaller one, advance that pointer. Attach remainder when one list is exhausted.

**Algorithm:**
```
MERGE_SORTED_LISTS(head1, head2):
  dummy = new Node(0)
  current = dummy

  WHILE head1 != NULL AND head2 != NULL:
    IF head1.data <= head2.data:
      current.next = head1
      head1 = head1.next
    ELSE:
      current.next = head2
      head2 = head2.next
    current = current.next

  IF head1 != NULL:
    current.next = head1
  ELSE:
    current.next = head2

  RETURN dummy.next
```

**Trace Example:**
- List 1: 1 → 3 → 5
- List 2: 2 → 4 → 6

| Step | head1 | head2 | Merged so far |
|------|-------|-------|---------------|
| 1    | 1     | 2     | 1             |
| 2    | 3     | 2     | 1→2           |
| 3    | 3     | 4     | 1→2→3         |
| 4    | 5     | 4     | 1→2→3→4       |
| 5    | 5     | 6     | 1→2→3→4→5     |
| 6    | NULL  | 6     | 1→2→3→4→5→6   |

**Result:** 1 → 2 → 3 → 4 → 5 → 6 ✓

**Time Complexity:** O(m + n)

---

### (d) Route planner with thousands of intersections (nodes) and few roads (edges). Adjacency list or matrix — which is more efficient and why? [10]

**Answer: Adjacency List is more efficient.**

**The graph is SPARSE (few edges compared to nodes).**

| Feature | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V + E) |
| Check if edge exists | O(1) | O(degree) |
| Find all neighbors | O(V) | O(degree) |
| Best for | Dense graphs | Sparse graphs |

**For this Route Planner:**
- V = thousands (large), E = few (small, E << V²)

If V = 10,000, Adjacency Matrix requires 10,000 × 10,000 = **100 million cells** — mostly zeros. This wastes enormous memory.

Adjacency List stores only actual edges, so memory = O(V + E) — much smaller.

**Conclusion:** For sparse graphs like city route planners, **Adjacency List** is far more memory-efficient and faster for DFS/BFS path finding.

---

## Question 4

### (a) What are the differences between a heap and BST? When to use a heap and when to use a BST? [06]

| Feature | Heap | BST |
|---|---|---|
| Order property | Parent ≥ children (max-heap) | Left < Root < Right |
| Structure | Always a **complete binary tree** | Not necessarily complete |
| Search | O(n) — not optimized | O(log n) average |
| Find min/max | O(1) — always at root | O(log n) |
| Insert | O(log n) | O(log n) average |
| Delete min/max | O(log n) | O(log n) |

**Use a Heap when:**
- Repeatedly finding/removing the min or max element
- Priority queues, Heap sort, Dijkstra's algorithm, task scheduling

**Use a BST when:**
- Searching for arbitrary elements efficiently
- Sorted traversal needed (inorder gives sorted output)
- Both insert, delete, and search are needed
- Range queries

---

### (b) Show the in-order traversal of BST T after key 17 is deleted. [10]

**Original BST:**
```
              17
            /    \
           9      26
          / \    /  \
         7  12  20   30
            /    \
           11    21
           /
          4
```

**Step 1: Delete node 17 (root) — it has two children**

Replace with **in-order successor** (smallest in right subtree):
- Go right to 26, then left as far as possible → reach **20** (no left child)
- **In-order successor = 20**

**Step 2: Replace 17 with 20**
- Copy 20 to root
- Delete original node 20; its right child (21) takes its place under 26

**BST after deletion:**
```
              20
            /    \
           9      26
          / \    /  \
         7  12  21   30
            /
           11
           /
          4
```

**Step 3: In-order Traversal (Left → Root → Right)**

`4, 7, 9, 11, 12, 20, 21, 26, 30`

---

### (c) Translate infix expression ((A + B) * C − (D − E) ↑ (F + G)) to postfix. Which data structure is needed? [09]

**Data Structure needed: Stack**

**Operator Precedence (High to Low):**
1. `↑` (Exponentiation) — highest
2. `*`, `/`
3. `+`, `-` — lowest

**Step-by-Step Conversion:**

| Token | Stack | Output |
|-------|-------|--------|
| `(`   | `(`   |        |
| `(`   | `((`  |        |
| `A`   | `((`  | A      |
| `+`   | `((+` | A      |
| `B`   | `((+` | A B    |
| `)`   | `(`   | A B +  |
| `*`   | `(*`  | A B +  |
| `C`   | `(*`  | A B + C|
| `-`   | `(-`  | A B + C * (pop `*` since `*` > `-`) |
| `(`   | `(-(` | A B + C * |
| `D`   | `(-(` | A B + C * D |
| `-`   | `(-(-`| A B + C * D |
| `E`   | `(-(-`| A B + C * D E |
| `)`   | `(-`  | A B + C * D E - |
| `↑`   | `(-↑` | A B + C * D E - |
| `(`   | `(-↑(`| A B + C * D E - |
| `F`   | `(-↑(`| A B + C * D E - F |
| `+`   | `(-↑(+`| A B + C * D E - F |
| `G`   | `(-↑(+`| A B + C * D E - F G |
| `)`   | `(-↑` | A B + C * D E - F G + |
| `)`   | empty | A B + C * D E - F G + ↑ - |

**Final Postfix Expression:**
```
A B + C * D E - F G + ↑ -
```

**Verification:**
- `A B +` → (A+B) then `* C` → (A+B)*C
- `D E -` → (D-E), `F G +` → (F+G), then `↑` → (D-E)↑(F+G)
- Final `-` → (A+B)*C − (D-E)↑(F+G) ✓

---

### (d) Write a procedure to remove the first element of linked list LIST(INFO, LINK, START) and add it to the end without changing any INFO values. Only START and LINK may be changed. [10]

**Algorithm:**
```
MOVE_FIRST_TO_END(INFO, LINK, START):
  IF START == NULL OR LINK[START] == NULL:
    RETURN                         // empty or single-node list

  FIRST = START                    // save first node
  START = LINK[START]              // move START to second node

  LAST = START
  WHILE LINK[LAST] != NULL:        // find last node
    LAST = LINK[LAST]

  LINK[LAST] = FIRST               // attach old first at end
  LINK[FIRST] = NULL               // it is now the last node
  RETURN
```

**Example Trace:**
```
Initial:  START → [10] → [20] → [30] → NULL

FIRST = node(10)
START = node(20)  →  START → [20] → [30] → NULL
LAST  = node(30)   (traverse to end)
LINK[30] = node(10)
LINK[10] = NULL

Final:    START → [20] → [30] → [10] → NULL
```

INFO values (10, 20, 30) are **unchanged**. Only LINK and START were modified. ✓

---

# SECTION – B (Marks: 105)
> Answer any **three (03)** questions from this section in **Script B**

---

## Question 5

### (a) Define priority queue. How do you write priority queue in a linear array and one-way list? [05]

**Priority Queue:**
A priority queue is a special type of queue where each element has an associated **priority**. Elements are served based on priority, not insertion order. Same-priority elements follow FIFO order.

**Implementation in a Linear Array:**

Each element is stored as a pair: `(data, priority)`

```
Index:  0           1           2           3
Data: (Task_C, 1) (Task_A, 3) (Task_B, 2) (Task_D, 4)
```

- Insert: add at end
- Delete (serve): scan entire array for highest priority element → O(n)

**Implementation in a One-Way (Singly) Linked List:**

Maintain a sorted list where **head always has the highest priority** element.

```
HEAD → [Task_D, P=4] → [Task_A, P=3] → [Task_B, P=2] → [Task_C, P=1] → NULL
```

- Insert: find correct position by priority → O(n)
- Delete (serve): remove from head → O(1)

---

### (b) Write algorithms PUSH(STACK, TOP, MAX, ITEM), POP(STACK, TOP), DISPLAY(STACK, TOP). [15]

**PUSH Algorithm:**
```
PUSH(STACK, TOP, MAX, ITEM):
  IF TOP == MAX:
    PRINT "Stack Overflow!"
    RETURN
  TOP = TOP + 1
  STACK[TOP] = ITEM
  RETURN
```

**POP Algorithm:**
```
POP(STACK, TOP):
  IF TOP == 0:
    PRINT "Stack Underflow!"
    RETURN NULL
  ITEM = STACK[TOP]
  TOP = TOP - 1
  RETURN ITEM
```

**DISPLAY Algorithm:**
```
DISPLAY(STACK, TOP):
  IF TOP == 0:
    PRINT "Stack is empty."
    RETURN
  PRINT "Stack contents (top to bottom):"
  FOR i = TOP downto 1:
    PRINT STACK[i]
  RETURN
```

**Example Trace (MAX = 5, TOP = 0 initially):**
```
PUSH 10 → TOP=1, STACK=[10]
PUSH 20 → TOP=2, STACK=[10,20]
PUSH 30 → TOP=3, STACK=[10,20,30]
DISPLAY → 30, 20, 10
POP     → returns 30, TOP=2
```

---

### (c) Implement QUICK_SORT(A, LOW, HIGH) algorithm using PARTITION subroutine. [15]

**Concept:** Choose a pivot, partition so elements < pivot are left, elements > pivot are right. Recursively sort each side.

**PARTITION Algorithm:**
```
PARTITION(A, LOW, HIGH):
  pivot = A[LOW]           // first element as pivot
  p = LOW + 1
  q = HIGH

  WHILE p <= q:
    WHILE p <= HIGH AND A[p] <= pivot:
      p = p + 1
    WHILE q >= LOW AND A[q] > pivot:
      q = q - 1
    IF p < q:
      SWAP(A[p], A[q])

  SWAP(A[LOW], A[q])       // place pivot in correct position
  RETURN q                 // return pivot index
```

**QUICK_SORT Algorithm:**
```
QUICK_SORT(A, LOW, HIGH):
  IF LOW < HIGH:
    pivotIndex = PARTITION(A, LOW, HIGH)
    QUICK_SORT(A, LOW, pivotIndex - 1)
    QUICK_SORT(A, pivotIndex + 1, HIGH)
```

**Example Trace:**
Array: `[44, 33, 11, 55, 77]`, pivot = 44

```
After partition: [33, 11, 44, 55, 77] → pivot at index 2
Recurse left:  [33, 11] → [11, 33]
Recurse right: [55, 77] → already sorted
Final: [11, 33, 44, 55, 77] ✓
```

**Time Complexity:**
- Best/Average: **O(n log n)**
- Worst case: **O(n²)** (when array is already sorted and pivot is always min/max)

---

## Question 6

### (a) Compare AVL, Red-Black, and Splay Trees in terms of balancing technique, search time, and suitability for dynamic datasets. [10]

| Feature | AVL Tree | Red-Black Tree | Splay Tree |
|---|---|---|---|
| **Balance Type** | Strictly balanced (height diff ≤ 1) | Loosely balanced (color rules) | Self-adjusting (recent access → root) |
| **Balance Enforcement** | Rotations on every insert/delete | Rotations + recoloring | Splaying (zig, zig-zig, zig-zag) |
| **Height** | ~1.44 log n (shorter) | ~2 log n (taller) | O(n) worst, O(log n) amortized |
| **Search Time** | O(log n) worst | O(log n) worst | O(log n) amortized |
| **Insert/Delete** | O(log n) | O(log n) | O(log n) amortized |
| **Memory** | Extra balance factor per node | Extra color bit per node | No extra storage |
| **Best For** | Frequent **searches** (read-heavy) | Frequent **insertions/deletions** | **Temporal locality** |
| **Dynamic datasets** | Good, but high rotation cost | Excellent | Excellent for non-uniform access |

**Summary:**
- Use **AVL** when search speed is critical (databases, read-heavy workloads)
- Use **Red-Black** for balanced insert/delete/search (e.g., Java's `TreeMap`, Linux kernel)
- Use **Splay** when some elements are accessed far more often than others

---

### (b) Show AVL Tree insertion for keys: 40, 20, 50, 10, 30 and mention rotations applied. [12]

**Recall:** BF(node) = height(left subtree) − height(right subtree). A rotation is needed only when |BF| becomes **2**. Height of an empty subtree = 0, single node = 1.

---

**Insert 40:**
```
    40 (BF=0)
```
Balanced ✓

---

**Insert 20:**
```
    40 (BF = 1−0 = 1)
   /
  20 (BF=0)
```
BF(40) = 1 — within {−1, 0, +1}. Balanced ✓

---

**Insert 50:**
```
    40 (BF = 1−1 = 0)
   /  \
  20   50
```
All BFs = 0. Balanced ✓

---

**Insert 10:**
```
    40
   /  \
  20   50
 /
10
```
Computing balance factors:
- h(10) = 1, h(50) = 1
- h(20) = max(1, 0) + 1 = 2 → BF(20) = 1 − 0 = **+1**
- h(40): left = h(20) = 2, right = h(50) = 1 → BF(40) = 2 − 1 = **+1**

All BFs ∈ {−1, 0, +1}. **No rotation needed.** ✓

---

**Insert 30:**
```
    40
   /  \
  20   50
 /  \
10   30
```
Computing balance factors:
- h(10) = 1, h(30) = 1
- h(20) = max(1, 1) + 1 = 2 → BF(20) = 1 − 1 = **0**
- h(40): left = h(20) = 2, right = h(50) = 1 → BF(40) = 2 − 1 = **+1**

All BFs ∈ {−1, 0, +1}. **No rotation needed.** ✓

---

**Final AVL Tree:**
```
    40
   /  \
  20   50
 /  \
10   30
```

All balance factors: BF(10)=0, BF(30)=0, BF(20)=0, BF(50)=0, BF(40)=+1

**Rotations applied: None.** Every insertion keeps all BFs within the valid range {−1, 0, +1}, so no rebalancing is required.

> **Note on a common mistake:** The BF at node 40 after inserting 10 is 2 − 1 = **1**, not 2. A rotation is triggered only when BF reaches ±2. Since we have a right subtree (node 50) balancing the left side, the tree stays balanced throughout all five insertions.

---

### (c) Build a max-heap from [16, 14, 10, 8, 7, 9, 3, 2, 4, 1] and perform heap sort. [13]

**The array [16, 14, 10, 8, 7, 9, 3, 2, 4, 1] is already a valid max-heap.**

Verification (1-indexed, parent at i, children at 2i and 2i+1):
```
              16
           /      \
         14        10
        /  \      /  \
       8    7    9    3
      / \  /
     2   4 1
```
Every parent ≥ its children ✓

**Heap Sort:** Repeatedly swap root with last element, shrink heap, then heapify (sift down) to restore.

**Pass 1 (n=10):** Swap A[1]=16 with A[10]=1
- Array: `[1, 14, 10, 8, 7, 9, 3, 2, 4 | 16]`
- Heapify root: 1 < 14 → swap → 1 < 8 → swap → 1 < 4 → swap
- Result: `[14, 8, 10, 4, 7, 9, 3, 2, 1 | 16]`

**Pass 2 (n=9):** Swap A[1]=14 with A[9]=1
- Array: `[1, 8, 10, 4, 7, 9, 3, 2 | 14, 16]`
- Heapify: 1 < 10 → swap → 1 < 9 → swap
- Result: `[10, 8, 9, 4, 7, 1, 3, 2 | 14, 16]`

**Pass 3 (n=8):** Swap A[1]=10 with A[8]=2
- Array: `[2, 8, 9, 4, 7, 1, 3 | 10, 14, 16]`
- Heapify: 2 < 9 → swap → 2 < 3 → swap
- Result: `[9, 8, 3, 4, 7, 1, 2 | 10, 14, 16]`

**Pass 4 (n=7):** Swap A[1]=9 with A[7]=2
- Result after heapify: `[8, 7, 3, 4, 2, 1 | 9, 10, 14, 16]`

**Pass 5 (n=6):** Swap A[1]=8 with A[6]=1
- Result after heapify: `[7, 4, 3, 1, 2 | 8, 9, 10, 14, 16]`

**Pass 6 (n=5):** Swap A[1]=7 with A[5]=2
- Result after heapify: `[4, 2, 3, 1 | 7, 8, 9, 10, 14, 16]`

**Pass 7 (n=4):** Swap A[1]=4 with A[4]=1
- Result after heapify: `[3, 2, 1 | 4, 7, 8, 9, 10, 14, 16]`

**Pass 8 (n=3):** Swap A[1]=3 with A[3]=1
- Result after heapify: `[2, 1 | 3, 4, 7, 8, 9, 10, 14, 16]`

**Pass 9 (n=2):** Swap A[1]=2 with A[2]=1
- Result: `[1 | 2, 3, 4, 7, 8, 9, 10, 14, 16]`

**Final Sorted Array:** `[1, 2, 3, 4, 7, 8, 9, 10, 14, 16]` ✓

**Time Complexity:** O(n log n) — best, average, and worst case.

---

## Question 7

### (a) Define hashing. Explain the purpose of collision resolution. [04]

**Hashing:**
Hashing converts a key into an index (address) in a hash table using a **hash function** `h(key)`, enabling fast data storage and retrieval.

```
h(key) = key mod table_size
```

Example: h(25) = 25 mod 7 = 4 → store at index 4.

**Collision:**
A **collision** occurs when two different keys map to the **same index**.

```
h(10) = 10 mod 7 = 3
h(17) = 17 mod 7 = 3  ← Collision!
```

**Purpose of Collision Resolution:**
Collisions are unavoidable (key space >> table size), so collision resolution ensures all elements can still be stored and retrieved correctly. Without it, the second element would overwrite the first.

**Common Methods:**
1. **Linear Probing** — try next available slot
2. **Quadratic Probing** — probe at distances 1², 2², 3²…
3. **Double Hashing** — use a second hash function
4. **Chaining** — use linked lists at each slot

---

### (b) Write an algorithm (pseudo-code) to sort an array using insertion sort. [08]

**Insertion Sort:** Build the sorted array one element at a time by inserting each element into its correct position among already-sorted elements.

**Algorithm:**
```
INSERTION_SORT(A, n):
  FOR i = 1 to n-1:
    key = A[i]
    j = i - 1
    WHILE j >= 0 AND A[j] > key:
      A[j+1] = A[j]
      j = j - 1
    A[j+1] = key
  RETURN A
```

**Trace Example:** Array = [5, 3, 8, 1, 2]

| Pass | Key | Array after insertion |
|------|-----|-----------------------|
| i=1  | 3   | [3, 5, 8, 1, 2]       |
| i=2  | 8   | [3, 5, 8, 1, 2]       |
| i=3  | 1   | [1, 3, 5, 8, 2]       |
| i=4  | 2   | [1, 2, 3, 5, 8]       |

**Time Complexity:**
- Best case: O(n) — already sorted
- Worst/Average: O(n²)

---

### (c) Given h(k) = k mod 7, insert keys 10, 22, 31, 4, 15, 28, 17, 88, 59 using Linear Probing. Show the final hash table. [10]

**Table size = 10, h(k) = k mod 7**
**Linear Probing:** If slot occupied, try `(h(k) + 1) mod 10`, then `+2`, etc.

| Key | h(k) = k mod 7 | Probe sequence | Final Index |
|-----|----------------|----------------|-------------|
| 10  | 3              | 3 → free       | **3**       |
| 22  | 1              | 1 → free       | **1**       |
| 31  | 3              | 3(taken) → 4   | **4**       |
| 4   | 4              | 4(taken) → 5   | **5**       |
| 15  | 1              | 1(taken) → 2   | **2**       |
| 28  | 0              | 0 → free       | **0**       |
| 17  | 3              | 3→4→5→6        | **6**       |
| 88  | 4              | 4→5→6→7        | **7**       |
| 59  | 3              | 3→4→5→6→7→8    | **8**       |

**Final Hash Table:**

| Index | Key |
|-------|-----|
| 0     | 28  |
| 1     | 22  |
| 2     | 15  |
| 3     | 10  |
| 4     | 31  |
| 5     | 4   |
| 6     | 17  |
| 7     | 88  |
| 8     | 59  |
| 9     | —   |

---

### (d) Trace binary search on sorted list to locate element 89. [13]

**Sorted list (1-indexed):**
`17, 19, 28, 30, 45, 55, 58, 61, 63, 67, 72, 76, 80, 89, 99`

n = 15, **Target = 89**

**Algorithm:**
```
LOW = 1, HIGH = 15
WHILE LOW <= HIGH:
  MID = (LOW + HIGH) / 2
  IF A[MID] == target: RETURN MID
  IF A[MID] < target:  LOW = MID + 1
  IF A[MID] > target:  HIGH = MID - 1
```

**Step-by-Step Trace:**

| Iteration | LOW | HIGH | MID | A[MID] | Comparison | Direction |
|-----------|-----|------|-----|--------|------------|-----------|
| 1         | 1   | 15   | 8   | 61     | 61 < 89    | Right → LOW=9 |
| 2         | 9   | 15   | 12  | 76     | 76 < 89    | Right → LOW=13 |
| 3         | 13  | 15   | 14  | 89     | 89 == 89   | **Found at index 14** |

**Element 89 found in just 3 comparisons!**

**Time Complexity:** O(log n)

---

## Question 8

### (a) Distinguish between internal sorting and external sorting. [08]

| Feature | Internal Sorting | External Sorting |
|---|---|---|
| **Definition** | All data fits in RAM; sorted entirely in memory | Data too large for RAM; uses external storage (disk) |
| **Storage** | Main memory (RAM) only | Hard disk, tapes |
| **Speed** | Fast — direct memory access | Slow — disk I/O is much slower than RAM |
| **Data size** | Small to medium datasets | Very large datasets |
| **Algorithms** | Bubble, Insertion, Selection, Quick, Merge, Heap Sort | External Merge Sort, Polyphase Sort |
| **Cost factor** | CPU time | Disk I/O time |
| **Example** | Sorting 10,000 records in RAM | Sorting 10 million database records from disk |

**Key Point:** External sorting uses **multi-way merge** — data is divided into sorted "runs" on disk which are then merged together.

---

### (b) Explain double hashing method with example. [08]

**Double Hashing** uses **two hash functions** to resolve collisions. When a collision occurs, a second hash function determines the step size for probing.

**Formula:**
```
h(k, i) = (h1(k) + i × h2(k)) mod TABLE_SIZE
```
- `h1(k)` — primary hash function
- `h2(k)` — secondary hash function (step size)
- `i` — probe number (0, 1, 2, …)

**Common choice:**
```
h1(k) = k mod TABLE_SIZE
h2(k) = R - (k mod R)   where R is a prime < TABLE_SIZE
```

**Why better than linear probing?**
Linear probing causes **primary clustering** (long chains). Double hashing avoids this since each key gets a different step size.

**Example:** TABLE_SIZE = 7, R = 5

| Key | h1(k) | Probe 0 | Result |
|-----|-------|---------|--------|
| 18  | 18 mod 7 = 4 | 4 → free | **4** |
| 41  | 41 mod 7 = 6 | 6 → free | **6** |
| 22  | 22 mod 7 = 1 | 1 → free | **1** |

Now insert **25** (collision):
- h1(25) = 25 mod 7 = **4** → occupied!
- h2(25) = 5 − (25 mod 5) = 5 − 0 = **5**
- Probe 1: (4 + 1×5) mod 7 = 9 mod 7 = **2** → free → store at 2 ✓

---

### (c) Perform DFS traversal on the given undirected graph starting from vertex 1. List vertices and draw DFS tree. [09]

**Graph edges:** 1-2, 1-5, 1-6, 2-3, 2-5, 3-4, 3-5, 4-5

**Adjacency List:**
```
1: [2, 5, 6]
2: [1, 3, 5]
3: [2, 4, 5]
4: [3, 5]
5: [1, 2, 3, 4]
6: [1]
```

**DFS from vertex 1 (visit smallest unvisited neighbor first):**
```
Visit 1 → go to 2
Visit 2 → go to 3
Visit 3 → go to 4
Visit 4 → go to 5
Visit 5 → all neighbors (1,2,3,4) already visited → backtrack
Backtrack to 4, 3, 2, 1 → go to 6
Visit 6 → done
```

**DFS Traversal Sequence:** `1 → 2 → 3 → 4 → 5 → 6`

**DFS Tree (tree edges only):**
```
    1
   / \
  2   6
  |
  3
  |
  4
  |
  5
```
- Tree edges: 1-2, 2-3, 3-4, 4-5, 1-6
- Back edges: 1-5, 2-5, 3-5 (connect to already-visited ancestors)

---

### (d) Determine the minimum spanning tree of the weighted undirected graph using Prim's algorithm starting from V₁. [10]

**Graph edges:**
```
V1-V2: 3,  V1-V4: 5
V2-V3: 7,  V2-V4: 2,  V2-V5: 6
V3-V5: 10, V3-V6: 2
V4-V5: 3,  V4-V7: 2
V5-V6: 7,  V5-V7: 5,  V5-V8: 5
V6-V8: 6,  V7-V8: 4
```

**Prim's Algorithm — Step-by-Step (start from V1):**

| Step | Visited Set | Cheapest Edge Available | MST Edge Added |
|------|-------------|------------------------|----------------|
| 1 | {V1} | V1-V2(3), V1-V4(5) | **V1-V2 = 3** |
| 2 | {V1,V2} | V2-V4(2), V1-V4(5), V2-V5(6), V2-V3(7) | **V2-V4 = 2** |
| 3 | {V1,V2,V4} | V4-V7(2), V4-V5(3), V1-V4 skip, V2-V5(6), V2-V3(7) | **V4-V7 = 2** |
| 4 | {V1,V2,V4,V7} | V4-V5(3), V7-V8(4), V2-V5(6), V2-V3(7) | **V4-V5 = 3** |
| 5 | {V1,V2,V4,V5,V7} | V7-V8(4), V5-V8(5), V5-V6(7), V2-V3(7), V5-V3(10) | **V7-V8 = 4** |
| 6 | {V1,V2,V4,V5,V7,V8} | V8-V6(6), V5-V6(7), V2-V3(7), V5-V3(10) | **V8-V6 = 6** |
| 7 | {V1,V2,V4,V5,V6,V7,V8} | V6-V3(2), V2-V3(7), V5-V3(10) | **V6-V3 = 2** |

All 8 vertices visited with 7 edges.

**MST Edges:**

| Edge  | Weight |
|-------|--------|
| V1-V2 | 3      |
| V2-V4 | 2      |
| V4-V7 | 2      |
| V4-V5 | 3      |
| V7-V8 | 4      |
| V8-V6 | 6      |
| V6-V3 | 2      |

**Total MST Weight = 3 + 2 + 2 + 3 + 4 + 6 + 2 = 22**

---

*End of Answer Script — CSE 2101 Data Structure*
*Chandpur Science and Technology University, 2024*
