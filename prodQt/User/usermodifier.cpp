#include "usermodifier.h"
#include "Database/useroperativedb.h"

namespace User{


UserModifier::UserModifier(std::shared_ptr<Database::IOperativeDatabaseConnector>& userOperativeDB) :
    m_userOperativeDB(userOperativeDB)
{}

UserModifier::~UserModifier()
{}

void UserModifier::addUser(UserData p_data)
{
    m_userOperativeDB->addUserToDatabase(p_data);
    m_userOperativeDB->VerifyUser("lakiluk", "aaa");
}

void UserModifier::removeUser(QString)
{

}

void UserModifier::editUser(UserData)
{

}

}
