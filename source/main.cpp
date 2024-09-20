#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "core_systems/strings/string_extensions.hpp"
#include "core_systems/logging/logger.hpp"

#include "pong/pong.hpp"

using namespace BFE::CoreSystems::Logging;
using namespace BFE::CoreSystems::Strings;

void InitializeEngine(const int& argc, const char* argv[]);
void TerminateEngine();

int main(const int argc, const char* argv[])
{
    InitializeEngine(argc, argv);

    Pong pong;

    pong.Initialize();
    pong.Run();
    pong.Shutdown();

    TerminateEngine();

    return EXIT_SUCCESS;
}

void InitializeEngine(const int& argc, const char* argv[])
{
    Logger::Info("Engine started with " + std::to_string(argc) + " argument(s): [ " + StringExtensions::Join(argv, "-") + " ]");
}

void TerminateEngine()
{
    Logger::Warning("Engine terminating...");
}