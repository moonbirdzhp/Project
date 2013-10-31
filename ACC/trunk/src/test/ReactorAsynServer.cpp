#include "ace/Proactor.h"
#include "ace/Asynch_Acceptor.h"
#include "AsynServiceHandler.h"

int main()
{
    ACE_INET_Addr port_to_accept(9000);
    ACE_Asynch_Acceptor<AsynServerHandler> server;
    if(server.open(port_to_accept) == -1)
    {
        return -1;
    }

    ACE_Proactor::instance()->proactor_run_event_loop();
    return 0;
}
