// Copyright (c) 2018 The PromTSDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.


#include <vector>


bool test_vector() {
  std::vector<int> ints;
  return ints.size() == 0;
}


int main(int argc, char** argv) {
  if (test_vector())
    return 0;
  return 1;
}