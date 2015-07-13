#ifndef BLOWFISHPROVIDER
#define BLOWFISHPROVIDER

#include <QString>

typedef unsigned char byte;
class BLOWFISH;

namespace Utils {
    class BlowFishProvider {
    public:
        static QString GetDbPasswordEncoded(QString password);
        static QString GetDbPasswordDecoded(QString hash);
        static QString GetUserPasswordEncoded(QString password);
        static QString GetUserPasswordDecoded(QString hash);
    private:
        static QString GetPasswordEncoded(QString password, BLOWFISH&);
        static QString GetPasswordDecoded(QString hash, BLOWFISH&);
        static BLOWFISH bfDb;
        static BLOWFISH bfUser;
    };
}

#endif // BLOWFISHPROVIDER

