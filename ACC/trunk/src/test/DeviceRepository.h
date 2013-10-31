#ifndef DEVICEREPOSITORY_H
#define DEVICEREPOSITORY_H
#include "ace/Synch.h"

class DeviceRepository
{
    public:
            DeviceRepository(){}
            void updateDevice(int deviceId);
    private:
            ACE_Thread_Mutex _mutex;
};
#endif
