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

#include <stdbool.h>

#include "deps/zonterm/outputstream.h"

static bool __zng_keep_testing = true;
static int __zng_test_result_ = 0;
#define TEST_RESULT() __zng_test_result_

#define FAIL(__ZNG_FAIL_MESSAGE)              \
do {                                          \
  STDERR_RED("  %s\n", (__ZNG_FAIL_MESSAGE)); \
  __zng_test_result_ = 1;                     \
  __zng_keep_testing = false;                 \
} while (0)

#endif // __ZNG_RESULTS_H__
