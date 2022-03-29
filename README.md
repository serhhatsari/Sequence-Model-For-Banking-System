# Sequence-Model-For-Banking-System

Sequence model for banking system implemented by using Structs in C.

The bank has five type of customer, which are labelled as 0, 1, 2, 3, 4.
Each customer’s construct must include Name, Age and Labels.
These labels showed us customer’s job. 0 is employee, 1 is retired, 2 is student, 3 is unemployed and 4 is other.
Label 0 has the highest priority, then 1, 2, 3, 4 have the lower priorities respectively.

Banking system keeps maximum 50 customer in same time.

To prevent starvation when occur 0 labelled customers comes continuously, each type of customer
has limitations like this: 0 label customer can join 5 times in a row, 1 label customer can join 3 times
in row, 2 label customer can join 3 times in a row, 3 label customer can join 2 times in a row, 4 label
customer can join 2 times in a row.

User can add a customer to the sequence.
User can process the first customer in the sequence.


You should be able to compile and run the program in linux environment.

In order to compile to program, enter the command : "make" in the terminal

In order to run the program, enter the command "./bank" in the terminal
