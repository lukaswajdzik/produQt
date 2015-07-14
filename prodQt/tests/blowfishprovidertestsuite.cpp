#include "gtest/gtest.h"
#include <QString>
#include "Utils/blowfishprovider.h"
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


TEST_F (blowFishProviderTest, comparePasswordAfterAndBeforeEncryption) {
    const QString password = "pass4check.";
    QString hashPass = sut.GetDbPasswordEncoded(password);
    QString pass = sut.GetDbPasswordDecoded(hashPass);
    EXPECT_EQ(password, pass);
}

}
