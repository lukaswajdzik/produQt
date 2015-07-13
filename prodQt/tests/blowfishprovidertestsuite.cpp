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

  virtual void SetUp()
  {}

  virtual void TearDown()
  {}

  Utils::BlowFishProvider sut;
};


TEST_F (blowFishProviderTest, comparePasswodAfterAndBeforeEncryption) {
    const QString password = "pass4check.";
    QString hashPass = sut.GetDbPasswordEncoded(password);
    QString pass = sut.GetDbPasswordDecoded(hashPass);
    EXPECT_EQ(password, pass);
}

}