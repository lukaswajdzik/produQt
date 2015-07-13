#include <QString>
#include <iostream>
#include <string>
//#include "External/blowfish.h"
#include "Utils/constants.h"
#include "Utils/Exceptions/securitycheckfailedexception.h"
#include "Utils/blowfishprovider.h"

typedef unsigned char byte;

namespace Utils {
    BlowFishProvider::~BlowFishProvider()
    {
        qDebug() <<  "~BlowFishProvider***********************";
    }

    QString BlowFishProvider::GetDbPasswordEncoded(QString password) {
        qDebug() <<  "GetDbPasswordEncoded***********************";
        return GetPasswordEncoded(password, Utils::Constants::GetBlowfishDatabaseUserPasswordKey());
    }
    QString BlowFishProvider::GetDbPasswordDecoded(QString hash) {
        return GetPasswordDecoded(hash, Utils::Constants::GetBlowfishDatabaseUserPasswordKey());
    }
    QString BlowFishProvider::GetUserPasswordEncoded(QString password) {
        return GetPasswordEncoded(password, Utils::Constants::GetBlowfishApplicationUserPasswordKey());
    }
    QString BlowFishProvider::GetUserPasswordDecoded(QString hash) {
        return GetPasswordDecoded(hash, Utils::Constants::GetBlowfishApplicationUserPasswordKey());
    }
    QString BlowFishProvider::GetPasswordEncoded(QString password, std::string bfHash) {
//        if(password.isEmpty() || QString(bfHash).isEmpty()) {
//            return "";
//        }
        qDebug() <<  "GetPasswordEncoded***********************";
//        try {
//            BLOWFISH bf(bfHash.toStdString());
//            std::string str = "";
//            str = bf.Encrypt_CBC(password.toStdString());
//            return QString::fromStdString(str);
//        }
//        catch(int) {
//            throw new SecurityCheckFailedException();
//        }
    }
    QString BlowFishProvider::GetPasswordDecoded(QString hash, std::string bfHash) {
//        if(hash.isEmpty() || bfHash.isEmpty()) {
//            return "";
//        }
        try {
//            BLOWFISH bf(bfHash.toStdString());
//            std::string str = "";
//            str = bf.Decrypt_CBC(hash.toStdString());
//            return QString::fromStdString(str);
        }
        catch(int) {
            throw new SecurityCheckFailedException();
        }
    }

}
