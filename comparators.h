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

#ifndef __ZNG_COMPARATORS_H__
#define __ZNG_COMPARATORS_H__

#include "results.h"

#define EXPECT_EQUAL(__ZNG_LHS, __ZNG_RHS) \
do {                                       \
  if ((__ZNG_LHS) != (__ZNG_RHS)) {        \
    FAIL("Arguments '"                     \
         #__ZNG_LHS                        \
         "' and '"                         \
         #__ZNG_RHS                        \
         "' should be equal.");            \
  }                                        \
} while (0)

#define EXPECT_DIFFERENT(__ZNG_LHS, __ZNG_RHS) \
do {                                           \
  if ((__ZNG_LHS) == (__ZNG_RHS)) {            \
    FAIL("Arguments '"                         \
         #__ZNG_LHS                            \
         "' and '"                             \
         #__ZNG_RHS                            \
         "' should be different.");            \
  }                                            \
} while (0)

#define EXPECT_TRUE(__ZNG_EXPRESSION)                         \
do {                                                          \
  if (!(__ZNG_EXPRESSION)) {                                  \
    FAIL("The following boolean expression should be true: '" \
         #__ZNG_EXPRESSION                                    \
         "'.");                                               \
  }                                                           \
} while (0)

#define EXPECT_FALSE(__ZNG_EXPRESSION)                         \
do {                                                           \
  if ((__ZNG_EXPRESSION)) {                                    \
    FAIL("The following boolean expression should be false: '" \
         #__ZNG_EXPRESSION                                     \
         "'.");                                                \
  }                                                            \
} while (0)

#endif // __ZNG_COMPARATORS_H__
