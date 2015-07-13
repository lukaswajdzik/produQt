#include <string>
#include "Utils/constants.h"
#include "Utils/Exceptions/securitycheckfailedexception.h"
#include "Utils/blowfishprovider.h"
#include "External/blowfish.h"


typedef unsigned char byte;

namespace Utils {
    BLOWFISH BlowFishProvider::bfDb(Utils::Constants::GetBlowfishDatabaseUserPasswordKey());
    BLOWFISH BlowFishProvider::bfUser(Utils::Constants::GetBlowfishApplicationUserPasswordKey());

    QString BlowFishProvider::GetDbPasswordEncoded(QString password) {
        return GetPasswordEncoded(password, BlowFishProvider::bfDb);
    }
    QString BlowFishProvider::GetDbPasswordDecoded(QString hash) {
        return GetPasswordDecoded(hash, BlowFishProvider::bfDb);
    }
    QString BlowFishProvider::GetUserPasswordEncoded(QString password) {
        return GetPasswordEncoded(password, BlowFishProvider::bfUser);
    }
    QString BlowFishProvider::GetUserPasswordDecoded(QString hash) {
        return GetPasswordDecoded(hash, BlowFishProvider::bfUser);
    }
    QString BlowFishProvider::GetPasswordEncoded(QString password, BLOWFISH &bf) {
        if(password.isEmpty()) {
            return "";
        }
        try {
            std::string str = "";
            str = bf.Encrypt_CBC(password.toStdString());
            return QString::fromStdString(str);
        }
        catch(int) {
            throw SecurityCheckFailedException();
        }
    }
    QString BlowFishProvider::GetPasswordDecoded(QString hash, BLOWFISH &bf) {
        if(hash.isEmpty()) {
            return "";
        }
        try {
            std::string str = "";
            str = bf.Decrypt_CBC(hash.toStdString());
            return QString::fromStdString(str);
        }
        catch(int) {
            throw SecurityCheckFailedException();
        }
    }

}
