#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <QDebug>
#include <QString>
#include <map>
#include <utility>

namespace Utils {
    class Constants {
        static std::map<int, QString> const s_accessType;/*{std::make_pair(10, "Pełny"),
                                                         std::make_pair(11, "Ograniczony")};*/

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
        static QStringList GetAccessTypes() {
            return {"Pełny", "Ograniczony"};
        }
    };
}

#endif // CONSTANTS
