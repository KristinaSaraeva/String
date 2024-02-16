#include "my_string.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1
void *my_memchr(const void *str, int c, my_size_t n) {
  unsigned char *is_char = MY_NULL;
  unsigned char *p = (unsigned char *)str;
  while ((str != MY_NULL) && (n--)) {
    if (*p != (unsigned char)c) {
      p++;
    } else {
      is_char = p;
      break;
    }
  }
  return is_char;
}

// 2
int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  my_size_t i = 0;
  int exit_flag = 0;

  for (i = 0; i < n; i++) {
    unsigned char c1 = ((unsigned char *)str1)[i];
    unsigned char c2 = ((unsigned char *)str2)[i];

    if (c1 != c2) {
      if (c1 < c2) {
        // c1 = (int)c1;
        exit_flag = -1;
        break;
      }
      // c2 = (int)c2;
      exit_flag = 1;
      break;
    }
  }
  return exit_flag;
}

// 3
void *my_memcpy(void *destination, const void *source, my_size_t num) {
  unsigned char *src = (unsigned char *)source;
  unsigned char *dst = (unsigned char *)destination;

  my_size_t i = 0;

  for (i = 0; i < num; i++) {
    const unsigned char value = src[i];
    dst[i] = value;
  }

  return destination;
}

// 4
void *my_memmove(void *dest, const void *src, my_size_t n) {
  char *dest_str = (char *)dest;
  const char *source_str = (const char *)src;

  char *temp_str = (char *)malloc(sizeof(char) * n);
  if (source_str == MY_NULL) {
    return MY_NULL;
  } else {
    unsigned int i = 0;

    for (i = 0; i < n; ++i) {
      *(temp_str + i) = *(source_str + i);
    }

    for (i = 0; i < n; ++i) {
      *(dest_str + i) = *(temp_str + i);
    }
    free(temp_str);
  }
  return dest;
}

// 5
void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *s = (unsigned char *)str;

  for (my_size_t i = 0; i < n; i++) {
    s[i] = (unsigned char)c;
  }
  return str;
}

// 6
char *my_strcat(char *dest, const char *src) {
  my_size_t i, j;

  i = my_strlen(dest);

  for (j = 0; src[j] != '\0'; j++) {
    dest[i + j] = src[j];
  }

  dest[i + j] = '\0';

  return dest;
}

// 7
char *my_strncat(char *dest, const char *src, my_size_t n) {
  my_size_t i, j;

  i = my_strlen(dest);

  for (j = 0; src[j] != '\0' && j < n; j++) {
    dest[i + j] = src[j];
  }

  dest[i + j] = '\0';

  return dest;
}

// 8
char *my_strchr(const char *str, int c) {
  char *position = MY_NULL;
  while (*str && *str != (char)c) {
    str++;
  }
  int i = 0;
  if (str[i] == c) {
    position = (char *)(&str[i]);
  }
  return position;
}

// 9
int my_strcmp(const char *str1, const char *str2) {
  int i = 0;
  int exit_flag = 0;

  for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
    char c1 = str1[i];
    char c2 = str2[i];
    if (c1 != c2) {
      if (c1 < c2) {
        exit_flag = -1;
        break;
      }

      exit_flag = 1;
      break;
    }
  }
  return exit_flag;
}

// 10
int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  my_size_t i = 0;
  int exit_flag;

  for (i = 0; i < n; i++) {
    char c1 = ((char *)str1)[i];
    char c2 = ((char *)str2)[i];
    exit_flag = 0;

    if (c1 != c2) {
      if (c1 < c2) {
        exit_flag = -1;
        break;
      }
      exit_flag = 1;
      break;
    }
  }
  return exit_flag;
}

// 11
char *my_strcpy(char *dest, const char *src) {
  int i = 0;
  while (1) {
    dest[i] = src[i];

    if (dest[i] == '\0') {
      break;
    }

    i++;
  }

  return dest;
}

// 12
char *my_strncpy(char *dest, const char *src, my_size_t n) {
  char *c1 = (char *)src;
  char *c2 = (char *)dest;
  my_size_t i = 0;

  for (i = 0; i < n; i++) {
    const char value = c1[i];
    c2[i] = value;
  }

  return dest;
}

// 13
my_size_t my_strcspn(const char *str1, const char *str2) {
  unsigned int match = 0;

  if ((str1 == MY_NULL) || (str2 == MY_NULL)) return match;

  while (*str1) {
    if (my_strchr(str2, *str1)) {
      return match;
    } else {
      str1++;
      match++;
    }
  }
  return match;
}

// 14
char *my_strerror(int errno) {
#if __linux__
  static char name_error[256] = {0};

  if (0 <= errno && errno < SIZE_ERR_LINUX) {
    static char *list_name_error[] = ERRSTR_LINUX;
    my_strcpy(name_error, list_name_error[errno]);
  } else {
    my_sprintf(name_error, "Unknown error %d", errno);
  }
  return name_error;
#endif

#if __APPLE__

  static char name_error[256] = {0};
  if (0 <= errno && errno < SIZE_ERR_APPLE) {
    static char *list_name_error[] = ERRSTR_APPLE;
    my_strcpy(name_error, list_name_error[errno]);
  } else {
    sprintf(name_error, "Unknown error: %d", errno);
  }
  return name_error;
#endif
}
// 15
my_size_t my_strlen(const char *str) {
  int length = 0;
  if (str == 0) {
    return length;
  }

  while (1) {
    int i;
    i = length;
    char c = 0;
    c = str[i];

    if (c == 0) {
      break;
    }
    length++;
  }
  return length;
}

// 16
char *my_strpbrk(const char *str1, const char *str2) {
  if ((str1 == MY_NULL) || (str2 == MY_NULL)) return MY_NULL;
  while (*str1) {
    if (my_strchr(str2, *str1)) {
      return (char *)str1;
    } else {
      str1++;
    }
  }
  return MY_NULL;
}

// 17
char *my_strrchr(const char *str, int c) {
  char *position = MY_NULL;
  int end = my_strlen(str);
  for (int i = end; i >= 0; i--) {
    if (str[i] == c) {
      position = (char *)(&str[i]);
      break;
    }
  }
  return position;
}

// 18
my_size_t my_strspn(const char *str1, const char *str2) {
  my_size_t n;
  const char *p;
  for (n = 0; *str1; str1++, n++) {
    for (p = str2; *p && *p != *str1; p++) {
      // ;
    }
    if (!*p) break;
  }
  return n;
}

// 19
char *my_strstr(const char *haystack, const char *needle) {
  const char *str1 = (const char *)haystack;
  const char *str2 = (const char *)needle;

  int i = 0;
  for (i = 0; str1[i] != '\0'; i++) {
    int j = 0;
    for (j = 0;; j++) {
      char c1 = str1[i + j];
      char c2 = str2[j];

      if (c2 == '\0') {
        return (char *)&str1[i];
      }
      if (c1 == '\0') {
        return MY_NULL;
      }
      if (c1 != c2) {
        break;
      }
    }
  }
  return 0;
}

// 20
char *my_strtok(char *str, const char *delim) {
  static char *new_str = MY_NULL;

  if (str) {
    new_str = str;
    while (1) {
      char c = *new_str;
      bool is_delim = my_strchr(delim, c);
      if (c == '\0' || !is_delim) {
        break;
      }

      *new_str = '\0';
      *(new_str++);
    }
  }

  if (!*new_str) {
    return MY_NULL;
  }

  str = new_str;

  while (1) {
    char c = *new_str;
    bool is_delim = my_strchr(delim, c);
    if (c == '\0' || is_delim) {
      break;
    }
    ++new_str;
  }

  while (1) {
    char c = *new_str;
    bool is_delim = my_strchr(delim, c);
    if (c == '\0' || !is_delim) {
      break;
    }

    *new_str = '\0';
    *(new_str++);
  }
  return str;
}

// five
void *my_to_upper(const char *str) {
  char *ret = MY_NULL;
  if (str) {
    ret = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
  }
  char *tmp = ret;
  if (tmp) {
    my_size_t len = my_strlen(str) + 1;
    while (*str && len--) {
      *ret = *str;
      ret++;
      str++;
    }
    *ret = '\0';
    for (char *i = tmp; *i; i++) {
      if (*i >= 'a' && *i <= 'z') {
        *i -= 32;
      }
    }
  }
  return (void *)tmp;
}

void *my_to_lower(const char *str) {
  char *ret = MY_NULL;
  if (str) {
    ret = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
  }
  char *tmp = ret;
  if (tmp) {
    my_size_t len = my_strlen(str) + 1;
    while (*str && len--) {
      *ret = *str;
      ret++;
      str++;
    }
    *ret = '\0';
    for (char *i = tmp; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') {
        *i += 32;
      }
    }
  }
  return (void *)tmp;
}

void *my_insert(const char *src, const char *str, size_t start_index) {
  int flag = 0;
  char *ret = NULL;
  if (src && str && start_index <= (my_strlen(src) + my_strlen(str))) {
    ret = calloc(my_strlen(str) + my_strlen(src) + 1, sizeof(char));
    if (ret == NULL) {
      flag = 1;
    }
    if (start_index == 0) {
      my_strcpy(ret, str);
      my_strcat(ret, src);
    } else {
      size_t end_index = start_index;
      my_strcpy(ret, src);
      for (size_t i = 0; i < my_strlen(str); i++, end_index++) {
        size_t ret_len = my_strlen(ret);
        for (size_t j = ret_len; j >= end_index; j--) {
          ret[j + 1] = ret[j];
        }
        ret[end_index] = str[i];
      }
    }

  } else {
    flag = 1;
  }
  return flag ? NULL : ret;
}

void *my_trim(const char *src, const char *trim_chars) {
  int is_error = 0;
  char *result = MY_NULL;
  if (src != MY_NULL) {
    int len = my_strlen(src);
    result = calloc(len + 1, sizeof(char));
  }
  if (src) {
    char default_chars[7] = " \t\n\v\r\f\0";
    if (trim_chars == MY_NULL) {
      trim_chars = default_chars;
    } else {
      if (my_strlen(trim_chars) == 0) {
        trim_chars = default_chars;
      }
    }
    if (result == MY_NULL) {
      is_error = 1;
    }
    my_strcpy(result, (char *)src);
    delete_left_part(result, src, trim_chars);
    delete_right_part(result, src, trim_chars);

  } else {
    is_error = 1;
  }
  return is_error ? MY_NULL : result;
}

void delete_first_letter(char *str) {
  my_size_t counter = 0;
  while (str[counter]) {
    str[counter] = str[counter + 1];
    counter++;
  }
}

void delete_left_part(char *result, const char *src, const char *trim_chars) {
  my_size_t format_length = my_strlen(trim_chars);
  my_size_t str_length = my_strlen(src);
  for (size_t i = 0; i < str_length; i++) {
    int is_break = 0;
    for (size_t j = 0; j < format_length; j++) {
      if (src[i] == trim_chars[j]) {
        delete_first_letter(result);
        break;
      }
      if (j == format_length - 1 && src[i] != trim_chars[format_length]) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}

void delete_right_part(char *result, const char *src, const char *trim_chars) {
  my_size_t format_length = my_strlen(trim_chars);
  my_size_t result_length = my_strlen(result);
  for (int i = (int)result_length - 1; i >= 0; i--) {
    int is_break = 0;
    for (size_t j = 0; j < format_length; j++) {
      if (result[i] == trim_chars[j]) {
        result[i] = '\0';
        break;
      }
      if (j == format_length - 1 && src[i] != trim_chars[format_length]) {
        is_break = 1;
      }
    }
    if (is_break) break;
  }
}
