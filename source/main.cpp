#define SDL_MAIN_HANDLED

#include <cstdlib>

#include "core_systems/strings/string_extensions.hpp"
#include "core_systems/logging/logger.hpp"
#include "pong/pong.hpp"

namespace Logging = BFE::CoreSystems::Logging;
namespace Strings = BFE::CoreSystems::Strings;

int main(int argc, char* argv[])
{
    Logging::Logger::Info("Engine started with " + std::to_string(argc) + " argument(s): [ " + Strings::StringExtensions::Join(argv, "-") + " ]");

    Logging::Logger::Debug("Pong game project selected...");

    Pong pong;

    pong.Initialize();
    pong.Run();
    pong.Shutdown();

    Logging::Logger::Warning("Engine terminating...");

    return EXIT_SUCCESS;
}