/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel García Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zontest/blob/main/LICENSE
 */

#ifndef __ZNG_TEST_H__
#define __ZNG_TEST_H__

#include <stdlib.h>

#include "comparators.h"

static void (**__zng_function_array)() = NULL;
static char** __zng_section_names = NULL;
static char** __zng_test_names = NULL;
static int __zng_function_array_size = 0;

#define TEST(NameOfTheTestSection, name_of_the_specific_test)                  \
  static void test_##NameOfTheTestSection##_##name_of_the_specific_test();     \
  __attribute__((constructor))                                                 \
  static void                                                                  \
  test_##NameOfTheTestSection##_##name_of_the_specific_test##_initialize() {   \
    __zng_function_array_size++;                                               \
    __zng_function_array =                                                     \
        (void (**)()) realloc(__zng_function_array,                            \
                              __zng_function_array_size * sizeof(void (*)())); \
    __zng_section_names =                                                      \
        (char **) realloc(__zng_section_names,                                 \
                          __zng_function_array_size * sizeof(char *));         \
    __zng_test_names =                                                         \
        (char **) realloc(__zng_test_names,                                    \
                          __zng_function_array_size * sizeof(char *));         \
    __zng_function_array[__zng_function_array_size - 1] =                      \
        test_##NameOfTheTestSection##_##name_of_the_specific_test;             \
    __zng_section_names[__zng_function_array_size - 1] =                       \
        #NameOfTheTestSection;                                                 \
    __zng_test_names[__zng_function_array_size - 1] =                          \
        #name_of_the_specific_test;                                            \
  }                                                                            \
  static void test_##NameOfTheTestSection##_##name_of_the_specific_test()

#define RUN_TESTS()                                     \
do {                                                    \
  for (int i = 0; i < __zng_function_array_size; i++) { \
    __zng_function_array[i]();                          \
    if (__zng_keep_testing) {                           \
      STDOUT_GREEN("  [%s][%s]: Passed.\n",             \
          __zng_section_names[i], __zng_test_names[i])  \
    } else {                                            \
      STDERR_RED("  [%s][%s]: Failed.\n",               \
          __zng_section_names[i], __zng_test_names[i]); \
      break;                                            \
    }                                                   \
  }                                                     \
  if (__zng_function_array != NULL) {                   \
    free(__zng_function_array);                         \
    __zng_function_array = NULL;                        \
  }                                                     \
  if (__zng_section_names != NULL) {                    \
    free(__zng_section_names);                          \
    __zng_section_names = NULL;                         \
  }                                                     \
  if (__zng_test_names != NULL) {                       \
    free(__zng_test_names);                             \
    __zng_test_names = NULL;                            \
  }                                                     \
} while (0)

#endif // __ZNG_TEST_H__
