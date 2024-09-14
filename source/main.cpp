#include "coresystems/application/application.hpp"

int main(int argc, char *argv[])
{
    Application application;

    application.Initialize();
    application.Run();
    application.Shutdown();

    return 0;
}