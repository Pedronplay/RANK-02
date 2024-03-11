# Push Swap: A Sorting Challenge

The push swap project at 42 presents students with a challenging task: to sort a random list of integers using two stacks and a limited set of operations. Here's an overview of the project requirements and guidelines:

## About

The push swap project at 42 offers students an opportunity to explore sorting algorithms and their implementation in C. Tasked with devising their version of a sorting algorithm, students delve into various techniques to efficiently rearrange integers within a stack while adhering to specific rules.

This project encourages students to explore different sorting strategies. Additionally, students often discover and implement optimization strategies to minimize the number of operations required for sorting.


## Challenge Overview

- **Goal:** Sort a random list of integers with the smallest number of moves.
- **Tools:** Two stacks, stack A and stack B, and a set of operations.
- **Allowed Moves:**
  - `sa`: Swap the first 2 elements at the top of stack A.
  - `sb`: Swap the first 2 elements at the top of stack B.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa`: Push the first element at the top of stack B to stack A.
  - `pb`: Push the first element at the top of stack A to stack B.
  - `ra`: Rotate stack A - shift up all elements by 1.
  - `rb`: Rotate stack B - shift up all elements by 1.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra`: Reverse rotate stack A - shift down all elements by 1.
  - `rrb`: Reverse rotate stack B - shift down all elements by 1.
  - `rrr`: Perform `rra` and `rrb` simultaneously.
- **End Condition:** Stack B must be empty, and all integers must be sorted in ascending order on stack A.

## Project Structure

- **Argument Parsing:** Both checker and push_swap programs can receive input arguments in multiple formats, such as command line arguments or reading from standard input. These arguments are parsed to ensure validity and consistency.
- **Argument Verification:** Upon receiving input arguments, the programs verify them for correctness, checking for empty strings, non-numeric parameters, duplicates, and invalid instructions.
- **Stack Insertion:** The integers provided in the input arguments are inserted into stack_a, utilizing custom-defined structures to represent the stacks efficiently.
- **Move Generation:** The push_swap program uses a series of moves that will be utilized by the end algorithm to efficiently sort the integers within the stacks. These moves involve pushing, swaping, rotating and reverse rotating elements between the two stacks.
- **Algorithm Design:** The process includes designing algorithms for sorting the intergers passed in efficiently.



## How The Algorithm Works

The main push swap algorithm i used in this project, the one i decided to call **Big sort** was inspired in a video explaation i found online [(this is the link to the video)](https://www.youtube.com/watch?v=wRvipSG4Mmk). Here's a breakdown of its key steps:

1. **Sort 3:**
    - This step works by swapping or reverse swapping so the largest number goes to the end, and then swaps if the first two are not in the correct position.

2. **Sort 5:**
    - The algorithm sorts a stack of five integers by first moving the minimum and maximum values to a temporary stack. Then, it sorts the remaining three integers using the sort_three function. Afterward, it moves all elements from the temporary stack back to the original stack, ensuring the correct order. Finally, it adjusts the order if necessary to ensure the stack is fully sorted.

3. **Big Sort:**
    - **Push 2 numbers from STACK_A:** To begin, two numbers are pushed from the top of STACK_A to STACK_B without any checks. This step sets the initial conditions for further sorting.
    - **Find the cheapest number:** The algorithm evaluates each integer in STACK_A to determine the cheapest option for pushing into STACK_B. For each value in stack_a, it searches for its target in stack_b. **The target** is the smallest closest number, or if there isn't any smallest number, the biggest number. And the **cheapest** is the one that requires fewer moves to be in the right position to be sent to STACK_B.
    - **Last three elements:** When there are only 3 elements left in STACK_A the function **sort_3** is used  to sort this stack. 
    - **Pushing back to STACK_A:** Next, the algorithm pushes all numbers from STACK_B back to STACK_A. Before pushing each number, it ensures the correct position of the element in STACK_B and its target. For each value in the stack_b, it searches for its target in stack_a. **The target** when moving from stack b to a is the biggest closest number, or if there isn't any bigger number, the smallest number. And the **cheapest** is the one that requires fewer moves to be in the right position to be sent to STACK_A.
    - **Final arrangement:** Finally, the algorithm ensures that the minimum number is positioned at the top of STACK_A, indicating that the stack is sorted.


   By understanding and implementing this algorithm, students can achieve a full score in the push swap project, demonstrating mastery of sorting techniques and algorithmic thinking.

---

##

## Visual demosntration of the algorith working
