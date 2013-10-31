#include "ace/Reactor.h"
#include "ace/Connector.h"
#include "ace/SOCK_Connector.h"
#include "ClientHandler.h"

int main(int argc, char* argv[])
{
    ACE_INET_Addr port_to_connect(9000,ACE_LOCALHOST);
    ACE_Connector<ClientHandler, ACE_SOCK_Connector> client;

    for(int i=0; i<5; i++)
    {
        ClientHandler* handler = NULL;
        if(client.connect(handler, port_to_connect) == -1)
        {
            ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%p|%t) Connection %d failed.\n"),i));
            return -1;
        }
    }
    ACE_Reactor::instance()->run_reactor_event_loop();
    return 0;
}
