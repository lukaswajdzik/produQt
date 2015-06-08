#ifndef IOPERATIVEDATABASECONNECTOR
#define IOPERATIVEDATABASECONNECTOR

#include <string>

namespace Database
{
    class IDatabaseConnector
    {
    public:
        IDatabaseConnector();
        ~IDatabaseConnector();
    private:
        void Connect();
        void Dispose();
    };
}

#endif

