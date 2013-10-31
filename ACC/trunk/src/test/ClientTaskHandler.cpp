#include "ClientTaskHandler.h"

int ClientTaskHandler::open(void* p)
{
    if(super::open(p)==-1)
    {
        return -1;
    }
    this->notifier_.reactor(this->reactor());
    this->msg_queue()->notification_strategy(&this->notifier_);

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Connection Start\n")));
    this->iterations_ = 0;
    return activate();
}

int ClientTaskHandler::close(u_long flags)
{
    return 0;
}
int ClientTaskHandler::handle_input(ACE_HANDLE)
{
    const int SIZE = 4096;
    char buffer[SIZE];
    memset(buffer,0,SIZE);
    int recv_cnt = this->peer().recv(buffer, sizeof(buffer));

    if(recv_cnt <= 0)
    {
        ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Connection close\n")));
        this->reactor()->end_reactor_event_loop();
        return -1;
    }

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Receive msg from server :%s\n"),buffer));
    return 0;
}

int ClientTaskHandler::svc(void)
{
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("[%T](%P|%t) Thread starts\n")));
    while(1)
    {
        if (++this->iterations_ > ITERATIONS)
        {
            ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Disconnect from server\n")));
            this->peer().close_writer();
            break;
        }
        ACE_Message_Block *mb;
        ACE_NEW_RETURN(mb, ACE_Message_Block(128), -1);
        int nbytes = ACE_OS::sprintf(mb->wr_ptr(),"Iteration %d \n", this->iterations_);
        ACE_ASSERT(nbytes > 0);
        mb->wr_ptr(static_cast<size_t>(nbytes));
        this->putq(mb);
        ACE_OS::sleep(2);
    }
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Thread ends\n")));
    return 0;
}

int ClientTaskHandler::handle_output(ACE_HANDLE)
{
    ACE_Message_Block *mb;
    while(-1 != this->getq(mb))
    {
        ssize_t send_cnt = this->peer().send(mb->rd_ptr(),mb->length());
        if(send_cnt == -1)
        {
            ACE_ERROR((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Send msg failed\n")));
        }
        else
        {
            mb->rd_ptr(static_cast<size_t>(send_cnt));
        }
        if(mb->length()>0)
        {
            this->ungetq(mb);
            break;
        }
        mb->release();
    }
    if(this->msg_queue()->is_empty())
    {
        this->reactor()->cancel_wakeup(this, ACE_Event_Handler::WRITE_MASK);
    }
    else
        this->reactor()->schedule_wakeup(this, ACE_Event_Handler::WRITE_MASK);
    return 0;
}
