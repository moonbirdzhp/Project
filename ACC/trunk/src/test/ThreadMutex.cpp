#include "DeviceRepository.h"
#include "RepositoryVisitor.h"

int main(int argc, char* argv[])
{
    DeviceRepository rep;
    RepositoryVisitor v1(rep);
    RepositoryVisitor v2(rep);
    v1.activate();
    v2.activate();
    v1.wait();
    v2.wait();
    return 0;
}
