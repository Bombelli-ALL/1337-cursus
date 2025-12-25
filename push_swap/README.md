This project has been created as part of the 42 curriculum by alerradi.

🗣️ Description
Push_swap is a strictly algorithmic project at 42 School. The goal is to sort data on a stack using a limited set of instructions (sa, sb, pa, pb, ra, rb, rr, rra, rrb, rrr) with the lowest possible number of operations.

This project involves manipulating various sorting algorithms and choosing the most appropriate solution for optimized data sorting. The program outputs a series of instructions that, when executed, result in a sorted stack.

🎓 Educational Value: Data Structures & AI Foundation
This project is a critical milestone for building a strong engineering mindset, specifically for Data Structures and Machine Learning:

Deepening Data Structure Knowledge: By strictly adhering to the Stack (LIFO) data structure and manipulating data via a limited instruction set, this project enforces a deep understanding of memory management, pointer manipulation (linked lists), and algorithmic constraints.

Precursor to Machine Learning Optimization: Push_swap is fundamentally an optimization problem. Just as Machine Learning models strive to minimize a "Loss Function" (error), this algorithm strives to minimize the "Cost Function" (number of operations). Developing heuristics (like the "Chunks" method) to approximate an optimal solution is the same logic used in AI search algorithms (like A*) and Reinforcement Learning strategies.

Key Constraints:

Stack A: Contains a random set of negative and positive duplicate-free numbers.

Stack B: Initially empty.

Goal: Sort numbers in Stack A in ascending order.

Mathematical implamaentation 

In standard Push_swap (2 stacks), we balance the cost of Searching Stack A vs. Sorting Stack B.If we have many stacks (let's say K total stacks, so 1 Source Stack A and K-1 Auxiliary Stacks), the equation changes because we can "parallelize" the sorting logic.

1. The Variables
	N: Total numbers to sort.
	R: The range (Chunk Size) for one auxiliary stack.
	M: Number of auxiliary stacks (M = K - 1).
		Example: If you have 5 stacks total, M = 4 target stacks.

2. The Equation for Many Stacks
The new cost function becomes:

							 COST(total) ~= N / 2(M.R) + R / 2;

Why?
Phase 1: Searching Stack A (The "Wide Net" Effect)In the 2-stack version, you look for a single chunk of size R.With $M$ stacks, you can simultaneously look for numbers belonging to any of the M stacks.
Total "Target" Size: M * R.
Probability of finding a number: Increases by M times.
Cost: The expected rotations to find a number in A drops significantly:

							 COST(total) ~= N / 2(M.R);

Phase 2: Insertion (The "Bucket" Cost) Once you find a number in A, you push it to its specific stack (say, Stack C). You still need to rotate Stack C to put it in the correct "V-Shape" spot.

  This cost depends only on the local chunks of that specific stack.
	Cost: Remains roughly proportional to the local range:

							 COST(total) ~= R / 2;

FINAL :chunk 
							R = √N/k-1
k : number of stack(2)
							R = √N

Efficiency: The complexity shifts from roughly O(N √N) towards $O(N \log_K N)$ because you are effectively performing a Radix Sort (base $K$) or a multi-way Merge Sort.

🛠️ Instructions

Clone the repository:
	git clone <repository_url> push_swap

	cd push_swap

Compile the Mandatory Part (push_swap):

	make

Compile the Bonus Part (checker):

	make bonus

Clean up object files:

	make clean

Full clean (objects + executables):

	make fclean


Usage:
Running the Checker (Bonus) The checker reads instructions from the standard input (stdin) and verifies if the stack is sorted. You can pipe the output of push_swap into checker:

	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

OK: The stack is sorted.

KO: The stack is not sorted.

Error: Invalid input or instructions.

📚 Resources

ReferencesSorting Algorithms: Studied various complexity classes ($O(N^2)$ vs $O(N \log N)$).

https://www.youtube.com/watch?v=yndgIDO0zQQ&t=2146s

https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/

🧠 Implementation Details

The "Range Sort" Algorithm (Chunks)

This project uses a custom algorithm optimized for 100 and 500 numbers:

Phase 1 (A to B): We scan Stack A for numbers belonging to a specific "range" or chunk size (approx. 30 for 500 numbers).

Numbers are pushed to B (pb).

If the number is in the lower half of the range, we rotate B (rb) to send it to the bottom.

This creates a "V-Shape" (hourglass) distribution in Stack B, keeping extreme values accessible.

Phase 2 (B to A): We simply push elements back to A in sorted order (Greedy strategy), finding the maximum element in B and moving it to the top.