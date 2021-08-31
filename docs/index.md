---
title: "AdMU ProgVar Team Notebook"
description: "A collection of algorithms, data structures and other useful information for competitive programming."
---

## Contents

### 1. Data Structures
- Fenwick Tree
- Leq Counter
- Misof Tree
- Mo's Algorithm
- Ordered Statistics Tree
- Segment Tree
- Sparse Table
- Splay Tree
- Treap
- Union Find
- Unique Counter

### 2. Dynamic Programming
- Dynamic Convex Hull Trick
- Divide and Conquer Optimization

### 3. Geometry
- Dots and Cross Products
- Angles and Rotations
- Spherical Coordinates
- Point Projection
- Great Circle Distance
- Point/Line/Plane Distances
- Intersections
- Polygon Areas
- Polygon Centroid
- Convex Hull
- Delaunay Triangulation
- Point in Polygon
- Cut Polygon by a Line
- Triangle Centers
- Convex Polygon Intersection
- Pick's Theorem for Lattice Points
- Minimum Enclosing Circle
- Shamos' Algorithm
- kD Tree
- Line Sweep (Closest Pair)
- Line Upper/Lower Envelope
- Formulas

### 4. Graph
- Single-Source Shortest Paths
- All-Pairs Shortest Paths
- Strongly Connected Components
- Minimum Mean Weight Cycle
- Biconnected Components
- Minimum Spanning Tree
- Euler Path/Cycle
- Bipartite Matching
- Maximum Flow
- Minimum Cost Maximum Flow
- Minimum Arborescence
- Blossom Algorithm
- Maximum Density Subgraph
- Maximum-Weight Closure
- Maximum Weighted Ind. Set in a Bipartite Graph
- Synchronizing Word Problem
- Max Flow with Lower Bounds on Edges
- Tutte Matrix for General Matching
- Heavy Light Decomposition
- Centroid Decomposition
- Least Common Ancestor
- Counting Spanning Trees
- Erdos-Gallai Theorem
- Tree Isomorphism

### 5. Math I - Algebra
- Generating Function Manager
- Fast Fourier Transform
- FFT Polynomial Multiplication
- Number Theoretic Transform
- Polynomial Long Division
- Matrix Multiplication
- Matrix Power
- Fibonacci Matrix
- Gauss-Jordan/Matrix Determinant

### 6. Math II - Combinatorics
- Lucas' Theorem
- Granville's Theorem
- Derangements
- Factoradics
- kth Permutation
- Catalan Numbers
- Stirling Numbers
- Partition Function

### 7. Math III - Number Theory
- Number/Sum of Divisors
- Mobius Inversion
- GCD Subset Counting
- Euler Totient Function
- Extended Euclidean Algorithm
- Modular Exponentiation
- Modular Inverse
- Modulo Solver
- Linear Diophantine
- Chinese Remainder Theorem
- Primitive Root
- Josephus
- Number of Integer Points under a Line

### 8. Numerical Methods
- Fast Square Testing
- Simpson Integration

### 9. Strings
- Knuth-Morris-Pratt
- Trie
- Suffix Array
- Longest Common Prefix
- Aho-Corasick
- Palindromes
- Z Algorithm
- Booth's Minimum String Rotation
- Hashing

### 10. Other Algorithms
- 2SAT
- DPLL Algorithm
- Stable Marriage
- Cycle-Finding
- Longest Increasing Subsequence
- Dates
- Simulated Annealing
- Simplex
- Fast Input Reading
- 128-Bit Integer
- Bit Hacks

### 11. Miscellaneous
- Debugging Tips
- Solution Ideas

### 12. Formulas
- Physics
- Markov Chains
- Burnside's Lemma
- Bezout's Identity
- Misc

### 13. Other Combinatorics Stuff
- The Twelvefold Way

---

## ReadMe

### How to contribute:
- clone this repository using `git clone https://github.com/leloykun/admu-progvar-notebook.git`
- add codes to the folder `/code` and edit `notebook.tex`
- install latex with `sudo apt install texlive-full` (warning: this could take up 5Gb of space)
- install `Pygments` with `pip3 install Pygments` or `pip install Pygments`
- run `makefile.sh`
- submit a pull request
- ...
- profit

### (sub)(sub)Section Syntax:
- <span style="color:red">Red</span>: copy-pasted / non-tested code
- <span style="color:black">Black</span>: no code yet
- To color a (sub)(sub)section, simple use `(sub)(sub)section(COLOR)`
    - For example, `subsectionBlack` gets you a black-colored subsection

### Todo
- Add layout.txt
- Add tests
- Automate testing and building docs with GitHub Actions
- Clean up Geometry section
- Add implementation of:
  - Dominator Tree
  - Fast Matrix Inverse in `F_2`
