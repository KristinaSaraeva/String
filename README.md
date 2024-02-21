# String

## Description

Implementation of string.h library in C.

`_memchr_` searches an array for the first occurrence of a character
_memcmp_ compares two buffers
_memset_ fills a buffer with a character
_memcpy_ copies one buffer to another
_memmove_ moves one buffer to another

_strcpy_ copies one string to another
_strncpy_ copies a certain amount of characters from one string to another
_strcat_ concatenates two strings
_strncat_ concatenates a certain amount of characters of two strings
_strcmp_ compares two strings

_strncmp_ compares a certain amount of characters of two strings
_strchr_ finds the first occurrence of a character
_strrchr_ finds the last occurrence of a character
_strspn_ returns the length of the maximum initial segment that consists
of only the characters found in another byte string
_strcspn_ returns the length of the maximum initial segment that consists
of only the characters not found in another byte string

_strpbrk_ finds the first location of any character in one string, in another string
_strstr_ finds the first occurrence of a substring of characters
_strtok_ finds the next token in a byte string
_strlen_ returns the length of a given string
_strerror_ returns a text version of a given error code

Also implements string processing functions from the String class in C#

_void_ *to_upper(const char *str)
Returns a copy of string (str) converted to uppercase. 

_void_ *to_lower(const char *str) Returns a copy of string (str) converted to lowercase. 

_void_ *insert(const char *src, const char *str, size_t start_index)
Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). 

_void_ *trim(const char *src, const char *trim_chars)
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
