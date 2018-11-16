// Copyright (c) 2018 The PromTSDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../db_connection.h"
#include "../my_database_app.h"


using ::testing::_;
using ::testing::AnyNumber;
using ::testing::Gt;
using ::testing::Return;


class MockDbConnection : public ctest::DbConnection {
public:
    MOCK_METHOD2(connect, bool (std::string username, std::string password));
};


TEST(my_database_app, login) {
  MockDbConnection dbConn;
  MyDatabaseApp app(dbConn);

  ON_CALL(dbConn, connect(_, _)).WillByDefault(Return(true));

  ASSERT_TRUE(app.login("hello", "world"));
}