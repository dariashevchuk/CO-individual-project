# FrogShopping — Greedy BFS Coverage Optimization

## Overview
**FrogShopping** is a combinatorial optimization problem where the goal is to choose optimal locations for “frog shops” on a graph so that every node is within a specified distance `D` of at least one shop.

The solution uses a **greedy Breadth-First Search (BFS)** strategy called *Pick and Cover*.  
This approach ensures full coverage of the graph while maintaining good runtime efficiency, even for large datasets.

The project was implemented and tested as part of a competitive programming task and achieved a score of **98.22 points**, outperforming multiple benchmark solutions.

---

## Problem Description
Given:
- A graph with `N` nodes and `M` edges
- A distance limit `D`

Find:
- The smallest possible set of nodes where frog shops should be placed so that every node in the graph is **within distance D** from at least one shop.

**Input format:**
N M
a1 b1
a2 b2
...
aM bM
D

lua
Copy code

**Output format:**
K
v1 v2 ... vK

Where `K` is the number of shops and `v1, v2, ... vK` are their positions.

---

## Algorithm Design

### 1. Greedy BFS ("Pick and Cover")
The algorithm iterates through all nodes:
1. If a node is **not covered**, place a frog shop at that node.
2. Run a **BFS** starting from this node to mark all nodes within distance `D` as *covered*.
3. Continue until all nodes in the graph are covered.

### 2. Data Structures
- **Adjacency list** for graph storage — efficient for sparse graphs  
- **Queue** for BFS traversal  
- **Boolean array `covered[]`** to mark visited or already-covered nodes  
- **Distance array `dist[]`** to control BFS depth and limit to distance `D`

### 3. Complexity
- Worst-case time complexity: `O(N * (N + M))`  
- In practice, each BFS covers many nodes, so the number of BFS calls is much smaller than `N`.
- Space complexity: `O(N + M)`

---

## Implementation Details
The program:
- Reads input values (`N`, `M`, edges, and `D`).
- Builds an adjacency list representation of the graph.
- Runs the greedy BFS loop.
- Outputs the number of frog shops and their indices.

The implementation is efficient, clean, and avoids unnecessary data structures — relying only on standard containers (`vector`, `queue`, `bool` arrays).

---

## Example

**Input:**
6 5
0 1
1 2
2 3
3 4
4 5
2

**Output:**
2
0 3


## Explanation:  
Shops are placed at nodes 0 and 3.  
All nodes are within distance 2 of at least one shop.

---

## Evaluation
- Guarantees full graph coverage  
- Simple, fast, and easy to implement  
- Does not always produce the absolute minimum number of shops, but gives a near-optimal result in practice  
- Scored **98.22 points** on Optil.io

---

## Code Highlights
- Efficient BFS-based coverage expansion
- Greedy node selection strategy
- Clear structure with minimal memory footprint

---

## Results
- Approach: Greedy + BFS (coverage optimization)
- Performance: Fast for large graphs, near-optimal accuracy
- Optil.io score: 98.22 / 100
- Author: Dariia Shevchuk (dashashevchuk)
