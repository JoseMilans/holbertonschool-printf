# A Custom 'C - printf' Version
## Our First Project in C Programming Language
***
## Table of Contents
1. [About Our Project](#about-our-project)
2. [Showcase](#showcase)
	* [Handling Edge Cases](#handling-edge-cases)
3. [Flowchart](#flowchart)
4. [Helpful Resources](#helpful-resources)
5. [Project Guidelines](#project-guidelines)
6. [Developers](#developers)
***
## About Our Project
##### Ever wondered what happens when you use printf in your C program? We did too! So, we made our own version of it, which we named _printf. This function takes a format string and prints it to the console, similar to printf but simpler and beginner-friendly.
![Pic](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTxtBoAQG-ycgK4yi6LJ9DH-VkRj6lsFT8rGA&usqp=CAUi)
***
## Showcase
Here is a quick demonstration of _printf in action:

```
 _printf("Hello, there!");
```

* $ Hello, there!

```
_printf("Sum of 1 and 1 is %d", 1+1);
```

* $ Sum of 1 and 1 is 2

```
_printf("My name is %s, I'm %d years old and I've given it my 100%%.", "Jose", 35);
```

* $ My name is Jose, I'm 35 years old and I've given it my 100%.

### Handling Edge Cases
Here are some special cases our `_printf` function can handle:

1. **NULL format string:**  
    ```c
    int main(void)
    {
        int i = _printf(NULL);
        printf("Returned: %d\n", i);
        return (0);
    }
    ```
2. **Incomplete format specifier:**  
    ```c
    int main(void)
    {
        int i = _printf("Incomplete format specifier, %\n");
        printf("Returned: %d\n", i);
        return (0);
    }
    ```

3. **Unknown format specifier:**  
    ```c
    int main(void)
    {
        int i = _printf("Unknown format specifier, %j\n");
        printf("Returned: %d\n", i);
        return (0);
    }
    ```

4. **Invalid arguments for format specifiers:**  
    ```c
    int main(void)
    {
        int i = _printf("Invalid argument: %d\n", "string");
        printf("Returned: %d\n", i);
        return (0);
    }
    ```

5. **Mismatch between format specifiers and passed arguments:**  
    ```c
    int main(void)
    {
        int i = _printf("Mismatch: %d %d\n", 1988);
        printf("Returned: %d\n", i);
        return (0);
    }
    ```
***
## Flowchart
![Alt text](https://github.com/JoseMilans/holbertonschool-printf/blob/main/diagdrawio.png)
## Helpful Resources
Need help? Check out our manual page for _printf!
```
$ man ./man_3_printf
```
***
## Project Guidelines

### Tasks

#### 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
Write a function that produces output according to a format.
* Prototype: int /_printf(const char *format, ...);
* Returns: the number of characters printed (excluding the null byte used to end output to strings)
* write output to stdout, the standard output stream
* format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
* * c
* * s
* * %
* You don’t have to reproduce the buffer handling of the C library printf function
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers
##### Repo: 
* GitHub repository: printf

#### 1. Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:
* d
* i
* You don’t have to handle the flag characters
* You don’t have to handle field width
* You don’t have to handle precision
* You don’t have to handle the length modifiers
##### Repo: 
* GitHub repository: holbertonschool-printf

#### 2. Just because it's in print doesn't mean it's the gospel
Create a man page for your function.
##### Repo: 
* GitHub repository: holbertonschool-printf
* File: man_3_printf
***
## Developers
* Jose Milans
* Jose Gil
