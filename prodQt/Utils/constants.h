#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <QStringList>
#include <map>

namespace {
    const std::map<int, QString> c_accessTypes={ std::make_pair(100, "Pełny"),
                                                 std::make_pair(101, "Ograniczony") };
}

namespace Utils {
    class Constants {
    public:
        static std::string GetBlowfishDatabaseUserPasswordKey() {
            return "0c9d3544ce78d33cf2ecc2945adda0c42c2b745b";
        }
        static std::string GetBlowfishApplicationUserPasswordKey() {
            return "fc3c7c79ec88242ff3a5dd163492826dc6c1f2d5";
        }
        static int GetLenghtOfUserPassword(){
            return 5;
        }
        static QStringList GetAllAccessTypes() {
            QStringList types;
            for(const auto &access : c_accessTypes)
                types.push_back(access.second);

            return types;
        }
        static int GetCorrespondingAccessNumber(QString accessName)
        {
            for(const auto &access : c_accessTypes)
            {
                if (access.second == accessName)
                    return access.first;
            }
            return -1;
        }

    };
}

#endif // CONSTANTS
