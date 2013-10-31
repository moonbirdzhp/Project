#ifndef CLIENTTASKHANDLER_H
#define CLIENTASKTHANDLER_H

#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"
#include "ace/Reactor_Notification_Strategy.h"

class ClientTaskHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
{
    typedef ACE_Svc_Handler<ACE_SOCK_STREAM,ACE_NULL_SYNCH> super;
    public:
        ClientTaskHandler():notifier_(0,this,ACE_Event_Handler::WRITE_MASK){}
        int open(void* ptr=0);
        int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
        int handle_output(ACE_HANDLE fd = ACE_INVALID_HANDLE);
        int svc(void);
        int close(u_long);
    private:
        enum {ITERATIONS = 5};
        int iterations_;
        ACE_Reactor_Notification_Strategy notifier_;
};
#endif
