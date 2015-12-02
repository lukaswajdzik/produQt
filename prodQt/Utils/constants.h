#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <QStringList>
#include <map>
#include "Application/UserAccessType.h"

using namespace Application;

namespace {
    const std::map<QString, UserAccessType> c_accessTypesTranslation =
    { std::make_pair("Pełny",       UserAccessType::FULL),
      std::make_pair("Ograniczony", UserAccessType::LIMITED) };
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
        static QString GetWeightTabViewName(){
            return "--Waga--";
        }
        static QString GetProductTableTabViewName(){
            return "--Produkty--";
        }
        static QString GetProductTableDbName(){
            return "products";
        }

        static QStringList GetAllAccessTypesTranslated() {
            QStringList types;
            for(const auto &access : c_accessTypesTranslation)
                types.push_back(access.first);

            return types;
        }
        static int GetCorrespondingAccessNumber(QString accessName)
        {
            for(const auto &access : c_accessTypesTranslation)
            {
                if (access.first == accessName)
                    return static_cast<int>(access.second);
            }
            return -1;
        }

    };
}

#endif // CONSTANTS
