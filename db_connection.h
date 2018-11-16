// Copyright (c) 2018 The PromTSDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.


#ifndef CTEST_DB_CONNECTION_H
#define CTEST_DB_CONNECTION_H


#include <string>


namespace ctest {


class DbConnection {
public:
  virtual bool connect(std::string username, std::string password) { return false; }
};



}


#endif //CTEST_DB_CONNECTION_H
