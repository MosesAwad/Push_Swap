This 42 School project involves coming up with an algorithm to sort a random sequence of numbers in ascending order. 
Inside the program, the random numbers are assigned as elements of a stack data structure (in the C language) and thus, the sorting algorithm is limited to just rotate, swap, and push operations.
This means that we can only rotate the elements of a stack, swap the top two elements, or push the top element from one stack to another. Another stack (which is empty initially) is used
as a temporary storage unit for the numbers to aid in the sorting process. 

The allowed operations are:
  sa (swap a): Swap the first 2 elements at the top of stack a.
  Do nothing if there is only one or no elements.
  
  sb (swap b): Swap the first 2 elements at the top of stack b.
  Do nothing if there is only one or no elements.
  
  ss : sa and sb at the same time.
  
  pa (push a): Take the first element at the top of b and put it at the top of a.
  Do nothing if b is empty.
  
  pb (push b): Take the first element at the top of a and put it at the top of b.
  Do nothing if a is empty.
  
  ra (rotate a): Shift up all elements of stack a by 1.
  The first element becomes the last one.
  
  rb (rotate b): Shift up all elements of stack b by 1.
  The first element becomes the last one.
  
  rr : ra and rb at the same time.
  
  rra (reverse rotate a): Shift down all elements of stack a by 1.
  The last element becomes the first one.
  
  rrb (reverse rotate b): Shift down all elements of stack b by 1.
  The last element becomes the first one.
  
  rrr : rra and rrb at the same time

The main idea behind the algorithm implement in this code is 
