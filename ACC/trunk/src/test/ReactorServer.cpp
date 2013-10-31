#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ServiceHandler.h"
class ServerHandler;
int main(int argc, char* argv[])
{
    ACE_INET_Addr port_to_accept(9000);
    ACE_Acceptor<ServerHandler, ACE_SOCK_ACCEPTOR> server;
    if(server.open(port_to_accept) == -1)
    {
        return -1;
    }
    ACE_Reactor::instance()->run_reactor_event_loop();
    return 0;
}
