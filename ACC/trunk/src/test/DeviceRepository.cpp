#include "DeviceRepository.h"

void DeviceRepository::updateDevice(int deviceId)
{
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Try to acquire the mutex...\n")));
    _mutex.acquire();
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Got the mutex.\n")));
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Updating device:%d\n"),deviceId));
    ACE_OS::sleep(1);
    _mutex.release();
    ACE_DEBUG((LM_DEBUG,ACE_TEXT("[%T](%P|%t) Release the mutex.\n")));
    ACE_OS::sleep(1);
}
