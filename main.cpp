#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <vector>

int myFunction();

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class mClass{
public:
	virtual bool foo(string a) {return true;}
};

class mMock: public mClass{
  public:
	MOCK_METHOD1(foo, bool (string a));
};



int main(int argc, char* argv[]) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


int myFunction(mMock &obj)
{
	obj.foo("hello mock");
	return 5;
//	return mClass.foo();
}

TEST (mockTest, mock1) {
    ASSERT_EQ (5, 5);
}

TEST (mockTest, mock2) {
    // arrange
   mMock mObj;
   EXPECT_CALL(mObj, foo("hello mock"))
  .Times(AtLeast(1));
  // .WillOnce(Return(true));
    // act
    int ret= myFunction(mObj);
    // assert
    ASSERT_EQ(ret, 5);
}









