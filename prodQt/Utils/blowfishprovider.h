#ifndef BLOWFISHPROVIDER
#define BLOWFISHPROVIDER

#include <QString>

typedef unsigned char byte;

namespace Utils {
    class BlowFishProvider {
    public:
        static QString GetDbPasswordEncoded(QString password);
        static QString GetDbPasswordDecoded(QString hash);
        static QString GetUserPasswordEncoded(QString password);
        static QString GetUserPasswordDecoded(QString hash);
    private:
        static QString GetPasswordEncoded(QString password, QString bfHash);
        static QString GetPasswordDecoded(QString hash, QString bfHash);
    };
}

#endif // BLOWFISHPROVIDER

