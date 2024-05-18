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

#ifndef __ZNG_RESULTS_H__
#define __ZNG_RESULTS_H__

#include "deps/zonterm/outputstream.h"

#ifdef __cplusplus

#include <string>

static std::string __zng_current_test_;
static const char* __zng_current_test() { return __zng_current_test_.c_str(); }

#else

static char* __zng_current_test_;
static const char* __zng_current_test() { return __zng_current_test_; }

#endif // __cplusplus

static int __zng_test_result_ = 0;
static int test_result() { return __zng_test_result_; }

# define START_TEST(str)       \
do {                           \
  __zng_current_test_ = (str); \
  __zng_test_result_ = 0;      \
} while (0)

#define FINISH_TEST()                                      \
do {                                                       \
  if (test_result() == 0) {                                \
    STDOUT_GREEN("[%s]: Passed.\n", __zng_current_test()); \
  }                                                        \
} while (0)

#define FINISH_TEST_FAILED()                           \
do {                                                   \
  STDERR_RED("[%s]: Failed.\n", __zng_current_test()); \
} while (0)

#define FAIL(str)                                        \
do {                                                     \
  STDERR_RED("[%s]: %s\n", __zng_current_test(), (str)); \
  FINISH_TEST_FAILED();                                  \
  __zng_test_result_ = 1;                                \
} while (0)

#endif // __ZNG_RESULTS_H__
