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
        static QString existCategory(){
            return "SELECT EXISTS (SELECT category FROM categories WHERE category = :categoryName AND parent = :parentName)";
        }
        static QString getCategoryParent(){
            return "SELECT parent FROM categories WHERE category = :categoryName";
        }
        static QString getUserData(){
            return "SELECT user_id, name, role FROM useraccount WHERE name = :userName";
        }
        static QString addNewCategorys(){
            return "INSERT INTO categories (category, parent) \
                    VALUES (:newName, :baseName);";
        }
        static QString addNewCategory(){
            return "INSERT INTO categories (category, parent, fullname) \
                    VALUES (:newName, :parentName, :fullName);";
        }


    };

}


#endif // DATABASEQUERYPROVIDER_H
