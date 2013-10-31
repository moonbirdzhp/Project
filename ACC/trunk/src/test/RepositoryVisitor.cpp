#include "RepositoryVisitor.h"

int RepositoryVisitor::svc()
{
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Visitor Thread Running...\n")));
    for(int i=0; i<NUM_USERS; i++)
        this->_rep.updateDevice(i);
    return 0;
}
