#include <cstdlib>

#include "core_systems/strings/string_extensions.hpp"
#include "core_systems/logger/logger.hpp"
#include "pong/pong.hpp"

using BFE::CoreSystems::Strings::StringExtensions;
using std::to_string;

int main(int argc, char* argv[])
{
    Logger::Debug("Engine started with " + to_string(argc) + " argument(s): [ " + StringExtensions::Join(argv, "-") + " ]");
    Logger::Debug("Pong game project selected...");

	Pong pong;

    pong.Initialize();
    pong.Run();
    pong.Shutdown();

    Logger::Warning("Engine terminating...");

    return EXIT_SUCCESS;
}