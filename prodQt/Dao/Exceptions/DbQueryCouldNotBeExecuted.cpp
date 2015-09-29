#include "DbQueryCouldNotBeExecuted.h"

DbQueryCouldNotBeExecuted::DbQueryCouldNotBeExecuted(QSqlError error) :
    m_error(error)
{
}

const char* DbQueryCouldNotBeExecuted::what() const throw()
{
    return m_error.text().toStdString().c_str();
}

