#include "usermodifier.h"
#include "Database/operativedatabaseconnector.h"

namespace User{


UserModifier::UserModifier()
{

}

UserModifier::~UserModifier()
{

}

void UserModifier::addUser(UserData p_data)
{
    Database::OperativeDatabaseConnector operativeDbConnector;
    operativeDbConnector.addUserToDatabase(p_data);
}

void UserModifier::removeUser(QString)
{

}

void UserModifier::editUser(UserData)
{

}

}
