#include "securitycheckfailedexception.h"

namespace Utils
{
    SecurityCheckFailedException::SecurityCheckFailedException()
    {
        ErrorMessage = "Credentials check failed.";
    }

    const char* SecurityCheckFailedException::what() const throw()
    {
        return ErrorMessage.toStdString().c_str();
    }
}

