#ifndef BLOWFISHPROVIDER
#define BLOWFISHPROVIDER

#include <QString>
#include <iostream>
#include <string.h>
#include "External/blowfish.h"
#include "Utils/constants.h"
#include "Utils/Exceptions/securitycheckfailedexception.h"

using namespace std;
typedef unsigned char byte;

namespace Utils {
    class BlowFishProvider {
    public:
        static QString GetDbPasswordEncoded(QString password) {
            return GetPasswordEncoded(password, Utils::Constants::GetBlowfishDatabaseUserPasswordKey());
        }
        static QString GetDbPasswordDecoded(QString hash) {
            return GetPasswordDecoded(hash, Utils::Constants::GetBlowfishDatabaseUserPasswordKey());
        }
        static QString GetUserPasswordEncoded(QString password) {
            return GetPasswordEncoded(password, Utils::Constants::GetBlowfishApplicationUserPasswordKey());
        }
        static QString GetUserPasswordDecoded(QString hash) {
            return GetPasswordDecoded(hash, Utils::Constants::GetBlowfishApplicationUserPasswordKey());
        }
    private:
        static QString GetPasswordEncoded(QString password, QString bfHash) {
            if(password.isEmpty() || bfHash.isEmpty()) {
                return "";
            }
            try {
                BLOWFISH bf(bfHash.toStdString());
                string str = "";
                str = bf.Encrypt_CBC(password.toStdString());
                return QString::fromStdString(str);
            }
            catch(int) {
                throw new SecurityCheckFailedException();
            }
        }
        static QString GetPasswordDecoded(QString hash, QString bfHash) {
            if(hash.isEmpty() || bfHash.isEmpty()) {
                return "";
            }
            try {
                BLOWFISH bf(bfHash.toStdString());
                string str = "";
                str = bf.Decrypt_CBC(hash.toStdString());
                return QString::fromStdString(str);
            }
            catch(int) {
                throw new SecurityCheckFailedException();
            }
        }
    };
}


#endif // BLOWFISHPROVIDER

