// Copyright (c) 2018 The PromTSDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.


#include <string>
#include <gtest/gtest.h>


TEST(map_test, push) {
  std::map<int, std::string> id_to_name;
  id_to_name[1] = "hello";

  ASSERT_EQ(id_to_name.size(), 1);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
