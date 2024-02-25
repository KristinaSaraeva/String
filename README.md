# String

## Description

Implementation of string.h library in C.

`memchr` searches an array for the first occurrence of a character
`memcmp` compares two buffers
`memset` fills a buffer with a character
`memcpy` copies one buffer to another
`memmove` moves one buffer to another

`strcpy` copies one string to another
`strncpy` copies a certain amount of characters from one string to another
`strcat` concatenates two strings
`strncat` concatenates a certain amount of characters of two strings
`strcmp` compares two strings

`strncmp` compares a certain amount of characters of two strings
`strchr` finds the first occurrence of a character
`strrchr` finds the last occurrence of a character
`strspn` returns the length of the maximum initial segment that consists
of only the characters found in another byte string
`strcspn` returns the length of the maximum initial segment that consists
of only the characters not found in another byte string

`strpbrk` finds the first location of any character in one string, in another string
`strstr` finds the first occurrence of a substring of characters
`strtok` finds the next token in a byte string
`strlen` returns the length of a given string
`strerror` returns a text version of a given error code

Also implements string processing functions from the String class in C#

`void *to_upper(const char *str)`
Returns a copy of string (str) converted to uppercase. 

`void *to_lower(const char *str)` Returns a copy of string (str) converted to lowercase. 

`void *insert(const char *src, const char *str, size_t start_index)`
Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). 

`void *trim(const char *src, const char *trim_chars)`
Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed.


All the functions are covered with unit tests.

## Getting Started

### Dependencies

- MacOS or Linux
- C++17 compiler

### Installing

1. Clone this repository to your local machine.
2. Run: `make` in the terminal when in the the project directory and compile the lib.
3. Now you can link it to your project.
4. For other targets check Makefile.
