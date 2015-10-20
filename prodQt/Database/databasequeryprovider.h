#ifndef DATABASEQUERYPROVIDER_H
#define DATABASEQUERYPROVIDER_H

#include <QString>

namespace Database
{
    class DatabaseQueryProvider
    {
    public:
        static QString getUserDatabaseName(){
            return "useraccount";
        }
        static QString getUserPassword(){
            return "SELECT hash_pass FROM useraccount WHERE name = :userName";
        }
        static QString addUser(){
            return "INSERT INTO useraccount (name, hash_pass, role) \
                    VALUES (:userName, :userPass, :userRole);";
        }
        static QString existUser(){
            return "SELECT EXISTS (SELECT name FROM useraccount WHERE name = :userName)";
        }

    };

}


#endif // DATABASEQUERYPROVIDER_H
