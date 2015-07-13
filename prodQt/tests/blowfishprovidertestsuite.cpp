#include "gtest/gtest.h"
#include <QString>
#include "Utils/blowfishprovider.cpp"
#include <QDebug>

namespace {

class blowFishProviderTest : public ::testing::Test{
protected:

  blowFishProviderTest()
  {}

  virtual ~blowFishProviderTest()
  {}

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp()
  {qDebug() <<  "set up***********************";}

  virtual void TearDown()
  {qDebug() <<  "tear down***********************";}

  Utils::BlowFishProvider sut;

};


TEST_F (blowFishProviderTest, ZeroAndNegativeNos) {
    qDebug() << "start*********************";
    QString abc1 = sut.GetDbPasswordEncoded("jajko");
    QString abc2 = sut.GetDbPasswordEncoded("jajsko");
//    QString abc2 = Utils::BlowFishProvider::GetDbPasswordDecoded(abc1);
//    QString abc3 = Utils::BlowFishProvider::GetDbPasswordDecoded(abc2);
//    ASSERT_EQ (abc1.toStdString(), abc2.toStdString());
//    ASSERT_EQ (abc, "ania");
//    ASSERT_GE
    EXPECT_GE (-100, (-22.0));

}

}
