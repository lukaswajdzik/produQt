#ifndef BLOWFISHCOMPUTATIONEXCEPTION_H
#define BLOWFISHCOMPUTATIONEXCEPTION_H

#include <exception>
#include <QString>

namespace Utils
{
    class SecurityCheckFailedException : public std::exception
    {
    public:
        SecurityCheckFailedException();
        virtual const char* what() const throw();
        private:
            QString ErrorMessage;
    };
}

#endif // BLOWFISHCOMPUTATIONEXCEPTION_H
