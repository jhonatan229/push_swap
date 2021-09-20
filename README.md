# push_swap

In this project, i starting my learning in the lists and arrays, see the principles of a stack and how work with then.

the goal of the project is sort a list of integer numbers and print in the terminal, the instruction used.

>This project was made to sort the list with as few instructions as possible

## The instructions
For this project, I can't manipulate the list, taking any position I want, otherwise it would be easy, because on the internet there are so many 'sorting algorithms'.So i have a coupe of instructions that i use to sort the list, i use a auxiliar list calls "list B", that is empty and will help me sort the first list, calls "list A".

|instruction | description|
|-----|-----|
|sa| Swap A - swap the first 2 elements at the top of stack A.|
|sb| Swap B - swap the first 2 elements at the top of stack B.|
|pa| Push A - take the first element at the top of B and put it at the top of A.|
|pb| Push B - take the first element at the top of A and put it at the top of B.|
|ra| Rotate A - shift up all elements of stack a by 1. The first element becomes the last one.|
|rb| Rotate B - shift up all elements of stack a by 1. The first element becomes the last one.|
|rra| Reverse rotate A - shift down all elements of stack a by 1. The last element becomes the first one.|
|rrb| Reverse rotate B - shift down all elements of stack a by 1. The last element becomes the first one.||

>There is more rules like, the numbers must be different, cannot be bigger than MAX INT and less than MIN INT.

## The algorithm
for sort the list with the length bigger than 5, i use a algorithm with some steps and with the concept of chunks:  
* Step 1: I find the first 25 smallest numbers, this numbers will make my chunk, and i find the biggest number into this chunk.
* Step 2: I verify the position of each number that is into the chunk and take the number that is more close of the top of the list, and i make 'ra' or 'rra' to put this number to top of the list.
* Step 3: I prepare list b for the coming of a new number by putting at the top of list b the number that is less than the number to come and that comes closest to the next number, the **perfect match.**
* Go back to step 2 until the block is empty, when that happens and still have numbers in the list A, go back to step 1 and do it all over again.
* When the list A is empty, put the biggest number of list b at the top and make 'pa' until the list b is empty.

And that is how the magic works!!

## How to use!
first clone the repository, get in it, write "make" in the terminal, this will create a execute file calls "push_swap", then just execute him with the numbers tha you wish, ex:
```shell
./so_long 45 53 6 23 1
```
>if the numbers already sort, the project just end.