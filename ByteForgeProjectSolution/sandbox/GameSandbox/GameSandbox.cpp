#include <managers/LogManager.h>

using ByteForgeEngine::LoggingSystem::LogManager;

int main(int argc, char* argv[])
{
	LogManager logManager;
	
	logManager.AddConsoleOutput();
	logManager.AddWindowsVisualStudioDebugOutput();

	logManager.Trace("Trace");
	logManager.Debug("Number: %d", 2903);
	logManager.Info("Teste");
	logManager.Success("Ready!");
	logManager.Warning("Possible null reference...");
	logManager.Error("Error");
	logManager.Fatal("Exception");

	while (true) {};

	return 0;
}