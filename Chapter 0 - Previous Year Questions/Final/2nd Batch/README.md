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

Initial state:
[ ][ ][ ]
[ ][ ][ ]
[ ][ ][ ]

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
  // Check rows
  FOR i = 0 to 2:
    IF board[i][0] == player AND board[i][1] == player AND board[i][2] == player:
      RETURN TRUE

  // Check columns
  FOR j = 0 to 2:
    IF board[0][j] == player AND board[1][j] == player AND board[2][j] == player:
      RETURN TRUE

  // Check main diagonal
  IF board[0][0] == player AND board[1][1] == player AND board[2][2] == player:
    RETURN TRUE

  // Check anti-diagonal
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
- A = [4, 7, 10, 15, 20, 3]  → n = 6
- B = [5, 8, 2]              → B[0] = 5
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
- Uses modulo arithmetic to wrap around: `(index + 1) mod MAX`

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

1. A single arithmetic calculation: `(REAR+1) mod MAX`
2. A single comparison (overflow/underflow check)
3. A single assignment

**No loops. No searching. No shifting of elements.**

**Amortized Analysis:**

In amortized analysis, we spread the cost of operations over a sequence of operations.

- Consider n enqueue + n dequeue operations.
- Total work done = n + n = 2n steps (each operation is constant work).
- Amortized cost per operation = 2n / 2n = **O(1)**

Since neither enqueue nor dequeue depends on the number of elements currently in the queue, both are **O(1) in worst case**, and trivially O(1) amortized.

> **Conclusion:** Because only pointer manipulation and modulo arithmetic (constant-time operations) are used, both enqueue and dequeue are O(1).

---

## Question 2

### (a) You have learned that singly linked lists are trees. Are circularly linked lists also trees? Why or why not? [06]

**Are Singly Linked Lists Trees?**
A singly linked list *can* be viewed as a degenerate tree where each node has at most one child (the next node). It has a root (head) and leaf (last node with NULL).

**Are Circularly Linked Lists Trees? → NO**

**Reason:**

A **tree** must satisfy these properties:
1. There is exactly **one root** node (no parent)
2. Every other node has **exactly one parent**
3. There are **no cycles**

A **circularly linked list** violates property 3 — it contains a **cycle**: the last node points back to the first node, forming a loop.

In a tree:
- There is a clear start and end
- You can reach NULL (base case)
- There is no cycle

In a circular linked list:
- There is no NULL
- Traversal goes in an infinite loop
- It forms a **cycle**, which trees cannot have

**Therefore, circular linked lists are NOT trees because they contain cycles, which violates the definition of a tree.**

---

### (b) Compare doubly linked lists and circular linked lists in terms of: i) Memory usage, ii) Insertion/deletion at both ends, iii) Traversal complexity [12]

#### i) Memory Usage

| | Doubly Linked List | Circular Linked List |
|---|---|---|
| Pointers per node | 2 (next + prev) | 1 (next only, singly circular) or 2 (doubly circular) |
| Extra overhead | Higher (2 pointers) | Lower for singly circular (1 pointer) |
| NULL pointers | Head.prev = NULL, Tail.next = NULL | No NULL pointers |

**Winner:** Singly Circular Linked List uses less memory per node.

#### ii) Insertion/Deletion at Both Ends

**Doubly Linked List (with head and tail pointers):**
- Insert at front: O(1) — update head.prev and new node's next
- Insert at end: O(1) — update tail.next and new node's prev
- Delete at front: O(1)
- Delete at end: O(1) — because we can use `tail.prev`

**Circular Linked List (singly, with only head pointer):**
- Insert at front: O(1)
- Insert at end: O(n) — must traverse to last node (unless tail pointer is maintained)
- Delete at front: O(1)
- Delete at end: O(n) — must find node before last

**Winner:** Doubly Linked List is better for end operations (O(1) vs O(n)).

#### iii) Traversal Complexity

| | Doubly Linked List | Circular Linked List |
|---|---|---|
| Forward traversal | O(n) | O(n) |
| Backward traversal | O(n) — use prev pointer | Not possible (singly circular) |
| Cycle detection needed? | No | Yes — need to track start node |
| Risk of infinite loop | No | Yes — must stop at head |

**Winner:** Doubly Linked List for bidirectional traversal. Circular is useful when you need to cycle through elements repeatedly (e.g., round-robin scheduling).

---

### (c) Delete the node containing 20 from the doubly linked list: NULL ← [10] ⇌ [20] ⇌ [30] → NULL [17]

**Initial State:**
```
NULL ← [10] ⇌ [20] ⇌ [30] → NULL
         ↑                ↑
        head             tail
```

Each node has: `PREV | DATA | NEXT`

- Node A: `NULL | 10 | →20`
- Node B: `←10  | 20 | →30`   ← This is the node to delete
- Node C: `←20  | 30 | NULL`

---

**Step-by-Step Deletion of Node containing 20:**

**Step 1: Identify the node to delete**
- Let `DEL = Node B (data = 20)`
- `DEL.PREV = Node A (data = 10)`
- `DEL.NEXT = Node C (data = 30)`

**Step 2: Update the NEXT pointer of the previous node**
- Set `DEL.PREV.NEXT = DEL.NEXT`
- i.e., `Node A.NEXT = Node C`
- Node A now points forward to Node C (skipping Node B)

```
Node A: NULL | 10 | →30   (previously pointed to 20, now points to 30)
```

**Step 3: Update the PREV pointer of the next node**
- Set `DEL.NEXT.PREV = DEL.PREV`
- i.e., `Node C.PREV = Node A`
- Node C now points backward to Node A (skipping Node B)

```
Node C: ←10 | 30 | NULL   (previously pointed back to 20, now points to 10)
```

**Step 4: Isolate the deleted node (optional cleanup)**
- Set `DEL.NEXT = NULL`
- Set `DEL.PREV = NULL`
- Free memory of DEL

**Final State:**
```
NULL ← [10] ⇌ [30] → NULL
```

**Visual Diagram of pointer updates:**

```
BEFORE:
NULL ←← [10] ←→ [20] ←→ [30] →→ NULL
               (delete this)

STEP 2: Node A's NEXT skips over 20
NULL ←← [10] ─────────→ [30] →→ NULL
               [20]  ←→

STEP 3: Node C's PREV skips over 20
NULL ←← [10] ←────────→ [30] →→ NULL
               [20] isolated

AFTER (Node 20 removed):
NULL ←← [10] ←→ [30] →→ NULL
```

**Algorithm:**
```
DELETE_NODE(DEL):
  IF DEL.PREV != NULL:
    DEL.PREV.NEXT = DEL.NEXT
  ELSE:
    HEAD = DEL.NEXT    // DEL was the head

  IF DEL.NEXT != NULL:
    DEL.NEXT.PREV = DEL.PREV
  ELSE:
    TAIL = DEL.PREV    // DEL was the tail

  FREE(DEL)
```

---

## Question 3

### (a) "Is bubble sort divide and conquer type?" Explain your answer. [08]

**Answer: NO, Bubble Sort is NOT a divide and conquer algorithm.**

**What is Divide and Conquer?**
Divide and Conquer has three steps:
1. **Divide** – Break the problem into smaller subproblems
2. **Conquer** – Solve each subproblem recursively
3. **Combine** – Merge the solutions

*Examples of true divide and conquer sorts:* Merge Sort, Quick Sort.

**How Bubble Sort Actually Works:**
Bubble Sort repeatedly **compares adjacent elements** and **swaps** them if they are in the wrong order. It does this pass by pass until the array is sorted.

```
Pass 1: Compare and swap neighbors → largest bubbles to end
Pass 2: Repeat for remaining n-1 elements
...
```

**Why it is NOT Divide and Conquer:**
1. Bubble sort does **not divide** the array into subproblems
2. It does **not solve subproblems independently**
3. It does **not combine** solutions
4. It works on the **entire array in each pass**, using a simple comparison-exchange strategy

**Counter Example:**
- Merge Sort divides array into halves → sorts each half → merges them ✓ (D&C)
- Bubble Sort just compares adjacent pairs again and again ✗ (Not D&C)

**Conclusion:** Bubble Sort is an **iterative comparison-based** sorting algorithm, classified under the **"Exchange Sort"** category, NOT divide and conquer.

---

### (b) Explain how Stack is used in Depth-First Search (DFS). [08]

**DFS Overview:**
Depth-First Search explores a graph by going as deep as possible before backtracking.

**Role of Stack in DFS:**
The stack keeps track of the path from start node. When we hit a dead end, we backtrack by popping from the stack.

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
Start at 1:
Stack: [1]
Pop 1, visit 1. Push neighbors 2, 3 → Stack: [2, 3]
Pop 3, visit 3. Push neighbor 4   → Stack: [2, 4]
Pop 4, visit 4. No unvisited.      → Stack: [2]
Pop 2, visit 2. Neighbor 4 already visited. → Stack: []
Done.
DFS Order: 1, 3, 4, 2
```

**Key Points:**
- Stack = LIFO (Last In, First Out) → naturally goes deep before backtracking
- Recursive DFS uses the **call stack** implicitly
- Iterative DFS uses an **explicit stack**

---

### (c) Write a function that will merge two Linked Lists of integers, sorted in ascending order. The merged list should also be sorted. [09]

**Idea:** Compare heads of both lists, pick the smaller one, and advance that pointer. Repeat until one list is exhausted, then attach the remainder.

**Algorithm:**
```
MERGE_SORTED_LISTS(head1, head2):
  // Create a dummy node to simplify code
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

  // Attach the remaining list
  IF head1 != NULL:
    current.next = head1
  ELSE:
    current.next = head2

  RETURN dummy.next   // head of merged list
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

**Time Complexity:** O(m + n) where m, n are lengths of the two lists.

---

### (d) Route planner with thousands of intersections (nodes) and few roads (edges). Adjacency list or matrix — which is more efficient and why? [10]

**Answer: Adjacency List is more efficient.**

**Why? The graph is SPARSE (few edges compared to nodes).**

**Comparison:**

| Feature | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V + E) |
| Check if edge exists | O(1) | O(degree of vertex) |
| Find all neighbors | O(V) | O(degree of vertex) |
| Add an edge | O(1) | O(1) |
| Best for | Dense graphs | Sparse graphs |

**For this Route Planner:**
- V = thousands of intersections (large V)
- E = few roads (small E, E << V²)

**Adjacency Matrix:** Would require a V × V matrix. If V = 10,000, that's 10,000 × 10,000 = **100 million cells** — mostly empty (zeros). This wastes enormous memory.

**Adjacency List:** Stores only actual edges. With few roads, only a small list per node is needed. Memory = O(V + E), which is much smaller.

**Conclusion:** For a sparse graph like a city route planner, **Adjacency List** is far more memory-efficient and faster for traversal operations like DFS/BFS used in path finding.

---

## Question 4

### (a) What are the differences between a heap and BST? When to use a heap and when to use a BST? [06]

**Differences:**

| Feature | Heap | Binary Search Tree (BST) |
|---|---|---|
| Order property | Parent ≥ children (max-heap) or Parent ≤ children (min-heap) | Left < Root < Right |
| Structure | Always a **complete binary tree** | Not necessarily complete |
| Search | O(n) — not optimized for search | O(log n) average |
| Find min/max | O(1) — always at root | O(log n) |
| Insert | O(log n) | O(log n) average |
| Delete min/max | O(log n) | O(log n) |

**When to use a Heap:**
- When you need to **repeatedly find/remove the minimum or maximum** element
- Priority queues
- Heap sort
- Dijkstra's shortest path algorithm
- Task scheduling systems

**When to use a BST:**
- When you need to **search for arbitrary elements** efficiently
- When you need **sorted traversal** (in-order gives sorted output)
- When you need both insert, delete, and search efficiently
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

**Step 1: Delete node 17 (root)**

Node 17 has **two children**, so we replace it with its **in-order successor** (the smallest value in the right subtree).

**Finding in-order successor of 17:**
- Go to right subtree (root = 26)
- Go as far left as possible → 20 (20 has no left child)
- **In-order successor = 20**

**Step 2: Replace 17 with 20**
- Copy 20's value to the root (root becomes 20)
- Delete node 20 from its original position
- Node 20 had a right child (21), so 21 takes 20's place

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

Traversal path:
- Go left from 20 → 9 → 7 (leftmost) → **visit 4, 7, 9**
- Then 12 → left child 11 → left child 4... 

Wait, let me re-read the tree. Node 11 is left child of 12, and node 4 is left child of 11.

In-order traversal visits: Left subtree, then root, then right subtree.

**In-order traversal after deletion:**

`4, 7, 9, 11, 12, 20, 21, 26, 30`

---

### (c) Translate infix expression ((A + B) * C − (D − E) ↑ (F + G)) to postfix. Which data structure is needed? [09]

**Data Structure needed: Stack**

A stack is used to hold operators temporarily while we process the infix expression left to right.

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
| `↑`   | `(-↑` | A B + C * D E - (push ↑ since `↑` > `-`) |
| `(`   | `(-↑(`| A B + C * D E - |
| `F`   | `(-↑(`| A B + C * D E - F |
| `+`   | `(-↑(+`| A B + C * D E - F |
| `G`   | `(-↑(+`| A B + C * D E - F G |
| `)`   | `(-↑` | A B + C * D E - F G + |
| `)`   | empty | A B + C * D E - F G + ↑ - (pop ↑ then -) |

**Final Postfix Expression:**
```
A B + C * D E - F G + ↑ -
```

**Verification:**
- `A B +` → (A+B)
- `A B + C *` → (A+B)*C
- `D E -` → (D-E)
- `F G +` → (F+G)
- `D E - F G + ↑` → (D-E)↑(F+G)
- `A B + C * D E - F G + ↑ -` → (A+B)*C - (D-E)↑(F+G) ✓

---

### (d) Write a procedure to remove the first element of linked list LIST(INFO, LINK, START) and add it to the end without changing any INFO values. Only START and LINK may be changed. [10]

**Idea:**
1. Save the first node
2. Move START to the second node
3. Find the last node
4. Attach the old first node at the end
5. Set its LINK to NULL

**Algorithm:**
```
MOVE_FIRST_TO_END(INFO, LINK, START):

  // Step 1: If list is empty or has only one node, do nothing
  IF START == NULL OR LINK[START] == NULL:
    RETURN

  // Step 2: Save the first node
  FIRST = START

  // Step 3: Move START to the second node
  START = LINK[START]

  // Step 4: Find the last node (node whose LINK is NULL)
  LAST = START
  WHILE LINK[LAST] != NULL:
    LAST = LINK[LAST]

  // Step 5: Attach FIRST node at the end
  LINK[LAST] = FIRST

  // Step 6: Set FIRST's LINK to NULL (it's now the last node)
  LINK[FIRST] = NULL

  RETURN
```

**Example Trace:**
```
Initial list:  START → [10] → [20] → [30] → NULL

Step 1: FIRST = node(10)
Step 2: START = node(20)  →  START → [20] → [30] → NULL
Step 3: LAST = node(30)   (traverse to end)
Step 4: LINK[30] = node(10)
Step 5: LINK[10] = NULL

Final list:  START → [20] → [30] → [10] → NULL
```

INFO values (10, 20, 30) are **unchanged**. Only LINK pointers and START were modified. ✓

---

# SECTION – B (Marks: 105)
> Answer any **three (03)** questions from this section in **Script B**

---

## Question 5

### (a) Define priority queue. How do you write priority queue in a linear array and one-way list? [05]

**Priority Queue:**
A priority queue is a special type of queue in which each element has an associated **priority**. Elements are removed based on priority, NOT on the order they were inserted.

- **Highest priority** element is served first
- If two elements have the same priority, they are served in FIFO order

**Implementation in a Linear Array:**

Each element is stored as a pair: `(data, priority)`

```
Array:
Index:  0          1          2          3
Data: (Task_C, 1) (Task_A, 3) (Task_B, 2) (Task_D, 4)
```

- To insert: add at end
- To delete (serve): scan entire array to find the element with the **highest priority** → O(n)
- Or keep array sorted by priority → O(n) insert, O(1) delete

**Implementation in a One-Way (Singly) Linked List:**

Maintain a sorted linked list where the **head** always has the highest priority element.

```
HEAD → [Task_D, P=4] → [Task_A, P=3] → [Task_B, P=2] → [Task_C, P=1] → NULL
```

- **Insert:** Find the correct position based on priority → O(n)
- **Delete (serve):** Remove from head → O(1)

---

### (b) Write algorithms PUSH(STACK, TOP, MAX, ITEM), POP(STACK, TOP), DISPLAY(STACK, TOP). [15]

**PUSH Algorithm:**
```
PUSH(STACK, TOP, MAX, ITEM):
  // Check for stack overflow
  IF TOP == MAX:
    PRINT "Stack Overflow! Cannot push."
    RETURN

  // Increment TOP and insert element
  TOP = TOP + 1
  STACK[TOP] = ITEM
  PRINT "Item", ITEM, "pushed successfully."
  RETURN
```

**POP Algorithm:**
```
POP(STACK, TOP):
  // Check for stack underflow
  IF TOP == 0:
    PRINT "Stack Underflow! Stack is empty."
    RETURN NULL

  // Remove top element
  ITEM = STACK[TOP]
  TOP = TOP - 1
  PRINT "Item", ITEM, "popped successfully."
  RETURN ITEM
```

**DISPLAY Algorithm:**
```
DISPLAY(STACK, TOP):
  // Check if stack is empty
  IF TOP == 0:
    PRINT "Stack is empty."
    RETURN

  // Print from top to bottom
  PRINT "Stack contents (top to bottom):"
  FOR i = TOP downto 1:
    PRINT STACK[i]

  RETURN
```

**Example Trace:**
```
MAX = 5, TOP = 0 (initially empty)

PUSH(STACK, TOP, MAX, 10): TOP=1, STACK=[10]
PUSH(STACK, TOP, MAX, 20): TOP=2, STACK=[10,20]
PUSH(STACK, TOP, MAX, 30): TOP=3, STACK=[10,20,30]

DISPLAY: 30, 20, 10 (top to bottom)

POP: Returns 30, TOP=2, STACK=[10,20]

PUSH when TOP==MAX: "Stack Overflow!"
POP when TOP==0:    "Stack Underflow!"
```

---

### (c) Implement QUICK_SORT(A, LOW, HIGH) algorithm using PARTITION subroutine. [15]

**Concept:**
Quick Sort is a divide-and-conquer algorithm:
1. Choose a **pivot** element
2. **Partition**: all elements < pivot go left, all > pivot go right
3. **Recursively** sort left and right subarrays

**PARTITION Algorithm:**
```
PARTITION(A, LOW, HIGH):
  pivot = A[HIGH]    // Choose last element as pivot
  i = LOW - 1       // i tracks position of smaller element

  FOR j = LOW to HIGH - 1:
    IF A[j] <= pivot:
      i = i + 1
      SWAP(A[i], A[j])

  SWAP(A[i+1], A[HIGH])   // Place pivot in correct position
  RETURN i + 1            // Return pivot index
```

**QUICK_SORT Algorithm:**
```
QUICK_SORT(A, LOW, HIGH):
  IF LOW < HIGH:
    // Get pivot index after partition
    pivotIndex = PARTITION(A, LOW, HIGH)

    // Recursively sort left subarray (elements < pivot)
    QUICK_SORT(A, LOW, pivotIndex - 1)

    // Recursively sort right subarray (elements > pivot)
    QUICK_SORT(A, pivotIndex + 1, HIGH)
```

**Example Trace:**
Array: `[3, 6, 8, 10, 1, 2, 1]`, LOW=0, HIGH=6

```
Pivot = A[6] = 1
Partition: all elements ≤ 1 go left
After partition: [1, 1, 8, 10, 6, 2, 3], pivot at index 1

Recurse left:  QUICK_SORT(A, 0, 0)  → single element, done
Recurse right: QUICK_SORT(A, 2, 6) with [8,10,6,2,3]
  Pivot = 3, partition → [2,3,6,10,8]
  ...continue recursively...

Final sorted: [1, 1, 2, 3, 6, 8, 10]
```

**Time Complexity:**
- Best/Average case: **O(n log n)**
- Worst case: **O(n²)** (when array is already sorted and pivot is always min/max)

---

## Question 6

### (a) Compare AVL, Red-Black, and Splay Trees in terms of balancing technique, search time, and suitability for dynamic datasets. [10]

| Feature | AVL Tree | Red-Black Tree | Splay Tree |
|---|---|---|---|
| **Balance Type** | Strictly balanced (height diff ≤ 1) | Loosely balanced (color rules) | Self-adjusting (recently accessed → root) |
| **Balance Enforcement** | Rotations on every insert/delete | Rotations + recoloring | Splaying (zig, zig-zig, zig-zag) |
| **Height** | ~1.44 log n (shorter) | ~2 log n (taller) | O(n) worst, O(log n) amortized |
| **Search Time** | O(log n) worst | O(log n) worst | O(log n) amortized |
| **Insert** | O(log n) | O(log n) | O(log n) amortized |
| **Delete** | O(log n) | O(log n) | O(log n) amortized |
| **Memory** | Extra height/balance factor | Extra color bit per node | No extra storage |
| **Best For** | Frequent **searches** (read-heavy) | Frequent **insertions/deletions** (write-heavy) | **Temporal locality** — recently accessed items searched again |
| **Dynamic datasets** | Good, but high rotation cost | Excellent | Excellent for non-uniform access patterns |

**Summary:**
- Use **AVL** when search speed is critical (databases, read-heavy)
- Use **Red-Black** for balanced insert/delete/search (e.g., Java's `TreeMap`, Linux kernel)
- Use **Splay** when some elements are accessed far more often than others

---

### (b) Show AVL Tree insertion for keys: 40, 20, 50, 10, 30 and mention rotations applied. [12]

**Insert 40:**
```
    40
```
Height: 1. Balanced. ✓

**Insert 20:**
```
    40
   /
  20
```
Balance factor of 40 = 1. Still balanced ✓

**Insert 50:**
```
    40
   /  \
  20   50
```
All balance factors = 0 or 1. Balanced ✓

**Insert 10:**
```
    40
   /  \
  20   50
 /
10
```
Balance factor of 20 = 1, of 40 = 2 → **Imbalanced!**

Node 40: left height=2, right height=1 → BF = 2-1 = **+2** (Left-heavy)
Node 20: left height=1, right height=0 → BF = **+1** (Left-heavy)
→ **Left-Left case → Apply Right Rotation at 40**

```
Right Rotation at 40:
    20
   /  \
  10   40
         \
          50
```
✓ Balanced

**Insert 30:**
```
    20
   /  \
  10   40
      /  \
     30   50
```
Balance factor of 20: left height=1, right height=2 → BF = **-1**
Balance factor of 40: left height=1, right height=1 → BF = 0
All within limits. **Balanced ✓ — No rotation needed.**

**Final AVL Tree:**
```
    20
   /  \
  10   40
      /  \
     30   50
```

**Rotations applied:** One **Right Rotation** at node 40 after inserting 10.

---

### (c) Build a max-heap from [16, 14, 10, 8, 7, 9, 3, 2, 4, 1] and perform heap sort. [13]

**What is a Max-Heap?**
A complete binary tree where each parent ≥ its children.

**The array [16,14,10,8,7,9,3,2,4,1] is already a max-heap!**

Let's verify using tree form (index starts at 1):
```
              16
           /      \
         14        10
        /  \      /  \
       8    7    9    3
      / \  /
     2   4 1
```
Every parent ≥ children → Max-heap confirmed ✓

**Heap Sort Steps:**

Heap sort works by:
1. The root (max element) is the largest
2. Swap root with last element
3. Reduce heap size by 1
4. Heapify (sift down) the new root to restore heap property
5. Repeat

**Step-by-step (array representation):**

Initial: `[16, 14, 10, 8, 7, 9, 3, 2, 4, 1]` (n=10)

**Pass 1:** Swap A[1]=16 with A[10]=1 → `[1, 14, 10, 8, 7, 9, 3, 2, 4, | 16]`
Heapify(1 to 9): 1 < 14 and 10 → swap with 14 → `[14, 1, 10, ...]` → swap 1 with 8 → `[14, 8, 10, 1, 7, 9, 3, 2, 4, | 16]` → swap 1 with 4 → `[14, 8, 10, 4, 7, 9, 3, 2, 1, | 16]`

**Pass 2:** Swap A[1]=14 with A[9]=1 → Heapify → result: `[10, 8, 9, 4, 7, 1, 3, 2, | 14, 16]`

**Pass 3:** Swap A[1]=10 with A[8]=2 → Heapify → result: `[9, 8, 3, 4, 7, 1, 2, | 10, 14, 16]`

**Pass 4:** Swap 9 with 2 → Heapify → `[8, 7, 3, 4, 2, 1, | 9, 10, 14, 16]`

**Pass 5:** Swap 8 with 1 → Heapify → `[7, 4, 3, 1, 2, | 8, 9, 10, 14, 16]`

**Pass 6:** Swap 7 with 2 → Heapify → `[4, 2, 3, 1, | 7, 8, 9, 10, 14, 16]`

**Pass 7:** Swap 4 with 1 → Heapify → `[3, 2, 1, | 4, 7, 8, 9, 10, 14, 16]`

**Pass 8:** Swap 3 with 1 → Heapify → `[2, 1, | 3, 4, 7, 8, 9, 10, 14, 16]`

**Pass 9:** Swap 2 with 1 → Heapify → `[1, | 2, 3, 4, 7, 8, 9, 10, 14, 16]`

**Final Sorted Array:** `[1, 2, 3, 4, 7, 8, 9, 10, 14, 16]` ✓

**Time Complexity:** O(n log n) — best, average, and worst case.

---

## Question 7

### (a) Define hashing. Explain the purpose of collision resolution. [04]

**Hashing:**
Hashing is a technique that converts a key into an index (address) in a hash table using a **hash function** `h(key)`. This allows for very fast data storage and retrieval.

```
h(key) = key mod table_size
```

**Example:** h(25) = 25 mod 7 = 4 → store at index 4.

**Collision:**
A **collision** occurs when two different keys map to the **same index** in the hash table.

```
h(10) = 10 mod 7 = 3
h(17) = 17 mod 7 = 3  ← Collision! Both map to index 3.
```

**Purpose of Collision Resolution:**
Since collisions are unavoidable, collision resolution techniques ensure that all elements can still be stored correctly and retrieved efficiently. Without it, the second element would overwrite the first and data would be lost.

**Common Methods:**
1. **Linear Probing** — probe the next available slot
2. **Quadratic Probing** — probe at distances 1², 2², 3²...
3. **Double Hashing** — use a second hash function
4. **Chaining** — use linked lists at each slot

---

### (b) Write an algorithm (pseudo-code) to sort an array using insertion sort. [08]

**Insertion Sort Concept:**
Build the sorted array one element at a time. For each element, find its correct position and insert it there (by shifting larger elements right).

**Algorithm:**
```
INSERTION_SORT(A, n):
  FOR i = 1 to n-1:
    key = A[i]          // Element to be inserted
    j = i - 1

    // Shift elements greater than key one position to the right
    WHILE j >= 0 AND A[j] > key:
      A[j+1] = A[j]
      j = j - 1

    A[j+1] = key        // Insert key at correct position

  RETURN A
```

**Trace Example:** Array = [5, 3, 8, 1, 2]

| Pass | Key | Array after insertion |
|------|-----|----------------------|
| i=1  | 3   | **[3, 5**, 8, 1, 2]  |
| i=2  | 8   | **[3, 5, 8**, 1, 2]  |
| i=3  | 1   | **[1, 3, 5, 8**, 2]  |
| i=4  | 2   | **[1, 2, 3, 5, 8]**  |

**Time Complexity:**
- Best case: O(n) — already sorted
- Worst/Average: O(n²)

---

### (c) Given h(k) = k mod 7, insert keys 10, 22, 31, 4, 15, 28, 17, 88, 59 using Linear Probing. Show the final hash table. [10]

**Table size = 10 (to accommodate 9 keys)**
**Hash function:** `h(k) = k mod 7`
**Linear Probing:** If slot is occupied, try `(h(k) + 1) mod 10`, then `+2`, etc.

**Insertions:**

| Key | h(k)=k mod 7 | Attempt slots | Final Index |
|-----|-------------|---------------|-------------|
| 10  | 10 mod 7 = 3 | 3 → free      | **3**       |
| 22  | 22 mod 7 = 1 | 1 → free      | **1**       |
| 31  | 31 mod 7 = 3 | 3 (taken) → 4 | **4**       |
| 4   | 4 mod 7 = 4  | 4 (taken) → 5 | **5**       |
| 15  | 15 mod 7 = 1 | 1 (taken) → 2 | **2**       |
| 28  | 28 mod 7 = 0 | 0 → free      | **0**       |
| 17  | 17 mod 7 = 3 | 3(taken)→4(taken)→5(taken)→6 | **6** |
| 88  | 88 mod 7 = 4 | 4(taken)→5(taken)→6(taken)→7 | **7** |
| 59  | 59 mod 7 = 3 | 3→4→5→6→7(all taken)→8 | **8** |

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

**Sorted list:**
`17, 19, 28, 30, 45, 55, 58, 61, 63, 67, 72, 76, 80, 89, 99`

Index (1-based): 1 through 15. **Target = 89**

**Binary Search Algorithm:**
```
LOW = 1, HIGH = 15
WHILE LOW <= HIGH:
  MID = (LOW + HIGH) / 2
  IF A[MID] == target: RETURN MID
  IF A[MID] < target:  LOW = MID + 1  (search right)
  IF A[MID] > target:  HIGH = MID - 1 (search left)
```

**Step-by-Step Trace:**

**Iteration 1:**
- LOW=1, HIGH=15
- MID = (1+15)/2 = **8**
- A[8] = **61**
- 61 < 89 → search RIGHT → LOW = 9

**Iteration 2:**
- LOW=9, HIGH=15
- MID = (9+15)/2 = **12**
- A[12] = **76**
- 76 < 89 → search RIGHT → LOW = 13

**Iteration 3:**
- LOW=13, HIGH=15
- MID = (13+15)/2 = **14**
- A[14] = **89**
- 89 == 89 → **FOUND at index 14** ✓

**Summary Table:**

| Iteration | LOW | HIGH | MID | A[MID] | Comparison | Direction |
|-----------|-----|------|-----|--------|------------|-----------|
| 1         | 1   | 15   | 8   | 61     | 61 < 89    | Right →   |
| 2         | 9   | 15   | 12  | 76     | 76 < 89    | Right →   |
| 3         | 13  | 15   | 14  | 89     | 89 == 89   | **Found** |

**Element 89 found at index 14 in just 3 comparisons!**
**Time Complexity:** O(log n)

---

## Question 8

### (a) Distinguish between internal sorting and external sorting. [08]

| Feature | Internal Sorting | External Sorting |
|---|---|---|
| **Definition** | Sorting where all data fits in main memory (RAM) | Sorting where data is too large for RAM; stored in external storage (disk) |
| **Storage used** | Main memory (RAM) only | External storage (hard disk, tapes) |
| **Speed** | Fast — direct memory access | Slow — disk I/O is much slower than RAM |
| **Data size** | Small to medium datasets | Very large datasets |
| **Algorithms** | Bubble, Insertion, Selection, Quick, Merge, Heap Sort | Merge Sort variants (External Merge Sort), Polyphase Sort |
| **Complexity** | Based on comparisons and swaps | Based on I/O operations (disk reads/writes) |
| **Example** | Sorting 10,000 records in RAM | Sorting 10 million records from a database file |
| **Cost factor** | CPU time | Disk access time (I/O cost) |

**Key Point:** External sorting typically uses **multi-way merge** where data is divided into sorted "runs" stored on disk, which are then merged together.

---

### (b) Explain double hashing method with example. [08]

**Double Hashing:**
Double hashing is a collision resolution technique that uses **two hash functions**.

When a collision occurs, instead of moving to the next slot (linear probing), we jump a distance determined by a **second hash function**.

**Formula:**
```
h(k, i) = (h1(k) + i * h2(k)) mod TABLE_SIZE
```
- `h1(k)` = primary hash function
- `h2(k)` = secondary hash function (determines step size)
- `i` = probe number (0, 1, 2, ...)

**Common choice:**
```
h1(k) = k mod TABLE_SIZE
h2(k) = R - (k mod R)   where R is a prime < TABLE_SIZE
```

**Why better than linear probing?**
Linear probing causes **primary clustering** (long chains of occupied slots). Double hashing avoids this by using a different step size for each key.

**Example:**
- TABLE_SIZE = 7, R = 5
- `h1(k) = k mod 7`
- `h2(k) = 5 - (k mod 5)`

Insert keys: **18, 41, 22**

| Key | h1(k) | h2(k) | Probe 0 (i=0) | Result |
|-----|-------|-------|----------------|--------|
| 18  | 18 mod 7 = **4** | — | 4 → free | Stored at **4** |
| 41  | 41 mod 7 = **6** | — | 6 → free | Stored at **6** |
| 22  | 22 mod 7 = **1** | — | 1 → free | Stored at **1** |

No collision in this example. Let's add a collision:

Insert **25:** h1(25) = 25 mod 7 = **4** → occupied!
- h2(25) = 5 - (25 mod 5) = 5 - 0 = **5**
- Probe 1: (4 + 1×5) mod 7 = 9 mod 7 = **2** → free → Store at **2**

---

### (c) Perform DFS traversal on the given undirected graph starting from vertex 1. List vertices and draw DFS tree. [09]

**Graph:**
Vertices: 1, 2, 3, 4, 5, 6
Edges (from figure): 1-2, 1-5, 1-6, 2-3, 2-5, 3-4, 3-5, 4-5

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
Visit 1 → push neighbors: go to 2
Visit 2 → push neighbors: go to 3
Visit 3 → push neighbors: go to 4
Visit 4 → push neighbors: go to 5
Visit 5 → all neighbors (1,2,3,4) already visited → backtrack
Backtrack to 4 → done
Backtrack to 3 → done
Backtrack to 2 → done
Backtrack to 1 → go to 6
Visit 6 → done
```

**DFS Traversal Sequence:** `1 → 2 → 3 → 4 → 5 → 6`

**DFS Tree:**
```
        1
       /|\
      2  5  6
      |
      3
      |
      4
      |
      5 (already visited, shown as back edge)
```

Simplified DFS tree (tree edges only):
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

**Graph edges (from figure):**
```
V1-V2: 3,  V1-V4: 5
V2-V3: 7,  V2-V4: 2,  V2-V5: 6
V3-V5: 10, V3-V6: 2
V4-V5: 3,  V4-V7: 2
V5-V6: 7,  V5-V7: 5,  V5-V8: 5
V6-V8: 6
V7-V8: 4
```

**Prim's Algorithm:**
Start from a vertex. At each step, add the cheapest edge that connects a visited vertex to an unvisited vertex.

**Step-by-Step:**

| Step | Visited Set | Edges available | Cheapest edge | MST Edge Added |
|------|-------------|-----------------|---------------|----------------|
| Start | {V1} | V1-V2(3), V1-V4(5) | **V1-V2 = 3** | V1-V2 |
| 2 | {V1,V2} | V1-V4(5), V2-V3(7), V2-V4(2), V2-V5(6) | **V2-V4 = 2** | V2-V4 |
| 3 | {V1,V2,V4} | V1-V4 skip, V4-V5(3), V4-V7(2), V2-V3(7), V2-V5(6) | **V4-V7 = 2** | V4-V7 |
| 4 | {V1,V2,V4,V7} | V4-V5(3), V2-V3(7), V2-V5(6), V7-V8(4) | **V4-V5 = 3** | V4-V5 |
| 5 | {V1,V2,V4,V5,V7} | V7-V8(4), V5-V3(10), V5-V6(7), V5-V8(5), V2-V3(7) | **V7-V8 = 4** | V7-V8 |
| 6 | {V1,V2,V4,V5,V7,V8} | V5-V3(10), V5-V6(7), V8-V6(6), V2-V3(7) | **V8-V6 = 6** | V8-V6 |
| 7 | {V1,V2,V4,V5,V6,V7,V8} | V6-V3(2), V2-V3(7), V5-V3(10) | **V6-V3 = 2** | V6-V3 |

All 8 vertices visited with 7 edges.

**Minimum Spanning Tree Edges:**

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

**MST Structure:**
```
V3 - V6 - V8 - V7 - V4 - V2 - V1
               |         |
               V5        (V2-V4 connects here)
```

---

*End of Answer Script — CSE 2101 Data Structure*
*Chandpur Science and Technology University, 2024*
