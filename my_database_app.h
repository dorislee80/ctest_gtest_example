// Copyright (c) 2018 The PromTSDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.


#include <iostream>
#include <string>
#include "db_connection.h"


class MyDatabaseApp {
private:
    ctest::DbConnection& conn_;


public:
    MyDatabaseApp(ctest::DbConnection& conn) : conn_(conn) { }


    bool login(std::string username, std::string password) {
      if (conn_.connect(username, password))
        std::cout << "OK" << std::endl;
      else
        std::cout << "FAILED" << std::endl;
    }
};
