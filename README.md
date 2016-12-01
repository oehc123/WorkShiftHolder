# WorkShiftHolder

Work shift C++ 	program
By Jose Sandoval
This project showcase some of my C++ concepts with respect to
•	Objects
•	Array pointers that grows Dynamically
•	Basic Algorithms
•	Call by references functions
•	Memory management
•	Use of header and cpp files
Two major objects are created:
1.	Time object: holds a regular time with such hours and minutes. Its attributes are Hour and Minutes.
•	Default constructor and parameterized constructor
•	Getter and setter methods that are called by reference
•	Private wrapped function to wrap hours and minutes to their respective values (hours < 24, minutes < 60)

2.	WorkWeek object: holds the start and end time of a work shift. Its attributes are two pointer arrays to Time objects (array references are stored in the stack memory, while the objects are stored in the heap memory); and two integers. One that stores the size of the array, and one that stores the current index of the array

•	Parameterized constructor and copy constructor. It creates a start and an end time array with the size of the parameter given. The copy constructor creates deep copies of the parameter given
•	It can add shifts by providing starting time, and duration of the shift
If the arrays are full when a new shift is trying to be added, the program will dynamically create two new arrays double the previous size, and will delete the previous arrays deeply to free memory accordingly
•	It produces the total amount of hours stored in its arrays
