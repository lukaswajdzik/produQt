#ifndef DBQUERYCOULDNOTBEEXECUTED_H
#define DBQUERYCOULDNOTBEEXECUTED_H
#include <exception>
#include <QSqlError>


class DbQueryCouldNotBeExecuted : public std::exception
{
public:
    DbQueryCouldNotBeExecuted(QSqlError);
    const char* what() const throw();
private:
    QSqlError m_error;
};

#endif // DBQUERYCOULDNOTBEEXECUTED_H
