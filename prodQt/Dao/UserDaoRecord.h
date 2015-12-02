#ifndef USERDAORECORD_H
#define USERDAORECORD_H

#include <QString>

namespace Dao {

    struct UserDaoRecord
    {
        int userId;
        QString name;
        QString hash_pass;
        int role;
    };
}
#endif // USERDAORECORD_H

