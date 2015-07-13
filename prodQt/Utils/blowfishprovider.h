#ifndef BLOWFISHPROVIDER
#define BLOWFISHPROVIDER

#include <string>
#include <QString>

typedef unsigned char byte;

namespace Utils {
    class BlowFishProvider {
    public:
        static QString GetDbPasswordEncoded(QString password);
        static QString GetDbPasswordDecoded(QString hash);
        static QString GetUserPasswordEncoded(QString password);
        static QString GetUserPasswordDecoded(QString hash);
        ~BlowFishProvider();
    private:
        static QString GetPasswordEncoded(QString password, std::string bfHash);
        static QString GetPasswordDecoded(QString hash, std::string bfHash);
    };
}

#endif // BLOWFISHPROVIDER

