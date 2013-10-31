#include "ServiceHandler.h"
int ServerHandler::open(void* p)
{
    if(super::open(p) == -1)
    {
        return -1;
    }

    ACE_INET_Addr peer_addr;
    if(this->peer().get_remote_addr(peer_addr)==0 &&
            peer_addr.addr_to_string(peer_name,MAXHOSTNAMELEN)==0)
    {
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Connection from %s\n"), peer_name));
    }
    return 0;
}
int ServerHandler::handle_input(ACE_HANDLE)
{
    const int INPUT_SIZE = 4096;
    char buffer[INPUT_SIZE];
    memset(buffer,0,INPUT_SIZE);

    int recv_cnt = this->peer().recv(buffer,sizeof(buffer));

    if(recv_cnt <= 0)
    {
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Connection close from %s\n"), peer_name));
        return -1;
    }
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Receive msg from %s: %s\n"), peer_name, buffer));
    this->peer().send(buffer,recv_cnt);
    return 0;
}
