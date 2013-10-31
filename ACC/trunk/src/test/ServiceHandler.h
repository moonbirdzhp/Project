#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"

class ServerHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
    typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> super;
    public:
        int open(void* = 0);
        int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
    private:
        ACE_TCHAR peer_name[MAXHOSTNAMELEN];
};
#endif
