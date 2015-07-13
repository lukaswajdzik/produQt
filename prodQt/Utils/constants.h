#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <QDebug>

namespace Utils {
    class Constants {
    public:
        inline static std::string GetBlowfishDatabaseUserPasswordKey() {
            qDebug() <<  "Constants***********************";
            return "0c9d3544ce78d33cf2ecc2945adda0c42c2b745b";
        }
        inline static std::string GetBlowfishApplicationUserPasswordKey() {
            qDebug() <<  "Constants***********************";
            return "fc3c7c79ec88242ff3a5dd163492826dc6c1f2d5";
        }
    };
}

#endif // CONSTANTS
