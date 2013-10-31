#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"
class ClientHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
    typedef ACE_Svc_Handler<ACE_SOCK_STREAM,ACE_NULL_SYNCH> super;
    public:
        int open(void* ptr=0);
        int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
        int handle_timeout(const ACE_Time_Value& current_time, const void *act=0);
    private:
        enum {ITERATIONS = 5};
        int iterations_;
};
#endif
