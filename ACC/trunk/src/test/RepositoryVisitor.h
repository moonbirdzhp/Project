#ifndef REPOSITORYVISITOR_H
#define REPOSITORYVISITOR_H
#include "ace/Task.h"
#include "DeviceRepository.h"

class RepositoryVisitor : public ACE_Task_Base
{
    public:
            RepositoryVisitor(DeviceRepository& rep):_rep(rep){}
            virtual int svc(void);
    private:
            enum{NUM_USERS = 10};
            DeviceRepository& _rep;
};
#endif
