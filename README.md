# holbertonschool-printf

C printf Project by the Joses (Gil_Milans)

main.h

The header file for our programme. It includes the necessary library inclusions as well as the function prototypes for our _printf function and other auxiliary functions (print_handlers.c). 
The typedef statement defines a new data type, specifier_t, which is a structure that holds a character that represents the format specifier, such as c, s, etc. and a function pointer that takes a va_list and returns an int. This structure is used to create an array of structures in the _printf function implementation.

print_handlers.c

This file contains the implementations of functions that handle the printing of different data types. Each function takes a variadic argument list (va_list) and returns an integer. The specifier_s struct is used to hold a format specifier (a string) and a function pointer (to a function that takes a va_list and returns an int). This structure allows us to associate each format specifier (like "c", "s", or "%") with the appropriate function to handle that type of argument.
In the _printf function, we create an array of these structs to handle the different format specifiers. We can easily extend this array to add more format specifiers in the future, which is one of the advantages of this design.

_printf.c

This file contains the implementation of the _printf function, which takes a format string and a variable number of arguments. A variadic function _printf is defined, which can take any number of arguments. Inside the function, we loop over the characters of the format string. If the character is not a %, it's printed directly to the standard output. If it is a %, we call the handle_format function.
In handle_format function, we have an array of structures, where each structure has a format specifier and a corresponding function pointer. We loop through this array and check if the next character in the format string matches any of the format specifiers. If it does, we call the corresponding function.
