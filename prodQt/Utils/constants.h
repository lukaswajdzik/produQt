#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <QDebug>

namespace Utils {
    class Constants {
    public:
        static std::string GetBlowfishDatabaseUserPasswordKey() {
            return "0c9d3544ce78d33cf2ecc2945adda0c42c2b745b";
        }
        static std::string GetBlowfishApplicationUserPasswordKey() {
            return "fc3c7c79ec88242ff3a5dd163492826dc6c1f2d5";
        }
        static std::string GetSuperUserPassword() {
            return "TkkUk6v4DcqfXfyK";
        }
    };
}

#endif // CONSTANTS
